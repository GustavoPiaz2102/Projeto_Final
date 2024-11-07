#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../View/view.h"
#include "../Model/integrante.h"
#include "../Model/Show.h"
#include "../Banda.h"
#include "../Musica.h"

class Controller {
    private: 
    Controller* controller = nullptr;

    public:
    ~Controller(){
        delete Musica;
        delete integrante;
        delete Banda;
        delete Show;
    }
}

