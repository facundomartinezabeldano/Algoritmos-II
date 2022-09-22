#include <iostream>

using namespace std;

using uint = unsigned int;

// Pre: 0 <= mes < 12
uint dias_en_mes(uint mes) {
    uint dias[] = {
        // ene, feb, mar, abr, may, jun
        31, 28, 31, 30, 31, 30,
        // jul, ago, sep, oct, nov, dic
        31, 31, 30, 31, 30, 31
    };
    return dias[mes - 1];
}

// Ejercicio 7, 8, 9 y 10

// Clase Fecha
class Fecha {
  public:
    Fecha(int mes,int dia);
    int mes();
    int dia();
    #if EJ >= 9 // Para ejercicio 9
    bool operator==(Fecha o);
    #endif
    void incrementar_dia();
  private:
    int _mes;
    int _dia;
};

Fecha::Fecha(int mes,int dia){
    _mes = mes;
    _dia = dia;
}

int Fecha::dia() {
    return _dia;
}

int Fecha::mes(){
    return _mes;
}

void Fecha::incrementar_dia() {
    if (_dia < dias_en_mes(_mes)){
       _dia = _dia + 1;
    } else {
        _dia = 1;
        _mes = _mes + 1;
    }
}

ostream& operator<<(ostream& os, Fecha f) {
    os << f.dia() << "/" << f.mes();
    return os;
}

#if EJ >= 9
bool Fecha::operator==(Fecha o) {
    bool igual_dia = this->dia() == o.dia();
    bool igual_mes = this->mes() == o.mes();
    return igual_dia && igual_mes;
}
#endif

// Ejercicio 11, 12

// Clase Horario

class Horario{
    public:
    Horario(uint hora, uint min);
    uint hora();
    uint min();
    bool operator < (Horario h);
    bool operator == (Horario h);

    private:
    uint _hora;
    uint _min;
};

Horario::Horario(uint hora,uint min) {
    _hora = hora;
    _min = min;
}

uint Horario::hora() {
    return _hora;
}

uint Horario::min() {
    return _min;
}

ostream& operator<<(ostream& os, Horario h) {
    os << h.hora() << ":" << h.min();
    return os;
}

bool ::Horario ::operator<(Horario h){
    if (this -> hora() == h.hora()){
        return this->min() < h.min();
    }
    else{
        return this->hora() < h.hora();
    }
}

bool ::Horario ::operator==(Horario h){
    bool horas = this->hora() == h.hora();
    bool minutos = this->min() == h.min();
    return horas && minutos;
}


// Clase Recordatorio
class Recordatorio {
    public:
    Recordatorio(Fecha fecha, Horario h, string evento);
    Fecha  fecha();
    Horario horario();
    string evento();

    private:
    Fecha _fecha = Fecha(1,1);
    Horario _horario = Horario(0,0);
    string _evento;
};

Recordatorio::Recordatorio(Fecha fecha, Horario h, string evento) {
    _fecha = fecha;
    _horario = h;
    _evento = evento;
}

Fecha Recordatorio::fecha() {
    return _fecha;
}

Horario Recordatorio::horario() {
    return _horario;
}

string Recordatorio::evento() {
    return _evento;
}


ostream& operator<<(ostream& os, Recordatorio r) {
    os << "" << r.evento()<< " @ " << r.fecha()<< " " << r.horario();
    return os;
}



// Ejercicio 14

// Clase Agenda

