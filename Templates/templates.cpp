// EXEMPLO DE COORDENADAS J� VISTO
// AGORA COM TEMPLATE PARA PERMITIR O USO DE COORDENADAS
// DO TIPO INTEIRO, FLOAT OU DOUBLE

#include <iostream>
using namespace std;

template <class T>

class Coordenadas
{
private:
    T x, y; // posi��es x e y do tipo T
public:
    Coordenadas(T, T); // construtor com posi��es do tipo T passadas por par�metro
    void Set(T, T);
    void Get(T &, T &) const;
    T GetX(void) const;
    T GetY(void) const;
};

template <class T> // n�o esquecer de colocar template aqui
Coordenadas<T>::Coordenadas(T coord_x, T coord_y)
{
    this->x = coord_x; // uso do this
    this->y = coord_y; // uso do this
}

template <class T> // e aqui tamb�m...
void Coordenadas<T>::Set(T x, T y)
{
    this->x = x;
    this->y = y;
}

template <class T>                         // j� percebeu que � em todas as declara��es, n�o?
void Coordenadas<T>::Get(T &x, T &y) const // parametros x e y do tipo T
{
    x = this->x;
    y = this->y;
}

template <class T>
T Coordenadas<T>::GetX(void) const // note aqui que h� o retorno de um valor do tipo T
{
    return (x);
}

template <class T>
T Coordenadas<T>::GetY(void) const // Aqui tamb�m!
{
    return (y);
}

int main(int argc, char *argv[])
{
    int X = 10, Y = 20;
    double Z = 11.1, W = 22.2;

    Coordenadas<int> Posicao_inteira(X, Y);
    Coordenadas<double> Posicao_precisa(Z, W);

    cout << Posicao_inteira.GetX() << " " << Posicao_inteira.GetY() << endl;
    cout << Posicao_precisa.GetX() << " " << Posicao_precisa.GetY() << endl;

    system("pause");
    return 0;
}