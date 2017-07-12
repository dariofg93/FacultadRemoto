module ListaNVT(ListaNV
	, agregar
	, iniciar
	, borrar
	, puedeBorrar
	, primero
	, longLNV) where

-- Tipo de Representación

data Tree a = 
	EmptyT 
  | NodeT a (Tree a) (Tree a)

data ListaNV a = 
	ConsLNV (Tree a) Int

{- Inv.Rep. 
   + La no puede ser vacia
   + Solo la rama derecha tiene elems
   + La raiz tiene el primer elem
   + Int es la longitud de la lista
-}

iniciar :: a -> ListaNV a
iniciar x = ConsLNV 
	(NodeT x EmptyT EmptyT) 1

agregar :: a -> ListaNV a -> ListaNV a
agregar x (ConsLNV t n) = 
	ConsLNV (NodeT x EmptyT t) (n+1)

borrar :: ListaNV a -> ListaNV a
borrar (ConsLNV t n) = 
	if n == 1
	   then error "no hay elementos"
	   else ConsLNV (sacarRaiz t) (n-1)

sacarRaiz :: Tree a -> Tree a
sacarRaiz (NodeT _ _ t2) = t2

puedeBorrar :: ListaNV a -> Bool
puedeBorrar (ConsLNV _ 1) = False
puedeBorrar _             = True

primero :: ListaNV a -> a
primero (ConsLNV t _) = raiz t

raiz :: Tree a -> a 
raiz (NodeT x _ _) = x

longLNV :: ListaNV a -> Int
longLNV (ConsLNV _ n) = n 
