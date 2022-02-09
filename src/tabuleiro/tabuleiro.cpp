#include "tabuleiro.h"

/* Tabuleiro::Tabuleiro() {
    this->matrix = new Noh**[6];

    for(int i=0; i<6; i++){
        this->matrix[i] = new Noh*[6];
    }

    // for( int i = 0; i < 6; i++ )
    //     for( int j = 0; j < 6; j++ )
    //         this->matrix[i][j] = new Noh;

    this->matrix[0][0] = new Noh(0);
    this->matrix[0][1] = new Noh(0);
    this->matrix[0][2] = new Noh(1);
    this->matrix[0][3] = new Noh(0);
    this->matrix[0][4] = new Noh(0);
    this->matrix[0][5] = new Noh(0);

    // Primeira coluna
    this->matrix[1][0] = new Noh(1);
    this->matrix[2][0] = new Noh(0);
    this->matrix[3][0] = new Noh(0);
    this->matrix[4][0] = new Noh(1);
    this->matrix[5][0] = new Noh(1);

    this->nAbertos = 1;
} */

Tabuleiro::Tabuleiro() {

    // Inicializando matriz de nós
    this->matrix = new Noh**[6];
    for(int i=0; i<6; i++){
        this->matrix[i] = new Noh*[6];
    }

    // Carregando estagio inicial do tabuleiro
    // 0 +.
    // Primeira linha 0
    this->matrix[0][0] = new Noh(0);
    this->matrix[0][1] = new Noh(0);
    this->matrix[0][2] = new Noh(1);
    this->matrix[0][3] = new Noh(0);
    this->matrix[0][4] = new Noh(0);
    this->matrix[0][5] = new Noh(0);

    // Primeira coluna 0
    this->matrix[1][0] = new Noh(1);
    this->matrix[2][0] = new Noh(0);
    this->matrix[3][0] = new Noh(0);
    this->matrix[4][0] = new Noh(1);
    this->matrix[5][0] = new Noh(1);


    for( int i = 1; i < 6; i++ ){
        for( int j = 1; j < 6; j++ ){
            Noh* cima = this->matrix[i-1][j];
            Noh* esquerda = this->matrix[i][j-1];
            Noh* diagonal = this->matrix[i-i][j-i];
            this->matrix[i][j] = new Noh(cima, esquerda, diagonal);
        }
    }

    for( int i = 1; i < 6; i++ ){
        for( int j = 1; j < 6; j++ ){
            Noh* cima = this->matrix[i-1][j];
            Noh* esquerda = this->matrix[i][j-1];
            Noh* diagonal = this->matrix[i-i][j-i];
            this->matrix[i][j] = new Noh(cima, esquerda, diagonal);
        }
    }

    for( int i = 0; i < 5; i++ ){
        for( int j = 0; j < 5; j++ ){
            Noh* baixo = this->matrix[i+1][j];
            Noh* direita = this->matrix[i][j+1];
            this->matrix[i][j]->setVizinhos(baixo, direita);
        }
    }

    this->nVazios = 25;
    this->listaAbertos.push_back(this->matrix[1][1]);
}

Tabuleiro::~Tabuleiro(){}

/* void Tabuleiro::Print( string file ) {
  ofstream out("Resultados/" + file + ".txt");
  out << "|---|---|---|---|---|---|" << endl;

  for( int i = 0; i < 6; i++ ) {
    for( int j = 0; j < 6; j++ ) {
      if( j < 5 ) {
        if( this->matrix[i][j] == 1 )
          out << "| X ";
        else if( this->matrix[i][j] == -1 )
          out << "| O ";
        else if( this->matrix[i][j] == 0 ) 
          out << "|   ";
    } else {
      if( this->matrix[i][j] == 1 )
        out << "| X |" << endl;
      else if( this->matrix[i][j] == -1 )
        out << "| O |" << endl;
      else if( this->matrix[i][j] == 0 ) 
        out << "|   |" << endl;
      }
    }
    out << "|---|---|---|---|---|---|" << endl;
  }
} */

void Tabuleiro::Print( string file ) {
  ofstream out("Resultados/" + file + ".txt");
  out << "|---|---|---|---|---|---|" << endl;

  for( int i = 0; i < 6; i++ ) {
    for( int j = 0; j < 6; j++ ) {
      if( j < 5 ) {
        if( this->matrix[i][j]->getCor() == 1 )
          out << "| X ";
        else if( this->matrix[i][j]->getCor() == 0 )
          out << "| O ";
        else 
          out << "|   ";
    } else {
      if( this->matrix[i][j]->getCor() == 1 )
        out << "| X |" << endl;
      else if( this->matrix[i][j]->getCor() == 0 )
        out << "| O |" << endl;
      else 
        out << "|   |" << endl;
      }
    }
    out << "|---|---|---|---|---|---|" << endl;
  }
}

void Tabuleiro::Each( void (*callback)(Noh*, int, int) ) {
  for( int i = 0; i < 6; i++ )
    for( int j = 0; j < 6; j++ )
      callback( this->matrix[i][j], i, j );
}

int Tabuleiro::CountAbertos() {
  return this->listaAbertos.size();
}