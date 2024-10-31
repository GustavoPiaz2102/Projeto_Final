#ifndef SHOW_H
#define SHOW_H
#include "Library.h"
class Show{
    private:
        string nome;
        string data;
    public:
        string getnome(){return nome;}
        string getdata(){return data;}
        void setnome(string n){nome=n;}
        void setdata(string d){data=d;}
}
#endif