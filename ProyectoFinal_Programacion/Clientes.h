#pragma once
#include <string.h>
#include <string>
#include <iostream>
#include "Persona.h"
#include "ConexionBD.h"

using namespace std;

class Cliente : public Persona {

private:
	int nit = 0;
	string correo, fechaingreso;

public:
	Cliente() {
	}
	Cliente(string nom,string ape,string dir,string fn,int tel,bool gen,int n,string email,string fechaingre) : Persona(nom,ape,dir,fn,tel,gen){
		
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
				"insert into clientes (nombres,apellidos,nit,genero,telefono,correo_electronico,fechaingreso) values('"+nombres+"', '"+apellidos+"', '55555', 1, '4775', 'miguelsancho@gmail.com', '2022-05-26'); ";
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


};
