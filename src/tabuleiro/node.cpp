#include "node.h"

node::node(node *cima, node *esquerda, node *diagonal){
    this->fechado = false;
    this->cima = cima;
    this->esquerda = esquerda;
    this->diagonal = diagonal;
    this->baixo = nullptr;
    this->direita = nullptr;
    this->vazio = true;
}

node::node(int cor){
    this->cor = cor;
    this->fechado = true;
    this->cima = nullptr;
    this->esquerda = nullptr;
    this->diagonal = nullptr;
    this->vazio = false;
}

node::~node(){}

int node::getCor(){
    return this->cor;
}

void node::setCor(int cor){
    this->cor = cor;
    this->vazio = false;
}

bool node::getFechado(){
    return this->fechado;
}
void node::setFechado(bool fechado){
    this->fechado = fechado;
}

void node::setVizinhos(node* direita, node* baixo){
    this->direita = direita;
    this->baixo = baixo;
}

node* node::getCima() { return this->cima; }
node* node::getEsquerda() { return this->esquerda; }
node* node::getDiagonal() { return this->diagonal; }
node* node::getDireita() { return this->direita; }
node* node::getBaixo() { return this->baixo; }

int node::getSoma() {
    return this->esquerda->getCor() + this->cima->getCor() + this->diagonal->getCor();
}

bool node::Vazio() { return this->vazio; }

void node::SetPos( int i, int j ) {
    this->i = i;
    this->j = j;
}
int node::I() { return this->i; }
int node::J() { return this->j; }