#ifndef PROFUNDIDADE_H_INCLUDED
#define PROFUNDIDADE_H_INCLUDED

#include <vector>
#include "../tabuleiro/tabuleiro.h"

using namespace std;

class Profundidade {
    public:
        Profundidade();
        ~Profundidade();

        void Run();

    private:
        Tabuleiro* tabuleiro;

        int Iterate( int& level );
};

#endif
