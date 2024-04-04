#include "trabjador.h"
#include<iostream>
#include<string>
using namespace std;
//metodos ClaseTrabajador

Trabajador::Trabajador(string ci,string nombre,int edad,char sexo,string oficio,int brigada): Persona(ci,nombre,edad,sexo){
    this->oficio=oficio;
    this->brigada=brigada;
}

int Trabajador::getBrigada(){
    return brigada;
}
double Trabajador::getSalarioHora(){
    return salarioHora;
}
void Trabajador::setSalarioHora(double salarioBrigada){
    salarioHora=salarioBrigada;
}
string Trabajador::getOficio(){
    return oficio;
}
//sobrecarga de operador/, se usa esta sobrecarga para calcular el salario de un trabajador segun las horas q lleva trabajadas en el mes
double Trabajador::operator/(int horas){
    return salarioHora*horas;
}
void Trabajador::imprimirDatos(){
    cout<<"Nombre: "<< getNombre()<<endl;
    cout<<"Edad: "<< getEdad()<<endl;
    cout<<"Sexo: "<<getSexo()<<endl;
    cout<<"Brigada: "<<getBrigada()<<endl;
    cout<<"Oficio "<<getOficio()<<endl;
}
