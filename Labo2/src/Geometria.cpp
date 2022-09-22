#include <iostream>

using namespace std;

using uint = unsigned int;

// Ejercicio 1

class Rectangulo {
    public:
        Rectangulo(uint alto, uint ancho);
        uint alto();
        uint ancho();
        float area();

    private:
        int _alto;
        int _ancho;

};

Rectangulo::Rectangulo(uint alto, uint ancho): _alto(alto), _ancho(ancho) {};

uint Rectangulo::alto() {
    return _alto;
}

// Completar definición: ancho

uint Rectangulo ::ancho() {
    return _ancho;
}

// Completar definición: area
float Rectangulo::area() {
    return _alto * _ancho;
}
// Ejercicio 2

// Clase Elipse
class Elipse {
    public:
        Elipse(uint r_a, uint r_b);
        uint r_a();
        uint r_b();
        float area();

    private:
        uint _r_a;
        uint _r_b;
};

Elipse::Elipse(uint r_a, uint r_b): _r_a(r_a), _r_b(r_b) {}

uint Elipse::r_a() {
    return _r_a;
}

uint Elipse::r_b() {
    return _r_b;
}

float Elipse::area(){
    return _r_a * _r_b * 3.14;
}


// Ejercicio 3

class Cuadrado {
    public:
        Cuadrado(uint lado);
        uint lado();
        float area();
    private:
        Rectangulo _r;
};

Cuadrado::Cuadrado(uint lado): _r(lado, lado) {}

uint Cuadrado::lado() {
    return _r.alto();
}

float Cuadrado::area() {
    return _r.alto()*_r.alto();
}

// Ejercicio 4

// Clase Circulo
class Circulo {
    public:
    Circulo(uint radio);
    uint radio();
    float area();

    private:
    Elipse elipse;
};

Circulo::Circulo(uint radio): elipse(radio,radio) {}

uint Circulo:: radio(){
    return elipse.r_a();
}

float Circulo::area() {
    return elipse.area();
}


// Ejercicio 5


ostream& operator<<(ostream& os, Rectangulo r) {
    os << "Rect(" << r.alto() << ", " << r.ancho() << ")";
    return os;
}

ostream& operator<<(ostream& os, Elipse e) {
    os << "Elipse(" << e.r_a() << ", " << e.r_b() << ")";
    return os;
}


ostream& operator<<(ostream& os, Cuadrado c) {
    os << "Cuad(" << c.lado() << ")";
    return os;
}


ostream& operator<<(ostream& os, Circulo c) {
    os << "Circ(" << c.radio() << ")";
    return os;
}