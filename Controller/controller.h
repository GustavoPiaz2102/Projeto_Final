#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "../Model/Library.h"
#include "../View/view.h"
#include "../Model/Integrante.h"
#include "../Model/Show.h"
#include "../Model/Banda.h"
#include "../Model/Musica.h"

class Controller
{
    private:
        vector<Show *> Shows;
        int finalizar;
        View interface;

    public : 
        Controller() : finalizar(1){}
        void executar()
        {
            while(finalizar)
            {
                switch (interface.menu())
                {
                case 1:
                    
                    break;
                case 2:
                    break;
                case 3:
                    break;
                case 4:
                    break;
                case 5:
                    break;
                case 6:
                    break;
                case 7:
                    break;
                case 8:
                    break;
                case 9:
                    break;
                case 0:
                    finalizar = 0;
                    break;
                default:
                    interface.menu();
                    break;
                }
            }
        }
};
#endif
