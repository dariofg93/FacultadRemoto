module Heap where

import practica3
-- data Tree a = EmptyT | Node a (Tree a) (Tree a)

Dir = Izq | Der

type dirs = [Dir]
data Heap = H (Tree a) dirs

{-
	INVARIANTES DE REPRESENTACION:
		- El arbol guarda su menor elemento en la raiz
		- Los hijos (izq der) de t son heaps
		- la lista de direcciones guarda el reccorido hacia
			 el siguiente lugar a insertar, y esta al revez
-}

emptyH :: Heap
emptyH = H EmptyT []

isEmptyH :: Heap a -> Bool
isEmptyH (H _ dirs) = null dirs

insertH :: Ord a => a -> Heap a -> Heap a
insertH  x (H t dirs) = H (agregarEnRepT x t (reverse dirs)) (nextPos dirs)

nextPos :: [Dir] -> [Dir]
nextPos [] = [Izq]
nextPos (d:ds) = case (d) of
					Izq -> Der : ds
					Der -> Izq : (nextPos ds)

agregarEnRepT ::  Ord a -> a -> Tree a -> [Dir] -> Tree a
agregarEnRepT EmptyT [] = Node x EmptyT EmptyT
agregarEnRept x (Node m t1 t2) (:ds) = case(d) of
										Izq -> orderIzq m (agregarEnRepT x t1 ds)
										Der -> orderDer m (agregarEnRepT x t1 ds)

orderIzq :: Ord a => a -> Tree a -> Tree a -> Tree a
orderIzq m  t1@(NodeT m2 t11 t12) t2 = if m < m2
								then NodeT m t1 t2
								else NodeT m2 (NodeT m t11 t12) t2

orderDer :: Ord a => a -> Tree a -> Tree a -> Tree a
orderDer m2 t1 t2@(NodeT m t21 t22) = if m < m2
								then NodeT m t1 t2
								else NodeT m2 t1 (NodeT m t21 t22)


