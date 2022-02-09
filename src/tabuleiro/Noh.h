#ifndef NOH_H_INCLUDED
#define NOH_H_INCLUDED

using namespace std;

class Noh {
    private:
        int cor;
        bool fechado;
        Noh* cima;
        Noh* esquerda;
        Noh* diagonal;
        Noh* direita;
        Noh* vizinho;

    public:
        Noh(Noh *cima, Noh *esquerda, Noh *diagonal);
        Noh(int cor);
        ~Noh();

        int getCor(); // 0 = Branco; 1 = Preto;
        void setCor(int cor);

        int getSoma();

        bool getFechado();
        void setFechado(bool fechado);

        Noh* getCima();
        Noh* getEsquerda();
        Noh* getDiagonal();
        Noh* getDireita();
        Noh* getVizinho();
};

#endif // NOH_H_INCLUDED