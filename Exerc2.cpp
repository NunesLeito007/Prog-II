#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Empregado {
public:
  virtual double getSalarioMensal() { return 0; };
  virtual void imprimirDetalhes() { return; };
};

class EmpregadoAssalariado : public Empregado {
public:
  EmpregadoAssalariado(double salario) : salarioMensal(salario) {}
  double getSalarioMensal() override { return salarioMensal; }
  void imprimirDetalhes() override {
    cout << "Empregado Assalariado, Salário Mensal: " << salarioMensal << endl;
  }

private:
  double salarioMensal;
};

class EmpregadoHorista : public Empregado {
public:
  EmpregadoHorista(int horasTrabalhadas, double taxaPorHora)
      : horasTrabalhadas(horasTrabalhadas), taxaPorHora(taxaPorHora) {}
  double getSalarioMensal() override { return horasTrabalhadas * taxaPorHora; }
  void imprimirDetalhes() override {
    cout << "Empregado Horista, Horas Trabalhadas: " << horasTrabalhadas
         << ", Taxa por Hora: " << taxaPorHora << endl;
  }

private:
  int horasTrabalhadas;
  double taxaPorHora;
};

int main() {
  vector<shared_ptr<Empregado>> empregados;

  empregados.push_back(make_shared<EmpregadoAssalariado>(3000.00));
  empregados.push_back(make_shared<EmpregadoHorista>(160, 25.00));

  for (const auto &empregado : empregados) {
    empregado->imprimirDetalhes();
    cout << "Salário Mensal: " << empregado->getSalarioMensal() << endl;
  }

  return 0;
}