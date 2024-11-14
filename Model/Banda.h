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

        vector<Integrante*> get_Integrante(){return vetorIntegrantes;}
        void set_Integrante(Integrante *a){vetorIntegrantes.push_back(a); }

        // Musicas

        vector<Musica*> get_Musicas(){return Musicas;}
        void set_Musicas(Musica *a){Musicas.push_back(a); }

        //Outras
        int empty(){
            if(nome == ""&&genero==""&&vetorIntegrantes.empty()&&Musicas.empty())return 1;
            else return 0;
        }
        
};
#endif
