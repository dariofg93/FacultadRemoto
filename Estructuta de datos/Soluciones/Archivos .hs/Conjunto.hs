module Conjunto(Conjunto,vacioC,agregarC,perteneceC,cantidadC,borrarC,unionC,listaC,maximoC,c1,c2,c3) where

data Conjunto a = ConsC [a] Cant (Maybe a) deriving(Show,Ord,Eq)
type Cant = Int

{-
	INVARIANTE DE REPRESENTACION: (Cons xs Cant max)
	*La lista xs no tiene elementos repetidos.
	*Se guarda la cantidad de elementos en Cant
	*max es un maybe que contiene el maximo de la lista
		
-}

c1 :: Conjunto Int
c1 = agregarC 10 ((agregarC 6 (agregarC 5 (vacioC))))

c2 :: Conjunto Int
c2 = agregarC 10 (agregarC 20 ((agregarC 30 (agregarC 40 (vacioC)))))


c3 :: Conjunto Int
c3 = agregarC 15 (agregarC 25 ((agregarC 35 (agregarC 40 (agregarC 45 (vacioC))))))

vacioC :: Conjunto a
vacioC = ConsC [] 0 Nothing

agregarC :: Ord a => a -> Conjunto a -> Conjunto a
agregarC x (ConsC xs n m) = if elem x xs
								then ConsC xs n m
								else ConsC (x:xs) (n+1) (agregarEnMax x m)

agregarEnMax :: Ord a => a -> Maybe a -> Maybe a
agregarEnMax x Nothing = Just x
agregarEnMax x (Just y) = if x>y
							then Just x
							else Just y

perteneceC :: Eq a => a -> Conjunto a -> Bool
perteneceC x (ConsC xs n m) = elem x xs

cantidadC :: Conjunto a -> Int
cantidadC (ConsC _ n m) = n

--Prec.: El conjunto tiene al menos un elemento
borrarC :: Ord a => a -> Conjunto a -> Conjunto a
borrarC x (ConsC xs n m) = if not (elem x xs)
							then ConsC xs n m
							else ConsC (borrarDeLista x xs) 
									   (restarSiCorresponde n x xs) 
									   (cambiarMaybe x m)

borrarDeLista :: Eq a => a -> [a] -> [a]
borrarDeLista x [] = []
borrarDeLista x (y:ys) = if x == y
							then ys
							else y : borrarDeLista x ys

restarSiCorresponde :: Eq a => Int -> a -> [a] -> Int
restarSiCorresponde n x xs = if elem x xs
						then n-1
						else n

cambiarMaybe :: Ord a => a -> Maybe a -> Maybe a
cambiarMaybe x (Just y) = Just (max x y)

unionC :: Ord a => Conjunto a -> Conjunto a -> Conjunto a
unionC (ConsC xs n1 m1) (ConsC ys n2 m2) = 
						let(list)=(unirListas xs ys)
						in (ConsC list
							(length list)
							(Just(maximum list)))

unirListas :: Eq a => [a] -> [a] -> [a]
unirListas xs [] = xs
unirListas [] ys = ys
unirListas (x:xs) ys = if elem x ys
						then unirListas xs ys
						else x : unirListas xs ys

listaC :: Conjunto a -> [a]
listaC (ConsC xs _ _) = xs

maximoC :: Conjunto a -> a
maximoC (ConsC xs cant max) = valorMaybe max

valorMaybe :: Maybe a -> a
valorMaybe (Just x) = x