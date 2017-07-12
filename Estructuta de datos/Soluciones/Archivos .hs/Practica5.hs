module Practica5 where

import Celda

initM :: [a] -> Maybe [a]
initM [] = Nothing
initM (x:[]) = Just []
initM (x:xs) = unirMaybeList x (initM xs)

unirMaybeList :: a -> Maybe [a] -> Maybe [a]
unirMaybeList x Nothing = Just [x]
unirMaybeList x (Just xs) = Just (x:xs)

lastM :: [a] -> Maybe a
lastM [] = Nothing
lastM (x:[]) = Just x
lastM (x:xs) = Just (fromJust (lastM xs))

fromJust :: Maybe a -> a
fromJust Nothing = error "No hay nada que devolver"
fromJust (Just x) = x

maximumM :: Ord a => [a] -> Maybe a
maximumM [] = Nothing
maximumM (x:xs) = Just (maxMaybeList x (maximumM xs))

maxMaybeList :: Ord a => a -> Maybe a -> a
maxMaybeList x Nothing = x
maxMaybeList x (Just y) = max x y

--Prop.: Devuelve True si hay mas de "n"bolitas de ese color.
--Prec.: No hay.
nroBolitasMayorA :: Color -> Int -> Celda -> Bool --O(n)
nroBolitasMayorA col n celda = nroBolitas col celda > n

--Prop.: Agrega "n"bolitas de ese color a la celda.
--Prec.: No hay.
--	Hago recursion sobre el indice de la cantidad de 
--	bolitas que agrega PonerN
--	ponerN 0 _ celda = ...
--	ponerN n col celda = ... ponerN (n-1) celda 
ponerN :: Int -> Color -> Celda -> Celda --O(n)
ponerN 0 _ celda = celda
ponerN n col celda = poner col (ponerN (n-1) col celda)

--Prec.: Indica si existe al menos una bolita de cada color posible.
--Prop.: No hay.
hayBolitasDeCadaColor :: Celda -> Bool
hayBolitasDeCadaColor celda = hayBolitas Azul celda &&
							  hayBolitas Negro celda &&
							  hayBolitas Rojo celda &&
							  hayBolitas Verde celda 