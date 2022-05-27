
#include <stdio.h>
#include <iostream>
#include "Empleados.h"
#include <string.h>
#include "Puestos.h"
#include <conio.h>
//nueva libreria, time.h
#include <time.h>




using namespace std;
int x = 0;
int op=0, op2=0, op3=0;
//string calcular_hora();
int main()
{
	string puesto = "";
	int idpuesto = 0;
	bool ciclo = true;

	/*string nombres = "", apellidos = "", direccion = "", dpi = "", fecha_inicio_lab = "", fechaingreso = "", fecha_nac = "";
	int idpuesto = 0, telefono = 0;
	
	bool genero=1;
	
	char genero1;
	bool ciclo = true;*/

	do
	{
		//calcular_hora();
		bool ciclo2 = true;
		cout << "BIENVENIDO AL SISTEMA DE EL_BUEN_ZAPATO" << endl;
		cout << "1. CRUD empleados" << endl;
		cout << "2. CRUD puestos" << endl;
		cout << "3. SALIR" << endl;
		cout << "ELIJA !" << endl;
		cin >> op;

		do {
		switch (op) {
			
			/*	{
		case 1:
			
			bool ciclo3 = true;
			//al cambiar el persona.h el constructor tambien cambió, solo miren como se construye el objeto segun personas.h
			Empleado obj = Empleado(nombres, apellidos, direccion, fecha_nac, telefono, genero, dpi, idpuesto, fecha_inicio_lab, fechaingreso);
			
			cout << "\t\t_________________________________________________" << endl;
			cout << "\t\t-------------- TABLA EMPLEADOS -------------------- " << endl;
			cout << "\t\tINGRESE OPCION" << endl;
			cout << "\t\t1 CREAR" << endl;
			cout << "\t\t2 LEER" << endl;
			cout << "\t\t3 ACTUALIZAR" << endl;
			cout << "\t\t4 ELIMINAR" << endl;
			cout << "\t\t5. SALIR" << endl;
			cout << "\t\tELIJA !" << endl;
			cin >> op2;

			switch (op2) {

				{
			case 1:
				
				cout << "ingrese nombres" << endl;
				cin.ignore();
				getline(cin, nombres);
				cout << "ingrese apellidos" << endl;
				getline(cin, apellidos);
				cout << "ingrese fecha nacimiento" << endl;
				getline(cin, fecha_nac);
				cout << "ingrese direccion" << endl;
				getline(cin, direccion);
				cout << "ingrese telefono" << endl;
				cin >> telefono;
				cout << "ingrese DPI" << endl;
				cin >> dpi;
				cout << "ingrese genero (m = masculino / f = femenino)" << endl;
				cin >> genero1;
				genero = genero1 == 'm' ? 1 : 0;
				
				cout << "ingrese id puesto" << endl;
				cin >> idpuesto;
				cin.ignore();
				cout << "ingrese fecha que inicio labores" << endl;
				getline(cin, fecha_inicio_lab);
				cout << "ingrese fecha/hora ingreso" << endl;
				fechaingreso = calcular_hora();

				obj.setNombre(nombres);
				obj.setApellido(apellidos);
				obj.setDireccion(direccion);
				obj.setTelefono(telefono);
				obj.setGenero(genero);
				obj.setDpi(dpi);
				obj.setIDpuesto(idpuesto);
				obj.setF_nacimiento(fecha_nac);
				obj.setF_inilab(fecha_inicio_lab);
				obj.setF_ingre(fechaingreso);


				obj.crear();
				break;
				}
				{
			case 2:
				system("cls");
				cout << "INFORMACION REVELADA" << endl;
				obj.leer();
				break;
				}
				{
			case 3:
				char eleccion;
				cout << "ingrese id a modificar" << endl;
				cin >> x;
				obj.leer(x);
				cout << "\nDesea modificar ? (s/n): ";
				cin >> eleccion;
				if (eleccion == 'n') {
					break;
				}
			
						cout << "ingrese nombres" << endl;
						cin.ignore();
						getline(cin, nombres);
						cout << "ingrese apellidos" << endl;
						getline(cin, apellidos);
						cout << "ingrese fecha nacimiento" << endl;
						getline(cin, fecha_nac);
						cout << "ingrese direccion" << endl;
						getline(cin, direccion);
						cout << "ingrese telefono" << endl;
						cin >> telefono;
						cout << "ingrese DPI" << endl;
						cin >> dpi;
						cout << "ingrese genero m/f (masculino = n / femenino = f)" << endl;
						cin >> genero1;
						genero = genero1 == 'm' ? 1 : 0;
						cout << "ingrese id puesto" << endl;
						cin >> idpuesto;
						cin.ignore();
						cout << "ingrese fecha que inicio labores" << endl;
						getline(cin, fecha_inicio_lab);
						cout << "fecha-hora en que fue hecho el update: '" << calcular_hora<<"'";
						fechaingreso = calcular_hora();
						obj.setNombre(nombres);
						obj.setApellido(apellidos);
						obj.setDireccion(direccion);
						obj.setTelefono(telefono);
						obj.setGenero(genero);
						obj.setDpi(dpi);
						obj.setIDpuesto(idpuesto);
						obj.setF_nacimiento(fecha_nac);
						obj.setF_inilab(fecha_inicio_lab);
						obj.setF_ingre(fechaingreso);
						obj.actualizar(x);

						system("pause");
						system("cls");
					
			
				break;

				}
				{
			case 4:
				int busqueda = 0;
				cout << "id a eliminar" << endl;
				cin >> x;
				obj.leer(x);
				cout << "ELIMINAR? (1/0)" << endl;
				cin >> busqueda;
					if (busqueda == 1) {
						obj.eliminar(x);
						}
						else {
							cout << "no hiciste nada" << endl;
						}
						break;
				}

				
			case 5:
				
				ciclo2 = false;
				ciclo3 = false;

				break;
				
			}
			break;
			}*/
			{


		case 2:

		bool ciclo3 = true;
		Puestos pu = Puestos(puesto);
		

		cout << "------------------CRUD PUESTOS-------------------------" << endl;
		cout << "\t\t_________________________________________________" << endl;
		cout << "\t\t-------------- TABLA EMPLEADOS -------------------- " << endl;
		cout << "\t\tINGRESE OPCION" << endl;
		cout << "\t\t1 CREAR" << endl;
		cout << "\t\t2 LEER" << endl;
		cout << "\t\t3 ACTUALIZAR" << endl;
		cout << "\t\t4 ELIMINAR" << endl;
		cout << "\t\t5. SALIR" << endl;
		cout << "\t\tELIJA !" << endl;
		cin >> op2;

		switch (op2) {

			{
		case 1:

			cout << "ingrese puesto" << endl;
			cin.ignore();
			getline(cin, puesto);
			

			

			pu.crear();
			break;

			{
		case 2:
			system("cls");
			cout << "INFORMACION REVELADA" << endl;
			pu.leer();
			break;
			}

			{
		case 3:
			char eleccion;
			cout << "ingrese id a modificar" << endl;
			cin >> x;
			pu.leer();
			cout << "\nDesea modificar ? (s/n): ";
			cin >> eleccion;
			if (eleccion == 'n') {
				break;
			}

			cout << "ingrese puesto" << endl;
			cin.ignore();
			getline(cin, puesto);
			pu.actualizar(x);

			system("pause");
			system("cls");


			break;

			}
			{
		case 4:
			int busqueda = 0;
			cout << "id a eliminar" << endl;
			cin >> x;
			pu.leer();
			cout << "ELIMINAR? (1/0)" << endl;
			cin >> busqueda;
			if (busqueda == 1) {
				pu.eliminar(x);
			}
			else {
				cout << "no hiciste nada" << endl;
			}
			break;
			}
			}
		
	}
		return 0;
		break;
			}

			{
	case 5:
		ciclo = false;	
		ciclo2 = false;
		break;
			}
		} 
		} while (ciclo2 != 0);

	
	} while (ciclo!=0);
	
	
	return 0;
}
;
/*
//metodo nuevo
string calcular_hora() {
	time_t now = time(NULL);
	struct tm tm_now;
	localtime_s(&tm_now, &now);
	char buff[100];
	strftime(buff, sizeof(buff), "%Y-%m-%d %H-%M-%S", &tm_now);
	return buff;



};*/