#pragma once
#include <string.h>
#include <string>
#include <iostream>
#include "Persona.h"
#include "ConexionBD.h"
#include <mysql.h>

using namespace std;


class Cliente : public Persona {

private:
	
	string correo, fechaingreso,nit;

public:
	Cliente() {
	}
	Cliente(string nom,string ape,string dir,string fn,int tel,bool gen,string n,string email,string fechaingre) : Persona(nom,ape,dir,fn,tel,gen){
		
		nit = n;
		correo = email;
		fechaingreso = fechaingre;
	}

	void crear() {
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		string tel = to_string(telefono);
		string gen_aux = to_string(genero);

		if (cn.getconectar()) {
			string insert =
				"insert into clientes (nombres,apellidos,nit,genero,telefono,correo_electronico,fechaingreso) values('"+nombres+"', '"+apellidos+"', '"+nit+"',"+gen_aux+", '"+tel+"', '"+correo+"', '"+fechaingreso+"'); ";
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getconectar(), i);
			if (!q_estado) {
				cout << "ingreso exitoso !!!!!!!!" << endl;
			}
			else {
				cout << "xxx ERROR AL HACER INSERT xxx" << endl;
			}
		}
		else {
			cout << " xxx ERROR en LA CONEXION xxx" << endl;
		}
		cn.cerrar_conexion();
	}

	void leer() {
		int q_estado = 0;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		cout << "id_c" <<" | " << "nombres" << " | " << "apellidos" << " | " << "NIT" << " | " << "genero" << " | " << "telefono" << " | " << "correo electronico" << " | " << "fecha_ing" << endl;
		if (cn.getconectar()) {
			string select = "select *from clientes;";
			const char* sele = select.c_str();
			q_estado = mysql_query(cn.getconectar(), sele);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getconectar());
				while (fila = mysql_fetch_row(resultado)) {
					for (int i = 0; i <= 7; i++) {
						cout << fila[i] << ",";
					}
					cout << endl;
				}
			}
			else {
				cout << " xxx ERROR AL HACER :: select xxx " << endl;
			}
		}
		else {
			cout << " xxx ERROR DE CONEXION xxx" << endl;
		}
		cn.cerrar_conexion();
	}
	
	void leer(int x) {
		int q_estado = 0;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		string auxbuscar = to_string(x);
		cn.abrir_conexion();
		cout << "id_c" << " | " << "nombres" << " | " << "apellidos" << " | " << "NIT" << " | " << "genero" << " | " << "telefono" << " | " << "correo electronico" << " | " << "fecha_ing" << endl;
		if (cn.getconectar()) {
			string select = "select *from clientes where idclientes = "+auxbuscar+";";
			const char* sele = select.c_str();
			q_estado = mysql_query(cn.getconectar(), sele);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getconectar());
				while (fila = mysql_fetch_row(resultado)) {
					for (int i = 0; i <= 7; i++) {
						cout << fila[i] << " , ";
					}
					cout << endl;
				}
			}
			else {
				cout << " xxx ERROR AL HACER :: select xxx " << endl;
			}
		}
		else {
			cout << " xxx ERROR DE CONEXION xxx" << endl;
		}
		cn.cerrar_conexion();
	}

	void actualizar(int x) {

		int q_estado = 0;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();

		string tel = to_string(telefono);
		string gentext = to_string(genero);
		string auxbuscar = to_string(x);
		if (cn.getconectar()) {
			string update = "update clientes SET nombres='" + nombres + "', apellidos='" + apellidos + "',nit='" + nit + "',genero=" + gentext + ",telefono='" + tel + "',correo_electronico='" + correo + "',fechaingreso='" + fechaingreso + "' where idclientes = " + auxbuscar + ";";
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
			cout << " XXX ERROR DE CONEXION xXx" << endl;
		}
		cn.cerrar_conexion();
		}

	void eliminar(int x) {
		int q_estado;
		
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		string where = to_string(x);
		if (cn.getconectar()) {
			string eliminar = "delete from clientes where idclientes = " + where + ";";
			const char* eli = eliminar.c_str();
			q_estado = mysql_query(cn.getconectar(), eli);
			if (!q_estado) {
				cout << " BORRADO EXITOSO !!!!!" << endl;
			}
			else {
				cout << " xxx ERROR al hacer DELETE xxx " << endl;
			}
		}
		else {
			cout << "xxx ERROR DE CONEXION xxx" << endl;
		}
		cn.cerrar_conexion();

	}

	void setNombre(string nom) { nombres = nom; };
	void setApellido(string ape) { apellidos=ape; };
	void setNit(string NIT) { nit = NIT; };
	void setGen(bool gen) { genero = gen; };
	void setTelefono(int tel) {telefono=tel; };
	void setE_mail(string E_mail) { correo=E_mail; };
	void setFecha_in(string Fecha_in) { fechaingreso=Fecha_in; };
};
