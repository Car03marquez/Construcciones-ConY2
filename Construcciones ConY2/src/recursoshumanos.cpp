#include "recursoshumanos.h"
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include <fstream>

using namespace std;

//metodos RecursosHumanos
RecursosHumanos::RecursosHumanos(vector<Trabajador*> B1,vector<Trabajador*> B2,vector<Trabajador*> B3,queue<Persona*> r){
    this->Brigada1=B1;
    this->Brigada2 =B2;
    this->Brigada3=B3;
    this->Reserva=r;

}

//Agrega un nuevo trabajador por default cada compa�ia tiene un maximo de 10 personas si pasa eso se va al reten
//la brigada 1 gana 155 pesos la hora,la 2 serian 375 y la 3 gana 260
void RecursosHumanos::agregarTrabajador(string ci,string nombre,int edad,char sexo,string oficio,int brigada){

    Trabajador* nuevo = new Trabajador(ci,nombre,edad,sexo,oficio,brigada);

    if(brigada>3 || brigada<1){
        cout<<"No existe la brigada"<<endl;
        delete(nuevo);
        return;
    }else{
        if(brigada==1 && Brigada1.size()<5 ){
            nuevo->setSalarioHora(155);
            Brigada1.push_back(nuevo);
            cout<<"trabajador agregado correctamente"<<endl;
        }else if(brigada==2 && Brigada2.size()<5 ){
            nuevo->setSalarioHora(375);
            Brigada2.push_back(nuevo);
            cout<<"trabajador agregado correctamente"<<endl;
        }else if(brigada==3 && Brigada3.size()<5){
            nuevo->setSalarioHora(260);
            Brigada3.push_back(nuevo);
            cout<<"trabajador agregado correctamente"<<endl;
        }else{
            //la persona tiene la opcion de colocarse en la recerva si asi los desea o de intentar buscar trabajo en otras brigadas
            Persona* p = new Persona(ci,nombre,edad,sexo);
            delete(nuevo);
            cout<<"Brigada llena"<<endl;
            cout<<"Marque 1 si desea agregar esta solicitud a la reserva y cualquier otra tecla en caso contrario"<<endl;
            string opcion;
            cin>>opcion;
            if(opcion=="1"){
                Reserva.push(p);
                cout<<"Solicitud agregada a la reserva correctamente"<<endl;
            } else{
                delete(p);
            }
        }
    }
}

//calcular el salario de un trabajador
double RecursosHumanos::calcularSalarioTrabajador(string ci){
    Trabajador* t = buscar(ci);
    if(t == nullptr){
        cout<<"Este trabajador no existe"<<endl;
        return 0;
    } else {
        cout<<"Intoduce las horas de trabajo acumuladas en el mes"<<endl;
        int horas;
        cin>>horas;
        return (*t)/horas;
        // se utilizo la recarga de operadores programada en la clase trabajador
    }
}

//elimina una persona de la brigada seleccionada y se agrega en esa brigada algun trabajador de la reserva en caso de q la reserva no este vacia

void RecursosHumanos::eliminarTrabajador(string ci,vector<Trabajador*>* brigada){
    for (auto it = (*brigada).begin(); it != (*brigada).end(); it++) {
            if ((*it)->getCi() == ci) {
                it = (*brigada).erase(it);
                cout<< "Trabajador con CI: '" << ci << "' eliminado de la lista." <<endl;
                if(!Reserva.empty()){
                cout<< "Se agregaran a la brigada una persona de la reserva"<<endl;
                Persona* p = Reserva.front();
                Reserva.pop();
                agregarTrabajador(p->getCi(),p->getNombre(),p->getEdad(),p->getSexo(),(*it)->getOficio(),(*it)->getBrigada());
                }
                return;
            }
        }

        cout << "Trabajador con CI: '" << ci << "' no encontrado en la lista." <<endl;

}
// lista de personas y datos de las mismas
void RecursosHumanos::trabajadoresBrigada(){
    cout<<""<<endl;
    int brigada;
    cout<<"Introduce el numero de la brigada"<<endl;
    cin>>brigada;
    if(brigada>3 || brigada<1){
        cout<<"No existe la brigada"<<endl;
    }else{
        if(brigada==1){
            for (auto it = Brigada1.begin(); it != Brigada1.end(); it++) {
                (*it)->imprimirDatos();
                cout<<""<<endl;
            }
        }else if(brigada==2 ){
            for (auto it = Brigada2.begin(); it != Brigada2.end(); it++) {
                (*it)->imprimirDatos();
                cout<<""<<endl;
            }
        }else {
            for (auto it = Brigada3.begin(); it != Brigada3.end(); it++) {
                (*it)->imprimirDatos();
                cout<<""<<endl;
            }
        }
    }
}

Trabajador* RecursosHumanos::buscar(string ci){
        for(auto it = Brigada1.begin(); it!=Brigada1.end();it++){
            if((*it)->getCi()==ci){
                return *it;
            }
        }
        for(auto it = Brigada2.begin(); it!=Brigada2.end();it++){
            if((*it)->getCi()==ci){
                return *it;
            }
        }
        for(auto it = Brigada3.begin(); it!=Brigada3.end();it++){
            if((*it)->getCi()==ci){
                return *it;
            }
        }
    return nullptr;
}

//Menu eliminar
void RecursosHumanos::MenuEliminar(){
    int brigada;
    string ci;
    cout<<"ingrese el CI de el trabajador y el numero de la brigada a la que pertence";
    cout<<"\n";
    cin>>ci;
    cin>>brigada;
    if(brigada==1){
        eliminarTrabajador(ci,&Brigada1);
    }else if(brigada==2){
        eliminarTrabajador(ci,&Brigada2);
    }else if(brigada==3){
        eliminarTrabajador(ci,&Brigada3);
    }else{
        cout<<"la brigada no existe"<<endl;
    }
}

//Menu Trabajador
 void RecursosHumanos::MenuTrabajador(){
    string ci,nombre,oficio;
    int edad,brigada;
    char sexo;
    cout<<"Ingrese los datos del trabajador(ci,nombre,edad,sexo,oficio,brigada):";
    cout<<"\n";
    cin>>ci;
    cin>>nombre;
    cin>>edad;
    cin>>sexo;
    cin>>oficio;
    cin>>brigada;
    agregarTrabajador(ci,nombre,edad,sexo,oficio,brigada);
}

//Menu Salario
void RecursosHumanos::MenuSalario(){
    cout<<""<<endl;
    string ci;
    cout<<"Por favor, ingrese el ci del Trabajador del que desea saber su salario"<<endl;
    cin>>ci;
    double s =calcularSalarioTrabajador(ci);
    if(s!=0){
        cout<<"El salario del trabajador de CI "<< ci <<" es de "<< s << " pesos"<<endl;
    }

}

void RecursosHumanos::leer(){
    ifstream fichero("Trabajadores.txt");
    Persona* p;
    int cant;
    string linea;
    int brigada;
    char sexo;
    string oficio;
    int edad;
    string nombre;
    string ci;
    getline(fichero,linea);
    cant = stoi(linea);
    for(int i = 0; i<cant; i++){
        getline(fichero,ci);
        getline(fichero,nombre);
        getline(fichero,linea);
        edad = stoi(linea);
        getline(fichero,linea);
        sexo = linea[0];
        getline(fichero,oficio);
        getline(fichero,linea);
        brigada = stoi(linea);
        agregarTrabajador(ci,nombre,edad,sexo,oficio,brigada);
    }
    getline(fichero,linea);
    cant = stoi(linea);
    for(int i = 0; i<cant; i++){
        getline(fichero,ci);
        getline(fichero,nombre);
        getline(fichero,linea);
        edad = stoi(linea);
        getline(fichero,linea);
        sexo = linea[0];
        getline(fichero,oficio);
        getline(fichero,linea);
        brigada = stoi(linea);
        agregarTrabajador(ci,nombre,edad,sexo,oficio,brigada);
    }
    getline(fichero,linea);
    cant = stoi(linea);
    for(int i = 0; i<cant; i++){
        getline(fichero,ci);
        getline(fichero,nombre);
        getline(fichero,linea);
        edad = stoi(linea);
        getline(fichero,linea);
        sexo = linea[0];
        getline(fichero,oficio);
        getline(fichero,linea);
        brigada = stoi(linea);
        agregarTrabajador(ci,nombre,edad,sexo,oficio,brigada);
    }
    getline(fichero,linea);
    cant = stoi(linea);
    for(int i = 0; i<cant; i++){
        getline(fichero,ci);
        getline(fichero,nombre);
        getline(fichero,linea);
        edad = stoi(linea);
        getline(fichero,linea);
        sexo = linea[0];
        p = new Persona(ci,nombre,edad,sexo);
        Reserva.push(p);
    }
}
//
void RecursosHumanos::escribir(){
    ofstream fichero("Trabajadores.txt");
    fichero<<Brigada1.size()<<endl;
    for(auto it = Brigada1.begin(); it!=Brigada1.end();it++){
            fichero<<(*it)->getCi()<<endl;
            fichero<<(*it)->getNombre()<<endl;
            fichero<<(*it)->getEdad()<<endl;
            fichero<<(*it)->getSexo()<<endl;
            fichero<<(*it)->getOficio()<<endl;
            fichero<<(*it)->getBrigada()<<endl;
        }
        fichero<<Brigada2.size()<<endl;
        for(auto it = Brigada2.begin(); it!=Brigada2.end();it++){
            fichero<<(*it)->getCi()<<endl;
            fichero<<(*it)->getNombre()<<endl;
            fichero<<(*it)->getEdad()<<endl;
            fichero<<(*it)->getSexo()<<endl;
            fichero<<(*it)->getOficio()<<endl;
            fichero<<(*it)->getBrigada()<<endl;
        }
        fichero<<Brigada3.size()<<endl;
        for(auto it = Brigada3.begin(); it!=Brigada3.end();it++){
            fichero<<(*it)->getCi()<<endl;
            fichero<<(*it)->getNombre()<<endl;
            fichero<<(*it)->getEdad()<<endl;
            fichero<<(*it)->getSexo()<<endl;
            fichero<<(*it)->getOficio()<<endl;
            fichero<<(*it)->getBrigada()<<endl;
        }
        Persona* p;
        fichero<<Reserva.size()<<endl;
        while(!Reserva.empty()){
             p = Reserva.front();
             Reserva.pop();
            fichero<<p->getCi()<<endl;
            fichero<<p->getNombre()<<endl;
            fichero<<p->getEdad()<<endl;
            fichero<<p->getSexo()<<endl;
        }
}
