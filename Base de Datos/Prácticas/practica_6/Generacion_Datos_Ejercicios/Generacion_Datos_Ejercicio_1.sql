CREATE TABLE LIBRO
	(`ISBN` int primary key, 
     `Titulo` varchar(32))
;
	
INSERT INTO LIBRO
	(`ISBN`, `Titulo`)
VALUES
	(33058621, 'Inferno'),
	(35494238, 'Cien Anios de Soledad'),
	(58764384, 'Venas abiertas de America Latina'),
	(38784929, 'Aeropuerto')
;

CREATE TABLE EJEMPLAR
	(`CodEjemplar` int primary key, 
     `ISBNLibro` int,
     `Edicion` int,
    constraint fk_ejemplar FOREIGN KEY (`ISBNLibro`)
     references LIBRO(`ISBN`)
     )
;
	
INSERT INTO EJEMPLAR
	(`CodEjemplar`, `ISBNLibro`, `Edicion`)
VALUES
	(503, 33058621, 2),
	(785, 33058621, 4),
	(065, 35494238, 1),
	(098, 38784929, 3),
	(223, 58764384, 3),
	(101, 58764384, 1)
;

CREATE TABLE SOCIO
	(`CodSocio` int primary key,
     `NombreyApellido` varchar(17),
     `FechaIngreso` datetime, 
     `MontoCuota` int, 
     `Matricula` int, 
     `Pais` varchar(9))
;
	
INSERT INTO SOCIO
	(`CodSocio`, `NombreyApellido`, `FechaIngreso`, `MontoCuota`, `Matricula`, `Pais`)
VALUES
	(78, 'Sheldon Cooper', '2011-05-03 00:00:00', 12, 4, 'Brasil'),
	(54, 'Howard Wolowitz', '2011-01-21 00:00:00', 16, 0, 'Argentina'),
	(03, 'Amy Farrah Fowler', '2011-02-17 00:00:00', 5, 10, 'Argentina')
;

CREATE TABLE PRESTAMO
	(`CodEjemplar` int,
     `CodSocio` int,
     `FechaPrestamo` datetime,
     `FechaDevolucion` varchar(10),
     primary key(`CodEjemplar`,`CodSocio`),
     constraint fk_CodEjemplar FOREIGN KEY (`CodEjemplar`)
         references EJEMPLAR(`CodEjemplar`),
     constraint fk_CodSocio FOREIGN KEY (`CodSocio`)
         references SOCIO(`CodSocio`)
    )
;
	
INSERT INTO PRESTAMO
	(`CodEjemplar`, `CodSocio`, `FechaPrestamo`, `FechaDevolucion`)
VALUES
	(503, 78, '2012-05-03 00:00:00', '2012/05/08'),
	(223, 54, '2013-01-21 00:00:00', '2013/20/01'),
	(785, 78, '2013-02-20 00:00:00', NULL),
	(101, 03, '2013-11-17 00:00:00', '2013/11/18')
;

CREATE TABLE NACIONALIDAD
	(`NombrePais` varchar(9),
     `Nacionalidad` varchar(9)
    )
;
	
INSERT INTO NACIONALIDAD
	(`NombrePais`, `Nacionalidad`)
VALUES
	('Argentina', 'Argentina'),
	('Brasil', 'Brasilera'),
	('Peru', 'Peruana'),
	('Mexico', 'Mexicana')
;
