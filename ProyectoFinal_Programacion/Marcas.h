#pragma once
#include <iostream>
#include <string.h>
#include "ConexionBD.h"
#include <string>


using namespace std;

class Marcas{
private: int idmarca=0;
public: string marca;

public: 
	Marcas() {
	}
	Marcas(int idma, string mar) {
			 idmarca = idma;
			 marca = mar;
	}


	void crear() {
		int q_query;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();

		if (cn.getconectar()) {
			string insertar = "insert into marcas(marca) values('" + marca + "');";
			const char* i = insertar.c_str();
			q_query = mysql_query(cn.getconectar(), i);
			if (!q_query) {
				cout << "Ingreso exitoso\n";
			}
			else {
				cout << "Error al ingresar\n";
			}
		}
		else {
			cout << "Error";
		}
		cn.cerrar_conexion();
	}

	void leer() {
		int q_query;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getconectar()) {
			string consulta = "select * from marcas";
			const char* c = consulta.c_str();
			q_query = mysql_query(cn.getconectar(), c);
			cout << "\n---------- MARCAS ----------\n";
			cout << "\nId Marca, Marca\n\n";
			if (!q_query) {
				resultado = mysql_store_result(cn.getconectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << " , " << fila[1] << endl;

				}
			}
			else {
				cout << "Error al consultar\n";
			}
		}
		else {
			cout << "Error";
		}
		cn.cerrar_conexion();
	}

	void actualizar() {
		int q_query;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();

		if (cn.getconectar()) {
			string t = to_string(idmarca);
			string update = "update marcas set marca='" + marca + "' where idmarca=" + t + ";";
			const char* i = update.c_str();
			q_query = mysql_query(cn.getconectar(), i);
			if (!q_query) {
				cout << "Actualizacion exitosa\n";
			}
			else {
				cout << "Error al ingresar\n";
			}
		}
		else {
			cout << "Error";
		}
		cn.cerrar_conexion();

	}

	void eliminar() {
		int q_query;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();

		if (cn.getconectar()) {
			string t = to_string(idmarca);
			string elimin = "delete from marcas where idmarca=" + t + ";";
			const char* i = elimin.c_str();
			q_query = mysql_query(cn.getconectar(), i);
			if (!q_query) {
				cout << "Eliminacion exitosa\n";
			}
			else {
				cout << "Error al ingresar\n";
			}
		}
		else {
			cout << "Error";
		}
		cn.cerrar_conexion();
	}

};




