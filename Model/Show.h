#ifndef SHOW_H
#define SHOW_H
#include "Library.h"
#include "Banda.h"
#include <vector>
class Show{
    private:
        string nome;
        int dia;
        int mes;
        int ano;
        vector<Banda*> VetorBandas;
    public:
        Show(): nome(""),dia(0),mes(0),ano(0),VetorBandas() {}
        string get_nome(){return nome;}
        string get_data(){return to_string(dia)+"/"+to_string(mes)+"/"+to_string(ano);}
        Banda get_banda(int i){return *VetorBandas[i];}
        void set_banda(int i, Banda a){*VetorBandas[i]=a;}
        void set_nome(string n){nome=n;}
        void set_dia(int d){dia = d;}
        void set_mes(int d){mes = d;}
        void set_ano(int d){ano = d;}
        int empty(){
            if(nome==""&&dia==0&&mes==0&&ano==0&&VetorBandas.empty())return 1;
            else return 0;
        }
};
#endif 