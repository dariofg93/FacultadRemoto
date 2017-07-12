-----------------------------
-- INTRODUCCIÓN
-----------------------------
cuatro = 2+2

otroCuatro = 3+1

ocho = cuatro*2

tresPrimeros :: [Int]
tresPrimeros = [1,2,3]

dosColores :: [Color]
dosColores = [Rojo, Verde]

-----------------------------
-- DEFINCIÓN
-----------------------------
{- ESTRUCTURAS DE DATOS
  * Son agrupaciones de datos
  * Sirven para organizar  información
  * Usamos las operaciones para ACCEDER a los datos
    de ciertas maneras
 -}

-----------------------------
-- RECURSIÓN
-----------------------------
{-
function sum(lista)
 {
   if (isEmpty(lista))
   then
     { return (0) }
   else
     { return (head(lista) + sum(tail(lista)) }
 }
-} 

{-
sum([1,2,3])
=
head[1,2,3] + sum(tail[1,2,3])
=
    1       + sum([2,3])
=
    1       +     5
-}

miSum lista =
   if (null lista)
    then 0
    else head lista  + miSum (tail lista)
                   -- Si escribo
                   --    miSum tail lista
                   -- (sin paréntesis) es como decir
                   --    miSum(tail,lista)
                   -- Y ESTÁ MAAAAAAAL!!!!
                   
miSum2 xs = if null xs
             then 0
             else head xs + miSum2 (tail xs)
              
-- Ej: mapSucc [10,20,30] = [11,21,31]

mapSucc xs = 
   if null xs
    then []
    else [head xs + 1] ++ mapSucc (tail xs)
          
-----------------------------
-- PATTERN MATCHING          
-----------------------------
mapSucc2 :: [Int] -> [Int]
mapSucc2 []     = []
mapSucc2 (y:ys) = [y+1] ++ mapSucc2 ys

mapSucc3 :: [Int] -> [Int]
mapSucc3 []     = []
mapSucc3 (y:ys) = y+1 : mapSucc3 ys
      
miSum3 []     = 0
miSum3 (y:ys) = y + miSum3 ys             

{-
-- DEFINIR POR RECURSIÓN SOBRE LISTAS (CON PATTERN MATCHING)
f :: [a] -> b
f []     = ...                    -- Caso base
f (x:xs) = ... x ... (f xs) ...   -- Caso recursivo
-}

-----------------------------
-- TIPOS
-----------------------------
-- Funciones:   argumento -> resultado
-- Números:     Int
-- Funciones con varios argumentos:
--    argumento1 -> argumento2 -> argument3 -> resultado

elegirElMasGrande :: Int -> Int -> Int
elegirElMasGrande n m = if n>m then n else m

ej = elegirElMasGrande 2 (head [4,5])
          -- IMPORTAN!!: ^          ^
          --             |          |
-----------------------------
-- POLIMORFISMO
-----------------------------
siempreSiete :: algo -> Int
siempreSiete x = 7

miSucc :: Int -> Int
miSucc x = x+1

miLen :: [a] -> Int
miLen []     = 0
miLen (x:xs) = 1 + miLen xs         

ej1 = miLen [10,20,30]                  -- acá miLen :: [Int] -> Int
ej2 = miLen [True, False, True, False]  -- acá miLen :: [Bool] -> Int
ej3 = miLen [Negro, Rojo]               -- acá miLen :: [Color] -> Int
-- miLen es polimórfica
          
-----------------------------
-- TIPOS ALGEBRAICOS
-----------------------------
-- Se definen con "data"
-- Hay que indicar cuáles son los "Constructores"
data Color = Azul | Negro | Rojo | Verde
data Dir = Norte | Este | Sur | Oeste
-- Azul, Negro, Rojo, Verde, Norte, Este, Sur y Oeste
--   son constructores

-- Puedo usar Pattern Matching sobre los 
--    constructores de un tipo algebraico
sigColor :: Color -> Color
sigColor Azul  = Negro
sigColor Negro = Rojo
sigColor Rojo  = Verde
sigColor Verde = Azul

-- Puede haber un solo constructor
data Persona = Persona String Int  Bool
                   --  Nombre Edad EsCasado
-- Persona es un constructor (y TAMBIÉN un tipo, pero son distintas cosas)                  

yo = Persona "Fidel" 47 False      
   -- Persona(nombre <- "Fidel", edad <- 47, esCasado <- False)

       -- | Este es el tipo Persona
       -- v
nombre :: Persona -> String
nombre (Persona nom edad estadoCivil) = nom
       -- ^
       -- | Este es el constructor Persona
 
edad :: Persona -> Int
edad (Persona nom edad estadoCivil) = edad

cumplirAnios :: Persona -> Persona
cumplirAnios (Persona  nom edad estadoCivil) = 
     Persona nom (edad + 1) estadoCivil
     -- Construye una nueva persona con la edad aumentada

-- Un tipo algebraico puede tener varios constructores, cada uno con argumentos
data Gusto = Chocolate | DulceDeLeche 
           | Sambayon | Vainilla | Granizado
data Helado = Cucurucho Gusto Gusto
            | Vasito Gusto 
            | Pote Gusto Gusto Gusto            
-- Chocolate, DulceDeLeche, Sambayon, Vainilla, Granizado, Cucurucho, Vasito y Pote
--    son constructores            

miHelado, otroHelado :: Helado
miHelado = Cucurucho Chocolate Sambayon
otroHelado = Vasito Vainilla
heladoChocolatoso = Cucurucho Chocolate Chocolate

-- Puedo usar Pattern Matching
tieneChocolate :: Helado -> Bool
tieneChocolate (Cucurucho g1 g2) = esChocolate g1 || esChocolate g2
tieneChocolate (Vasito g)        = esChocolate g
tieneChocolate (Pote g1 g2 g3)   = esChocolate g1 || esChocolate g2 
                                                  || esChocolate g3      
                            
-- Pattern matching COMPLETO
esChocolate' Chocolate    = True
esChocolate' DulceDeLeche = False
esChocolate' Sambayon     = False
esChocolate' Vainilla     = False
esChocolate' Granizado    = False

-- Pattern matching con un caso por defecto                            
esChocolate :: Gusto -> Bool
esChocolate Chocolate    = True
esChocolate g            = False  -- Todos los que no son Chocolate, entrar por acá

-- Si no uso un parámetro, puedo usar guión bajo (ignoro el parámetro)
esCucurucho :: Helado -> Bool
esCucurucho (Cucurucho _ _) = True
esCucurucho _               = False

gustoDelVasito :: Helado -> Gusto
gustoDelVasito (Vasito g) = g

-- El guión bajo NO PUEDE aparecer a la derecha del igual
-- malGustoDelVasito (Vasito _) = _

primerGustoDelCucurucho  (Cucurucho g1 _) = g1

segundoGustoDelCucurucho (Cucurucho _ g2) = g2

-----------------------------
-- EJERCICIOS
-----------------------------
--Escribir
--    agregarAtras --Sugerencia: USAR RECURSIÓN, 
--       NO VALE USAR (++)
--    sumarACada   --Sugerencia: USAR RECURSIÓN
--    sigDir :: Dir -> Dir


