#ifndef ORDENADA_H_INCLUDED
#define ORDENADA_H_INCLUDED
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "../tabuleiro/tabuleiro.h"

using namespace std;

class Ordenada{
    private:
        Tabuleiro* tabuleiro;
        void Iterate( int& score );
        void QuickSort(vector<Noh*> *abertos, int inicio, int fim);
        int PartQuick(vector<Noh*> *abertos, int esq, int dir);

    public:
        Ordenada();
        ~Ordenada();

        void Run();


};


#endif // ORDENADA_H_INCLUDED