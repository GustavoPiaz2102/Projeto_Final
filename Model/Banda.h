#ifndef BANDA_H
#define BANDA_H
#include "Integrante.h"
#include "Library.h"
#include "Musica.h"
class Banda {
    private:
        string nome;
        string genero;
        vector<Integrante*> vetorIntegrantes; 
        vector<Musica*> Musicas;
    public:
    
        // Nome & Genero

        Banda() : nome(""), genero(""), vetorIntegrantes(), Musicas() {} 
        string get_nome() { return nome; }
        string get_genero() { return genero; }
        void set_nome(string n) { nome = n; }
        void set_genero(string d) { genero = d; }

        // Integrante

        Integrante get_Integrante(int i){return *vetorIntegrantes[i];}
        void set_Integrante(Integrante a,int i){*vetorIntegrantes[i]=a; }

        // Musicas

        Musica get_Musicas(int i){return *Musicas[i];}
        void set_Musicas(int i, Musica a){*Musicas[i] = a; }

        //Outras
        int empty(){
            if(nome == ""&&genero==""&&vetorIntegrantes.empty()&&Musicas.empty())return 1;
            else return 0;
        }
        
};
#endif
