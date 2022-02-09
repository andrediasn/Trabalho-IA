#include "asterisk.h"

Asterisk::Asterisk(){
  this->tabuleiro = new Tabuleiro();
}

Asterisk::~Asterisk(){};

void Asterisk::Run() {
  while( tabuleiro->CountAbertos() > 0 ) {
    this->Iterate();
  }

  tabuleiro->Print("asterisk");
}

/* void Asterisk::Iterate() {
  list<int> scores;

  for( int i = 0; i < tabuleiro->CountAbertos(); i++ ) {
    int sum = 0;
    int pretos = tabuleiro->listaAbertos[i]->getSoma();
    sum += 3 - pretos;

  }
} */