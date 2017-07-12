-- import ListaNV
import ListaNVT
import Queue

sumarTodos :: ListaNV Int -> Int
sumarTodos xsL = 
	if puedeBorrar xsL
	   then (primero xsL) + 
	        sumarTodos (borrar xsL)
	   else (primero xsL)

unaLista :: ListaNV Int
unaLista = 
	agregar 3 
		(agregar 2
			(iniciar 1))

longitudLNV :: ListaNV a -> Int
longitudLNV xsL = longLNV xsL