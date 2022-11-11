
template <class T>
Conjunto<T>::Conjunto() {
    _raiz = nullptr;
    _cardinal = 0;
    return;
}

template <class T>
Conjunto<T>::~Conjunto() {
    // Completar
}

template <class T>
bool Conjunto<T>::pertenece(const T& clave) const {
    Nodo* n = _raiz;

    if (n == nullptr){
        return false;
    }

    while (n != nullptr) {
        if (n->valor == clave) {
            return true;
        } else if (n->valor > clave) {
            n = n->izq;
        } else {
            n = n->der;
        }
    }
    return false;
}

template <class T>
void Conjunto<T>::insertar(const T& clave) {
    if (pertenece(clave)){
        return;
    }
    Nodo* nuevo = new Nodo(clave);
    Nodo* p = nullptr;
    Nodo* a = _raiz;

    if (a == nullptr){
        _raiz = nuevo;
        _cardinal++;
        return;
    }

    while (a != nullptr ){
        if (a->valor < clave){
            p = a;
            a = a->der;
        } else {
            p = a;
            a = a->izq;
            }
        }

    if (p->valor < clave){
        p->der = nuevo;
    } else {
        p->izq = nuevo;
    }
    _cardinal++;
}

template <class T>
void Conjunto<T>::remover(const T& clave) {
    Nodo* n = _raiz;
    if (!pertenece(clave)){
        return;
    }
    while (n->valor != clave){
        if (n->valor > clave){
            n = n->izq;
        } else {
            n = n->der;
        }
    }

    if (n->der == nullptr && n->izq == nullptr){
        delete n;
    } else if(n->der == nullptr && n->izq != nullptr) {
        n = n->izq;
    } else if (n->der != nullptr && n->izq == nullptr) {
        n = n->der;
    } else {
        int sigV = siguiente(clave);
        int nV = n->valor;

    }
    _cardinal --;

}

template <class T>
const T& Conjunto<T>::siguiente(const T& clave) {
    Nodo* n = _raiz;
    Nodo* p = nullptr;

    while (n->valor != clave){
        if (n->valor > clave){
            p = n;
            n = n->izq;
        } else {
            p = n;
            n = n->der;
        }
    }
    // Ahora tenemos al nodo n con el valor de clave y p el padre de dicho nodo

    if (n->der != nullptr){ // Caso 1
        Nodo* n = n->der;
        while (n->izq != nullptr){
            n = n->izq;
        }
        return n->valor;
    } else if (n == p->izq) { // Caso 2.1
        return p->valor;
    }
}

template <class T>
const T& Conjunto<T>::minimo() const {
    Nodo* n = _raiz;
    while (n->izq != nullptr){
        n = n->izq;
    }
    return n->valor;
    assert(false);
}

template <class T>
const T& Conjunto<T>::maximo() const {
    Nodo* n = _raiz;
    while (n->der != nullptr){
        n = n->der;
    }
    return n->valor;
    assert(false);
}

template <class T>
unsigned int Conjunto<T>::cardinal() const {
    return _cardinal;
}

template <class T>
void Conjunto<T>::mostrar(std::ostream&) const {
    assert(false);
}

template <class T>
Conjunto<T>::Nodo::Nodo(const T &v) {
    valor = v;
    izq = nullptr;
    der = nullptr;
}