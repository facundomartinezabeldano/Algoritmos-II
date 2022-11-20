#ifndef CONJUNTO_H_
#define CONJUNTO_H_

#include <assert.h>
#include <string>
#include <iostream>

using namespace std;

template <class T>
class Conjunto
{
    public:

        // Constructor. Genera un conjunto vacío.
        Conjunto();

        // Destructor. Debe dejar limpia la memoria.
        ~Conjunto();

        // Inserta un elemento en el conjunto. Si este ya existe,
        // el conjunto no se modifica.
        void insertar(const T&);

        // Decide si un elemento pertenece al conjunto o no.
        bool pertenece(const T&) const;

        // Borra un elemento del conjunto. Si este no existe,
        // el conjunto no se modifica.
        void remover(const T&);

        // Siguiente elemento al recibido por párametro, en orden.
        // Pre: el elemento está en el conjunto y no es el máximo del conjunto.
        const T& siguiente(const T& elem);

        // Devuelve el mínimo elemento del conjunto según <.
        const T& minimo() const;

        // Devuelve el máximo elemento del conjunto según <.
        const T& maximo() const;

        // Devuelve la cantidad de elementos que tiene el conjunto.
        unsigned int cardinal() const;

        // Muestra el conjunto.
        void mostrar(std::ostream&) const;

    private:

        /**
         * Completar con lo que sea necesario...
         **/

        struct Nodo
        {
            // El constructor, toma el elemento al que representa el nodo.
            Nodo(const T& v);
            // El elemento al que representa el nodo.
            T valor;
            // Puntero a la raíz del subárbol izquierdo.
            Nodo* izq;
            // Puntero a la raíz del subárbol derecho.
            Nodo* der;
        };
        int _cardinal;
        // Puntero a la raíz de nuestro árbol.
        Nodo* _raiz;

        Nodo* buscar (const T& clave) const {
            Nodo* i = _raiz;
            while (i != nullptr){
                if (i->valor > clave){
                    i = i->izq;
                } else if (i->valor < clave){
                    i = i->der;
                } else{
                    return i;
                }
            }
            return nullptr;
        }

        Nodo* buscarPadre(const T& clave) const {
            Nodo* i = _raiz;
            Nodo* p = nullptr;
            while (i != nullptr){
                if (i->valor > clave){
                    p = i;
                    i = i->izq;
                } else {
                    p = i;
                    i = i->der;
                }
            }
            return p;
        }

        void intercambiarYborrar(Nodo* a, Nodo* b){
            //intercambia a con b y borra a
            b = a;
            delete a;
            _cardinal --;
        }

        void borrarNodos(Nodo* r){
            if (r != nullptr){
                if (r->der == nullptr && r->izq == nullptr){
                    delete r;
                } else if (r->der != nullptr && r->izq == nullptr){
                    borrarNodos(r->der);
                } else if (r->der == nullptr && r->izq != nullptr){
                    borrarNodos(r->izq);
                } else {
                    borrarNodos(r->izq);
                    borrarNodos(r->der);
                }
            }
            return;
        }

};

template<class T>
std::ostream& operator<<(std::ostream& os, const Conjunto<T>& c) {
     c.mostrar(os);
     return os;
}

#include "Conjunto.hpp"

#endif // CONJUNTO_H_