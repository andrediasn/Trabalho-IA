#include "asterisk.h"

Asterisk::Asterisk(){
  this->tabuleiro = new Tabuleiro();
}

Asterisk::~Asterisk(){};

void Asterisk::Run() {
  int score = 0;
  int it = 1;

  this->tabuleiro->Print("asterisk", "INICIO", false);

  while( this->tabuleiro->CountAbertos() > 0 ) {
    this->Iterate( score );
    
    string abertos;
    for( int i = 0; i < this->tabuleiro->CountAbertos(); i++ )
      abertos = abertos + (i == 0 ? "[":" - [") + to_string(this->tabuleiro->listaAbertos[i]->I()) + "," + to_string(this->tabuleiro->listaAbertos[i]->J()) + "]";

    tabuleiro->Print("asterisk", "ITERACAO " + to_string(it) + " | SCORE " + to_string(score) + " | ABERTOS = { " + abertos + " }");

    it++;
  }

  tabuleiro->Print("asterisk", "FINAL");
}

void Asterisk::Iterate( int& score ) {
  int highest = score;
  int highestIndex = 0;
  int color = 0;
  Noh* best;

  // Acha o nó aberto de maior score
  for( int i = 0; i < tabuleiro->CountAbertos(); i++ ) {
    int sum = score;
    int pretos = this->tabuleiro->listaAbertos[i]->getSoma();

    // Adiciona a pontuação referente à heuristica ( numero de peças brancas vizinhas )
    sum += 3 - pretos;

    // Adiciona a pontuação ordenada ( maximizar pretas, logo preta = 1 ponto )
    // Também define a cor que será setada
    if( pretos <= 1 ) sum++;

    // Seleciona o nó aberto de maior pontuação
    if( highest < sum ) {
      highest = sum;
      highestIndex = i;
      color = pretos <= 1 ? 1:0;
      // cout << "found highest: " << i << endl;
    }
  }

  // cout << "highest i: " << highestIndex << endl;
  best = this->tabuleiro->listaAbertos[highestIndex];

  // Se a maioria for branca, a proxima e preta, caso contrario será branca
  best->setCor(color);
  best->setFechado(true);

  // Abre os novos nós
  Noh* aux;
  aux = best->getBaixo();
  if( 
    aux != nullptr &&
    !aux->getEsquerda()->Vazio() && 
    !aux->getDiagonal()->Vazio()
  ) {
    // cout << "get baixo" << endl;
    aux->setFechado(false);
    this->tabuleiro->listaAbertos.push_back( aux );
    // cout << aux << endl;
  }

  aux = best->getDireita();
  if( 
    aux != nullptr &&
    !aux->getCima()->Vazio() && 
    !aux->getDiagonal()->Vazio()
   ) {
    //  cout << "get direita" << endl;
     aux->setFechado(false);
     this->tabuleiro->listaAbertos.push_back( aux );
    //  cout << aux << endl;
   }

  // Remove da lista de abertos, atualizando o score atual
  this->tabuleiro->listaAbertos.erase( this->tabuleiro->listaAbertos.begin() + highestIndex );
  score = highest;
}