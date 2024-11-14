#ifndef INTEGRANTE_H
#define INTEGRANTE_H
#include "Library.h"
class Integrante {
    private:
        string nome;
        string instrumento;
        int idade;
    public:
        Integrante() : nome(""), instrumento(""), idade(0) {}
        string get_nome() { return nome; }
        string get_instrumento() { return instrumento; }
        int get_idade() { return idade; }

        void set_nome(string a) { nome = a; }
        void set_instrumento(string a) { instrumento = a; }
        void set_idade(int a) { idade = a; }

        int empty(){
            if(nome==""&&instrumento==""&&idade==0)return 1;
            else return 0;
        }


};
#endif
