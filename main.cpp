/*
main.cpp

ITESM
Campus Querétaro
Programación de Estructuras de Datos y Algoritmos Fundamentales.

Cristian Leilael Rico Espinosa.
Matrícula: A01707023.
*/

#include "comida.h"
#include "sorts.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
using namespace std;


void menu()
{
    cout<<"\n--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**"<<endl;
    cout<<"1. Leer los datos."<<endl;
    cout<<"2. Mostrar los datos."<<endl;
    cout<<"3. Ordenar los datos."<<endl;
    cout<<"4. Salir."<<endl;
    cout<<"--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**"<<endl;
}


template <class T>
string arrayToString(const vector<T> &v) {
	stringstream aux;

	aux << "[" << v[0];
	for (int i = 1; i < v.size(); i++) {
		aux << ", " << v[i];
	}
	aux << "]";
	return aux.str();
}


int main(){

    ifstream myfile("datost.txt");
    string nam;
    int cl, i, opc;
    float cb, lp, pt;
    vector<Comida> comid;
    Comida c;
    vector<string> vc;
    string arr[27];

    do{
        menu();
        cout<<"Elige una de las opciones: ";
        cin>>opc;

            switch(opc){
                case 1:
                    while(myfile.peek()!=EOF)
                    {

                        if(myfile>>nam>>cl>>cb>>lp>>pt)
                        {
                            c.setNombre(nam);
                            c.setCalorias(cl);
                            c.setCarbohidratos(cb);
                            c.setLipidos(lp);
                            c.setProteinas(pt);
                            comid.push_back(c);
                        }
                    }
                    myfile.close();
                    cout<<"Datos Cargados"<<endl;
                        break;


                case 2:
                    for (i = 0; i<comid.size(); i++){
                        cout<<"\n--------------------------------";
                            cout<<"\nNombre: "<<comid[i].getNombre();
                            cout<<"\nCalorias: "<<comid[i].getCalorias();
                            cout<<"\nCarbohidratos: "<<comid[i].getCarbohidratos();
                            cout<<"\nLipidos: "<<comid[i].getLipidos();
                            cout<<"\nProteinas: "<<comid[i].getProteinas();
                            cout<<"\n--------------------------------";
                    }
                    break;


                case 3:

                    for (i = 0; i<comid.size(); i++){
                        string arr[i] = {comid[i].getNombre()};
                    }

                    vector<string> original1 (arr, arr + sizeof(arr) / sizeof(int) );

                    vector<string> prueba;
                    Sorts<string> sorts;

                    prueba = original1;
                    sorts.ordenaSeleccion(prueba);

                    cout << "\n programa " << arrayToString(prueba) << "\n";



                    break;


            }
        }
        while(opc != 4);
        cout<<"Salida\n";


    return 0;
}
