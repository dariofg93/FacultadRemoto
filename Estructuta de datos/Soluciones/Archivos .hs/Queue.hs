module Queue(Queue,emptyQ,isEmptyQ,queue,firstQ,dequeue,qUno,qDos) where

{-
	INVARIANTE DE REPRESENTACION:
	*El tipo simula ser una cola  
	FIFO(el primero en entrar, es el primero en salir).
-}

qUno :: Queue Int
qUno = queue 50 (queue 40 (queue 30 (queue 20 (queue 10 (emptyQ)))))

qDos :: Queue Int
qDos = queue 70 (queue 60 (emptyQ))

data Queue a = ConsQ [a] Cantidad deriving(Show,Eq)
type Cantidad = Int

emptyQ :: Queue a
emptyQ = ConsQ [] 0

isEmptyQ :: Queue a -> Bool
isEmptyQ (ConsQ [] n) = n==0

queue :: a -> Queue a -> Queue a
queue x (ConsQ xs n) = ConsQ (xs++[x]) (n+1)

--Prec.: En la cola debe haber almenos un elemento.
firstQ :: Queue a -> a
firstQ (ConsQ (x:xs) n) = x

--Prec.: En la cola debe haber almenos un elemento.
dequeue :: Queue a -> Queue a
dequeue (ConsQ (x:xs) n) = ConsQ xs (n-1)

lenQ :: Queue a -> Int
lenQ (ConsQ xs n) = n