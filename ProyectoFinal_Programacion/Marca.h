#pragma once
#include<iostream>
#include "ConexionBD.h"
#include <string.h>
#include <string>
using namespace std;

class Marcas {
private: int idmarca = 0;
public: string marca;

public:
	Marcas() {
	}
	Marcas(string mar) {
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
	void leer(int x) {
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

	void actualizar(int x) {
		int q_query = 0;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();

		if (cn.getconectar()) {
			string t = to_string(x);
			string update = "update marcas set marca='" + marca + "' where idMarca=" + t + ";";
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

	void eliminar(int x) {
		int q_query;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();

		if (cn.getconectar()) {
			string busquedaaux = to_string(x);
			string elimin = "delete from marcas where idMarca=" + busquedaaux + ";";
			const char* eli = elimin.c_str();
			q_query = mysql_query(cn.getconectar(), eli);
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
	void setMarca(string mar) { marca = mar; }

};