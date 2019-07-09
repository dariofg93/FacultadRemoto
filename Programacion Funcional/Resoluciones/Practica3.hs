LANGUAGE RankNTypes
type BoolLam a = forall (a) -> a

--trueLam :: BoolLam -> a
trueLam = \x y -> x
--falseLam :: BoolLam -> a
falseLam = \x y -> y

notLam b = b falseLam trueLam

--orLam :: BoolLam a -> BoolLam a -> BoolLam a
orLam x y = x trueLam y