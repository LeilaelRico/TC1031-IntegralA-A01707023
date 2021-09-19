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
using namespace std;


void menu()
{
    cout<<"\n--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**"<<endl;
    cout<<"1. Leer los datos."<<endl;
    cout<<"2. Formato."<<endl;
    cout<<"3. Formato."<<endl;
    cout<<"4. Salir."<<endl;
    cout<<"--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**"<<endl;
}


int main(){

    ifstream myfile("datost.txt");
    string nam;
    int cl;
    float cb, lp, pt;
    vector<Comida> comid;
    Comida c;

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

    for (int i = 0; i<comid.size(); i++){
        cout<<"\n--------------------------------";
            cout<<"\nNombre: "<<comid[i].getNombre();
            cout<<"\nCalorias: "<<comid[i].getCalorias();
            cout<<"\nCarbohidratos: "<<comid[i].getCarbohidratos();
            cout<<"\nLipidos: "<<comid[i].getLipidos();
            cout<<"\nProteinas: "<<comid[i].getProteinas();
            cout<<"\n--------------------------------";
    }


    return 0;
}