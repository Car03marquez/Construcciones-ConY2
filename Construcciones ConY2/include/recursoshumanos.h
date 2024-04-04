#ifndef RECURSOSHUMANOS_H
#define RECURSOSHUMANOS_H
#include "trabjador.h"
#include<string>
#include<vector>
#include<queue>

using namespace std;

class RecursosHumanos{
    private:
        vector<Trabajador*> Brigada1;
        vector<Trabajador*> Brigada2;
        vector<Trabajador*> Brigada3;
        queue<Persona*> Reserva;
    public:
        RecursosHumanos(vector<Trabajador*>,vector<Trabajador*>,vector<Trabajador*>,queue<Persona*>);
        void agregarTrabajador(string,string,int,char,string,int);
        void eliminarTrabajador(string,vector<Trabajador*>*);
        double calcularSalarioTrabajador(int,string);
        void MenuTrabajador();
        void MenuSalario();
        void MenuEliminar();
        Trabajador* buscar(string);
        double calcularSalarioTrabajador(string);
        void trabajadoresBrigada();
        void escribir();
        void leer();
};

#endif // RECURSOSHUMANOS_H
