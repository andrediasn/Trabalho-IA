#include "asterisk.h"

Asterisk::Asterisk(){
  this->tabuleiro = new Tabuleiro();
}

Asterisk::~Asterisk(){};

void Asterisk::Run() {
  int score;
  int it = 1;

  tabuleiro->Print("asterisk", "INICIO", false);

  while( tabuleiro->CountAbertos() > 0 ) {
    this->Iterate( score );
    tabuleiro->Print("asterisk", "ITERACAO " + to_string(it) + " | SCORE " + to_string(score));

    it++;
  }

  tabuleiro->Print("asterisk", "FINAL");
}

void Asterisk::Iterate( int& score ) {
  int highest = score;
  int highestIndex = 0;
  int color = 0;

  // Acha o nó aberto de maior score
  for( int i = 0; i < tabuleiro->CountAbertos(); i++ ) {
    int sum = score;
    int pretos = this->tabuleiro->listaAbertos[i]->getSoma();

    // Adiciona a pontuação referente à heuristica ( numero de peças brancas vizinhas )
    sum += 3 - pretos;

    // Adiciona a pontuação ordenada ( maximizar pretas, logo preta = 1 ponto )
    // Também define a cor que será setada
    if( pretos <= 1 ) {
      sum++;
      color = 1;
    } else color = 0;

    // Seleciona o nó aberto de maior pontuação
    if( highest < sum ) highestIndex = i;
  }

  // Se a maioria for branca, a proxima e preta
  this->tabuleiro->listaAbertos[highestIndex]->setCor(color);

  // Fecha o nó e remove da lista de abertos, atualizando o score atual
  this->tabuleiro->listaAbertos[highestIndex]->setFechado(true);
  this->tabuleiro->listaAbertos.erase( this->tabuleiro->listaAbertos.begin() + highestIndex );
  score = highest;

  // Abre os novos nós
  Noh* aux;
  aux = this->tabuleiro->listaAbertos[highestIndex]->getBaixo();
  if( 
    !aux->getEsquerda()->Vazio() && 
    !aux->getDiagonal()->Vazio()
  ) { 
    this->tabuleiro->listaAbertos.push_back( aux );
    cout << "push baixo" << endl; 
  }

  aux = this->tabuleiro->listaAbertos[highestIndex]->getDireita();
  if( 
    !aux->getCima()->Vazio() && 
    !aux->getDiagonal()->Vazio()
   ) { 
     this->tabuleiro->listaAbertos.push_back( aux );
     cout << "push direita" << endl; 
    }

  cout << "lista size at iteration end " << this->tabuleiro->CountAbertos() << endl;
}