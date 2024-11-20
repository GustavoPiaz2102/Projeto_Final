#ifndef VIEW_H
#define VIEW_H
#include <string>
#include <iostream>
#include <vector>
#include "../Model/Show.h"
#include "../Model/Banda.h"
#include "../Model/Integrante.h"
#include "../Model/Musica.h"
using namespace std;
//Tem varias funções aqui que não são chamadas mas vou deixar para uma implementação futura pois a maioria sao mensagens de erro
class View {
    public: 
    View() {}
    static void bemvinde() {
        cout << "Bem-vindo(a) a formacao do line-up do Festival!\n";
    }
    static void incorreto() {
        cout << "A opcao inserida e invalida.\n" << endl;
    }
    static void val_invalido(){
        cout << "O valor inserido e invalido.\n" << endl;
    }
    static void sair(){
        cout << "Fim do cadastro. Aproveite o show e até mais!\n" << endl;
    }

    static int menu(){
        int opcao;
        string mensagem = "";

        mensagem += "Digite a opcao que voce deseja: \n";
        mensagem += "1 - Adicionar musicas.\n";
        mensagem += "2 - Adicionar integrantes.\n";
        mensagem += "3 - Adicionar banda.\n";
        mensagem += "4 - Adicionar show!\n";
        mensagem += "5 - Visualizar musicas que irao tocar.\n";
        mensagem += "6 - Visualizar os integrantes.\n";
        mensagem += "7 - Visualizar as bandas.\n";
        mensagem += "8 - Visualizar os shows que acontecerao.\n";
        mensagem += "0 - Sair.\n";
        cout << mensagem << endl;
        cin >> opcao;
        return opcao;
    }

    static void msg_musicas(int n_msg){
        string msg = "";

        switch (n_msg){
            case 1:
            msg = "Tudo certo. A musica foi inserida na lista com sucesso!\n";
            case 2:
            msg = "ERRO! Essa musica ja esta na lista.\n";
        }
        cout << msg << endl;
    }

    static void msg_integrantes(int n_msg){
        string msg = "";
        switch (n_msg){
            case 1:
            msg = "Tudo certo. O integrante foi inserido na lista com sucesso!\n";
            case 2:
            msg = "ERRO! Esse integrante ja esta na lista.\n";
        }
        cout << msg << endl;
    }

    static void msg_banda(int n_msg){
        string msg = "";
        switch (n_msg){
            case 1:
            msg = "Tudo certo. Essa banda foi inserida na lista com sucesso!\n";
            case 2:
            msg = "ERRO! Essa banda ja esta na lista.\n";
        }
        cout << msg << endl;
    }

    static void msg_show(int n_msg){
        string msg = "";
        switch (n_msg){
            case 1:
            msg = "Tudo certo. Esse show foi inserido na lista com sucesso!\n";
            case 2:
            msg = "ERRO! Esse show ja esta na lista.\n";
        }
        cout << msg << endl;
    }
    // Eu tinha que trocar essa comparação com size, ele retorna o valor em bits mas eu to comparando com um inteiro. Todavia por sorte não ta dando problema e eu não sei nem como
    void mostrar_musicas(const vector<Musica*>& Musicas){
        cout << "Aqui estao os dados sobre as musicas!\n";
        if (Musicas.empty()) {
            cout << "Nenhuma musica foi adicionada ainda :(\n";
            } else {
                for (int i = 0;i<Musicas.size();i++){
                    cout << "["+to_string(i)+"]"+" Musica: " +Musicas[i]->get_nome()+ " Compositor: " + Musicas[i]->get_compositor() + " Duracao: " + Musicas[i]->get_tempo() + "\n.";
                }
        }
    }

    void mostrar_integrantes(const vector<Integrante*>& Integrantes){

        cout << "Aqui estao os dados sobre os integrantes!\n";

        if (Integrantes.empty()) {
            cout << "Nenhum integrante foi adicionado a essa banda ainda :(\n";
            } else {
                for(int i = 0;i<Integrantes.size();i++){
                    cout << "["+to_string(i)+"]"+"Nome do integrante: " + Integrantes[i]->get_nome() + " Idade: " + to_string(Integrantes[i]->get_idade()) + " Instrumento: " + Integrantes[i]->get_instrumento() << "\n.";
                }
        }
    }
    void mostrar_bandas(const vector<Banda*>& Bandas){

        cout << "Aqui estao os dados sobre as bandas!\n";

        if (Bandas.empty()) {
            cout << "Nenhuma banda foi adicionada a esse show ainda :(\n";
            } else {
                for(int i = 0;i<Bandas.size();i++){
                    cout << "["+to_string(i)+"]"+"Nome da banda: " + Bandas[i]->get_nome() + "Genero: " << Bandas[i]->get_genero() << "\n";
                }
        }
    }

    void mostrar_shows(const vector<Show*>& Shows){

        cout << "Aqui estao os dados sobre os shows!\n";

        if (Shows.empty()) {
            cout << "Nenhum show foi adicionado ainda :(\n";
            } else {
                for (int i = 0;i<Shows.size();i++){
                    cout << "Nome do show: " + Shows[i]->get_nome() + "\n";
                }
        }
    }
    //Tem alguma função que chama isso?
    //Deveria ter alguma função que chama essa?
    void mostrarTudo(const vector<Musica*>& Musicas, const vector<Integrante*>& Integrantes, const vector<Banda*>& Bandas, const vector<Show*>& Shows){
        mostrar_musicas(Musicas);
        mostrar_integrantes(Integrantes);
        mostrar_bandas(Bandas);
        mostrar_shows(Shows);
    }
};

#endif
