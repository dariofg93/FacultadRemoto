module Practica4 where

import Practica2
import Practica3
import Conjunto
import Queue
import Stack

setTree :: Tree (Conjunto Int)
setTree = Node c1 (Node c2 (Node c1 EmptyT EmptyT) 
						   EmptyT)
			   	  (Node c3 EmptyT EmptyT)

setTree2 :: Tree (Conjunto Int)
setTree2 = Node c1 (Node c2 (Node c1 EmptyT EmptyT) 
						   EmptyT)
					EmptyT
			   	 		  
losQuePertenecen :: [Int] -> Conjunto Int -> [Int]
losQuePertenecen [] _ = []
losQuePertenecen (x:xs) c1 = if perteneceC x c1
						then x : losQuePertenecen xs c1
						else losQuePertenecen xs c1

sinRepetidos :: [Int] -> [Int]
sinRepetidos xs = listaC (listToSet xs)

listToSet :: [Int] -> Conjunto Int
listToSet [] = vacioC
listToSet (x:xs) = if perteneceC x (listToSet xs)
					then listToSet xs
					else agregarC x (listToSet xs)

unirTodos :: Tree (Conjunto Int) -> Conjunto Int
unirTodos EmptyT = vacioC
unirTodos (Node c l r) = unionC c (unionC (unirTodos l) (unirTodos r))

interseccionArbol :: Tree Int -> Tree Int -> Conjunto Int
interseccionArbol t1 t2 = listToSet (intersectLists (listInOrder t1) (listInOrder t2))

intersectLists :: [Int] -> [Int] -> [Int]
intersectLists [] ys = []
intersectLists (x:xs) ys = if elem x ys
						then x : intersectLists xs ys
						else intersectLists xs ys

qPersonas :: Queue Persona
qPersonas = queue lola (queue fer (queue dario (emptyQ)))

largoQ :: Queue a -> Int
largoQ q1 = if not (isEmptyQ q1)
				then 1 + largoQ (dequeue q1)
				else 0

atender :: Queue Persona -> [Persona]
atender colaP = if not (isEmptyQ colaP)
					then firstQ colaP : atender (dequeue colaP)
					else []

unirQ :: Queue a -> Queue a -> Queue a
unirQ q1 q2 = if not (isEmptyQ q2)
				then unirQ (queue (firstQ q2) q1) (dequeue q2)
				else q1

apilar :: Ord a => [a] -> Stack a
apilar [] = emptyS
apilar (x:xs) = push x (apilar xs)

balanceado :: String -> Bool
balanceado cuenta = cantApilada (apilarChar '(' cuenta) == cantApilada (apilarChar ')' cuenta)

cantApilada :: Ord a => Stack a -> Int
cantApilada st = if isEmptyS st
					then 0
					else 1 + cantApilada (pop st)

apilarChar :: Char -> String -> Stack Char
apilarChar _ [] = emptyS
apilarChar char (c:cs) = if c==char
					then push c (apilarChar char cs)
					else apilarChar char cs

