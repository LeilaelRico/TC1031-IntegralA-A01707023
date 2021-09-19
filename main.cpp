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
    cout<<"2. Show the videos with a specific rating or from a specific genre."<<endl;
    cout<<"3. Show the episodes of a specific series with a specific rating."<<endl;
    cout<<"4. Show the movies with a specific rating."<<endl;
    cout<<"5. Rate a video."<<endl;
    cout<<"6. Exit."<<endl;
    cout<<"--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**--**"<<endl;
}


int main(){

    ifstream myfile("datost.txt");
    string nam;
    int cl;
    float cb, lp, pt;
    vector<Comida> comid;
    Comida c;

    while(myfile.peek()!=EOF){

        if(myfile>>nam>>cl>>cb>>lp>>pt)
        {
            c.setNombre(nam);      
            c.setCalorias(cl);
            c.setCarbohidratos(cb);
            c.setLipidos(lp);
            c.setProteinas(pt);
            comid.push_back(c);
            cout<<"\n--------------------------------";
            cout<<"\nNombre: "<<c.getNombre();
            cout<<"\nCalorias: "<<c.getCalorias();
            cout<<"\nCarbohidratos: "<<c.getCarbohidratos();
            cout<<"\nLipidos: "<<c.getLipidos();
            cout<<"\nProteinas: "<<c.getProteinas();
            cout<<"\n--------------------------------";
        }
    }
        myfile.close();


    return 0;
}