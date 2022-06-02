#pragma once
#include <iostream>
#include <string.h>
#include "ConexionBD.h"
#include <string>
using namespace std;

class Puesto{
private: string puesto;

public:
	Puesto() {
	}
	Puesto(string pue) {
		puesto = pue;
	}
	//CRUD//
	void crear() {
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		int q_estado;

		if (cn.getconectar()) {
			string insert = "insert into puestos (puesto) values ('" + puesto + "');";
			const char* i = insert.c_str(); //convertido a char
			q_estado = mysql_query(cn.getconectar(), i);
			if (!q_estado) {
				cout << "ingreso exitoso!" << endl;
			}
			else {
				cout << " xxx error al hacer insert xxx " << endl;
			}
		}
		else {
			cout << " xxx error de conexion xxx" << endl;
		}
		cn.cerrar_conexion();
	}


	void leer() {
		ConexionBD cn = ConexionBD();
		int q_estado;
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		cout << "id_p" << " | " << "puesto" << endl;

		if (cn.getconectar()) {
			string consulta = "select *from puestos;";
			const char* con = consulta.c_str(); //convertimos a char
			q_estado = mysql_query(cn.getconectar(), con);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getconectar());

				while (fila = mysql_fetch_row(resultado)) {
					for (int i = 0; i <= 1; i++) {
						cout << fila[i] << " , ";
					}
					cout << endl;
				}
			}
			else {
				cout << " error al hacer select XXX" << endl;
			}
		}
		else {
			cout << " xxx sin conexion xxx" << endl;
		}
		cn.cerrar_conexion();
	}

	void leer(int x) {
		ConexionBD cn = ConexionBD();
		int q_estado;
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		string auxtext = to_string(x);
		cout << "id_p" << " | " << "puesto" << endl;

		if (cn.getconectar()) {
			string consulta = "select *from puestos where idPuesto = " + auxtext + ";";
			const char* con = consulta.c_str(); //convertimos a char
			q_estado = mysql_query(cn.getconectar(), con);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getconectar());

				while (fila = mysql_fetch_row(resultado)) {
					for (int i = 0; i <= 1; i++) {
						cout << fila[i] << " , ";
					}
					cout << endl;
				}
			}
			else {
				cout << " error al hacer select XXX" << endl;
			}
		}
		else {
			cout << " xxx sin conexion xxx" << endl;
		}
		cn.cerrar_conexion();
	}

	



	void actualizar(int x) {
		
		int q_estado = 0;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		string i = to_string(x);
		if (cn.getconectar()) {
			string update = "UPDATE puestos SET puesto = '" + puesto + "' WHERE idPuesto = " + i + ";";
			const char* upda = update.c_str();
			q_estado = mysql_query(cn.getconectar(), upda);
			if (!q_estado) {
				cout << " modificado " << endl;
			}
			else {
				cout << "error xxx" << endl;
			}

		}
		else {
			cout << " error de conexion xxx" << endl;
		}
		cn.cerrar_conexion();
	}

	void eliminar(int x) {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		string busquedaaux = to_string(x);
		if (cn.getconectar()) {
			string eliminar = "delete from puestos where idPuesto = " + busquedaaux + "; ";
			const char* eli = eliminar.c_str();
			q_estado = mysql_query(cn.getconectar(), eli);
			if (!q_estado) {
				cout << " fila eliminada !!!!" << endl;
			}
			else {
				cout << "XXXX error al hacer delete xxxx" << endl;
			}
		}
		else {
			cout << "ERROR EN LA CONEXION!!!!" << endl;

		}
		cn.cerrar_conexion();
	};
	///////////////////////////

	void setPuesto(string pue) { puesto = pue; }


};

