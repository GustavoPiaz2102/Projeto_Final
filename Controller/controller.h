#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "../Model/Library.h"
#include "../View/view.h"
#include "../Model/Integrante.h"
#include "../Model/Show.h"
#include "../Model/Banda.h"
#include "../Model/Musica.h"
#include <string>
#include <unistd.h>
#include <cstdlib>
#include <vector>
#include <iostream>
//#include <SFML/Audio.hpp>
// "Audio.hpp" é uma biblioteca externa e deve ser incluida no include default
// A parte de audio ainda não foi integrada e se for é bom fazer tratamentos para as entradas de audio caso forem feitas pois além do programa da problema no sistema.
// A manipulação de memoria está funcionando bem mas eu não desaloquei ainda.(Perguntar referente a isso para o professor

using namespace std;
class Controller
{
private:
    vector<Show *> Shows;
    int finalizar;
    View interface;

public:
    Controller() : finalizar(1) {}
    int selecionar_show()
    {
        if (!Shows.empty())
        {
            for (int i = 0; i < Shows.size(); i++)
            {
                cout << i << " - " << Shows[i]->get_nome() << endl;
            }
            int a;
            do
            {
                cin >> a;
            } while (a < 0 || a > Shows.size());
            return a;
        }
        else
        {
            cout << "Nao existem shows ainda, Crie um primeiro!\n";
            return -11;
        }
    }
    int selecionar_banda(int indice_show)
    {
        int qnt_bandas = Shows[indice_show]->get_banda().size();
        for (int i = 0; i < qnt_bandas; i++)
        {
            cout << i << " - " << Shows[indice_show]->get_banda()[i]->get_nome() << endl;
        }
        if (!Shows[indice_show]->get_banda().empty())
        {
            int indice_banda;
            do
            {
                cin >> indice_banda;
            } while (indice_banda < 0 || indice_banda > Shows[indice_show]->get_banda().size());
            return indice_banda;
        }
        else
        {
            cout << "Nao existem bandas ainda, Crie uma primeiro!";
        }
        return -11;
    }
    int selecionar_musica(int indice_show, int indice_banda)
    {
        int qnt_musicas = Shows[indice_show]->get_banda()[indice_banda]->get_Musicas().size();
        for (int i = 0; i < qnt_musicas; i++)
        {
            cout << i << " - " << Shows[indice_show]->get_banda()[indice_banda]->get_Musicas()[i] << endl;
        }
        if (!Shows[indice_show]->get_banda()[indice_banda]->get_Musicas().empty())
        {
            int a;
            do
            {
                cin >> a;
            } while (a < 0 || a > Shows[indice_show]->get_banda()[indice_banda]->get_Musicas().size());
            return a;
        }
        else
        {
            cout << "Nao existem musicas ainda, Crie uma primeiro!";
        }
        return -11;
    }
    // Essa bomba devia estar na view, mas acessar a memoria dessas variaveis por lá estava dando problema
    void add_show()
    {
        int s = 0;
        do
        {
            Show *a = new Show();
            string nome;
            int ano, mes, dia;
            cout << "Digite o Nome,Ano,Mes E o dia do show\n";
            cin >> nome >> ano >> mes >> dia;
            a->set_nome(nome);
            a->set_ano(ano);
            a->set_mes(mes);
            a->set_dia(dia);
            Shows.push_back(a);
            cout << "Show Adicionado Com Sucesso!\n";
            cout << "Deseja Adicionar Mais Shows? 1-Sim 2-Nao\n";
            cin >> s;
        } while (s == 1);
    }
    void add_banda(int indice_show)
    {
        int s = 0;
        do
        {
            Banda *a = new Banda();
            string nome, genero;
            cout << "Digite o Nome e o genero da banda\n";
            cin >> nome;
            cin >> genero;
            a->set_nome(nome);
            a->set_genero(genero);
            Shows[indice_show]->set_banda(a);
            cout << "Deseja Adicionar Mais Bandas? 1-Sim 2-Nao\n";
            cin >> s;
        } while (s == 1);
    }
    //A implementação real não depende de um valor entre sim ou não e sim entre 1 e qualquer outro
    void add_musica(int indice_show, int indice_banda)
    {
        int s = 0;
        do
        {
            Musica *a = new Musica();
            string nome, compositor;
            int min, seg;
            cout << "Digite o Nome,Compositor,Minutos e segundos da musica\n";
            cin >> nome >> compositor >> min >> seg;
            a->set_nome(nome);
            a->set_compositor(compositor);
            a->set_min(min);
            a->set_seg(seg);
            Shows[indice_show]->get_banda()[indice_banda]->set_Musicas(a);
            cout << "Deseja adicionar outra musica? 1-Sim 2-Nao\n";
            cin >> s;
        } while (s == 1);
    }

    void add_integrante(int indice_show, int indice_banda)
    {
        int s = 0;
        do
        {
            Integrante *a = new Integrante();
            string nome, instrumento;
            int idade;
            cout << "Digite o Nome,Instrumento e idade do Integrante\n";
            cin >> nome >> instrumento >> idade;
            a->set_nome(nome);
            a->set_instrumento(instrumento);
            a->set_idade(idade);
            Shows[indice_show]->get_banda()[indice_banda]->set_Integrante(a);
            cout << "Deseja adicionar outro Integrante? 1-Sim 2-Nao\n";
            cin >> s;
        } while (s == 1);
    }

    void executar()
    {
        interface.bemvinde();
        while (finalizar)
        {
            int i_show, i_banda;
            switch (interface.menu())
            {
            case 1:
                i_show = selecionar_show();
                if (i_show != -11)
                {
                    i_banda = selecionar_banda(i_show);
                    if (i_banda != -11)
                    {
                        add_musica(i_show, i_banda);
                    }
                }
                break;
            case 2:
                i_show = selecionar_show();
                if (i_show != -11)
                {
                    i_banda = selecionar_banda(i_show);
                    if (i_banda != -11)
                    {
                        add_integrante(i_show, i_banda);
                    }
                }
                break;
            case 3:
                i_show = selecionar_show();
                if (i_show != -11)
                {
                    add_banda(i_show);
                }
                break;
            case 4:
                add_show();
                break;
            case 5:
                i_show = selecionar_show();
                if(i_show!=-11){i_banda = selecionar_banda(i_show);
                 if(i_banda!=-11){interface.mostrar_musicas(Shows[i_show]->get_banda()[i_banda]->get_Musicas());}}
                break;
            case 6:
                i_show = selecionar_show();
                if(i_show!=-11){i_banda = selecionar_banda(i_show);
                if(i_banda!=-11){interface.mostrar_integrantes(Shows[i_show]->get_banda()[i_banda]->get_Integrante());}}
                break;
            case 7:
                i_show = selecionar_show();
                if(i_show!=-11){interface.mostrar_bandas(Shows[i_show]->get_banda());}
                break;
            case 8:
                interface.mostrar_shows(Shows);
                break;
            case 0:
                finalizar = 0;
                break;
            case 9:
                // Testar a implementação disso no Code blocks para ver se eu consigo implementar a biblioteca pois no vscode n ta rolando
                //Biblioteca das musicas
                sleep(2);
                system("color A & curl ascii.live/can-you-hear-me");
                break;
            default:
                break;
            }
        }
    };
};
#endif
