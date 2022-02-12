#include "Noh.h"

Noh::Noh(Noh *cima, Noh *esquerda, Noh *diagonal){
    this->fechado = false;
    this->cima = cima;
    this->esquerda = esquerda;
    this->diagonal = diagonal;
    this->baixo = nullptr;
    this->direita = nullptr;
    this->vazio = true;
}

Noh::Noh(int cor){
    this->cor = cor;
    this->fechado = true;
    this->cima = nullptr;
    this->esquerda = nullptr;
    this->diagonal = nullptr;
    this->vazio = false;
}

Noh::~Noh(){}

int Noh::getCor(){
    return this->cor;
}

void Noh::setCor(int cor){
    this->cor = cor;
    this->vazio = false;
}

bool Noh::getFechado(){
    return this->fechado;
}
void Noh::setFechado(bool fechado){
    this->fechado = fechado;
}

void Noh::setVizinhos(Noh* direita, Noh* baixo){
    this->direita = direita;
    this->baixo = baixo;
}

Noh* Noh::getCima() { return this->cima; }
Noh* Noh::getEsquerda() { return this->esquerda; }
Noh* Noh::getDiagonal() { return this->diagonal; }
Noh* Noh::getDireita() { return this->direita; }
Noh* Noh::getBaixo() { return this->baixo; }

int Noh::getSoma() {
    return this->esquerda->getCor() + this->cima->getCor() + this->diagonal->getCor();
}

bool Noh::Vazio() { return this->vazio; }

void Noh::SetPos( int i, int j ) {
    this->i = i;
    this->j = j;
}
int Noh::I() { return this->i; }
int Noh::J() { return this->j; }