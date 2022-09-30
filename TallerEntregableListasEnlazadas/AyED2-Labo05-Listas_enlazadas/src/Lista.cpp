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
        _ult = _prim;
    } else {
        Nodo* nuevo_prim = new Nodo(elem);
        _prim->ant = nuevo_prim;
        nuevo_prim->prox = _prim;
        _prim = nuevo_prim;
    }
}

void Lista::agregarAtras(const int& elem) {
    Nodo* nuevo_ult = new Nodo(elem);
    if (_ult == nullptr){
        _ult = nuevo_ult;
        _prim = _ult;
    } else {
        _ult->prox =nuevo_ult;
        nuevo_ult->ant = _ult;
        _ult = nuevo_ult;
    }
}

void Lista::eliminar(Nat i) {
    int j = 0;
    Nodo* n =  _prim;
    while (j != i){
        n = n->prox;
        j++;
    }
    if(_prim == _ult) {
        _prim = nullptr;
        _ult = _prim;
    }else if (n == _prim){
        Nodo* nuevoPrim = n->prox;
        _prim = nuevoPrim;
        _prim->ant = nullptr;
    } else if (n == _ult) {
        Nodo* nuevoUlt = n->ant;
        _ult = nuevoUlt;
        _ult->prox = nullptr;
    } else {
        Nodo* nAnterior = n->ant;
        Nodo* nProximo = n->prox;
        nAnterior->prox = nProximo;
        nProximo->ant = nAnterior;
    }
    delete n;
}

int Lista::longitud() const {
    int res = 0;
    Nodo* n = _prim;
    while (n != nullptr){
        res++;
        n = n->prox;
    }
    return res;
}

const int& Lista::iesimo(Nat i) const {
    Nodo* buffer = _prim;
    int j = 0;
    while (j != i){
     buffer = buffer->prox;
     j = j+1;
    }
    return buffer->valor;
    assert(false);
}

int& Lista::iesimo(Nat i) {
    Nodo* buffer = _prim;
    int j = 0;
    while (j != i){
     buffer = buffer->prox;
     j = j+1;
    }
    return buffer->valor;
    assert(false);
}

void Lista::mostrar(ostream& o) {
    // Completar
}

void Lista::copiarNodos(const Lista& l){
    Nodo* actual = l._prim;
    while ( actual != nullptr ) {
        agregarAtras(actual->valor);
        actual = actual->prox;
    }
}

void Lista::destruirNodos(){
    Nodo* actual = _prim;
    while(actual != nullptr){
        Nodo* siguiente = actual->prox;
        delete actual;
        actual = siguiente;
    }
}