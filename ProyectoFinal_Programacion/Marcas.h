#pragma once
#include<iostream>
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
};

