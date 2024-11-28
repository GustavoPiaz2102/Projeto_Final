#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <string>
#include <unistd.h>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <limits>
#include "../Model/Library.h"
#include "../View/view.h"
#include "../Model/Integrante.h"
#include "../Model/Show.h"
#include "../Model/Banda.h"
#include "../Model/Musica.h"
// #include <SFML/Audio.hpp>(não é mais usada)
//  "Audio.hpp" é uma biblioteca externa e deve ser incluida no include default(não é mais usada)
//  A parte de audio ainda não foi integrada e se for é bom fazer tratamentos para as entradas de audio caso forem feitas pois além do programa da problema no sistema.
//  A manipulação de memoria está funcionando bem mas eu não desaloquei ainda.(Perguntar referente a isso para o professor)(Ele disse que não necessariamente eu preciso desalocar, talvez eu implemtente depois se tiver tempo)
// O programa parece estar a prova de mamaco, se o Pedro usar sa porra e bugar eu surto

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
                cout << "Selecione um show pelo numero correspondente:\n";
                cin >> a;
                if (cin.fail() || a < 0 || a >= Shows.size())
                {
                    cout << "Entrada invalida. Tente novamente.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                else
                {
                    break;
                }
            } while (true);
            return a;
        }
        else
        {
            cout << "Nao existem shows ainda, crie um primeiro!\n";
            return -11;
        }
    }

    int selecionar_banda(int indice_show)
    {
        int qnt_bandas = Shows[indice_show]->get_banda().size();
        if (qnt_bandas > 0)
        {
            for (int i = 0; i < qnt_bandas; i++)
            {
                cout << i << " - " << Shows[indice_show]->get_banda()[i]->get_nome() << endl;
            }
            int indice_banda;
            do
            {
                cout << "Selecione uma banda pelo numero correspondente:\n";
                cin >> indice_banda;
                if (cin.fail() || indice_banda < 0 || indice_banda >= qnt_bandas)
                {
                    cout << "Entrada invalida. Tente novamente.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                else
                {
                    break;
                }
            } while (true);
            return indice_banda;
        }
        else
        {
            cout << "Nao existem bandas ainda, crie uma primeiro!\n";
            return -11;
        }
    }

    int selecionar_musica(int indice_show, int indice_banda)
    {
        int qnt_musicas = Shows[indice_show]->get_banda()[indice_banda]->get_Musicas().size();
        if (qnt_musicas > 0)
        {
            for (int i = 0; i < qnt_musicas; i++)
            {
                cout << i << " - " << Shows[indice_show]->get_banda()[indice_banda]->get_Musicas()[i]->get_nome() << endl;
            }
            int a;
            do
            {
                cout << "Selecione uma musica pelo numero correspondente:\n";
                cin >> a;
                if (cin.fail() || a < 0 || a >= qnt_musicas)
                {
                    cout << "Entrada invalida. Tente novamente.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }
                else
                {
                    break;
                }
            } while (true);
            return a;
        }
        else
        {
            cout << "Nao existem musicas ainda, crie uma primeiro!\n";
            return -11;
        }
    }

    // Essa bomba devia estar na view, mas acessar a memoria dessas variaveis por lá estava dando problema
void add_show()
    {
        int s = 0;
        do
        {
            Show *a = new Show();
            string nome;
            int ano = 0, mes = 0, dia = 0;
            cout << "Digite o Nome do show:\n";
            getline(cin, nome);
            do{
                
                cout << "Digite um ano para o Show:\n";
                cin >> ano;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }while(cin.fail()||ano<2025||ano>2050);
            do{
                cout<< "Digite um mes para o Show:\n";
                cin>> mes;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }while(cin.fail()||mes<1||mes>12);
            do{
                cout<< "Digite um dia para o Show:\n";
                cin >> dia;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }while(cin.fail()||(dia<1||(dia>28&&mes==2&&ano%4!=0))||(dia>29&&mes==2&&ano%4==0)||(dia>30&&(mes==4||mes==6||mes==9||mes==11))||(dia>31&&(mes==1||mes==3||mes==5||mes==7||mes==8||mes==10||mes==12)));
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
            cin.ignore();
            getline(cin, nome);
            if (nome.empty())
            {
                cout << "Nome invalido. Tente novamente\n";
                continue;
            }
            getline(cin, genero);
            if (genero.empty())
            {
                cout << "Genero invalido. Tente novamente\n";
                continue;
            }
            a->set_nome(nome);
            a->set_genero(genero);
            Shows[indice_show]->set_banda(a);
            cout << "Deseja Adicionar Mais Bandas? 1-Sim 2-Nao\n";
            cin >> s;
            if (cin.fail() || (s != 1 && s != 2))
            {
                cout << "Opcao invalida. Encerrando...\n";
                s = 2;
            }
        } while (s == 1);
    }

    // A implementação real não depende de um valor entre sim ou não e sim entre 1 e qualquer outro
    void add_musica(int indice_show, int indice_banda)
    {
        int s = 0;

        do
        {
            Musica *a = new Musica();
            string nome, compositor;
            int min, seg;

            cout << "Digite o nome da musica:\n";
            cin.ignore();
            getline(cin, nome);
            if (nome.empty())
            {
                cout << "O nome da musica nao pode estar vazio. Tente novamente.\n";
                continue;
            }

            cout << "Digite o compositor:\n";
            getline(cin, compositor);
            if (compositor.empty())
            {
                cout << "O compositor nao pode estar vazio. Tente novamente.\n";
                continue;
            }

            cout << "Digite os minutos e os segundos da musica (ex: 3 45):\n";
            cin >> min >> seg;

            if (cin.fail() || min < 0 || seg < 0 || seg >= 60)
            {
                cout << "Valores invalidos para minutos ou segundos. Minutos devem ser >= 0, e segundos entre 0 e 59.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            a->set_nome(nome);
            a->set_compositor(compositor);
            a->set_min(min);
            a->set_seg(seg);

            Shows[indice_show]->get_banda()[indice_banda]->set_Musicas(a);

            cout << "Deseja adicionar outra musica? (1 - Sim, 2 - Nao)\n";
            cin >> s;

            if (cin.fail() || (s != 1 && s != 2))
            {
                cout << "Opcao invalida. Encerrando...\n";
                s = 2;
            }

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
            cout << "Digite o Nome, Instrumento e Idade do Integrante\n";
            cin.ignore();
            getline(cin, nome);
            if (nome.empty())
            {
                cout << "Nome invalido. Tente novamente\n";
                continue;
            }
            getline(cin, instrumento);
            if (instrumento.empty())
            {
                cout << "Instrumento invalido. Tente novamente\n";
                continue;
            }
            cin >> idade;
            if (cin.fail() || idade <= 0)
            {
                cout << "Idade invalida. Tente novamente\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            a->set_nome(nome);
            a->set_instrumento(instrumento);
            a->set_idade(idade);
            Shows[indice_show]->get_banda()[indice_banda]->set_Integrante(a);
            cout << "Deseja adicionar outro Integrante? 1-Sim 2-Nao\n";
            cin >> s;
            if (cin.fail() || (s != 1 && s != 2))
            {
                cout << "Opcao invalida. Encerrando...\n";
                s = 2;
            }
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
                if (i_show != -11)
                {
                    i_banda = selecionar_banda(i_show);
                    if (i_banda != -11)
                    {
                        interface.mostrar_musicas(Shows[i_show]->get_banda()[i_banda]->get_Musicas());
                    }
                }
                break;
            case 6:
                i_show = selecionar_show();
                if (i_show != -11)
                {
                    i_banda = selecionar_banda(i_show);
                    if (i_banda != -11)
                    {
                        interface.mostrar_integrantes(Shows[i_show]->get_banda()[i_banda]->get_Integrante());
                    }
                }
                break;
            case 7:
                i_show = selecionar_show();
                if (i_show != -11)
                {
                    interface.mostrar_bandas(Shows[i_show]->get_banda());
                }
                break;
            case 8:
                interface.mostrar_shows(Shows);
                break;
            case 9:
                if (!Shows.empty())
                {
                    interface.mostrarTudo(Shows);
                }
                else
                {
                    cout << "Nenhum Show Criado ainda :(\n";
                }
                break;
            case 10:
                // Testar a implementação disso no Code blocks para ver se eu consigo implementar a biblioteca pois no vscode n ta rolando(Na real Precisa n kk)
                system("start wmplayer C:\\Users\\Gustavo\\Desktop\\Projeto_Final\\Model\\Desenvolvimento\\aquelequenaodevesermencionado.mp3");
                system("color A & curl ascii.live/can-you-hear-me");
                break;
            case 23:
            // EU NAO SEI ADICIONAR BIBLIOTECAS EM C++ EU VOU COMETER UM CRIMEE
                system("start wmplayer C:\\Users\\Gustavo\\Desktop\\Projeto_Final\\Model\\Desenvolvimento\\aquelequenaodevesermencionadodoparaguaio.mp3");
                parrot();
                break;

            case 0:
                finalizar = 0;
                break;
            default:
                break;
            }
        }
    };
};
#endif
