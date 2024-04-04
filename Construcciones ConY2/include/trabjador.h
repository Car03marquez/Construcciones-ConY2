#ifndef TRABJADOR_H
#define TRABJADOR_H
#include<string>
#include"persona.h"

using namespace std;
//clase trabajador
class Trabajador : public Persona {
    private:
        double salarioHora;
        string oficio;
        int brigada;

    public:
        Trabajador(string,string,int,char,string,int);
        int getBrigada();
        double getSalarioHora();
        void setSalarioHora(double);
        string getOficio();
        double operator/(int horas);
        void imprimirDatos();
};

#endif // TRABJADOR_H
