// Funcao Amiga Pokemon

#include <iostream>
#include <string>

class Pokemon {
private:
    std::string nome;
    int hp;
public:
    Pokemon(const std::string& n, int h) : nome(n), hp(h) {}

    // Declaração da função amiga que acessa membros privados
    friend void atacar(Pokemon& atacante, Pokemon& defensor, int dano);

    // Função para mostrar informações do Pokémon
    void mostrarInformacoes() const {
        std::cout << "Pokémon: " << nome << ", HP: " << hp << std::endl;
    }
};

// Função amiga que calcula o dano causado de um Pokémon ao outro
void atacar(Pokemon& atacante, Pokemon& defensor, int dano) {
    std::cout << "\n"<< atacante.nome << " ataca " << defensor.nome << " causando " << dano << " de dano.\n" << std::endl;
    defensor.hp -= dano; // Reduz o HP do Pokémon defensor
    if (defensor.hp < 0) {
        defensor.hp = 0; // Garante que o HP não fique negativo
    }
}

int main() {
    Pokemon pikachu("Pikachu", 100);
    Pokemon charmander("Charmander", 100);

    pikachu.mostrarInformacoes();
    charmander.mostrarInformacoes();

    atacar(pikachu, charmander, 20);

    pikachu.mostrarInformacoes();
    charmander.mostrarInformacoes();

    return 0;
}


