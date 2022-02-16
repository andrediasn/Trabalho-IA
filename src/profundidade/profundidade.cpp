#include "profundidade.h"

Profundidade::Profundidade(){
    this->tabuleiro = new Tabuleiro();
};

Profundidade::~Profundidade(){};

void Profundidade::Run() {
    int score = 0;
    int it = 1;

        this->tabuleiro->Print("profundidade", "INICIO", false);

        while( this->tabuleiro->CountAbertos() > 0 ) {
            this->Iterate( score );

            string abertos;
            for( int i = 0; i < this->tabuleiro->CountAbertos(); i++ )
                abertos = abertos + (i == 0 ? "[":" - [") + to_string(this->tabuleiro->listaAbertos[i]->I()) + "," + to_string(this->tabuleiro->listaAbertos[i]->J()) + "]";

            tabuleiro->Print("profundidade", "ITERACAO " + to_string(it) + " | SCORE " + to_string(score) + " | ABERTOS = { " + abertos + " }");

            it++;
        }

        tabuleiro->Print("profundidade", "FINAL");
    }

 void Profundidade::Iterate( int& score ) {

  int highest = score;
  int highestIndex = 0; 
  int color = 0; 
  Noh* best;

  for( int i = 0; i < tabuleiro->CountAbertos(); i++ ) {
    int sum = 0; 
    int pretos = this->tabuleiro->listaAbertos[i]->getSoma(); 

    sum = 3 - pretos; 

    if( highest < sum ) {
      highest = sum;
      highestIndex = i;
      color = pretos <= 1 ? 1:0; 
    }
  }

  best = this->tabuleiro->listaAbertos[highestIndex];

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
    aux->setFechado(false); 
    this->tabuleiro->listaAbertos.push_back( aux ); 
  }

  aux = best->getDireita();
  if( 
    aux != nullptr &&
    !aux->getCima()->Vazio() && 
    !aux->getDiagonal()->Vazio()
   ) {

     aux->setFechado(false);
     this->tabuleiro->listaAbertos.push_back( aux );

   }

  this->tabuleiro->listaAbertos.erase( this->tabuleiro->listaAbertos.begin() + highestIndex );
  score = highest;
}
 
