data Dir = Left2 | Right2 | Straight2 deriving Show
data Mapa a = Cofre [a] | Nada (Mapa a) | Bifurcacion [a] (Mapa a) (Mapa a) deriving Show

m1 = Bifurcacion [] (Nada (Nada (Cofre [1]))) (Bifurcacion [] (Nada (Cofre [])) (Bifurcacion [2] (Cofre [3]) (Nada (Cofre [4, 5])) ) )

-- 1)
-- a.Recolecta los objetos del mapa
objects :: Mapa a -> [a]
objects (Cofre a) = a
objects (Nada m) = objects m
objects (Bifurcacion a l r) = a ++ (objects l) ++ (objects r)

-- b.Dada una función, transforma los objetos del mapa
mapM2 :: (a -> b) -> Mapa a -> Mapa b
mapM2 f (Cofre a) = Cofre (map2 f a)
mapM2 f (Nada m) = Nada (mapM2 f m)
mapM2 f (Bifurcacion a l r) = Bifurcacion (map2 f a) (mapM2 f l) (mapM2 f r)

map2 :: (a -> b) -> [a] -> [b]
map2 f [] = []
map2 f (x:xs) = f x : (map f xs)

-- c.Indica si un objeto al final de un camino cumple con cierta condición. 
-- Precondición: el camino existe en el mapa
hasObjectAt :: (a -> Bool) -> Mapa a -> [Dir] -> Bool
hasObjectAt f m [] = hasObject f m
hasObjectAt f m (x:xs) = hasObjectAt f (goToWay x m) xs

hasObject :: (a -> Bool) -> Mapa a -> Bool
hasObject f (Cofre a) = all2 f a
hasObject f (Bifurcacion a l r) = all2 f a

goToWay :: Dir -> Mapa a -> Mapa a
goToWay Left2 (Bifurcacion _ l _) = l
goToWay Straight2 (Nada m) = m
goToWay Right2 (Bifurcacion _ _ r) = r

all2 :: (a -> Bool) -> [a] -> Bool
all2 f [] = True
all2 f (x:xs) = f x && all2 f xs

-- d.Devuelve el camino más largo del mapa.
longestPath :: Mapa a -> [Dir]
longestPath	(Cofre a) = []
longestPath	(Nada m) = Straight2 : longestPath m
longestPath	(Bifurcacion a l r) = if (heightMap l >= heightMap r) 
	then Left2 : (longestPath l) 
	else Right2 : (longestPath r)

heightMap :: Mapa a -> Int
heightMap (Cofre _) = 0
heightMap (Nada m) = 1 + (heightMap m)
heightMap (Bifurcacion _ l r) = 1 + (heightMap l) + (heightMap r)

-- e.Devuelve todos los objetos del camino más largo del mapa.
objectsOfLongestPath :: Mapa a -> [a]
objectsOfLongestPath (Cofre a) = a
objectsOfLongestPath (Nada m) = objectsOfLongestPath m
objectsOfLongestPath (Bifurcacion a l r) = if (heightMap l >= heightMap r) 
	then a ++ (objectsOfLongestPath l) 
	else a ++ (objectsOfLongestPath r)

-- f.Devuelve todos los caminos posibles en el mapa.
allPaths :: Mapa a -> [[Dir]]
allPaths (Cofre a) = [] 
allPaths (Nada m) = addToAll Straight2 (allPaths m)
allPaths (Bifurcacion a l r) = (addToAll Left2 (allPaths l)) ++ (addToAll Right2 (allPaths r)) 

addToAll :: Dir -> [[Dir]] -> [[Dir]]
addToAll d [] = [[d]]
addToAll d (ds:dss) = (d:ds) : (addToAll d dss)

-- 2)
foldM :: ([a] -> b) -> (b -> b) -> ([a] -> b -> b -> b) -> Mapa a -> b
foldM fc fn fb (Cofre a) = fc a
foldM fc fn fb (Nada m) = fn (foldM fc fn fb m)
foldM fc fn fb (Bifurcacion a l r) = fb a (foldM fc fn fb l) (foldM fc fn fb r)

foldR :: (a -> b -> b) -> b -> [a] -> b
foldR f cb [] = cb
foldR f cb (x:xs) = f x (foldR f cb xs)

-- 3)
-- a.Recolecta los objetos del mapa
objectsFold :: Mapa a -> [a]
objectsFold map = foldM (\a -> a) (\r -> r) (\a l r -> a ++ l ++ r) map

-- b.Dada una función, transforma los objetos del mapa
mapMFold :: (a -> b) -> Mapa a -> Mapa b
mapMFold f map = foldM (\a -> Cofre (map2 f a)) (\r -> r) (\a l r -> Bifurcacion (map2 f a) l r) map

-- c.Indica si un objeto al final de un camino cumple con cierta condición. 
-- Precondición: el camino existe en el mapa
hasObjectAtFold :: (a -> Bool) -> Mapa a -> [Dir] -> Bool
hasObjectAtFold f map xs = foldM (\a -> allFold f a) (\r -> r) (\a l r ->  if(isEmptyL xs) 
	then allFold f a
	else hasObject f (goToWay (headL xs) map)) map

allFold :: (a -> Bool) -> [a] -> Bool
allFold f xs = foldR (\x r -> f x && r) True xs

isEmptyL :: [a] -> Bool
isEmptyL [] = True
isEmptyL _ = False

headL :: [a] -> a
headL (x:xs) = x

-- d.Devuelve el camino más largo del mapa.
longestPathFold :: Mapa a -> [Dir]
longestPathFold	map = foldM (\a -> []) (\r -> Straight2 : r) (\_ l r -> if (lenFold l >= lenFold r) 
	then Left2 : l 
	else Right2 : r) map

lenFold :: [a] -> Int
lenFold xs = foldR (\_ r -> 1 + r) 0 xs

-- e.Devuelve todos los objetos del camino más largo del mapa.
objectsOfLongestPathFold :: Mapa a -> [a]
objectsOfLongestPathFold map = foldM (\a -> a) (\r -> r) (\a l r -> if (lenFold l >= lenFold r) 
	then a ++ l 
	else a ++ r) map

-- f.Devuelve todos los caminos posibles en el mapa.
allPathsFold :: Mapa a -> [[Dir]]
allPathsFold map = foldM (\_ -> []) (\r -> addToAllFold Straight2 r) (\a l r -> (addToAllFold Left2 l) ++ (addToAllFold Right2 r)) map

addToAllFold :: Dir -> [[Dir]] -> [[Dir]]
addToAllFold d dss = foldR (\ds r -> (d:ds) : r) [[d]] dss

-- 4) Defino la funcion de la demo, solo para verla aca...
countObjects :: Mapa a -> Int
countObjects (Cofre a) = lenL a
countObjects (Nada m) = countObjects m
countObjects (Bifurcacion a l r) = lenL a + countObjects l + countObjects r

lenL :: [a] -> Int
lenL [] = 0
lenL (x:xs) = 1 + lenL xs

objects :: Mapa a -> [a]
objects (Cofre a) = a
objects (Nada m) = objects m
objects (Bifurcacion a l r) = a ++ (objects l) ++ (objects r)