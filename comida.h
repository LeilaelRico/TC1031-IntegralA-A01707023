/*
comida.h

ITESM
Campus Querétaro
Programación de Estructuras de Datos y Algoritmos Fundamentales.

Cristian Leilael Rico Espinosa.
Matrícula: A01707023.
*/

#ifndef COMIDA_H_
#define COMIDA_H_

#include <iostream>
using namespace std;

class Comida {

    private:

        string nombre;
        int calorias;
        float carbohidratos;
        float lipidos;
        float proteina;

    public:
        Comida(){};
        Comida(string, int, float, float, float){};

};

#endif /* COMIDA_H_ */