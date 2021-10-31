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
#include <sstream>
#include <cstring>


#include "sorts.h"
#include "list.h"
#include "comida.h"

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


void menu1()
{
    cout<<"\n--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**"<<endl;
    cout<<"1. Opcion libre."<<endl;
    cout<<"2. Mostrar los datos."<<endl;
    cout<<"3. Ordenar los nombres."<<endl;
    cout<<"4. Salir."<<endl;
    cout<<"--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**"<<endl;
}


template <class T>
string arrayToString(const vector<T> &v) {
	stringstream aux;

	aux << "0 " << v[0];
	for (int i = 1; i < v.size(); i++) {
		aux << "\n" << i << " " << v[i];
	}

	return aux.str();
}


int main(){


    int op = 0;
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


    /************************* Uso de clase y ejecución de segundo menú *************************/


    ifstream ficla("datosed.txt");
    string nam;
    int cl, i, opc;
    float cb, lp, pt;
    vector<Comida> comid;
    Comida c;
    vector<string> vc;


    while(ficla.peek()!=EOF)
    {

        if(ficla>>nam>>cl>>cb>>lp>>pt)
        {
            c.setNombre(nam);
            c.setCalorias(cl);
            c.setCarbohidratos(cb);
            c.setLipidos(lp);
            c.setProteinas(pt);
            comid.push_back(c);
        }
    }
    ficla.close();


    string arr[comid.size()];


    do{
        menu1();
        cout<<"Elige una de las opciones: ";
        cin>>opc;

            switch(opc){
                case 1:
                    cout<<"Op Libre"<<endl;
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
                        arr[i] = {comid[i].getNombre()};
                    }

                    for (i = 0; i<comid.size(); i++){
                        cout<< i<<" "<<arr[i]<<endl;
                    }


                    vector<string> originalnom (arr, arr + sizeof(arr) / sizeof(string) );

                    vector<string> orcom;
                    Sorts<string> sorts;

                    orcom = originalnom;
                    sorts.ordenaMerge(orcom);

                    cout << "\nOrdenado:\n" << arrayToString(orcom) << "\n";

                    break;
            }
        }
        while(opc != 4);
        cout<<"Salida\n";


    return 0;
}
