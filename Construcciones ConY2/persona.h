#ifndef PERSONA_
#define PERSONA_
#include<string>
using namespace std;

//clase persona
class Persona{
    private:
        string ci;
        string nombre;
        int edad;
        char sexo;
    public:
        Persona(string,string,int,char);
        string mostrarPersona();
        string getNombre();
        string getCi();
        int getEdad();
        char getSexo();
};

#endif // PERSONA_
