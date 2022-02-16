#ifndef LARGURA_H_INCLUDED
#define LARGURA_H_INCLUDED

#include <vector>
#include "../tabuleiro/tabuleiro.h"

using namespace std;

class Largura {
    public:
        Largura();
        ~Largura();

        void Run();

    private:
        Tabuleiro* tabuleiro;

        int Iterate();
};

#endif