module Practica2 where

data Dir = Norte | Sur | Este | Oeste deriving(Show)

opuesto :: Dir -> Dir
opuesto Norte = Sur
opuesto Sur   = Norte
opuesto Este  = Oeste
opuesto Oeste = Este

siguiente :: Dir -> Dir
siguiente Norte = Este
siguiente Sur   = Oeste
siguiente Este  = Sur
siguiente Oeste = Norte

data Persona = ConsPer String Int deriving(Show)

dario = ConsPer "Dario" 22
fer = ConsPer "Fernando" 50
lola = ConsPer "Lola" 30

personas :: [Persona]
personas = [dario,fer,lola]

nombre :: Persona -> String
nombre (ConsPer n _) = n

edad :: Persona -> Int
edad (ConsPer _ e) = e

crecer :: Persona -> Persona
crecer (ConsPer n e) = ConsPer n (e+1)

cambioDeNombre :: String -> Persona -> Persona
cambioDeNombre newName (ConsPer _ edad) = ConsPer newName edad

esMenorQueLaOtra :: Persona -> Persona -> Bool
esMenorQueLaOtra p1 p2 = edad p1 < edad p2

mayoresA :: Int -> [Persona] -> [Persona]
mayoresA _ [] 	  = []
mayoresA n (p:ps) = if edad p > n
			then p : mayoresA n ps
			else mayoresA n ps

promedioEdad :: [Persona] -> Int
--Prec.: La lista al menos posee una persona.
promedioEdad personas = sumarEdades personas `div` length personas

sumarEdades :: [Persona] -> Int
sumarEdades [] 	  = 0
sumarEdades (p:ps) = edad p + sumarEdades ps

elMasViejo :: [Persona] -> Persona
--Prec.: La lista al menos posee una persona.
elMasViejo (p:ps) = elMasViejoDeDos p ps

elMasViejoDeDos :: Persona -> [Persona] -> Persona
elMasViejoDeDos p [] = p
elMasViejoDeDos p (x:xs) = if edad p > edad x
				then elMasViejoDeDos p xs
				else elMasViejoDeDos x xs

data TipoDePokemon = Agua | Fuego | Planta deriving(Show)

type PorcentajeVida = Int
data Pokemon = ConsPkmn TipoDePokemon PorcentajeVida deriving(Show)

type Nombre = String
type Pokemones = [Pokemon]
data Entrenador = ConsEntr Nombre Pokemones deriving(Show)

pkmn1 = ConsPkmn Fuego 100
pkmn2 = ConsPkmn Planta 50
pkmn3 = ConsPkmn Agua 25
pkmn4 = ConsPkmn Fuego 0

ash = ConsEntr "Ash Ketchup" [pkmn1,pkmn2,pkmn3,pkmn1]
brook = ConsEntr "Brook" [pkmn2,pkmn4,pkmn3]

elementoGanador :: TipoDePokemon -> TipoDePokemon
elementoGanador Agua = Planta
elementoGanador Fuego = Agua
elementoGanador Planta = Fuego

leGanaA :: Pokemon -> Pokemon -> Bool
--Dados dos pokemon indica si el primero le puede ganar al segundo.
--Se considera que gana si su elemento es opuesto al del otro pokemon.
--Si poseen el mismo elemento se considera que no gana.
leGanaA p1 p2 = esMismoTipo (elementoGanador (tipo p2)) (tipo p1)

esMismoTipo :: TipoDePokemon -> TipoDePokemon -> Bool
esMismoTipo Agua Agua 	  = True
esMismoTipo Fuego Fuego   = True
esMismoTipo Planta Planta = True
esMismoTipo _ _ 		  = False

tipo :: Pokemon -> TipoDePokemon
tipo (ConsPkmn tipo _) = tipo

energia :: Pokemon -> Int
energia (ConsPkmn _ e) = e

tiposDePkmns :: [TipoDePokemon]
tiposDePkmns = [Agua,Fuego,Planta]

capturarPokemon :: Pokemon -> Entrenador -> Entrenador
capturarPokemon pkmn (ConsEntr n pkmns) = ConsEntr n (pkmn:pkmns)

cantidadDePokemons :: Entrenador -> Int
cantidadDePokemons (ConsEntr n pkmns) = length pkmns

cantidadDePokemonsDeTipo :: TipoDePokemon -> Entrenador -> Int
cantidadDePokemonsDeTipo tipo (ConsEntr n pkmns)= contarLosDeTipo tipo pkmns

contarLosDeTipo :: TipoDePokemon -> [Pokemon] -> Int
contarLosDeTipo t [] 	 = 0
contarLosDeTipo t (p:ps) = if esMismoTipo (tipo p) t
						then 1 + contarLosDeTipo t ps
						else contarLosDeTipo t ps

pokemones :: Entrenador -> [Pokemon]
pokemones (ConsEntr _ pkmns) = pkmns

lePuedeGanar :: Entrenador -> Pokemon -> Bool
lePuedeGanar entrenador pkmn = algunoLeGana (pokemones entrenador) pkmn

algunoLeGana :: [Pokemon] -> Pokemon -> Bool
algunoLeGana [] _ = False
algunoLeGana (p:ps) pkmn = leGanaA p pkmn || algunoLeGana ps pkmn

puedenPelear :: TipoDePokemon -> Entrenador -> Entrenador -> Bool
--Dados un tipo de pokemon y dos entrenadores, devuelve True si ambos
--entrenadores tiene al menos un pokemon de ese tipo y que tenga energía para pelear.
puedenPelear t e1 e2 = hayTipoYPuedePelear t (pokemones e1) &&
					   hayTipoYPuedePelear t (pokemones e2)

hayTipoYPuedePelear :: TipoDePokemon -> [Pokemon] -> Bool
hayTipoYPuedePelear t [] 	  = False
hayTipoYPuedePelear t (x:xs) = (esMismoTipo t (tipo x) && (energia x)>0) || hayTipoYPuedePelear t xs

esExperto :: Entrenador -> Bool
-- Prop.: Dado un entrenador devuelve True si ese entrenador posee al menos
-- un pokemon de cada tipo posible.
esExperto (ConsEntr _ pkmns) = length (filtrarPkmnsTiposRep pkmns) == length tiposDePkmns

filtrarPkmnsTiposRep :: [Pokemon] -> [Pokemon]
--Prop.: Devuelve la misma lista de pokemones pero sin tipos repetidos
filtrarPkmnsTiposRep [] 	   = []
filtrarPkmnsTiposRep (x:xs) = if perteneceTipoEnLista (tipo x) (filtrarPkmnsTiposRep xs)
							then filtrarPkmnsTiposRep xs
							else x : filtrarPkmnsTiposRep xs

perteneceTipoEnLista :: TipoDePokemon -> [Pokemon] -> Bool
--Prop.: Dado un tipo de pokemon y una lista pokemon devuelve True
--si alguno de los pokemones es del tipo dado.
perteneceTipoEnLista t [] 	  = False
perteneceTipoEnLista t (x:xs) = esMismoTipo t (tipo x) || perteneceTipoEnLista t xs


fiestaPokemon :: [Entrenador] -> [Pokemon]
-- Dada una lista de entrenadores devuelve una lista con todos los po-
-- kemon de cada entrenador.
fiestaPokemon []	 = []
fiestaPokemon (e:es) = juntarPkmns (pokemones e) (fiestaPokemon es)

juntarPkmns :: [Pokemon] -> [Pokemon] -> [Pokemon]
juntarPkmns [] ys 	  = ys
juntarPkmns xs [] 	  = xs
juntarPkmns (x:xs) ys = x : juntarPkmns xs ys