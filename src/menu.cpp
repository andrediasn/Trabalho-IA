#ifndef MENU_INCLUDED
#define MENU_INCLUDED

#include <iostream>
#include <string>
#include "asterisk/asterisk.h"
#include "ordenada/ordenada.h"
#include "tabuleiro/tabuleiro.h"
#include "greedy/greedySearch.h"

using namespace std;

Asterisk* asterisk = new Asterisk();
Ordenada* ordenada = new Ordenada();
GreedySearch* greedy = new GreedySearch();

const int _m_opt_count = 5;
string _m_opts[_m_opt_count] = {
  "Busca em Largura",
  "Busca em Profundidade",
  "Busca Ordenada",
  "Busca Gulosa",
  "Arvore *"
};

void menu_draw() {
  cout << "===== MENU =====" << endl;

  for( int i = 0; i < _m_opt_count; i++ ) {
    cout << i+1 << ". " << _m_opts[i] << endl;
  }

  cout << "0. Exit" << endl;
}

void menu_select( int i ) {
  if( i < 1 || i > _m_opt_count ) return;

  switch( i ) {
    case 3: {
      ordenada->Run();
      break;
    }

    case 4: {
      greedy->Run();
      break;
    }

    case 5: {
      asterisk->Run();
      break;
    }

    default: {
      cout << "Opcao desconhecida" << endl;
      break;
    }
  }
}

int menu_listen() {
  int a;
  cin >> a;

  return a;
}

void menu_loop() {
  int opt = -1;

  do {
    menu_draw();
    opt = menu_listen();
    menu_select(opt);
  } while( opt != 0 );
}

#endif