#include <iostream>
#include <fstream>
#include <list>
// añadiendo includes que creo necesarios:
#include <unordered_map>
#include <map>
#include <set>
using namespace std;

using Participante = string;
using Objeto = string;
using Puja = int;
using Posicion = list<Participante>::iterator;
struct infoParticipante{
    int saldo;
    /* 
        un mapa sin orden para guardar los objetos por los qye ha pujado y cuanto ha pujado por ellos ademas de un iterador a la
        posicion para que cuando tengamos que borrar al participante de una puja existente sea mas rapido
    */
    unordered_map<Objeto, pair<Puja, Posicion>> pujasPendientes; 
    set<Objeto> objetosGanados; // Un set ya que solo queremos saber que objetos ha ganado en orden alfabetico
};

struct infoObjeto{
    Puja minimo;
    bool vendido = false;
    map<Puja, list<Participante>> pujas; // Usamos un map para encontrar la puja ganadora mas rapido, y usamos un list para tener el orden cronologico de los participantes que han pujado por un objeto
};


class CasaDePujas
{

public:
    // O(1)
    void nuevo_participante(Participante part, int saldo_inicial) {
        if(participantes.count(part) != 0) throw domain_error("Participante ya existente");
        if(saldo_inicial <= 0) throw domain_error("Saldo inicial no valido");
        participantes[part].saldo = saldo_inicial;
    }

    // O(1)
    void nueva_subasta(Objeto obj, int puja_minima)
    {
        if(objetos.count(obj) != 0) throw domain_error("Objeto no valido");
        if(puja_minima <= 0) throw domain_error("Puja minima no valida");
        objetos[obj].minimo = puja_minima;
    }

    // O(logP) donde P es el numero de participantes. => En el caso peor, todos los participantes podrían haber pujado por el objeto.
    void nueva_puja(Participante part, Objeto obj, int cantidad)
    {
        if(participantes.count(part) == 0) throw domain_error("Participante no existente");
        if(objetos.count(obj) == 0 || objetos[obj].vendido) throw domain_error("Objeto no valido");
        if(participantes[part].pujasPendientes.count(obj) != 0) throw domain_error("Participante repetido");
        if(participantes[part].saldo < cantidad || objetos[obj].minimo > cantidad) throw domain_error("Cantidad no valida");    
        objetos[obj].pujas[cantidad].push_back(part); // O(log(Participantes)) ya que es un mapa ordenado
        participantes[part].pujasPendientes[obj] = {cantidad, --objetos[obj].pujas[cantidad].end()}; // la cantidad y un iterador
        participantes[part].saldo -= cantidad;
    }

    // O(Obj), donde Obj es el numero de objetos.
    list<Objeto> subastas_ganadas(Participante part) const
    {
        if(participantes.count(part) == 0) throw domain_error("Participante no existente");
        list<Objeto> objs;
        for(auto obj : participantes.at(part).objetosGanados)
            objs.push_back(obj);
        return objs;
    }

    // Para cada objeto tengo que ver si el participante forma parte de la puja, por lo tanto
    //O(obj*log(P))
    void abandonar_casa(Participante part)
    {  
        if(participantes.count(part) == 0) throw domain_error("Participante no existente");
        for(auto [obj, pair] : participantes[part].pujasPendientes){ // del unordered_map que tenemos en participantes de las pujas pendientes
            Puja p = pair.first; // el valor de la puja
            auto it = pair.second; // O(1)
            objetos[obj].pujas[p].erase(it); //O(logP)
            if(objetos[obj].pujas[p].empty()) // Nos quedan pujas por el objeto
                objetos[obj].pujas.erase(p); //O(logP)
        }
        participantes.erase(part);
    }

    //O(logObj) + O(P)
    string cerrar_subasta(Objeto obj)
    {
        if(objetos.count(obj) == 0 || objetos[obj].vendido) throw domain_error("Objeto no valido");
        if(objetos[obj].pujas.empty()) throw domain_error("Objeto no vendido");
        auto it = --objetos[obj].pujas.end(); // tenemos las pujas en un map => la ultima es la mayor puja
        string ganador = it->second.front(); // O(1) el primero es el ganador ya que es el primero que pujo por el objeto
        participantes[ganador].pujasPendientes.erase(obj); // O(1) Eliminamos el objeto de las subastas pendientes en las que esta el participante
        participantes[ganador].objetosGanados.insert(obj); // O(logObj) Insertamos, al ser un set es log en vez de 1
        it->second.pop_front(); // O(1) Lo eliminamos de la lista de los participantes que han pujado por el objeto
        for(auto [puja, parts] : objetos[obj].pujas){ // para cada una de las pujas
            for(string part : parts){ // para cada uno de los participantes de la puja
                participantes[part].saldo += puja; // devolvemos el dinero que han pujado a los perdedores
                participantes[part].pujasPendientes.erase(obj); // Eliminamos el objeto del map de objetos pendientes
            }
        } 
        objetos[obj].vendido = true; // lo marcamos como vendido
        return ganador;
    }

private:

unordered_map<Participante, infoParticipante> participantes;
unordered_map<Objeto, infoObjeto> objetos;
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuraci�n, y escribiendo la respuesta
bool resuelveCaso()
{
    // leer los datos de la entrada
    string op;
    std::cin >> op;
    if (!std::cin)
        return false;
    CasaDePujas casa;
    while (op != "FIN")
    {

        try
        {

            if (op == "nuevo_participante")
            {

                string nombre;
                int saldo;
                std::cin >> nombre >> saldo;

                casa.nuevo_participante(nombre, saldo);
                cout << "OK\n";
            }

            else if (op == "nueva_subasta")
            {

                string nombre;
                int minimo;
                std::cin >> nombre >> minimo;

                casa.nueva_subasta(nombre, minimo);
                cout << "OK\n";
            }

            else if (op == "nueva_puja")
            {

                string nombre, objeto;
                int minimo;
                std::cin >> nombre >> objeto >> minimo;

                casa.nueva_puja(nombre, objeto, minimo);
                cout << "OK\n";
            }
            else if (op == "abandonar_casa")
            {
                string nombre;
                std::cin >> nombre;
                casa.abandonar_casa(nombre);
                cout << "OK\n";
            }
            else if (op == "subastas_ganadas")
            {
                string nombre;
                std::cin >> nombre;
                list<string> v = casa.subastas_ganadas(nombre);
                cout << nombre << " ha ganado: ";
                for (string el : v)
                {
                    cout << el << " ";
                }
                cout << "\n";
            }
            else if (op == "cerrar_subasta")
            {
                string nombre;
                std::cin >> nombre;
                string ganador = casa.cerrar_subasta(nombre);
                cout << nombre << " ha sido ganado por: " << ganador;
                cout << "\n";
            }
        }
        catch (std::domain_error &e)
        {

            std::cout << "ERROR: " << e.what() << "\n";
        }

        std::cin >> op;
    }

    std::cout << "---\n";

    return true;
}

int main()
{
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
    std::ofstream out("e.out");
    auto coutbuf = std::cout.rdbuf(out.rdbuf());
#endif
    while (resuelveCaso())
        ; // Resolvemos todos los casos
#ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
    std::cout.rdbuf(coutbuf);
#endif
}