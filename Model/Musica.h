#ifndef MUSICA_H
#define MUSICA_H
#include "Library.h"
class Musica{
    private:
        string nome;
        int duracaomin;
        int duracaoseg;
        string compositor;
    public:
        Musica(): nome(""),duracaomin(0),duracaoseg(0),compositor(""){}
        void set_nome(string a){nome = a;}
        void set_min(int a){duracaomin=a;}
        void set_seg(int a){duracaoseg=a;}
        void set_compositor(string a){compositor = a;}

        string get_tempo(){return "A musica tem "+to_string(duracaomin)+" minutos e "+to_string(duracaoseg)+" segundos";}
        string get_nome(){return nome;}
        string get_compositor(){return compositor;}
        };

#endif