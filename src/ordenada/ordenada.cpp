#include "ordenada.h"

Ordenada::Ordenada(){
    this->tabuleiro = new Tabuleiro();
}
Ordenada::~Ordenada(){}

void Ordenada::Run(){
    int score = 0;
    int it = 0;

    // Quantidade de peças pretas iniciais
    score += this->tabuleiro->matrix[0][0]->getCor();
    for(int i=1; i<6; i++){
        score += this->tabuleiro->matrix[0][i]->getCor();
        score += this->tabuleiro->matrix[i][0]->getCor();
    }

    // Iniciando arquivo
    this->tabuleiro->Print("ordenada", "INICIO", false);

    while( this->tabuleiro->CountAbertos() > 0 ) {
        this->Iterate( score );
        
        string abertos;
        for( int i=0; i<this->tabuleiro->CountAbertos(); i++){
            abertos = abertos + (i == 0 ? "[":" - [") + to_string(this->tabuleiro->listaAbertos[i]->I()) + "," + to_string(this->tabuleiro->listaAbertos[i]->J()) + "]";
        }

        tabuleiro->Print("ordenada", "ITERACAO " + to_string(it) + " | SCORE " + to_string(score) + " | ABERTOS = { " + abertos + " }");

        it++;
    }

    tabuleiro->Print("ordenada", "FINAL");

}

void Ordenada::Iterate( int& score ) { 
    int numAbertos = this->tabuleiro->listaAbertos.size() - 1;

    // Ordenando lista de abertos
    this->QuickSort(&this->tabuleiro->listaAbertos, 0,  numAbertos);

    Noh* best = this->tabuleiro->listaAbertos[numAbertos];

    int color = best->getSoma() >= 2 ? 0 : 1;

    best->setCor(color);
    best->setFechado(true);

    // Abre os novos nós
    Noh* aux;
    aux = best->getBaixo();
    if( aux!=nullptr && !aux->getEsquerda()->Vazio() && !aux->getDiagonal()->Vazio()) {
        aux->setFechado(false);
        this->tabuleiro->listaAbertos.push_back( aux );
    }

    aux = best->getDireita();
    if( aux!=nullptr && !aux->getCima()->Vazio() && !aux->getDiagonal()->Vazio() ) {
        aux->setFechado(false);
        this->tabuleiro->listaAbertos.push_back( aux );
    }

    // Remove da lista de abertos, atualizando o score atual
    this->tabuleiro->listaAbertos.erase( this->tabuleiro->listaAbertos.begin() + numAbertos );
    score += best->getCor();
}

void Ordenada::QuickSort(vector<Noh*> *abertos, int inicio, int fim){ 
    if(inicio < fim){ // Enquanto posicao de inicio nao ultrapassar final
        int p = PartQuick(abertos, inicio, fim); // Calcula posicao do pivo
        QuickSort(abertos, inicio, p - 1); // Recursividade da primeira metade do vetor
        QuickSort(abertos, p, fim); // Recursividade da segunda metade do vetor
    }
}

int Ordenada::PartQuick(vector<Noh*> *abertos, int esq, int dir){
    int p = esq + (dir - esq) / 2; // indicado do pivo recebe a metade do vetor como posicao
    Noh* pivo = abertos->at(p); // posiciona pivo utilizando ponteiro
    int i = esq; // Posicao percorrida pela esquerda
    int j = dir; // Posicao percorrida pela direita
    while(i<=j) { // Enquanto esquerda nao ultrapassar direita
        while(abertos->at(i)->getSoma() > pivo->getSoma())  // Compara Soma do noh de pivo com posicao mais a esquerda
            i++;
        while(abertos->at(j)->getSoma() < pivo->getSoma())  // Compara Soma do noh de pivo com posicao mais a direita
            j--;
         if(i <= j) { 
            Noh* aux = abertos->at(i); // auxiliar para fazer a troca
            abertos->at(i) = abertos->at(j);
            abertos->at(j) = aux;
            i++;
            j--;
        }
    }
    return i; // Retorna indice para o pivo
}


