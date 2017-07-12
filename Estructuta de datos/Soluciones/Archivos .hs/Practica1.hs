module Practica1 where

exampleList :: [Int]
exampleList = [1,2,3,4,5,10]

sumatoria :: [Int] -> Int
sumatoria [] 	 = 0
sumatoria (n:ns) = n + sumatoria ns

longitud :: [a] -> Int
longitud [] 	= 0
longitud (_:xs) = 1 + longitud xs

promedio :: [Int] -> Int
promedio xs = sumatoria xs `div` longitud xs

mapSucesor :: [Int] -> [Int]
mapSucesor [] 	  = []
mapSucesor (x:xs) = x+1 : mapSucesor xs

mapSumaPar :: [(Int,Int)] -> [Int]
mapSumaPar []  		= []
mapSumaPar (x:xs) 	= (fst x +snd x) : mapSumaPar xs

mapMaxDelPar :: [(Int,Int)] -> [Int]
mapMaxDelPar [] 	= []
mapMaxDelPar (x:xs) = max (fst x) (snd x) : mapMaxDelPar xs

todoVerdad :: [Bool] -> Bool
todoVerdad [] 		= True
todoVerdad (x:xs)	= x && todoVerdad xs

algunaVerdad :: [Bool] -> Bool
algunaVerdad [] 	= False
algunaVerdad (x:xs) = x || algunaVerdad xs

pertenece :: Eq a => a -> [a] -> Bool
pertenece p [] 	 = False
pertenece p (x:xs) = if x==p
						then True
						else pertenece p xs

apariciones :: Eq a => a -> [a] -> Int
apariciones a [] 	 = 0
apariciones a (x:xs) = if x==a
						then 1 + apariciones a xs
						else apariciones a xs

filtrarMenoresA :: Int -> [Int] -> [Int]
filtrarMenoresA n [] 	 = []
filtrarMenoresA n (x:xs) = if x < n
						then filtrarMenoresA n xs
						else x : filtrarMenoresA n xs

filtrarElemento :: Eq a => a -> [a] -> [a]
filtrarElemento e [] 	 = []
filtrarElemento e (x:xs) = if x == e
						then filtrarElemento e xs
						else x : filtrarElemento e xs

mapLongitudes :: [[a]] -> [Int]
mapLongitudes [] 		= []
mapLongitudes (x:xs) 	= longitud x : mapLongitudes xs

longitudMayorA :: Int -> [[a]] -> [[a]]
longitudMayorA n [] 	= []
longitudMayorA n (x:xs) = if longitud x > n
							then x : longitudMayorA n xs
							else longitudMayorA n xs

intercalar :: a -> [a] -> [a]
intercalar e [] 	= []
intercalar e [x]	= [x]
intercalar e (x:xs) = x:e : intercalar e xs

snoc :: [a] -> a -> [a]
snoc [] e 		= [e]
snoc (x:xs) e 	= x : snoc xs e

append :: [a] -> [a] -> [a]
append xs [] 	 = xs
append [] ys 	 = ys
append xs (y:ys) = append (snoc xs y) ys

aplanar :: [[a]] -> [a]
aplanar [] 		= []
aplanar (x:xs)  = x ++ aplanar xs

reversa :: [a] -> [a]
reversa [] 		= []
reversa (x:xs)	= snoc (reversa xs) x

zipMaximos :: [Int] -> [Int] -> [Int]
zipMaximos [] ys 		 = ys
zipMaximos xs [] 		 = xs
zipMaximos (x:xs) (y:ys) = if x>=y
			then x : zipMaximos xs ys
			else y : zipMaximos xs ys

zipSort :: [Int] -> [Int] -> [(Int, Int)]
--Prec.: Las lista tienen la misma longitud
zipSort [] [] = []
zipSort (x:xs) (y:ys) = if x>=y
			then (y,x) : zipSort xs ys
			else (x,y) : zipSort xs ys

factorial :: Int -> Int
factorial 0 = 1
factorial n = n * factorial (n-1)

cuentaRegresiva :: Int -> [Int]
--Prec.: Si el numero es inferior a 1, devuelve la lista vacia.
cuentaRegresiva 0 = []
cuentaRegresiva n = n : cuentaRegresiva (n-1)

contarHasta :: Int -> [Int]
contarHasta 0 = []
contarHasta n = desdeHasta 1 n

replicarN :: Int -> a -> [a]
replicarN 0 _  = []
replicarN n e = e : replicarN (n-1) e

desdeHasta :: Int -> Int -> [Int]
desdeHasta n m = if n /= m
			then n : desdeHasta (n+1) m
			else [m]

takeN :: Int -> [a] -> [a]
takeN 0 xs 	   = []
takeN _ [] 	   = []
takeN n (x:xs) = x : takeN (n-1) xs

dropN :: Int -> [a] -> [a]
dropN 0 xs 	   = xs
dropN _ [] 	   = []
dropN n (x:xs) = dropN (n-1) xs

splitN :: Int -> [a] -> ([a], [a])
splitN n xs = (takeN n xs,dropN n xs)

particionPorSigno :: [Int] -> ([Int], [Int])
particionPorSigno [] 	 = ([],[])
particionPorSigno (x:xs) = if  x>0
				then addToPositives x (particionPorSigno xs)
				else addToNegatives x (particionPorSigno xs)

addToPositives :: Int -> ([Int],[Int]) -> ([Int],[Int])
addToPositives p (neg,pos) = (neg,p:pos)

addToNegatives :: Int -> ([Int],[Int]) -> ([Int],[Int])
addToNegatives n (neg,pos) = (n:neg,pos)

particionPorParidad :: [Int] -> ([Int], [Int])
particionPorParidad [] 	 = ([],[])
particionPorParidad (x:xs) = ubicarPorParidad x (particionPorParidad xs)

ubicarPorParidad :: Int -> ([Int],[Int]) -> ([Int],[Int])
ubicarPorParidad n (ps,is) = if  n `mod` 2 == 0
						then (n:ps,is)
						else (ps,n:is)

subtails :: [a] -> [[a]]
subtails []   = []
subtails (x:xs) = addToListOfList (x:xs) (subtails xs)

addToListOfList :: [a] -> [[a]] -> [[a]]
addToListOfList list lolist = (list:lolist)