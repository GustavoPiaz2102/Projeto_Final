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
        Banda() : nome(""), genero(""), vetorIntegrantes() {} 
        string get_nome() { return nome; }
        string get_genero() { return genero; }
        void set_nome(string n) { nome = n; }
        void set_genero(string d) { genero = d; }
        // Integrante
        string get_nome(int a) { return vetorIntegrantes[a]->get_nome(); }
        string get_instrumento(int a) { return vetorIntegrantes[a]->get_instrumento(); }
        int get_idade(int a) { return vetorIntegrantes[a]->get_idade(); }

        void set_nome(string a, int i) { vetorIntegrantes[i]->set_nome(a); }
        void set_instrumento(string a, int i) { vetorIntegrantes[i]->set_instrumento(a); }
        void set_idade(int a, int i) { vetorIntegrantes[i]->set_idade(a); }
        // Musicas
        string get_nome(int a) { return Musicas[a]->get_nome(); }
        string get_genero(int a) { return Musicas[a]->get_tempo(); }
        string get_tempo(int a) { return Musicas[a]->get_compositor(); }

        void set_nome(string a, int i) { Musicas[i]->set_nome(a);}
        void set_minutos(int a, int i) { Musicas[i]->set_min(a);}
        void set_segundos(int a, int i) { Musicas[i]->set_seg(a);}
        void set_compositor(string a, int i) { Musicas[i]->set_compositor(a);}

        
};
#endif
