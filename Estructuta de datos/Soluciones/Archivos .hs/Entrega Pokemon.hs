data TipoDePokemon = Agua | Fuego | Planta deriving(Show)

type PorcentajeVida = Int
data Pokemon = ConsP TipoDePokemon PorcentajeVida deriving(Show)

type Nombre = String
type Pokemones = [Pokemon]
data Entrenador = ConsE Nombre Pokemones deriving(Show)

pkmn1 = ConsP Fuego 100
pkmn2 = ConsP Planta 50
pkmn3 = ConsP Agua 25

ash = ConsE "Ash Ketchup" [pkmn1,pkmn2,pkmn3,pkmn1]
brook = ConsE "Brook" [pkmn2,pkmn1]

esExperto :: Entrenador -> Bool
-- Prop.: Dado un entrenador devuelve True si ese entrenador posee al menos
-- un pokemon de cada tipo posible.
esExperto (ConsE _ pkmns) = length (filtrarPkmnsTiposRep pkmns) == length tiposDePkmns

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

esMismoTipo :: TipoDePokemon -> TipoDePokemon -> Bool
esMismoTipo Agua Agua 	  = True
esMismoTipo Fuego Fuego   = True
esMismoTipo Planta Planta = True
esMismoTipo _ _ 		  = False

tipo :: Pokemon -> TipoDePokemon
tipo (ConsP tipo _) = tipo

tiposDePkmns :: [TipoDePokemon]
tiposDePkmns = [Agua,Fuego,Planta]

fiestaPokemon :: [Entrenador] -> [Pokemon]
-- Dada una lista de entrenadores devuelve una lista con todos los po-
-- kemon de cada entrenador.
fiestaPokemon []	 = []
fiestaPokemon (e:es) = juntarPkmns (pokemones e) (fiestaPokemon es)

juntarPkmns :: [Pokemon] -> [Pokemon] -> [Pokemon]
juntarPkmns [] ys 	  = ys
juntarPkmns xs [] 	  = xs
juntarPkmns (x:xs) ys = x : juntarPkmns xs ys

pokemones :: Entrenador -> [Pokemon]
pokemones (ConsE _ pkmns) = pkmns

batallaSplit :: Pokemon -> Entrenador -> ([Pokemon], [Pokemon])
-- Dado un pokemon "p" y un entrenador devuelve un par de listas 
-- (xs, ys) donde xs son los pokemon del entrenador que NO le ganan a "p"
-- e ys son aquellos que SI le ganan a "p"
batallaSplit p e = pkmnsQuePierdenYganan p (pokemones e)

pkmnsQuePierdenYganan :: Pokemon -> [Pokemon] -> ([Pokemon], [Pokemon])
pkmnsQuePierdenYganan _ [] 	   = ([],[])
pkmnsQuePierdenYganan p (x:xs) = if leGanaA p x
					then addLosers x (pkmnsQuePierdenYganan p xs)
					else addWinners x (pkmnsQuePierdenYganan p xs)

addLosers :: Pokemon -> ([Pokemon], [Pokemon]) -> ([Pokemon], [Pokemon])
addLosers p (xs,ys) = (p:xs,ys)

addWinners :: Pokemon -> ([Pokemon], [Pokemon]) -> ([Pokemon], [Pokemon])
addWinners p (xs,ys) = (xs,p:ys)

leGanaA :: Pokemon -> Pokemon -> Bool
--Dados dos pokemon indica si el primero le puede ganar al segundo.
--Se considera que gana si su elemento es opuesto al del otro pokemon.
--Si poseen el mismo elemento se considera que no gana.
leGanaA p1 p2 = tipoPkmnLeGanaA (tipo p1) (tipo p2)

tipoPkmnLeGanaA :: TipoDePokemon -> TipoDePokemon -> Bool
tipoPkmnLeGanaA Fuego Agua	 = False
tipoPkmnLeGanaA Agua Planta	 = False
tipoPkmnLeGanaA Planta Fuego = False
tipoPkmnLeGanaA _ _ 		 = True