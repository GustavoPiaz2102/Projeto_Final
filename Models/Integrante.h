#ifdef INTEGRANTE_H
#define INTEGRANTE_H
class Integrante{
    private:
        string nome;
        string instrumento;
        int idade;
    public:
        Integrante(): nome(""),intrumento(""),idade(0){}
        string get_nome(){return nome;}
        string get_instrumento(){return instrumento;}
        int get_idade(){return idade;}

        void set_nome(string a){nome = a;}
        void set_intrumento(string a){instrumento = a;}
        void set_idade(int a){idade = a;}
};
#endif