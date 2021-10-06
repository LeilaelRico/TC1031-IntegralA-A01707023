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

#include "sorts.h"
#include "list.h"

using namespace std;

void menu()
{
    cout<<"\n--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**"<<endl;
    cout<<"1. Leer los datos."<<endl;
    cout<<"2. Mostrar los datos."<<endl;
    cout<<"3. Ordenar los nombres."<<endl;
    cout<<"4. Salir."<<endl;
    cout<<"--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**"<<endl;
}


int main(){
  vector<string> v;
  Sorts<string> sorts;

    ifstream archivo ("datost.txt");
    vector<string>vc;
    string str;

    while(archivo >> str){
        vc.push_back(str);
    }
    sorts.ordenaMerge(vc);
    copy (vc.begin(),vc.end(),ostream_iterator<string>(cout,"\n"));

  /*int op;

  do{

    menu();
    cin>>op;
        switch(op){
            case 1:
                // Algo
            break;
            case 2:
                // Algo
            break;
        }
    }
    while(op != 3);
    cout<<"Salida\n";*/

    return 0;
}
