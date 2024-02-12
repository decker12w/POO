#include <iostream>

using std::cout;
using std::endl;
using std::string;

class Animal
{
public:
    Animal(string Anome = "Animal Anonimo")
    {
        nome = Anome;
    };

    string getNome() const
    {
        return nome;
    };

    virtual void emitir_som() const = 0; // m?todo virtual puro

    void comer() const
    {
        cout << "comendo \"genericamente\"..." << endl;
    };

    virtual void andar() const
    {
        cout << "andando como um animal generico..." << endl;
    };

    virtual ~Animal(){};

private:
    string nome;
};

// metodo virtual puro nao precisa, mas pode ser implementado.
void Animal::emitir_som() const
{
    cout << "Preparando para emitir som  e..." << endl;
};

class Cachorro : public Animal
{
public:
    Cachorro(string Anome = "Cachorro Anonimo", string Cpedigree = "SRD") : Animal(Anome)
    {
        pedigree = Cpedigree;
    };

    void emitir_som() const
    {
        Animal::emitir_som();
        cout << "AU   AU   AU" << endl;
    };

    void comer() const
    {
        cout << "comendo como um cachorro" << endl;
    };

    void andar() const
    {
        cout << "andando como um cachorro" << endl;
    };

    void abanarRabo() const
    {
        cout << "abanando o rabo porque sou um cachorro e so cachorros abanam o rabo" << endl;
    };

private:
    string pedigree;
};

class Gato : public Animal
{
public:
    Gato(string Anome = "Gato Anonimo", int GVidas = 7) : Animal(Anome)
    {
        VidasRestantes = GVidas;
    };

    void emitir_som() const
    {
        Animal::emitir_som();
        cout << "MIAU   MIAU   MIAU" << endl;
    };

private:
    int VidasRestantes;
};

class Carneiro : public Animal
{
public:
    Carneiro(string Anome = "Carneiro Anonimo") : Animal(Anome){};

    void emitir_som() const
    {
        Animal::emitir_som();
        cout << "Meeee   Meeee   Meeee" << endl;
    };
};

int main()
{

    Animal *VetorAnimais[5] = {NULL};

    VetorAnimais[0] = new Cachorro("Ajudante de Papai Noel", "SRD");
    VetorAnimais[1] = new Gato("Bola de neve", 6);
    VetorAnimais[2] = new Carneiro;
    //      VetorAnimais[3] = new Animal("ze ninguem"); //classe abstrata

    Cachorro *ptrCachorro; // ponteiro a ser usado no dynamic_cast

    for (int i = 0; i < 5; i++)
        if (VetorAnimais[i] != NULL)
        {
            cout << endl
                 << VetorAnimais[i]->getNome() << endl;
            VetorAnimais[i]->emitir_som();
            // se for cachorro, quero que abane o rabo tb!
            ptrCachorro = dynamic_cast<Cachorro *>(VetorAnimais[i]);
            if (ptrCachorro != NULL) //? cachorro
                ptrCachorro->abanarRabo();
            else
                cout << "N?o sou um cachorro para abanar o rabinho" << endl;
        }

    system("pause");
    return 0;
}
