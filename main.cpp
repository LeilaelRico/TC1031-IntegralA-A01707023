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
#include "bst.h"
#include "comida.h"

using namespace std;


void menu()
{
    cout<<"\n--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**"<<endl;
    cout<<"1. Mostrar los datos."<<endl;
    cout<<"2. Agrega un alimento."<<endl;
    cout<<"3. Elimina un alimento."<<endl;
    cout<<"4. Terminar con la edicion."<<endl;
    cout<<"--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**"<<endl;
}


void menu1()
{
    cout<<"\n--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**"<<endl;
    cout<<"1. Mostrar los datos."<<endl;
    cout<<"2. Ordenar por calorias."<<endl;
    cout<<"3. Ordenar por nombres."<<endl;
    cout<<"4. Salir."<<endl;
    cout<<"--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**"<<endl;
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

    cout<<"El programa permite editar los datos proporcionados en el .txt, en caso de no querer agregar o eliminar un elemento de la lista,\nsimplemente elija la 'opcion 4' para continuar.\n";

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
                cout<<"Elemento agregado correctamente, para comprobarlo, utilice la 'opcion 1' en el menu."<<endl;

            break;


            case 3:

                lscomid.printL();

                cout<<"Introduzca el numero del elemento a borrar: ";
                cin>>el;

                if (el == 0){
                    cout<<"El encabezado no puede ser borrado, intente con otro elemento."<<endl;
                } else{

                    lscomid.remove(el);
                    cout<<"Elemento eliminado, para comprobarlo, utilice la 'opcion 1' en el menu."<<endl;

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
    ifstream abcalo("cal.txt");
    string nam;
    int cl, i, opc;
    float cb, lp, pt;
    vector<Comida> comid;
    Comida c;
    vector<string> vc;
    BST<int> bst;


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

    ofstream calo("cal.txt");
    string arr[comid.size()];
    int arrint[comid.size()];

    vector<string> orcom;
    Sorts<string> sorts;

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
                        bst.add(comid[i].getCalorias());
                    } 

                    //cout<<bst.inorder();

                    
                    if(calo.is_open()){
                        calo<<bst.inorder()<<endl;
                        calo.close();
                    }
                    else{
                    cout<<"\nError al crear un archivo.\n";
                    }
                    

                    if(abcalo.peek()!=EOF)
                    {
                        for (int i = 0; i < comid.size(); i++)
                        {
                            abcalo >> arrint[i];
                            //cout << arrint[i] << " ";
                        }
                    }

                    ficla.close();


                    for (i = 0; i<comid.size(); i++){
                        for (int j = 0; j<comid.size(); j++){
                            if(arrint[i] == comid[j].getCalorias()){

                                cout<<"\n--------------------------------";
                                cout<<"\nNombre: "<<comid[j].getNombre()<<
                                ", "<<"Calorias: "<<comid[j].getCalorias()<<
                                ", "<<"Carbohidratos: "<<comid[j].getCarbohidratos()<<
                                ", "<<"Lipidos: "<<comid[j].getLipidos()<<
                                ", "<<"Proteinas: "<<comid[j].getProteinas()<<endl;
                            }
                        }
                    }
                                    

                break;


                case 3:

                    for (i = 0; i<comid.size(); i++){
                        arr[i] = {comid[i].getNombre()};
                    }


                    vector<string> originalnom (arr, arr + sizeof(arr) / sizeof(string) );

                    

                    orcom = originalnom;
                    sorts.ordenaMerge(orcom);   


                    for (i = 0; i<orcom.size(); i++){
                        for (int j = 0; j<orcom.size(); j++){
                            if(orcom[i] == comid[j].getNombre()){

                                cout<<"\n--------------------------------";
                                cout<<"\nNombre: "<<comid[j].getNombre()<<
                                ", "<<"Calorias: "<<comid[j].getCalorias()<<
                                ", "<<"Carbohidratos: "<<comid[j].getCarbohidratos()<<
                                ", "<<"Lipidos: "<<comid[j].getLipidos()<<
                                ", "<<"Proteinas: "<<comid[j].getProteinas()<<endl;
                            }
                        }
                    }

                break;


            }
        }
        while(opc != 4);
        cout<<"Salida\n";


    return 0;
}