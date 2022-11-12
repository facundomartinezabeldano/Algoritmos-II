#ifndef _LISTA_ALUMNOS_H_
#define _LISTA_ALUMNOS_H_
#include <string>
#include <ostream>
using namespace std;
typedef unsigned long Nat;

class Lista {
public:
    Lista();
    Lista(const Lista& l);
    ~Lista();
    Lista& operator=(const Lista& aCopiar);
    void agregarAdelante(const int& elem);
    void agregarAtras(const int& elem);
    void eliminar(Nat i);
    int longitud() const;
    const int& iesimo(Nat i) const;
    int& iesimo(Nat i);
    void mostrar(ostream& o);
    friend ostream& operator<<(ostream& os, Lista& l) {
        l.mostrar(os);
        return os;
    }
private:
    struct Nodo {
        Nodo* ant;
        Nodo* prox;
        int valor;
        Nodo(int n){
            ant = nullptr;
            prox = nullptr;
            valor = n;
        }
    };
    Nodo* _prim;
    Nodo* _ult;
    void copiarNodos(const Lista& o);
    void destruirNodos();
};

#endif
