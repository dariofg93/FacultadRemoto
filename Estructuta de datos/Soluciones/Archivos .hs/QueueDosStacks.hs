module QueueDosStacks(QueueDosStacks,emptyQ,isEmptyQ,queue,firstQ,dequeue,qUno,qDos) where

import Stack

{-
	INVARIANTE DE REPRESENTACION:
	* El tipo simula ser una cola  
	FIFO(el primero en entrar, es el primero en salir).
	* Si fs se encuentra vacía, entonces la cola se encuentra vacía.
-}

qUno :: QueueDosStacks Int
qUno = queue 50 (queue 40 (queue 30 (queue 20 (queue 10 (emptyQ)))))

qDos :: QueueDosStacks Int
qDos = queue 70 (queue 60 (emptyQ))

data QueueDosStacks a = ConsQ (Stack a){-Front stack-} (Stack a){-Back stack-} Cantidad deriving(Show,Eq)
type Cantidad = Int

emptyQ :: QueueDosStacks a
emptyQ = ConsQ emptyS emptyS 0

isEmptyQ :: QueueDosStacks a -> Bool
isEmptyQ (ConsQ fs _ _) = isEmptyS fs

queue :: a -> QueueDosStacks a -> QueueDosStacks a
queue x (ConsQ xs n) = ConsQ (xs++[x]) (n+1)

--Prec.: En la cola debe haber almenos un elemento.
firstQ :: QueueDosStacks a -> a
firstQ (ConsQ (x:xs) n) = x

--Prec.: En la cola debe haber almenos un elemento.
dequeue :: QueueDosStacks a -> QueueDosStacks a
dequeue (ConsQ (x:xs) n) = ConsQ xs (n-1)

lenQ :: QueueDosStacks a -> Int
lenQ (ConsQ xs n) = n