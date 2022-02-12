#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

using namespace std;

class node {
    private:
        int cor;
        bool fechado;
        node* cima;
        node* esquerda;
        node* diagonal;
        node* direita;
        node* baixo;
        bool vazio;
        int i;
        int j;

    public:
        node(node *cima, node *esquerda, node *diagonal);
        node(int cor);
        ~node();

        int getCor(); // 0 = Branco; 1 = Preto;
        void setCor(int cor);

        int getSoma();

        bool getFechado();
        void setFechado(bool fechado);

        node* getCima();
        node* getEsquerda();
        node* getDiagonal();
        node* getDireita();
        node* getBaixo();
        void setVizinhos(node* direita, node* baixo);
        bool Vazio();

        void SetPos( int, int );
        int I();
        int J();
        // int I();
        // int J();
};

#endif // NODE_H_INCLUDED