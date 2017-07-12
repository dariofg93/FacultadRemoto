module ListaNV(ListaNV
	, agregar
	, iniciar
	, borrar
	, puedeBorrar
	, primero
	, longLNV) where

-- Tipo de Representación

data ListaNV a = ConsLNV [a] Int

{- Inv.Rep. 
   + La  no puede ser vacia
   + Int es la longitud de la lista
-}

iniciar :: a -> ListaNV a
iniciar x = ConsLNV [x] 1

agregar :: a -> ListaNV a -> ListaNV a
agregar x (ConsLNV xs n) = 
	ConsLNV (x:xs) (n+1)

borrar :: ListaNV a -> ListaNV a
borrar (ConsLNV xs n) = 
	if null xs
	   then error "no hay elementos"
	   else ConsLNV (tail xs) (n-1)

puedeBorrar :: ListaNV a -> Bool
puedeBorrar (ConsLNV _ 1) = False
puedeBorrar _             = True

primero :: ListaNV a -> a
primero (ConsLNV xs _) = head xs

longLNV :: ListaNV a -> Int
longLNV (ConsLNV _ n) = n 
