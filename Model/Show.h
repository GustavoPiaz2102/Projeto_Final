#ifndef SHOW_H
#define SHOW_H
#include "Library.h"
#include "Integrante.h"
class Show{
    private:
        string nome;
        int dia;
        int mes;
        int ano;
    public:
        string get_nome(){return nome;}
        string get_data(){return to_string(dia)+"/"+to_string(mes)+"/"+to_string(ano);}
        void set_nome(string n){nome=n;}
        void set_dia(int d){dia = d;}
        void set_mes(int d){mes = d;}
        void set_ano(int d){ano = d;}
};
#endif 