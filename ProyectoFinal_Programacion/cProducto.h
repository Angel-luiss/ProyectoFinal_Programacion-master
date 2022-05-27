#pragma once
#include<iostream>
using namespace std;
class cProducto{
private: string idproducto,idmarca;

public: string nombre_producto, descripcion,imagen,fechaingreso;
		 int existencia=0;
		 float precio_costo=0.0, precio_venta=0.0;

public: 
	cProducto() {
	}
	cProducto(string idprod,string nprod,string idma, string des,string img, float pcosto, float pventa, int exis,string f_in) {
		idproducto = idprod;
		nombre_producto = nprod;
		idmarca = idma;
		descripcion = des;
		imagen = img;
		precio_costo = pcosto;
		precio_venta = pventa;
		existencia = exis;
		fechaingreso = f_in;
	}
};

