#include "SistemaDeMensajes.h"

// Completar...

SistemaDeMensajes:: SistemaDeMensajes(){
    for (int i = 0; i < 4; ++i) {
        _conns[i] = nullptr;
    }
}

void  SistemaDeMensajes::registrarJugador(int id, string ip){
    if (registrado(id)){
        _conns[id]->ip() = ip;
    } else {
        desregistrarJugador(id);
    }
}

void SistemaDeMensajes::enviarMensaje(int id, string mensaje){
    _conns[id]->enviarMensaje(mensaje);
}

bool SistemaDeMensajes::registrado(int id) const {
    return _conns[id] != nullptr;
}

string SistemaDeMensajes::ipJugador(int id) const {
    return _conns[id]->ip();
}

void SistemaDeMensajes::desregistrarJugador(int id) {
    if (registrado(id)) {
        delete _conns[id];
    }
}

SistemaDeMensajes::~SistemaDeMensajes() {
    for (int i = 0; i < 4; ++i) {
        delete _conns[i];
    }
}

Proxy *SistemaDeMensajes::obtenerProxy(int id) {
    Proxy * p = new Proxy(_conns[id]);
    return p;
}