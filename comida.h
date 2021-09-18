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
        float proteinas;

    public:
        Comida(){};
        Comida(string, int, float, float, float){};

        // Getters

        string getNombre(){
            return nombre;
        }

        int getCalorias(){
            return calorias;
        }

        float getCarbohidratos(){
            return carbohidratos;
        }

        float getLipidos(){
            return lipidos;
        }
        
        float getProteina(){
            return proteinas;
        }

        // Setters

        void setNombre(string nm){
            nombre = nm;
        }

        void setCalorias(int cal){
            calorias = cal;
        }

        void setCarbohidratos(float car){
            carbohidratos = car;
        }

        void setLipidos(float lip){
            lipidos = lip;
        }

        void setProteinas(float pro){
            proteinas = pro;
        }

};

#endif /* COMIDA_H_ */