module UserOfCeldaTAD where

import Celda

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