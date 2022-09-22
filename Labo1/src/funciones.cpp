#include <vector>
#include "algobot.h"
using namespace std;

//----------------------------------------------------------------------------------------------------------------------
// Funciones Auxiliares
set<int> pasarASet(vector<int> t){
    set<int> res;
    for (int e : t){
        res.insert(e);
    }
    return res;
}

vector<int> passToList(set<int> s){
    vector<int> res;
    for (int e : s){
        res.push_back(e);
    }
    return res;
}

int contarAparicionesV1(vector<int>s, int e){
    int res = 0;
    for (int i:s) {
        if(i == e){
            res++;
        }
    }
    return res;
}
//----------------------------------------------------------------------------------------------------------------------

// Ejercicio 1
vector<int> quitar_repetidos(vector<int> s){
    vector<int> res = passToList(pasarASet(s));
    return res;
}

// Ejercicio 2
vector<int> quitar_repetidos_v2(vector<int> s){
    return quitar_repetidos(s);
}

// Ejercicio 3
bool mismos_elementos(vector<int> a, vector<int> b){
    bool res = pasarASet(a) == pasarASet(b);
    return res;
}

// Ejercicio 4
bool mismos_elementos_v2(vector<int> a, vector<int> b){
    return mismos_elementos(a,b);
}

// Ejercicio 5
map<int, int> contar_apariciones(vector<int> s){
    map<int, int> res;
    for (int i:s){
        res[i] = contarAparicionesV1(s,i);
    }
    return res; 
}

// Ejercicio 6
vector<int> filtrar_repetidos(vector<int> s){
    vector<int> res;
    for (int i:s) {
        if(contarAparicionesV1(s,i) == 1){
            res.push_back(i);
        }
    }
    return res;
}

// Ejercicio 7
set<int> interseccion(set<int> a, set<int> b){
    set<int> res;
    for (int e:a) {
        if(b.count(e) >= 1){
            res.insert(e);
        }
    }
    return res;
}

// Ejercicio 8
map<int, set<int>> agrupar_por_unidades(vector<int> s){
    return map<int, set<int>>();
}

// Ejercicio 9
vector<char> traducir(vector<pair<char, char>> tr, vector<char> str){
    return vector<char>();
}

// Ejercicio 10
bool integrantes_repetidos(vector<Mail> s){
    return true;
}

// Ejercicio 11
map<set<LU>, Mail> entregas_finales(vector<Mail> s){
    return map<set<LU>, Mail>();
}
