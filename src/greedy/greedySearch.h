#ifndef GREEDYSEACH_H_INCLUDED
#define GREEDYSEACH_H_INCLUDED

#include <vector>
#include "../tabuleiro/tabuleiro.h"

using namespace std;

class GreedySearch {
  public:
    GreedySearch();
    ~GreedySearch();

    void Run();

  private:
    Tabuleiro* tabuleiro;

    void Iterate( int& score );
};

#endif