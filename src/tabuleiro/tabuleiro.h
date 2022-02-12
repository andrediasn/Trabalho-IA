#ifndef TABULEIRO_H_INCLUDED
#define TABULEIRO_H_INCLUDED
#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include "node.h"
#include <vector>

using namespace std;

class Tabuleiro {
  public:
    node*** matrix;
    vector<node*> listaAbertos;

    Tabuleiro();
    ~Tabuleiro();

    void Print( string file, string title = "", bool append = true );
    void Each( void (*callback)(node*, int, int) );
    int CountAbertos();

  private:
    int nVazios;
};

#endif