module MapCR (Map, emptyM, assocM, deleteM, lookUpM, domM) where

import Set

{- 
### Invariantes de representación ###

	* No tiene.
	
	Ejemplo de representación válido (Para un Map Int Char):
		(Para un Map Int Char)
		ConsM [(2,'n'),(3,'n')]
		ConsM [(2,'n'),(3,'f'),(3,'d')]
	Ejemplo de representación inválido (Para un Map Int Char):
		Al no haber invariante, no se pueden construir ejemplos que no lo respenten.
-}

-- ### Tipo de representación ###
data Map k v = ConsM [(k,v)]	deriving(Show)

-- PROPÓSITO: Devuelve un Map vacío.
-- PRECONDICIONES: No tiene.
-- Orden de complejidad : O(1)
emptyM :: Map k v
emptyM = ConsM []

-- PROPÓSITO: Dado un Map, una clave y un valor, devuelve un Map que contenga
-- una tupla con esa clave-valor.
-- PRECONDICIONES: No tiene.
-- Orden de complejidad : O(1)
assocM :: Eq k => Map k v -> k -> v -> Map k v
assocM (ConsM kvs) k v = ConsM ((k,v):kvs)

-- PROPÓSITO: Dado un Map y una clave, devuelve el mismo Map
-- sin las tuplas con esa clave.
-- PRECONDICIONES: No tiene.
-- Orden de complejidad : O(n)
deleteM :: Eq k => Map k v -> k -> Map k v	--O(n)
deleteM (ConsM kvs) k =	ConsM (deleteMAux kvs k)

-- PROPÓSITO: Dada una lista de pares clave-valor y una clave,
-- devuelve una lista sin los pares que tengan esa clave.
-- PRECONDICIONES: No tiene.
deleteMAux :: Eq k => [(k,v)] -> k -> [(k,v)]
deleteMAux [] k = []
deleteMAux (kv:kvs) k =	if k == (fst kv)
						-- debo hacer el llamado recursivo porque "k" puede estar en kvs también.
						then deleteMAux kvs k  
						else kv: (deleteMAux kvs k)

-- PROPÓSITO: Dado un Map y una clave, devuelve un Maybe v (correspondiente
-- al valor de la clave dada). 
-- Nota: Dado que puede haber múltiples ocurrencias de pares con clave igual a "k", 
-- lookUp devuelve la primera que encuentra.
-- PRECONDICIONES: No tiene.
-- Orden de complejidad : O(n)
lookUpM :: Eq k => Map k v -> k-> Maybe v
lookUpM (ConsM xs) k = lookUpMAux xs k

-- PROPÓSITO: Dada una lista clave-valor y una clave, devuelve un Maybe v (correspondiente
-- al valor de la clave dada).
-- PRECONDICIONES: No tiene.
lookUpMAux :: Eq k => [(k,v)] -> k -> Maybe v
lookUpMAux [] k = Nothing
lookUpMAux (kv:kvs) k =	if k == (fst kv)
						then Just(snd kv)
						else lookUpMAux kvs k

-- PROPÓSITO: Dado un Map, devuelve un set que contiene todas las claves
-- del Map dado.
-- PRECONDICIONES:
-- Orden de complejidad : O(n) / O(2.n)
domM :: Eq k => Map k v -> Set k	
domM (ConsM xs) = list2Set (listaDeClaves xs)

-- PROPÓSITO: Dada una lista de pares clave-valor, devuelve la lista de claves.
listaDeClaves :: [(k,v)] -> [k] 	
listaDeClaves [] = []
listaDeClaves (kv:kvs) = (fst kv):(listaDeClaves kvs)