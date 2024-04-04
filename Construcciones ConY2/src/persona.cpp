#include "persona.h"
#include<string>

using namespace std;

//Implementacion de los metodos
Persona::Persona(string ci,string nombre,int edad,char sexo){
    this->ci=ci;
    this->nombre=nombre;
    this->edad=edad;
    this->sexo=sexo;
}
string Persona::mostrarPersona(){
    string mensaje="La persona "+nombre+" de edad: "+ to_string(edad)+" y de sexo: "+sexo;
    return mensaje;
}
string Persona::getNombre(){
    return nombre;
}
string Persona::getCi(){
    return ci;
}
int Persona::getEdad(){
    return edad;
}
char Persona::getSexo(){
    return sexo;
}
