import Prelude hiding (replicate, const, repeat, take, product, last, map, filter, all, any)

id x = x
const x y = x

tres :: a -> [a]
tres x = [x,x,x]

replicate :: Int -> a -> [a]
replicate 0 x = []
replicate n x =
  x : replicate (n-1) x

repeat :: a -> [a]
repeat x = x : repeat x

take :: Int -> [a] -> [a]
take 0 xs = []
take n [] = []
take n (x:xs) =
  x : take (n-1) xs

nats :: [Int]
nats = sucesores 0

sucesores :: Int -> [Int]
sucesores x = x : sucesores (x+1)

product :: [Int] -> Int
product [] = 1
product (x:xs) =
 x * product xs

factorial :: Int -> Int
factorial x = product (take x (sucesores 1))

pares :: [Int]
pares = porDos nats

porDos :: [Int] -> [Int]
porDos xs =
  map (\x -> x * 2) xs

-- version anterior
-- porDos [] = []
-- porDos (x:xs) = x * 2 : porDos xs

impares :: [Int]
impares = masUno pares

masUno :: [Int] -> [Int]
masUno xs = map (\x -> x + 1) xs

-- version anterior
-- masUno [] = []
-- masUno (x:xs) = x + 1 : masUno xs

-- generalizacion
map :: (a -> b) -> [a] -> [b]
map f [] = []
map f (x:xs) = f x : map f xs

-- a los impares le saco el 1
primos :: [Int]
primos = 2 : soloPrimos (tail impares)

soloPrimos :: [Int] -> [Int]
soloPrimos xs =
   filter (\x -> esPrimo x) xs

-- version anterior
-- soloPrimos [] = []
-- soloPrimos (x:xs) = 
--   if esPrimo x
--       then x : soloPrimos xs
--       else soloPrimos xs
   
filter :: (a -> Bool) -> [a] -> [a]
filter f [] = []
filter f (x:xs) = 
   if f x
      then x : filter f xs
      else filter f xs

esPrimo :: Int -> Bool
esPrimo x = 
 all
  (\n -> not (divide n x))
  [2..(x-1)]

all :: (a -> Bool) -> [a] -> Bool
all f [] = True
all f (x:xs) = 
  f x && all f xs

any :: (a -> Bool) -> [a] -> Bool
any f [] = False
any f (x:xs) = 
  f x || any f xs

divide :: Int -> Int -> Bool
divide n x = x `mod` n == 0

-- son equivalentes
-- sucesor x = x + 1
-- sucesor = (\x -> x + 1)

-- no termina para listas infinitas
last (x:[]) = x
last (x:xs) = last xs

-- solo para que les compile de cualquier forma en la
-- que corran este archivo
main = return ()

-- Ejercicios

-- -- Primera componente del par
-- fst :: (a,b) -> a

-- -- Longitud de la lista
-- length :: [a] -> Int

-- -- Indican si todo es True o todo es False respectivamente
-- and, or :: [Bool] -> Bool

-- -- Cuántos elementos son iguales al dado
-- count :: Eq a => a -> [a] -> Int

-- -- Agrega al final
-- snoc :: [a] -> a -> [a]

-- -- Da vuelta la lista
-- reverse :: [a] -> [a]

-- -- Indica si los elementos de la primera lista
-- -- estan incluidos en la segunda
-- subset :: Eq a => [a] -> [a] -> Bool

-- -- Concatena ambas listas
-- (++) :: [a] -> [a] -> [a]

-- -- Arma pares en base a dos listas, juntando
-- -- los elementos en una misma posicion
-- zip :: [a] -> [b] -> [(a,b)]

-- -- Hace que los elementos de una lista se repitan una
-- -- y otra vez
-- cycle :: [a] -> [a]
-- -- Ejemplo: cycle [1,2,3] == [1,2,3,1,2,3,...]

-- -- Devuelve toda la sucesión de fibonacci
-- fibs :: [Int]