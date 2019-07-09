fold::(a->b->b) -> b -> [a] -> b
fold f cb [] = cb
fold f cb (x:xs) = f x (foldr f cb xs)

headL (x:xs) = x
tailL (x:xs) = xs

elemD:: Eq a => a -> [a] -> Bool
elemD x ys = fold (\x r -> x == headL ys || r) False ys
--elem x ys = fold (\x r -> if x == headL ys then True else r x (tailL ys))
