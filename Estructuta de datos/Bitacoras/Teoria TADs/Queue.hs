module Queue(Queue,
	emptyQ,
	isEmptyQ,
	firstQ,
	queueQ,
	dequeueQ,
	lenQ) where

-- Tipo de Representacion
data Queue a = ConsQ [a] Int

{- Inv. Rep.:
  + Int es la longitud de la lista
  + Los elementos se agregan
    por el final y 
    salen el principio de la lista
-}

-- Interfaz
emptyQ :: Queue a
isEmptyQ :: Queue a -> Bool
queueQ :: a -> Queue a -> Queue a
dequeueQ :: Queue a -> Queue a
firstQ :: Queue a -> a
lenQ :: Queue a -> Int

-- O(1)
emptyQ = ConsQ [] 0

-- O(1)
isEmptyQ (ConsQ _ n) = n == 0

-- O(n)
queueQ x (ConsQ xs n) = 
  ConsQ	(xs++[x]) (n+1) 

-- O(1)
dequeueQ (ConsQ xs n) =
   ConsQ (tail xs) (n-1)

-- O(1)
firstQ (ConsQ xs n) =
   head xs

-- O(1)
lenQ (ConsQ xs n) = n