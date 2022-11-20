
template <class T>
Conjunto<T>::Conjunto() {
    _raiz = nullptr;
    _cardinal = 0;
}

template <class T>
Conjunto<T>::~Conjunto() {
    borrarNodos(_raiz);
}

template <class T>
bool Conjunto<T>::pertenece(const T& clave) const {
    Nodo* n = buscar(clave);
    return (n != nullptr && n->valor == clave);
}

template <class T>
void Conjunto<T>::insertar(const T& clave) {
    Nodo* p = buscarPadre(clave);

    if (p == nullptr){
        _raiz = new Nodo(clave);
        _cardinal ++;
    } else if (p->valor > clave){
        p->izq = new Nodo(clave);
        _cardinal ++;
    } else {
        p->der = new Nodo(clave);
        _cardinal ++;
    }
}

template <class T>
void Conjunto<T>::remover(const T& clave) {
    Nodo* i = buscar(clave);
    if (i == _raiz){
        _raiz = nullptr;
        _cardinal --;
    } else if (i->der == nullptr && i->izq == nullptr){
        delete i;
        _cardinal--;
    } else if (i->der != nullptr && i->izq == nullptr){
        intercambiarYborrar(i,i->izq);
    } else if (i->der == nullptr && i->izq != nullptr){
        intercambiarYborrar(i,i->der);
    } else {
        Nodo* sig = buscar(siguiente(i->valor));
        i->valor = sig->valor;
        delete sig;
        _cardinal--;
    }
}

template <class T>
const T& Conjunto<T>::siguiente(const T& clave) {
    Nodo* p = nullptr;
    Nodo* i = _raiz;
    while (i->valor != clave){
        if (i->valor > clave){
            p = i;
            i = i->izq;
        } else {
            i = i->der;
        }
    }
    if (i->der != nullptr){
        Conjunto<T>* subArbolIzq = new Conjunto<T>();
        subArbolIzq->_raiz = i->der;
        return subArbolIzq->minimo();
    } else {
        return p->valor;
    }
}

template <class T>
//Se asume que el conjunto es NO vacio
const T& Conjunto<T>::minimo() const {
    Nodo* i = _raiz;
    while (i->izq != nullptr){
        i = i->izq;
    }
    return i->valor;
}

template <class T>
//Se asume que el conjunto es NO vacio
const T& Conjunto<T>::maximo() const {
    Nodo* i = _raiz;
    while (i->der != nullptr){
        i = i->der;
    }
    return i->valor;
}

template <class T>
unsigned int Conjunto<T>::cardinal() const {
    return _cardinal;
}

template <class T>
Conjunto<T>::Nodo::Nodo(const T &v) {
    valor = v;
    izq = nullptr;
    der = nullptr;
}

template <class T>
void Conjunto<T>::mostrar(std::ostream&) const {
    assert(false);
}

