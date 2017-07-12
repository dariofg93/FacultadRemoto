module Stack(Stack,emptyS,isEmptyS,push,top,pop,stUno,stDos) where

{-
	INVARIANTE DE REPRESENTACION:
	*La estructura simula ser una pila  
	LIFO(el ultimo en entrar, es el primero en salir).
	*El Max representa el maximo elemento en un Stack
-}

stUno :: Stack Int
stUno = push 4 (push 3 (push 2 (push 1 (emptyS))))

stDos :: Stack Int
stDos = push 7 (push 6 (push 5 (emptyS)))

data Stack a = ConsS [a] [a]	deriving(Show,Ord,Eq)

emptyS :: Ord a => Stack a
emptyS = (ConsS []) []

isEmptyS :: Stack a -> Bool
isEmptyS (ConsS [] _) = True
isEmptyS _			= False

push :: Ord a => a -> Stack a -> Stack a
push x (ConsS xs ys) = ConsS (x:xs) (maxEntreDos x ys)

maxEntreDos :: Ord a => a -> [a] -> [a]
maxEntreDos x [] = [x]
maxEntreDos x (y:ys) = if x>y
						then (x:y:ys)
						else (y:ys)

--Prec.: En la pila debe haber almenos un elemento.
top :: Stack a -> a
top (ConsS (x:xs) _) = x

--Prec.: En la pila debe haber almenos un elemento.
pop :: Ord a => Stack a -> Stack a
pop (ConsS (x:xs) m) = ConsS xs (devolverMax x m)

devolverMax :: Ord a => a -> [a] -> [a]
devolverMax _ [y] = []
devolverMax x (y:ys) = if x==y
						then ys
						else (y:ys)

maxS :: Ord a =>  Stack a -> a
maxS (ConsS xs (y:ys)) = y