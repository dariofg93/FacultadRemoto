module ConjuntoSufijos where
--(ConjuntoSufijos,vacio,terminanCon,agregarSufijos,borrarSufijos)
import MapSR
import Conjunto

data ConjuntoSufijos = CP (Map String (Conjunto String)) deriving(Show)

{-
	INVARIANTES DE REPRESENTACION:
		* Las claves del Map seran los sufijos, mientras que 
		los valores seran las palabras que posean dicho sufijo.
-}

--Crea un ConjuntoSufijos vacio. O(1).
vacio :: ConjuntoSufijos
vacio = CP emptyM

--Devuelve el conjunto de palabras asociadas a determinado sufijo. O(log(n)).
terminanCon :: String -> ConjuntoSufijos -> Conjunto String
terminanCon sufijo (CP mapping) = buscarPalabrasEnRep sufijo mapping

buscarPalabrasEnRep :: String -> Map String (Conjunto String) -> Conjunto String
buscarPalabrasEnRep sufijo palabras = case (lookUpM palabras sufijo) of
				Nothing	   -> error "No hay palabras con ese sufijo."
				Just words -> words

--Asocia una palabra a cada uno de sus sufijos. O(s.log(n)).
agregarSufijos :: String -> ConjuntoSufijos -> ConjuntoSufijos
agregarSufijos word (CP sufWords) = 
	CP (agregarSufsEnRep word (sufijos word) sufWords)

sufijos :: String -> [String]
sufijos "" = [""]
sufijos word = word : sufijos (tail word)

agregarSufsEnRep :: String -> [String] -> Map String (Conjunto String) -> Map String (Conjunto String)
agregarSufsEnRep word (suf:sufs) mapping = 
	agregarSufsEnRep word sufs (assocM mapping suf word)








--agregarTodosLosSufijos :: String -> [String] -> Map String (Conjunto String) -> Map String (Conjunto String)
--agregarTodosLosSufijos _ [] mapping = mapping
--agregarTodosLosSufijos word (s:ss) mapping = 
--	agregarTodosLosSufijos word ss (assocM mapping s word)