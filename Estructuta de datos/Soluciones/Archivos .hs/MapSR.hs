module MapSR (Map, emptyM, assocM, deleteM, lookUpM, domM) where

import Conjunto	

{- 
### Invariantes de representación ###

	* La lista no puede tener tuplas con el mismo la misma clave.
	
	Ejemplo de representación válido (Para un Map Int Char):
		(Para un Map Int Char)
		ConsM [(2,'n'),(3,'n')]
		ConsM [(2,'n'),(3,'f')]
	Ejemplo de representación inválido (Para un Map Int Char):
		ConsM [(2,'m'),(2,'n')]
-}

-- ### Tipo de representación ###
data Map k v = ConsM [(k,v)]	deriving(Show,Eq)

-- PROPÓSITO: Devuelve un Map vacío.
-- PRECONDICIONES: No tiene.
-- Orden de complejidad : O(1)
emptyM :: Map k v
emptyM = ConsM []

-- PROPÓSITO: Dado un Map, una clave y un valor, devuelve un Map que contenga
-- una tupla con esa clave-valor.
-- PRECONDICIONES: No tiene.
-- Orden de complejidad : O(n)
assocM :: Eq k => Map k v -> k -> v -> Map k v
assocM (ConsM kvs) k v = ConsM (assocMAux kvs k v)

-- PROPÓSITO: Dada una lista clave-valor, una clave y un valor, devuelve una lista que contenga
-- una tupla con esa clave-valor.
-- PRECONDICIONES: No tiene.
-- Orden de complejidad : O(n)
assocMAux :: Eq k => [(k,v)] -> k -> v -> [(k,v)]
assocMAux [] k v =	[(k,v)]
assocMAux (kv:kvs) k v =	if (fst kv) == k
							then (k,v): kvs
							else kv : (assocMAux kvs k v) 

-- PROPÓSITO: Dado un Map y una clave, devuelve el mismo Map
-- sin las tuplas con esa clave.
-- PRECONDICIONES: No tiene.
deleteM :: Eq k => Map k v -> k -> Map k v	--O(n)
deleteM (ConsM kvs) k =	ConsM (deleteMAux kvs k)

-- PROPÓSITO: Dada una lista de pares clave-valor y una clave,
-- devuelve una lista sin el par que tengan esa clave.
-- PRECONDICIONES: No tiene.
deleteMAux :: Eq k => [(k,v)] -> k -> [(k,v)]
deleteMAux [] k = []
deleteMAux (kv:kvs) k =	if k == (fst kv)
						then kvs
						else kv: (deleteMAux kvs k)

-- PROPÓSITO: Dado un Map y una clave, devuelve un Maybe v (correspondiente
-- al valor de la clave dada).
-- PRECONDICIONES: No tiene.
lookUpM :: Eq k => Map k v -> k-> Maybe v
lookUpM (ConsM kvs) k = lookUpMAux kvs k

-- PROPÓSITO: Dada una lista clave-valor y una clave, devuelve un Maybe v (correspondiente
-- al valor de la clave dada).
-- PRECONDICIONES: No tiene.
-- Orden de complejidad : O(n)
lookUpMAux :: Eq k => [(k,v)] -> k -> Maybe v
lookUpMAux [] k = Nothing
lookUpMAux (kv:kvs) k =	if k == (fst kv)
						then Just(snd kv)
						else lookUpMAux kvs k

-- PROPÓSITO: Dado un Map, devuelve un set que contiene todas las claves
-- del Map dado.
-- PRECONDICIONES:
-- Orden de complejidad : O(n) / O(2.n)
domM :: Ord k => Map k v -> Conjunto k	
domM (ConsM kvs) = list2Set (listaDeClaves kvs)

-- PROPÓSITO: Dada una lista de pares clave-valor, devuelve la lista de claves.
listaDeClaves :: [(k,v)] -> [k] 	
listaDeClaves [] = []
listaDeClaves (kv:kvs) = (fst kv):(listaDeClaves kvs)

list2Set :: Ord a => [a] -> Conjunto a
list2Set [] = vacioC
list2Set (x:xs) = agregarC x (list2Set xs)