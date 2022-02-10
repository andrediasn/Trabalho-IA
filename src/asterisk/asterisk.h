#ifndef ASTERISK_H_INCLUDED
#define ASTERISK_H_INCLUDED

#include <vector>
#include "../tabuleiro/tabuleiro.h"

using namespace std;

class Asterisk {
  public:
    Asterisk();
    ~Asterisk();

    void Run();

  private:
    Tabuleiro* tabuleiro;

    void Iterate( int& score );
};

#endif