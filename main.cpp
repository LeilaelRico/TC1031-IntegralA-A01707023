/*
main.cpp
ITESM
Campus Querétaro
Programación de Estructuras de Datos y Algoritmos Fundamentales.
Cristian Leilael Rico Espinosa.
Matrícula: A01707023.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <iterator>
#include <string>

#include "sorts.h"
#include "list.h"

using namespace std;

void menu()
{
    cout<<"\n--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**"<<endl;
    cout<<"1. Leer los datos."<<endl;
    cout<<"2. Mostrar los datos."<<endl;
    cout<<"3. Agrega un alimento."<<endl;
    cout<<"4. Elimina un alimento."<<endl;
    cout<<"5. Ordenar los nombres."<<endl;
    cout<<"6. Salir."<<endl;
    cout<<"--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**"<<endl;
}


int main(){
    int op = 0;
    int el;
    List<string>comid;
    string str, comList, nom, cal, car, li, pro, neoCom;
    ifstream myfile ("datost.txt");

    do{
    menu();
    cout<<"Elige una de las opciones: ";
    cin>>op;
        switch(op){


            case 1:

                while(getline(myfile,comList)){
                    if(comList.size() > 0){
                        comid.add(comList);
                    }
                }
                myfile.close();
                cout<<"Datos Cargados"<<endl;

            break;


            case 2:

                comid.printL();
                cout<<endl;

            break;


            case 3:

                cout<<"Especifica el nombre: ";
                cin>>nom;

                cout<<"\nEspecifica las calorias: ";
                cin>>cal;

                cout<<"\nEspecifica los carbohidratos: ";
                cin>>car;

                cout<<"\nEspecifica los lipidos: ";
                cin>>li;

                cout<<"\nEspecifica las proteinas: ";
                cin>>pro;

                /*neoCom = nom + cal + car + li + pro;
                cout<<neoCom;*/

                //cin>>nom>>cal>>car>>li>>pro;
                //cin>>neoCom;

                //cin.ignore(neoCom, ' ');
                getline((cin>>nom)>>cal>>car>>li>>pro,comList);
                getline(cin,comList);
                comid.add(comList);

            break;


            case 4:

                comid.printL();

                cout<<"Introduzca el numero del elemento a borrar: ";
                cin>>el;

                comid.remove(el);

            break;


            case 5:

                cout<<"Algo"<<endl;

            break;


        }


    }
    while(op != 6);
    cout<<"Salida\n";


    return 0;
}
