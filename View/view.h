#infdef VIEW_H
#define VIEW_H
#include <string>
#include <iostream>
#include <vector>
#include "../Models/Show.h"
#include "../Models/Banda.h"
#include "../Models/Integrantes.h"
#include "../Models/Musicas.h"
using namespace std;

class View {
    public: 
    static void bemvinde() {
        cout << "Bem-vindo(a) a formação do line-up do Festival!";
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
        string msg = "";

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
        cout << msg << endl;
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

    string void mostrar_musicas(const vector<musicas*>& Musica){
        string msg = "";
        int x=0;

        msg += "Aqui estao os dados sobre as musicas!\n";

        if (Musicas.empty()) {
            mensagem += "Nenhuma musica foi adicionada ainda :(.";
            } else {
                for (const auto& Musica : Musicas){
                    x++;
                    msg = "Musica: " + to_string(x) + " Compositor: " + to_string(Musica->getMusica()) + "\n.";
                }
                msg += ""
        }
    }

    string void mostrar_integrantes(const vector<integrantes*>& Integrantes){
        string msg = "";
        int x=0;

        msg += "Aqui estao os dados sobre os integrantes!\n";

        if (Integrantes.empty()) {
            mensagem += "Nenhum integrante foi adicionado a essa banda ainda :(.";
            } else {
                for (const auto& Integrante : Integrantes){
                    x++;
                    msg = "Nome do integrante: " + to_string(Integrante->getNome) + " Idade: " + to_string(Integrante->getidade()) + " Instrumento: " + to_string(Integrante->getInstrumento) "\n.";
                }
        }
    }
    string void mostrar_bandas(const vector<bandas*>& Bandas){
        string msg = "";
        int x=0;

        msg += "Aqui estao os dados sobre as bandas!\n";

        if (Bandas.empty()) {
            mensagem += "Nenhuma banda foi adicionada a esse show ainda :(.";
            } else {
                for (const auto& Bandas : Bandas){
                    x++;
                    msg = "Nome da banda: " + to_string(Bandas->getBanda) + "\n";
                }
        }
    }

    string void mostrar_shows(const vector<shows*>& Shows){
        string msg = "";
        int x=0;

        msg += "Aqui estao os dados sobre os shows!\n";

        if (Bandas.empty()) {
            mensagem += "Nenhum show foi adicionado ainda :(.";
            } else {
                for (const auto& Shows : Shows){
                    x++;
                    msg = "Nome do show: " + to_string(Shows->getShow) + "\n";
                }
        }
    }

    static void mostrarTudo(const vector<musicas*>& Musicas, const vector<integrantes*>& Integrantes, const vector<bandas*>& Bandas, const vector<shows*>& Shows){
        mostrar_musicas(Musicas);
        mostrar_integrantes(Integrantes);
        mostrar_bandas(Bandas);
        mostrar_shows(Shows);
    }
};

#endif
