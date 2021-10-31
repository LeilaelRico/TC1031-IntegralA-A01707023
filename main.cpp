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
    cout<<"1. Mostrar los datos."<<endl;
    cout<<"2. Agrega un alimento."<<endl;
    cout<<"3. Elimina un alimento."<<endl;
    cout<<"4. Salir."<<endl;
    cout<<"--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**"<<endl;
}


void menu1()
{
    cout<<"\n--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**"<<endl;
    cout<<"1. Mostrar los datos."<<endl;
    cout<<"2. Ordenar los nombres."<<endl;
    cout<<"3. Salir."<<endl;
    cout<<"--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**"<<endl;
}


int main(){


    int op = 0;
    int el;
    List<string>lscomid;
    string str, comList, nom, cal, car, li, pro, neoCom;
    ifstream myfile ("datost.txt");


    while(getline(myfile,comList)){
        if(comList.size() > 0){
            lscomid.add(comList);
        }
    }
    myfile.close();
    cout<<"Datos Cargados"<<endl;


    do{
    menu();
    cout<<"Elige una de las opciones: ";
    cin>>op;
        switch(op){


            case 1:

                lscomid.printL();
                cout<<endl;

            break;


            case 2:

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


            case 3:

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
    while(op != 4);
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
                    for (i = 0; i<comid.size(); i++){
                        
                        cout<<"\n--------------------------------";
                        cout<<"\nNombre: "<<comid[i].getNombre()<<
                        ", "<<"Calorias: "<<comid[i].getCalorias()<<
                        ", "<<"Carbohidratos: "<<comid[i].getCarbohidratos()<<
                        ", "<<"Lipidos: "<<comid[i].getLipidos()<<
                        ", "<<"Proteinas: "<<comid[i].getProteinas()<<endl;
                    }
                    break;


                case 2:

                    for (i = 0; i<comid.size(); i++){
                        arr[i] = {comid[i].getNombre()};
                    }

                    /*for (i = 0; i<comid.size(); i++){
                        cout<< i<<" "<<arr[i]<<endl;
                    }*/


                    vector<string> originalnom (arr, arr + sizeof(arr) / sizeof(string) );

                    vector<string> orcom;
                    Sorts<string> sorts;

                    orcom = originalnom;
                    sorts.ordenaMerge(orcom);   


                    for (i = 0; i<orcom.size(); i++){
                        for (int j = 0; j<orcom.size(); j++){
                            if(orcom[i] == comid[j].getNombre()){

                                cout<<"\n--------------------------------";
                                cout<<"\nNombre: "<<comid[j].getNombre()<<
                                ", "<<"Cal: "<<comid[j].getCalorias()<<
                                ", "<<"Carb: "<<comid[j].getCarbohidratos()<<
                                ", "<<"Lip: "<<comid[j].getLipidos()<<
                                ", "<<"Prot: "<<comid[j].getProteinas()<<endl;
                            }
                        }
                    }

                    break;
            }
        }
        while(opc != 3);
        cout<<"Salida\n";


    return 0;
}
