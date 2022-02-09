#ifndef TABULEIRO_H_INCLUDED
#define TABULEIRO_H_INCLUDED
#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include "Noh.h"

using namespace std;

class Tabuleiro {
  public:
    Noh*** matrix;
    list<Noh*> listaAbertos;

    Tabuleiro();
    ~Tabuleiro();

    void Print( string file );
    void Each( void (*callback)(Noh*, int, int) );
    int CountAbertos();

  private:
    int nVazios;
};

#endif