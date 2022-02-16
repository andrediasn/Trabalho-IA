#include "profundidade.h"

Profundidade::Profundidade(){
    this->tabuleiro = new Tabuleiro();
};

Profundidade::~Profundidade(){};

void Profundidade::Run() {
  int it = 0;
  int result = 0;
  int level = 0;

  this->tabuleiro->Print("profundidade", "INICIO", false);

  while( result == 0 ) {
      result = this->Iterate( level );

      string abertos;
      for( int i = 0; i < this->tabuleiro->CountAbertos(); i++ )
          abertos = abertos + (i == 0 ? "[":" - [") + to_string(this->tabuleiro->listaAbertos[i]->I()) + "," + to_string(this->tabuleiro->listaAbertos[i]->J()) + "]";

      tabuleiro->Print("profundidade", "ITERACAO " + to_string(it) + " | ABERTOS = { " + abertos + " }");

      it++;
  }

  tabuleiro->Print("profundidade", "FINAL | RESULTADO = " + (result == -1 ? (string)"FALHA":(string)"SUCESSO") );
}

 int Profundidade::Iterate( int& level ) {
	// Pega sempre o primeiro noh da lista de abertos
	Noh* firstOpen = this->tabuleiro->listaAbertos[0];

	// O primeiro noh pode ja ter sido visitado
	if( firstOpen->getFechado() ) return 0;

	// Pega os nohs vizinhos
	Noh* down = firstOpen->getBaixo();
	Noh* right = firstOpen->getDireita();

	int sum = firstOpen->getSoma();

	// Define a cor como preta ou branca com base nos vizinhos
	if( sum > 2 ) {
		firstOpen->setCor(0);
	} else {
		firstOpen->setCor(1);
	}

	// Fecha o noh e abre os proximos caso possivel
  // Abre os proximos na ordem inversa e insere no inicio
  // Dessa forma sempre sera visitado o primeiro filho
	firstOpen->setFechado(true);

  int spacer = 0;

  if(
		right != nullptr &&
		!right->getCima()->Vazio() &&
		!right->getDiagonal()->Vazio()
	) {
		right->setFechado(false);
    this->tabuleiro->listaAbertos.insert( this->tabuleiro->listaAbertos.begin(), right );
    spacer++;
	}

	if( 
		down != nullptr &&
		!down->getEsquerda()->Vazio() &&
		!down->getDiagonal()->Vazio()
	) {
		down->setFechado(false);
    this->tabuleiro->listaAbertos.insert( this->tabuleiro->listaAbertos.begin(), down );
    spacer++;
	}

	// Remove o noh da lista
	this->tabuleiro->listaAbertos.erase( this->tabuleiro->listaAbertos.begin() + spacer );

	// Se nao existem nohs abertos e nem para onde ir, retorna sucesso
	// caso nao haja para onde ir, retorna falha
	if( down == nullptr && right == nullptr && this->tabuleiro->CountAbertos() == 0 ) 
		return 1;
}
 
