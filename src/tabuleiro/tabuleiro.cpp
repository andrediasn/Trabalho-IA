#include "tabuleiro.h"

Tabuleiro::Tabuleiro() {

    // Inicializando matriz de nós
    this->matrix = new node**[6];
    for(int i=0; i<6; i++){
        this->matrix[i] = new node*[6];
    }

    // Carregando estagio inicial do tabuleiro
    // 0 +.
    // Primeira linha 0
    this->matrix[0][0] = new node(0);
    this->matrix[0][1] = new node(0);
    this->matrix[0][2] = new node(1);
    this->matrix[0][3] = new node(0);
    this->matrix[0][4] = new node(0);
    this->matrix[0][5] = new node(0);

    // Primeira coluna 0
    this->matrix[1][0] = new node(1);
    this->matrix[2][0] = new node(0);
    this->matrix[3][0] = new node(0);
    this->matrix[4][0] = new node(1);
    this->matrix[5][0] = new node(1);


    for( int i = 1; i < 6; i++ ){
        for( int j = 1; j < 6; j++ ){
            node* cima = this->matrix[i-1][j];
            node* esquerda = this->matrix[i][j-1];
            node* diagonal = this->matrix[i-1][j-1];
            this->matrix[i][j] = new node(cima, esquerda, diagonal);
        }
    }

    for( int i = 0; i < 6; i++ ) {
        for( int j = 0; j < 6; j++ ) {
          node* baixo = i == 5 ? nullptr : this->matrix[i+1][j];
          node* direita = j == 5 ? nullptr : this->matrix[i][j+1];
          this->matrix[i][j]->setVizinhos(direita, baixo);

          this->matrix[i][j]->SetPos(i,j);
        }
    }

    this->nVazios = 25;
    this->listaAbertos.push_back(this->matrix[1][1]);
}

Tabuleiro::~Tabuleiro(){}

void Tabuleiro::Print( string file, string title, bool append ) {
  ofstream out("Resultados/" + file + ".txt", append ? ios_base::app:ios_base::out);

  if( !title.empty() )
    out << title << endl;

  out << "|---|---|---|---|---|---|" << endl;

  for( int i = 0; i < 6; i++ ) {
    for( int j = 0; j < 6; j++ ) {
      if( j < 5 ) {
        if( this->matrix[i][j]->Vazio() )
          out << "|   ";
        else if( this->matrix[i][j]->getCor() == 1 )
          out << "| X ";
        else if( this->matrix[i][j]->getCor() == 0 )
          out << "| O ";
    } else {
      if( this->matrix[i][j]->Vazio() )
          out << "|   |" << endl;
      else if( this->matrix[i][j]->getCor() == 1 )
        out << "| X |" << endl;
      else if( this->matrix[i][j]->getCor() == 0 )
        out << "| O |" << endl;
      }
    }
    out << "|---|---|---|---|---|---|" << endl;
  }
}

void Tabuleiro::Each( void (*callback)(node*, int, int) ) {
  for( int i = 0; i < 6; i++ )
    for( int j = 0; j < 6; j++ )
      callback( this->matrix[i][j], i, j );
}

int Tabuleiro::CountAbertos() {
  return this->listaAbertos.size();
}