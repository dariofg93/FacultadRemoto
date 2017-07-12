--ENTREGA SQL
--NOMBRE: Gutierrez, Dario Fernando

EJERCICIO A:
--1) TABLAS CREADAS con el archivo argenflix.sql, descargado de la pagina de base de datos.
--2)
insert into ACTOR values
('Jordana Brewster',35,20), ('Vin Diesel',47,25), ('Paul Walker',40,28);

insert into PELICULA values
(31,'Rapido y furioso 1','Accion',104,8,'Vin Diesel','Rob Cohen'),
(32,'Rapido y furioso 2','Accion',107,7,'Paul Walker','John Singleton'),
(33,'Rapido y furioso 4','Accion',106,8,'Jordana Brewster','Justin Lin');

insert into SERIE values
('¿Quien manda a quien?',1984,'Comedia',8,8,'Paul Walker','Martin Cohan'),
('True Detective',2014,'Crimen',1,7,'Colin Farrell','Nic Pizzolatto'),
('Vikings',2013,'Aventura',4,8,'Travis Fimmel','Michael Hirts');
--3)
UPDATE PELICULA set calificacion=5 where nombreDirector='Christopher Nolan';

---------------------------------------------------------------------------------------------------------------------------------------
EJERCICIO B:
--1)
SELECT nombreActor, count(*) as cantPeliculasActuadas from PELICULA where nombreActor= 'Jim Carrey';
--2)
SELECT distinct nombreSerie, temporadas from SERIE join PELICULA on SERIE.nombreDirector=PELICULA.nombreDirector;
--3)
SELECT distinct nombreActor from PELICULA MINUS select nombreActor from SERIE;
--4)
SELECT nombrePelicula, nombreActor, DIRECTOR.nombreDirector from PELICULA join DIRECTOR on nombreActor=actorFetiche;
--5)
SELECT nombreSerie, genero, nombreUsuario as usuarioTambienVio from SERIE natural join VIOSERIE where nombreSerie='Game of Thrones' UNION SELECT nombreSerie, genero, nombreUsuario as usuarioTambienVio from SERIE natural join VIOSERIE where nombreSerie='Friends';
--6)
SELECT nombreUsuario, count(nombreUsuario) as cantidadDePeliculasVistas from VIOPELICULA group by nombreUsuario order by count(nombreUsuario) desc;
--7)
SELECT distinct USUARIO.nombreUsuario, nombreYApellido from VIOSERIE join USUARIO on VIOSERIE.nombreUsuario=USUARIO.nombreUsuario where anhoSerie=1980;
--8)
SELECT nombreSerie, anhoSerie, count(nombreUsuario) as cantUsuarioQueVieron from SERIE natural join VIOSERIE where genero='Western' group by nombreSerie;
--9)
SELECT distinct serie.nombreActor from PELICULA join SERIE on pelicula.nombreActor=serie.nombreActor where duracion>120 and temporadas>=3;
--10)
SELECT idPelicula, nombrePelicula from PELICULA natural join ACTOR where calificacion>7 and anhosActivo<10;
--11)
SELECT nombreYApellido, vioPelicula.nombreUsuario from USUARIO natual join vioPelicula join PELICULA on vioPelicula.idPelicula=pelicula.idPelicula where contrasenha!=vioPelicula.nombreUsuario and contrasenha!=12345 and calificacion>(select avg(calificacion) from pelicula) group by nombreYApellido desc;

--En el ejercicio 11: En el momento de la consulta donde hay un AND quise usar un OR, ya que un campo no puede tomar dos valores a la vez, pero como mariadb me daba error use AND, y aun asi dio el resultado que esperaba con un OR.
--En el ejercicio 11: La contraseña del usuario no estaba seguro si debia ser solo 12345 o una cadena en donde apareciera 12345 seguido o continuado de otros caractéres. Entonces tomé la contraseña que podia tener mas caracteres ademas de los conocidos.