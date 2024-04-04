#include <iostream>
#include<string>
#include<vector>
#include<queue>
#include"recursoshumanos.h"
#include <fstream>

using namespace std;

int main(){
    char respuesta;
    vector<Trabajador*>b1;
    vector<Trabajador*>b2;
    vector<Trabajador*>b3;
    queue<Persona*>q;
// se cargan los datos almacenados en el fichero
    RecursosHumanos* administrador = new RecursosHumanos(b1,b2,b3,q);
    administrador->leer();
    cout<<"\n";
   cout<<"--------------BIENVENIDO AL SISTEMA DE RECURSOS HUMANOS-----------\n ";
   cout<<"\n";
   while(respuesta!='f'){
    cout<<"\n";
    cout<<"ESCOJA LA OPCION DESEADA:\n";
    cout<<"a- Agregar un trabajador a una brigada.\n"<<"b- Eliminar un trabajador de una brigada.\n"<<"c- Calcular el salario de un trabajdor.\n"<<"d- Mostrar los datos de un trabajdor.\n"<<"e- Mostrar los datos de los trabajdores de una brigada.\n"<<"f- Terminar la interaccion.";
    cout<<"\n";
    cout<<"\n";
    cin>> respuesta;
    cout<< "-----------------------------------------------------------------";
    cout<<"\n";
        if(respuesta=='a'){
            administrador->MenuTrabajador();
        }else if(respuesta=='b'){
            administrador->MenuEliminar();
        }else if(respuesta=='c'){
            administrador->MenuSalario();
        }else if(respuesta=='d'){
            cout<<"Intoduce el CI del trabajador"<<endl;
            string ci;
            cin>>ci;
            Trabajador* t = administrador->buscar(ci);
            if(t!=nullptr){
                t->imprimirDatos();
            }else {
            cout<<"No existe el trabajador"<<endl;
            }
        }else if(respuesta=='e'){
                administrador->trabajadoresBrigada();
        } else if(respuesta=='f'){
            administrador->escribir();
            //cuando el usuario desea salir se guardan todas las modificaciones hechas en el fichero
        }else{
             cout<<"\n";
        }
  }

  return 0;
};
