module Practica3 where

import Practica2

data Tree a = EmptyT | Node a (Tree a) (Tree a) deriving(Show)

intTree :: Tree Int
intTree = Node 5 (Node 8 (Node 6 EmptyT EmptyT)
					   	 (Node 1 EmptyT (Node 5 (Node 10 EmptyT EmptyT)
					   						  	(Node 15 EmptyT EmptyT))))
			   	 (Node 50 (Node 0 EmptyT EmptyT)
			   	 		  (Node 100 EmptyT EmptyT))
intsTree :: Tree [Int]
intsTree = Node [1,2,3] (Node [4,5,6] (Node [7,8,9] EmptyT EmptyT)
									  (Node [10] EmptyT 
									  			 (Node [11,12,13] EmptyT EmptyT)))
			  		 	(Node [14,15] EmptyT EmptyT)
dirTree :: Tree Dir
dirTree = Node Norte (Node Sur (Node Oeste EmptyT EmptyT)
					  		   (Node Norte EmptyT (Node Sur EmptyT EmptyT)))
			  		 (Node Norte EmptyT EmptyT)
stringTree :: Tree String
stringTree = Node "Hola" (Node "Soy" (Node "Un" EmptyT EmptyT)
					  		  		 (Node "Arbol" EmptyT (Node "De" EmptyT EmptyT)))
			  			 (Node "Strings" EmptyT EmptyT)
peopleTree :: Tree Persona
peopleTree = Node dario (Node lola (Node fer EmptyT EmptyT)
					  		  		 (Node lola EmptyT (Node fer EmptyT EmptyT)))
			  			 (Node dario EmptyT EmptyT)


sumarT :: Tree Int -> Int
sumarT EmptyT = 0
sumarT (Node n l r) = n + sumarT l + sumarT r

sizeT :: Tree a -> Int
sizeT EmptyT = 0
sizeT (Node _ l r) = 1 + sizeT l + sizeT r

mapDobleT :: Tree Int -> Tree Int
mapDobleT EmptyT = EmptyT
mapDobleT (Node n l r) = Node (n*2) (mapDobleT l) (mapDobleT r)

mapOpuestoT :: Tree Dir -> Tree Dir
mapOpuestoT EmptyT = EmptyT
mapOpuestoT (Node d l r) = Node (opuesto d) (mapOpuestoT l) (mapOpuestoT r)

mapLongitudT :: Tree String -> Tree Int
mapLongitudT EmptyT = EmptyT
mapLongitudT (Node s l r) = Node (length s) (mapLongitudT l) (mapLongitudT r)

perteneceT :: Eq a => a -> Tree a -> Bool
perteneceT _ EmptyT = False
perteneceT e (Node x l r) = e==x || perteneceT e l || perteneceT e r

aparicionesT :: Eq a => a -> Tree a -> Int
aparicionesT _ EmptyT = 0
aparicionesT e (Node x l r) = if e==x
					then 1 + aparicionesT e l + aparicionesT e r
					else aparicionesT e l + aparicionesT e r

promedioEdadesT :: Tree Persona -> Int
promedioEdadesT EmptyT = 0
promedioEdadesT peopleT = sumarEdadesT peopleT `div` sizeT peopleT

sumarEdadesT :: Tree Persona -> Int
sumarEdadesT EmptyT = 0
sumarEdadesT (Node p l r) = edad p + sumarEdadesT l + sumarEdadesT r

engancharYSumaEnRaiz :: Tree Int -> Tree Int -> Tree Int
engancharYSumaEnRaiz t1 t2 = Node (sumarT t1 + sumarT t2) t1 t2

leaves :: Tree a -> Int
leaves EmptyT = 0
leaves (Node _ EmptyT EmptyT) = 1
leaves (Node _ l r) = leaves l + leaves r

heightT :: Tree a -> Int
heightT EmptyT = 0
heightT (Node _ EmptyT EmptyT) = 1
heightT (Node _ l r) = 1 + max (heightT l) (heightT r)

nodes :: Tree a -> Int
nodes EmptyT = 0
nodes (Node _ EmptyT EmptyT) = 0
nodes (Node _ l r) = 1 + (nodes l) + (nodes r)

espejoT :: Tree a -> Tree a
espejoT EmptyT = EmptyT
espejoT (Node x l r) = Node x (espejoT r) (espejoT l)

listInOrder :: Tree a -> [a]
listInOrder EmptyT = []
listInOrder (Node x l r) = (listInOrder l) ++ (x:listInOrder r)

listPreOrder :: Tree a -> [a]
listPreOrder EmptyT = []
listPreOrder (Node x l r) = (x:listPreOrder l) ++ (listPreOrder r)

listPosOrder :: Tree a -> [a]
listPosOrder EmptyT = []
listPosOrder (Node x l r) = (listPosOrder l) ++ (listPosOrder r) ++ [x]

concatenarListasT :: Tree [a] -> [a]
concatenarListasT EmptyT = []
concatenarListasT (Node x l r) = (concatenarListasT l) ++ x ++ (concatenarListasT r)

levelN :: Int -> Tree a -> [a]
levelN 0 (Node x _ _) = [x]
levelN n EmptyT = []
levelN n (Node x l r) = levelN (n-1) l ++ levelN (n-1) r

listPerLevel :: Tree a -> [[a]]
listPerLevel EmptyT = []
listPerLevel t = reverse (elemDeCadaLvl ((heightT t)-1) t)

elemDeCadaLvl :: Int -> Tree a -> [[a]]
elemDeCadaLvl 0 (Node x _ _) = [[x]]
elemDeCadaLvl n t = (levelN n t) : elemDeCadaLvl (n-1) t

widthT :: Tree a -> Int
widthT EmptyT = 0
widthT t = maximum (lengthOfLists (listPerLevel t))

lengthOfLists :: [[a]] -> [Int]
lengthOfLists [] = []
lengthOfLists (x:xs) = length x : lengthOfLists xs

data Exp = Constante Int | ConsExpUnaria OpUnaria Exp | ConsExpBinaria OpBinaria Exp Exp deriving(Show)

data OpUnaria = Neg deriving(Show)

data OpBinaria = Suma | Resta | Mult | Div deriving(Show)

op11 = Constante 5

op21 = ConsExpUnaria Neg (Constante 10)

op31 = ConsExpBinaria Suma (ConsExpUnaria Neg (Constante 10))
						   (Constante 30)
op32 = ConsExpBinaria Suma (ConsExpUnaria Neg (Constante 10))
						   (Constante 0)
op33 = ConsExpBinaria Suma (ConsExpUnaria Neg (Constante 10))
						   (ConsExpBinaria Suma (ConsExpUnaria Neg (Constante 10))
						  						(Constante 0))

eval :: Exp -> Int
eval (Constante n) = n
eval (ConsExpUnaria opu exp) = - (eval exp)
eval (ConsExpBinaria opb exp1 exp2) = operarSegunCorresponda opb (eval exp1) (eval exp2)

operarSegunCorresponda :: OpBinaria -> Int -> Int -> Int
operarSegunCorresponda Suma n1 n2 = n1 + n2
operarSegunCorresponda Resta n1 n2 = n1 - n2
operarSegunCorresponda Mult n1 n2 = n1 * n2
operarSegunCorresponda Div n1 n2 = n1 `div` n2

simplificar :: Exp -> Exp
simplificar (Constante n) = Constante n
simplificar (ConsExpUnaria opu exp) = ConsExpUnaria Neg (simplificar exp)
simplificar (ConsExpBinaria opb exp1 exp2) = simplificarExpresiones opb (simplificar exp1) (simplificar exp2)

simplificarExpresiones :: OpBinaria -> Exp -> Exp -> Exp
simplificarExpresiones Suma exp1 exp2 = if eval exp1 == 0
							then exp2
							else if eval exp2 == 0
								then exp1
								else ConsExpBinaria Suma exp1 exp2
simplificarExpresiones Resta exp1 exp2 = if eval exp1 == 0
							then exp2
							else if eval exp2 == 0
								then exp1
								else ConsExpBinaria Resta exp1 exp2
simplificarExpresiones Mult exp1 exp2 = if eval exp1 == 1
							then exp2
							else if eval exp2 == 1
								then exp1
								else ConsExpBinaria Mult exp1 exp2
simplificarExpresiones Mult exp1 exp2 = if eval exp1 == 0 || eval exp1 == 0
							then Constante 0
							else ConsExpBinaria Mult exp1 exp2
simplificarExpresiones Div exp1 exp2 = if eval exp2 == 1
							then exp1
							else if eval exp2 == 0
								then error "No se puede dividir por 0"
								else ConsExpBinaria Div exp1 exp2