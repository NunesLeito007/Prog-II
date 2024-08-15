#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Animal {
private:
  string som;

public:
  virtual void emitirSom() { return; }
};

class Vaca : public Animal {
private:
  string som;

public:
  void emitirSom() override { cout << "Muuu\n"; }
};

class Gato : public Animal {
private:
  string som;

public:
  void emitirSom() override { cout << "Miau\n"; }
};

class Cachorro : public Animal {
private:
  string som;

public:
  void emitirSom() override { cout << "Au Au\n"; }
};

int main() {
  Cachorro cachorro;
  Gato gato;
  Vaca vaca;
  vector<Animal *> animais;
  animais.push_back(&cachorro);
  animais.push_back(&gato);
  animais.push_back(&vaca);
  for (Animal *animal : animais) {
    animal->emitirSom();
  }
  return 0;
}