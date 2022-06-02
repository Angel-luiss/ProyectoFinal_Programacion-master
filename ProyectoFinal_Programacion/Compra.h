#pragma once
#include "ConexionBD.h"
#include <iostream>
#include <string.h>
#include <time.h>

using namespace std;

class Compra {
	//compra: idCompra(llave)  no_orden_compra  idProveedor(datos proveedor)  fecha_orden(now())   fechaingreso(now())
	//detalle: idCompra_Detalle   idCompra(llave)   idProducto(datos producto)   
	//         cantidad(en base al producto)   precio_costo_unitario(en base al producto)
	//extra: cantidad*costo     total

public: string idCompra, idCompraDetalle, noOrdenCompra, idProveedor;

public: string idProducto;
	  int cantidad = 0;
	  float PrecioCostoUnitario = 0, costo = 0, total = 0;

public:
	Compra() {
	}
	Compra(string idcom, string idcomDet, string noOrCom, string idProv, string idprod, int cant, float precioCU, float cost, float tot) {
		idCompra = idcom;
		idCompraDetalle = idcomDet;
		noOrdenCompra = noOrCom;
		idProveedor = idProv;
		idProducto = idprod;
		cantidad = cant;
		PrecioCostoUnitario = precioCU;
		costo = cost;
		total = tot;
	}

	void ingresoCompras() {
		int q_consulta;
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		ConexionBD cn = ConexionBD();
		
		cn.abrir_conexion();

		if (cn.getconectar()) {
			string consulta = "select proveedor, nit, direccion, telefono from proveedores where idproveedores =" + idProveedor + ";";
			const char* c = consulta.c_str();
			q_consulta = mysql_query(cn.getconectar(), c);
			if (!q_consulta) {
				resultado = mysql_store_result(cn.getconectar());
				fila = mysql_fetch_row(resultado);
				cout << "Nombre del Proveedor: " << fila[0] << endl;
				cout << "Nit: " << fila[1] << endl;
				cout << "Direccion: " << fila[2] << endl;
				cout << "Telefono: " << fila[3] << endl;

			}
			else {
				cout << "Error select";
			}
		}
		else {
			cout << "Error";
		}
		cn.cerrar_conexion();
	}
	   
	void ingresoCompraDet() {
		int q_consulta;
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();

		if (cn.getconectar()) {
			string consulta = "select p.producto, m.marca, p.descripcion, p.existencia, p.fecha_ingreso from productos as p inner join marcas as m on p.idmarca=m.idmarca where idproductos =" + idProducto + ";";
			const char* c = consulta.c_str();
			q_consulta = mysql_query(cn.getconectar(), c);
			if (!q_consulta) {
				resultado = mysql_store_result(cn.getconectar());
				fila = mysql_fetch_row(resultado);
				cout << "Nombre del producto: " << fila[0] << endl;
				cout << "Marca: " << fila[1] << endl;
				cout << "Descripcion: " << fila[2] << endl;
				cout << "existencias: " << fila[3] << endl;
				cout << "Fecha de ingreso: " << fila[4] << endl;
			}
			else {
				cout << "Error select";
			}
		}
		else {
			cout << "Error consulta";
		}
		cn.cerrar_conexion();
	}

	void insertCompra() {
		int q_consulta;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();

		if (cn.getconectar()) {
			//añadir las fechas y hora
			string insertar = "insert into compras(no_orden_compra,idproveedor) values('" + noOrdenCompra + "','" + idProveedor + "');";
			const char* i = insertar.c_str();
			q_consulta = mysql_query(cn.getconectar(), i);
			if (!q_consulta) {
				cout << "Ingreso exitoso\n";
			}
			else {
				cout << "Error al insertar\n";
			}
		}
		else {
			cout << "error conexion\n";
		}
		cn.cerrar_conexion();
	}
	void insertComprasDet() {
		string c = to_string(cantidad);
		string p = to_string(PrecioCostoUnitario);
		int q_consulta;
		ConexionBD cn = ConexionBD();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();

		if (cn.getconectar()) {
			string consulta = "select max(idcompra) from compras;";
			const char* i = consulta.c_str();
			q_consulta = mysql_query(cn.getconectar(), i);
			if (!q_consulta) {
				resultado = mysql_store_result(cn.getconectar());
				fila = mysql_fetch_row(resultado);
				idCompra = fila[0];
			}
			else {
				cout << "error al consultar";
			}

		}
		else {
			cout << "Error al conectar";
		}

		if (cn.getconectar()) {
			string insert = "insert into compras_detalle(idcompra,idproducto,cantidad,precio_costo_unitario) values('" + idCompra + "','" + idProducto + "'," + c + "," + p + ");";
			const char* i = insert.c_str();
			q_consulta = mysql_query(cn.getconectar(), i);
			if (!q_consulta) {
				cout << "Ingreso Exitoso";
			}
			else {
				cout << "Error al insertar;";
			}

		}
		else {
			cout << "Error conexion";
		}
		if (cn.getconectar()) {
			string update = "update productos set existencia=existencia+" + c + ", precio_costo=" + p + " where idproductos=" + idProducto + ";";
			const char* i = update.c_str();
			q_consulta = mysql_query(cn.getconectar(), i);
			if (!q_consulta) {
				cout << "actualizacion exitosa\n";
			}
			else {
				cout << "error al actualiza\n";
			}

		}
		else {
			cout << "Error conexion\n";
		}
		cn.cerrar_conexion();
	}
	void lecturacompra() {
		int q_consulta;
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getconectar()) {
			string consulta = "select c.*, pr.*,p.*,m.*,d.* from compras_detalle as d inner join productos as p on d.idproducto=p.idproductos inner join marcas as m on p.idmarca=m.idmarca inner join compras as c on d.idcompra=c.idcompra inner join proveedores as pr on c.idproveedor = pr.idproveedores;";
			const char* c = consulta.c_str();
			q_consulta = mysql_query(cn.getconectar(), c);
			if (!q_consulta) {
				resultado = mysql_store_result(cn.getconectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << "___________________________________________________\n";
					cout << "Id compra: " << fila[0] << "\t\tNo. orden de compra: " << fila[1] << endl;
					cout << "Proveedores: " << fila[6] << "\t\tNit: " << fila[7] << endl;
					cout << "Direccion: " << fila[8] << "\t\tTelefono: " << fila[9] << endl;
					//cout << "Fecha de orden: " << fila[3] << "\t\tFecha de ingreso: " << fila[4] << endl;
					cout << endl;
					cout << "Detalle de compra: " << fila[21] << endl << "Id Producto: " << fila[10] << endl;
					cout << "Producto: " << fila[11] << "\t\tMarca: " << fila[20] << endl;
					cout << "Descripcion: " << fila[13] << endl;
					cout << "Cantidad: " << fila[24] << "\t\tPrecio c/u: " << fila[25] << endl;
					cout << "___________________________________________________\n";
				}
			}
			else {
				cout << "Error select\n";
			}
		}
		else {
			cout << "Error\n";
		}
		cn.cerrar_conexion();
	}
	void lecturacompra(string idcompra) {
		int q_consulta;
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getconectar()) {
			string consulta = "select c.*, pr.*,p.*,m.*,d.* from compras_detalle as d inner join productos as p on d.idproducto=p.idproductos inner join marcas as m on p.idmarca=m.idmarca inner join compras as c on d.idcompra=c.idcompra inner join proveedores as pr on c.idproveedor = pr.idproveedores where c.no_orden_compra=" + idcompra + ";";
			const char* c = consulta.c_str();
			q_consulta = mysql_query(cn.getconectar(), c);
			if (!q_consulta) {
				resultado = mysql_store_result(cn.getconectar());
				while (fila = mysql_fetch_row(resultado)) {
					cout << "___________________________________________________\n";
					cout << "Id compra: " << fila[0] << "\t\tNo. orden de compra: " << fila[1] << endl;
					cout << "Proveedores: " << fila[6] << "\t\tNit: " << fila[7] << endl;
					cout << "Direccion: " << fila[8] << "\t\tTelefono: " << fila[9] << endl;
					//cout << "Fecha de orden: " << fila[3] << "\t\tFecha de ingreso: " << fila[4] << endl;
					cout << endl;
					cout << "Detalle de compra: " << fila[21] << endl << "Id Producto: " << fila[10] << endl;
					cout << "Producto: " << fila[11] << "\t\tMarca: " << fila[20] << endl;
					cout << "Descripcion: " << fila[13] << endl;
					cout << "Cantidad: " << fila[24] << "\t\tPrecio c/u: " << fila[25] << endl;
					cout << "___________________________________________________\n";
				}
			}
			else {
				cout << "Error select\n";
			}
		}
		else {
			cout << "Error\n";
		}
		cn.cerrar_conexion();
	}

	void eliminar(string NoOrdenCOmpra) {
		int q_consulta;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();
		if (cn.getconectar()) {
			string elim = "delete compras_detalle,compras from compras_detalle inner join compras on compras_detalle.idcompra=compras.idcompra where compras.no_orden_compra=" + NoOrdenCOmpra + ";";
			const char* i = elim.c_str();
			q_consulta = mysql_query(cn.getconectar(), i);
			if (!q_consulta) {
				cout << "Eliminacion exitosa\n";
			}
			else {
				cout << "Error al ingresar\n";
			}
		}
		cn.cerrar_conexion();
	}
	void actualizarcompra(string idcompra) {
		int q_consulta;
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();

		if (cn.getconectar()) {
			string update = "update compras set idproveedor='" + idProveedor + "' where no_orden_compra='" + idcompra + "';";
			const char* i = update.c_str();
			q_consulta = mysql_query(cn.getconectar(), i);
			if (!q_consulta) {
				cout << "actualizacion exitosa\n";
			}
			else {
				cout << "error al actualiza\n";
			}

		}
		else {
			cout << "Error conexion\n";
		}
		cn.cerrar_conexion();

	}
	void actualizardet(string idcompradet) {
		int q_consulta;
		string c = to_string(cantidad);
		string p = to_string(PrecioCostoUnitario);
		ConexionBD cn = ConexionBD();
		cn.abrir_conexion();

		if (cn.getconectar()) {
			string update = "update compras_detalle set idproducto=" + idProducto + ",cantidad=" + c + ",precio_costo_unitario=" + p + "where idcompra_detalle=" + idcompradet + " ;";
			const char* i = update.c_str();
			q_consulta = mysql_query(cn.getconectar(), i);
			if (!q_consulta) {
				cout << "actualizacion exitosa\n";
			}
			else {
				cout << "error al actualiza\n";
			}

		}
		else {
			cout << "Error conexion\n";
		}
		cn.cerrar_conexion();
	}


};

