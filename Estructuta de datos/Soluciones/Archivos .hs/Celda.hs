module Celda (Color(..),Celda,  celdaVacia, poner, sacar , nroBolitas, hayBolitas) where

import MapSR --Se utiliza el map visto en clases con pares
			 --clave-valor, sin claves repetidas.

data Color = Azul | Negro | Rojo | Verde deriving(Show)

data Celda = MkCelda (Map Color Int) deriving(Show,Eq)

{-
	INVARIANTE DE REPRESENTACION:
		*Existe una clave para cada color.
		*El valor asociado a un color es un numero positivo, 
		  es decir, cantidadDeBolitasa>0.
-}

instance Eq Color where
  Azul  == Azul  = True
  Negro == Negro = True
  Rojo  == Rojo  = True
  Verde == Verde = True
  _     == _     = False

--Prop.: Crea una celda con cero bolitas de cada color.
--Prec.: No tiene.
celdaVacia :: Celda --O(1)
celdaVacia = MkCelda emptyM

--Prop.: Agrega una bolita de ese color a la celda.
--Prec.: No tiene.
poner :: Color -> Celda -> Celda --O(n)
poner col (MkCelda map) = MkCelda (agregarARepresentacion map col)

--Prop.: Agrega una bolita del color dado por parámetro al map.
--Prec.: No tiene.
agregarARepresentacion :: Map Color Int -> Color -> Map Color Int --O(n)
agregarARepresentacion map col = case(lookUpM map col) of
								 Nothing -> assocM map col 1
								 Just n  -> assocM map col (n+1)

--Prop.: Saca una bolita del color dado.
--Prec.: Debe haber almenos una bolita del color que se desea sacar.
sacar :: Color -> Celda -> Celda --O(n)
sacar col (MkCelda map) = MkCelda (quitarEnRepresentacion map col)

--Prop.: Saca una bolita del color dado.
--Prec.: Debe haber almenos una bolita del color que se desea sacar.
quitarEnRepresentacion :: Map Color Int -> Color -> Map Color Int --O(n)
quitarEnRepresentacion map col = case(lookUpM map col) of
				Nothing -> error "No hay bolitas del color requerido"
				Just n  -> if n==1
					then deleteM map col
					else assocM map col (n-1)

--Prop.: Devuelve la cantidad de bolitas de ese color.
--Prec.: No hay.
--Nota: No me parecio necesario hacer una subtarea ya que no necesito
-- hacer una recursion ni pattern matching, solo una simple instruccion.
nroBolitas :: Color -> Celda -> Int --O(n)
nroBolitas col (MkCelda map) = case (lookUpM map col) of
									Nothing -> 0
									(Just n) -> n



--Prop.: Indica si hay bolitas del color.
--Prec.: No hay.
--Nota: No me parecio necesario hacer una subtarea ya que no necesito
-- hacer una recursion ni pattern matching, solo una simple instruccion.
hayBolitas :: Color -> Celda -> Bool --O(n)
hayBolitas col (MkCelda map) = case (lookUpM map col) of
									Nothing -> False
									(Just n) -> True