#pragma once
#include<iostream>
#include "ConexionBD.h"
#include<string.h>
#include<string>


using namespace std;



class Producto {


public: string producto, descripcion, imagen, fechaingreso, idmarca;
	  int existencia = 0;
	  float precio_costo = 0.0, precio_venta = 0.0;

public:
	Producto() {
	}
	Producto(string nprod, string idma, string des, string img, float pcosto, float pventa, int exis, string f_in) {
		
		producto = nprod;
		idmarca = idma;
		descripcion = des;
		imagen = img;
		precio_costo = pcosto;
		precio_venta = pventa;
		existencia = exis;
		fechaingreso = f_in;
	}


	void crear() {
		int q_query;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		string pc = to_string(precio_costo);
		string pv = to_string(precio_venta);
		string e = to_string(existencia);


		if (cn.getconectar()) {
			string insertar = 
			"insert into productos(producto, idmarca, descripcion, imagen, precio_costo, precio_venta, existencia, fechaingreso) values('" + producto + "'," + idmarca + ",'" + descripcion + "','" + imagen + "'," + pc + "," + pv + "," + e + ",'" + fechaingreso + "');";

			const char* i = insertar.c_str();
			q_query = mysql_query(cn.getconectar(), i);
			if (!q_query) {
				cout << "Ingreso exitoso\n";
			}
			else {
				cout << "Error al ingresar!!!!!!!!!!!!!!\n";
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
			string consulta = "select * from productos";
			const char* c = consulta.c_str();
			q_query = mysql_query(cn.getconectar(), c);
			cout << "\n---------- Productos ----------\n";
			cout << "\nidproducto, producto, idmarca, descripcion, imagen, precio_costo, precio_venta, existencia, fechaingreso\n\n";
			if (!q_query) {
				resultado = mysql_store_result(cn.getconectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << " , " << fila[1] << " , " << fila[2] << " , " << fila[3] << " , " << fila[4] << " , " << fila[5] << " , " << fila[6] << " , " << fila[7] << " , " << fila[8] << endl;

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
		int q_estado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		string busqueda = to_string(x);
		if (cn.getconectar()) {
			string selecto = "select *from productos where idproductos=" + busqueda + ";";
			const char* c = selecto.c_str();
			q_estado = mysql_query(cn.getconectar(), c);
			cout << "\n---------- Productos ----------\n";
			cout << "\nidproducto, producto, idmarca, descripcion, imagen, precio_costo, precio_venta, existencia, fechaingreso\n\n";
			if (!q_estado) {
				resultado = mysql_store_result(cn.getconectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << " , " << fila[1] << " , " << fila[2] << " , " << fila[3] << " , " << fila[4] << " , " << fila[5] << " , " << fila[6] << " , " << fila[7] << " , " << fila[8] << endl;

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
		int q_estado = 0;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		int aux;
		cout << "ingrese id a actualizar " << endl;
		cin >> aux;
		string pc = to_string(precio_costo);
		string pv = to_string(precio_venta);
		string e = to_string(existencia);
		string i = to_string(aux);

		if (cn.getconectar()) {
			string update = "update productos SET producto = '" + producto + "', idmarca = '" + idmarca + "', descripcion = '" + descripcion + "',imagen = '" + imagen + "', precio_costo =" + pc + ", precio_venta = " + pv + ", existencia = " + e + ",fechaingreso = '" + fechaingreso + "',where idproducto = " + i + ";";
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
		string id = to_string(x);
		if (cn.getconectar()) {
			string eliminar = "delete from productos where idproductos = " + id+ ";";
			const char* eli = eliminar.c_str();
			q_estado = mysql_query(cn.getconectar(), eli);
			if (!q_estado) {
				cout << " BORRADO EXITOSO !!!!!" << endl;
			}
			else {
				cout << "NO SE PUEDE BORRAR UN REGISTRO QUE ES ES LLAVE PRIMARIA DE UNA LLAVE FORANEA DE OTRA TABLA" << endl;
			}
		}
		else {
			cout << "xxx ERROR DE CONEXION xxx" << endl;
		}
		cn.cerrar_conexion();
	}

	void setProducto(string pro) { producto = pro; }
	void setIDmarca(string id_marca) { idmarca = id_marca; }
	void setDescrip(string des) { descripcion=des; }
	void setIMG(string IMG) {imagen=IMG; }
	void setPrecio_c(float Precio_c) {precio_costo=Precio_c; }
	void setPrecio_v(float Precio_v) { precio_venta=Precio_v; }
	void setEXIST(int EXIST) { existencia=EXIST; }
	void setF_ingre(string F_ingre) { fechaingreso=F_ingre; }
};

