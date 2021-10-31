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
    cout<<"5. Salir."<<endl;
    cout<<"--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**"<<endl;
}


int main(){
    int op = 0, op1 = 0;
    int el;
    List<string>lscomid;
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
                        lscomid.add(comList);
                    }
                }
                myfile.close();
                cout<<"Datos Cargados"<<endl;

            break;


            case 2:

                lscomid.printL();
                cout<<endl;

            break;


            case 3:

                cout<<"Especifica el nombre: ";
                cin>>nom;

                cout<<"Especifica las calorias: ";
                cin>>cal;

                cout<<"Especifica los carbohidratos: ";
                cin>>car;

                cout<<"Especifica los lipidos: ";
                cin>>li;

                cout<<"Especifica las proteinas: ";
                cin>>pro;

                neoCom = nom;
                neoCom.append(" ");
                neoCom.append(cal);
                neoCom.append(" ");
                neoCom.append(car);
                neoCom.append(" ");
                neoCom.append(li);
                neoCom.append(" ");
                neoCom.append(pro);

                lscomid.add(neoCom);
                cout<<"Elemento agregado correctamente, para comprobarlo, utilice la 'opcion 2' en el menu."<<endl;

            break;


            case 4:

                lscomid.printL();

                cout<<"Introduzca el numero del elemento a borrar: ";
                cin>>el;

                if (el == 0){
                    cout<<"El encabezado no puede ser borrado, intente con otro elemento."<<endl;
                } else{

                    lscomid.remove(el);
                    cout<<"Elemento eliminado, para comprobarlo, utilice la 'opcion 2' en el menu."<<endl;

                }

                

            break;


        }


    }
    while(op != 5);
    lscomid.remove(0);
    ofstream final("datosed.txt");
                 if(final.is_open()){
                     final<<lscomid.toString()<<endl;
                     final.close();
                  cout<<"\nEdicion de datos completa.\n";
                 }
                 else{
                   cout<<"\nError al crear un archivo.\n";
                 }


    return 0;
}
