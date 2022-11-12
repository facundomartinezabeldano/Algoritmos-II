#include "Lista.h"
#include <cassert>
Lista::Lista() {
    _prim = nullptr;
    _ult = nullptr;
}

Lista::Lista(const Lista& l) : Lista() {
    //Inicializa una lista vacía y luego utiliza operator= para no duplicar el código de la copia de una lista.
    *this = l;
}

Lista::~Lista() {
    destruirNodos();
}

Lista& Lista::operator=(const Lista& aCopiar) {
    destruirNodos();
    copiarNodos(aCopiar);
    return *this;
}

void Lista::agregarAdelante(const int& elem) {
    if (this->_prim == nullptr){
        _prim = new Nodo(elem);
    } else {
        Nodo* nuevo_prim = new Nodo(elem);
        _prim->ant = nuevo_prim;
        nuevo_prim->prox = _prim;
        _prim = nuevo_prim;
    }
}

void Lista::agregarAtras(const int& elem) {
    Nodo* nuevo = new Nodo(elem);
    _ult->prox = nuevo;
    nuevo->ant = _ult;
    _ult = nuevo;
}

void Lista::eliminar(Nat i) {

}

int Lista::longitud() const {
    int res = 0;
    if(_prim == nullptr) {
        return res;
    }else{
        res++;
        Nodo* buffer = _prim;
        while (buffer->prox != nullptr){
            res++;
            buffer = buffer->prox;
        }
    }
    return res;
}

const int& Lista::iesimo(Nat i) const {
    Nodo* buffer = _prim;
    for (int j = 0; j < i; ++j) {
        buffer = _prim->prox;
    }
    return buffer->valor;
    assert(false);
}

int& Lista::iesimo(Nat i) {
    Nodo* buffer = _prim;
    for (int j = 0; j < i; ++j) {
        buffer = _prim->prox;
    }
    return buffer->valor;
    assert(false);
}

void Lista::mostrar(ostream& o) {
    // Completar
}

void Lista::copiarNodos(const Lista& l){
    Nodo* actual = l._prim;
    while ( actual != NULL ) {
        agregarAdelante(actual->valor);
        actual = actual->prox;
    }
}

void Lista::destruirNodos(){
    Nodo* actual = _prim;
    while(_prim != nullptr){
        Nodo* siguiente = actual->prox;
        delete actual;
        actual = siguiente;
    }
}