
#include <mysql.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
	int main(int argc, char **argv)
{
	DROP DATABASE IF EXISTS JuegoPropio;
	CREATE DATABASE JuegoPropio;
	USE JuegoPropio;
	CREATE TABLE Jugadores ( 
	id INTEGRER PRIMARY KEY NOT NULL,
	Nombre TEXT NOT NULL,
	) ENGINE = InnoDB;
	CREATE TABLE IDJuadores (
	Jugador INTEGRER NOT  NULL
	ID INTEGRER NOT NULL
	FOREIGN KEY (Jugador) REFERENCES Player (id),
	) ENGINE = InnoDB;

	INSERT INTO Jugadores VALUES (1,'Arnau');
	INSERT INTO Jugadores VALUES (2,'Aaron');
	INSERT INTO Jugadores VALUES (3,'Aalejandro');
	INSERT INTO Jugadores VALUES (4,'Carla');

	INSERT INTO IDJugadores VALUES (1,'001');
	INSERT INTO IDJugadores VALUES (2,'002');
	INSERT INTO IDJugadores VALUES (3,'003');
	INSERT INTO IDJugadores VALUES (4,'004');

}
