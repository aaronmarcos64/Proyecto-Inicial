#include <mysql.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
	int main(int argc, char **argv)
{
	//Conector para acceder al servidor de bases de datos 
		MYSQL *cnx;
	int err;
	//Creamos una conexion al servidor MYSQL
	cnx = mysql_init(NULL);
	if (cnx==NULL) {
		printf ("Error al crear la conexion: %u %s\n", mysql_errno(cnx), mysql_error(cnx));
		exit (1);
	}
	//inicializar la conexion, indicando nuestras claves de acceso
	// al servidor de bases de datos (user,pass)
	cnx = mysql_real_connect (cnx, "localhost","root", "mysql", NULL, 0, NULL, 0);
	if (cnx==NULL)
	{
		printf ("Error al inicializar la conexion: %u %s\n", mysql_errno(cnx), mysql_error(cnx));
		exit (1);
	}
	// Creamos la base de datos del juego
	mysql_query(cnx, "drop database if exists Juego;"); 
	err=mysql_query(cnx, "create database Juego;");
	if (err!=0) {
		printf ("Error al crear la base de datos %u %s\n", mysql_errno(cnx), mysql_error(cnx));
		exit (1);
	}
	//indicamos la base de datos con la que queremos trabajar 
	err=mysql_query(cnx, "use Juego;");
	if (err!=0)
	{
		printf ("Error al crear la base de datos %u %s\n", mysql_errno(cnx), mysql_error(cnx));
		exit (1);
	}
	// creamos la tabla que define la entidad Jugadores que incluye nombre y id
		err=mysql_query(cnx,"CREATE TABLE Jugadores (nombre VARCHAR(25), id int)");
		if (err!=0)
	{
			printf ("Error al definir la tabla %u %s\n", mysql_errno(cnx), mysql_error(cnx));
			exit (1);
	}
		// ahora tenemos la base de datos lista en el servidor de MySQL
		// cerrar la conexion con el servidor MYSQL 
		mysql_close (cnx);
		exit(0);
}
