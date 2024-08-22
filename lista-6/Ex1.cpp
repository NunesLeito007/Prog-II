// Sobrecarga Operador Data

#include <iostream>
#include <iomanip> // Para std::setw e std::setfill

class Data {
private:
    int dia;
    int mes;
    int ano;

    // Função auxiliar para ajustar o dia e o mês, considerando limites simples
    void ajustarData() {
        const int diasPorMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (mes > 12) {
            mes = 12;
        }
        if (mes < 1) {
            mes = 1;
        }
        if (dia > diasPorMes[mes - 1]) {
            dia = diasPorMes[mes - 1];
        }
        if (dia < 1) {
            dia = 1;
        }
    }

public:
    // Construtor
    Data(int d = 1, int m = 1, int a = 1900) : dia(d), mes(m), ano(a) {
        ajustarData();
    }

    // Sobrecarga do operador +
    Data operator+(int dias) const {
        Data novaData = *this;
        novaData.dia += dias;

        // Simples ajuste de dias e meses
        while (novaData.dia > 31) { // Limite de dias simples
            novaData.dia -= 31;
            novaData.mes++;
            if (novaData.mes > 12) {
                novaData.mes = 1;
                novaData.ano++;
            }
        }
        novaData.ajustarData();
        return novaData;
    }

    // Sobrecarga do operador -
    Data operator-(int dias) const {
        Data novaData = *this;
        novaData.dia -= dias;

        // Simples ajuste de dias e meses
        while (novaData.dia < 1) { // Limite de dias simples
            novaData.dia += 31;
            novaData.mes--;
            if (novaData.mes < 1) {
                novaData.mes = 12;
                novaData.ano--;
            }
        }
        novaData.ajustarData();
        return novaData;
    }

    // Sobrecarga do operador <<
    friend std::ostream& operator<<(std::ostream& os, const Data& data) {
        os << std::setw(2) << std::setfill('0') << data.dia << "/"
           << std::setw(2) << std::setfill('0') << data.mes << "/"
           << data.ano;
        return os;
    }

    // Sobrecarga do operador >>
    friend std::istream& operator>>(std::istream& is, Data& data) {
        char barra1, barra2;
        int d, m, a;

        // Tenta ler no formato dd/mm/aaaa
        is >> d >> barra1 >> m >> barra2 >> a;
        if (barra1 == '/' && barra2 == '/') {
            data.dia = d;
            data.mes = m;
            data.ano = a;
        } else {
            // Volta para o estado anterior e tenta ler no formato dd mm aaaa
            is.clear();
            is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            is >> d >> m >> a;
            data.dia = d;
            data.mes = m;
            data.ano = a;
        }
        data.ajustarData();
        return is;
    }
};

int main() {
    Data data1(10, 5, 2024);

    Data dataSoma = data1 + 45;   // Adiciona 45 dias
    Data dataSubtracao = data1 - 30; // Subtrai 30 dias

    std::cout << "Data Original: " << data1 << std::endl;
    std::cout << "Data após soma de 45 dias: " << dataSoma << std::endl;
    std::cout << "Data após subtração de 30 dias: " << dataSubtracao << std::endl;

    Data dataInput;
    std::cout << "Digite uma data no formato dd/mm/aaaa ou dd mm aaaa: ";
    std::cin >> dataInput;

    if (std::cin) {
        std::cout << "Data Digitada: " << dataInput << std::endl;
    } else {
        std::cerr << "Formato de data inválido!" << std::endl;
    }

    return 0;
}
