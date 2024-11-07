#ifndef BANDA_H
#define BANDA_H
#include "Library.h"
#include "Integrante.h"
class Banda{
    private:
        string nome;
        string genero;
        vector<Integrante*> VetorIntegrantes; 

    public:
        Banda(): nome(""), genero(""){} 
        string get_nome(){return nome;}
        string get_genero(){return genero;}
        void set_nome(string n){nome=n;}
        void set_genero(string d){genero=d;}

        string get_nome(int a){return VetorIntegrantes[a].nome;}
        string get_instrumento(int a){return VetorIntegrantes[a].instrumento;}
        int get_idade(int a){return VetorIntegrantes[a].idade;}

        void set_nome(string a,int i){VetorIntegrantes[i].nome = a;}
        void set_intrumento(string a,int i){VetorIntegrantes[i].instrumento = a;}
        void set_idade(int a,int i){VetorIntegrantes[i].idade = a;}
};
#endif