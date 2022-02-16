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
        Noh* baixo;
        bool vazio;
        int i;
        int j;
        // int level;

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
        Noh* getBaixo();
        void setVizinhos(Noh* direita, Noh* baixo);
        bool Vazio();

        void SetPos( int, int );
        int I();
        int J();

        // void Noh::setLevel( int );
        // int Noh::getLevel();
        // int I();
        // int J();
};

#endif // NOH_H_INCLUDED