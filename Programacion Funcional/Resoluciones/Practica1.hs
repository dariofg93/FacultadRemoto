--import Prelude hiding (Bool(..),not)
import Prelude hiding (not, and, or, fst, snd, null)

-- ################ 1) Booleanos ################
--data Bool = True | False

--a.
not :: Bool -> Bool
not True = False
not False = True

--b.
and :: Bool -> Bool -> Bool
and True True = True
and _ _ = False

--c.
or :: Bool -> Bool -> Bool
or False False = False
or _ _ = True

--d.
--(==) :: Bool -> Bool -> Bool
--(==) False False = True
--(==) True True = True
--(==) _ _ = False

--e.
ifThenElse :: Bool -> a -> a -> a
ifThenElse True x _ = x
ifThenElse False _ y = y

-- ################ 2) Pares ################
-- data (a , b) = (a , b) --notacion especial de Haskell

--a.
fst :: (a,b) -> a
fst (x,_) = x

--b.
snd :: (a,b) -> b
snd (_,y) = y

--c.
swap :: (a,b) -> (b,a)
swap (x,y) = (y,x)

--d.
eqPair :: Eq a => Eq b => (a,b) -> (a,b) -> Bool
eqPair x y = and (fst x == fst y) (snd x == snd y)

-- ################ 3) Maybe ################

--a.
isNothing :: Maybe a -> Bool
isNothing Nothing = True
isNothing _ = False

-- ################ 4) Naturales ################
data Nat = Zero | Suc Nat deriving Show

--c.
sub :: Nat -> Nat -> Maybe Nat
sub Zero Zero = Nothing
sub (Suc n) Zero = Just n
sub Zero (Suc m) = Just m
sub (Suc n) (Suc m) = sub n m

-- ################ 5) Listas ################
--data [ a ] = [] | a : [ a ] notacion especial de Haskell

--a.
null :: [a] -> Bool --(indica si está vacía)
null (x:xs) = False
null _ = True

--e.
--dAppend :: [a] -> [a] -> [a] --(concatena dos listas)
--dAppend [] b = b
--dAppend (x:xs) b = x:(dAppend a xs)


------------------------------------------------------------------------------
