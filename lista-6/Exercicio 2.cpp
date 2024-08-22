#include <iostream>
#include <vector>
using namespace std;

class Vector2D {
private:
    double x ;
    double y ; 

public:
    Vector2D () : x(0.0), y(0.0){}
    Vector2D(double x, double y) : x(x), y(y) {}
  
    Vector2D operator+(const Vector2D& other) const {
        return Vector2D(x + other.x, y + other.y);
    }

    Vector2D operator-(const Vector2D& other) const {
        return Vector2D(x - other.x, y - other.y);
    }

    bool operator==(const Vector2D& other) const {
        return (x == other.x && y == other.y);
    }

    friend std::ostream& operator<<(std::ostream& os, const Vector2D& v) {
        os << "(" << v.x << ", " << v.y << ")";
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Vector2D& v) {
        is >> v.x >> v.y;
        return is;
    }
};

int main() {
    Vector2D v1(3.5, 2.0);
    Vector2D v2(1.5, 4.0);

    
    Vector2D v3 = v1 + v2;
    std::cout << "Soma de v1 e v2: " << v3 << std::endl;

    Vector2D v4 = v1 - v2;
    std::cout << "Diferença entre v1 e v2: " << v4 << std::endl;

    if (v1 == v2) {
        std::cout << "v1 e v2 são iguais." << std::endl;
    } else {
        std::cout << "v1 e v2 são diferentes." << std::endl;
    }

    Vector2D v5;
    std::cout << "Digite um vetor (formato: x y): ";
    std::cin >> v5;
    std::cout << "Vetor lido: " << v5 << std::endl;

    return 0;
}




