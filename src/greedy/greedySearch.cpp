#include "greedySearch.h"

GreedySearch::GreedySearch(){
   this->tabuleiro = new Tabuleiro();
};

GreedySearch::~GreedySearch(){};

void GreedySearch::Run() {
  int score = 0;
  int it = 1;

  // cria o arquivo em ./Resultados, criando um novo arquivo (sem conteúdo)
  this->tabuleiro->Print("GreedySearch", "INICIO", false);

  // percorre todos os estados abertos aplicando o algorimo
  while( this->tabuleiro->CountAbertos() > 0 ) {
    // chama a função que escolhe o próximo estado, processa ele, gera os filhos (lista de abertos)
    score = 0;
    this->Iterate( score );
    
    string abertos;
    // geração da lista de abertos no formato { [i,j] - [i,j] }
    for( int i = 0; i < this->tabuleiro->CountAbertos(); i++ )
      abertos = abertos + (i == 0 ? "[":" - [") + to_string(this->tabuleiro->listaAbertos[i]->I()) + "," + to_string(this->tabuleiro->listaAbertos[i]->J()) + "]";
    // escreve no arquivo os dados da iteração
    tabuleiro->Print("GreedySearch", "ITERACAO " + to_string(it) + " | SCORE " + to_string(score) + " | ABERTOS = { " + abertos + " }");

    it++;
  }

  // escreve no arquivo o fim da busca
  tabuleiro->Print("GreedySearch", "FINAL");
}


void GreedySearch::Iterate( int& score ) {

  int highest = score;
  int highestIndex = 0; // considera que o maior score está na posição 0
  int color = 0; // define a cor para qual o estado vai
  Noh* best;

  /* na busca gulosa queremos estimar o valor do estado atual n até o estado objetivo
  * assim, o score (ou valor até o nó n) não é relevante, por isso é 0
  */

  // Acha o nó aberto de maior score - o nó que vai ser processado
  for( int i = 0; i < tabuleiro->CountAbertos(); i++ ) {
    int sum = 0; 
    int pretos = this->tabuleiro->listaAbertos[i]->getSoma(); // qnt de peças pretas em cima, lado e diagonal

    // Adiciona a pontuação referente à heuristica ( numero de peças brancas vizinhas )
    sum = 3 - pretos; // calcula o heuristica refere a quantidade de peças brances (vinde doc)

    // Adiciona a pontuação ordenada ( maximizar pretas, logo preta = 1 ponto )
    // Também define a cor que será setada
    // if( pretos <= 1 ) sum++;

    // Seleciona o nó aberto de maior pontuação
    if( highest < sum ) {
      highest = sum;
      highestIndex = i;
      color = pretos <= 1 ? 1:0; // define a cor do estado
      // cout << "found highest: " << i << endl;
    }
  }

  // cout << "highest i: " << highestIndex << endl;

  // ponteiro pro nó no índice com maior valor calculado acima (for)
  best = this->tabuleiro->listaAbertos[highestIndex];

  // Se a maioria for branca, a proxima e preta, caso contrario será branca
  best->setCor(color);
  best->setFechado(true); // fechado pois estamos processando o estado nesse momento

  // Abre os novos nós
  Noh* aux;
  aux = best->getBaixo();
  if(  // nullptr = ponteiro vazio
      //se existir o estado para baixo e os estados a esquerda e a diagonal forem diferente de vazio, podemos processar o estado para baixo
    aux != nullptr &&
    !aux->getEsquerda()->Vazio() && 
    !aux->getDiagonal()->Vazio()
  ) {
    // cout << "get baixo" << endl;
    aux->setFechado(false); // aberto pois vamos processado
    this->tabuleiro->listaAbertos.push_back( aux ); // adiciona a lista de abertos para poder ser escolhido e processado
    // cout << aux << endl;
  }

  // mesma coisa pra direita
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


