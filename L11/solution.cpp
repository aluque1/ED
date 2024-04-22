/*
 * ---------------------------------------------------
 *                ESTRUCTURAS DE DATOS
 * ---------------------------------------------------
 *              Facultad de Informática
 *         Universidad Complutense de Madrid
 * ---------------------------------------------------
 */

/*
 * Introduce el nombre y apellidos de los/as componentes del grupo:
 *
 * Estudiante 1: Alejandro Luque Villegas
 * Estudiante 2:
 *
 */

#include <iostream>
#include <stdexcept>
#include <cassert>
#include <fstream>
#include <vector>
#include <utility>

using namespace std;

class ConteoVotos {
public:
  void nuevo_estado(const string &nombre, int num_compromisarios) {
    // Completar
  }

  void sumar_votos(const string &estado, const string &partido, int num_votos) {
    // Completar
  }

  string ganador_en(const string &estado) const {
    // Completar
  }

  vector<pair<string,int>> resultados() const {
    // Completar
  }

private:
  using Estado = string;
  using Partido = string;

  class Elecciones{
    void nuevo_estado(const string &nombre, int num_compromisarios) {
      if(estados.count(nombre) > 0) throw std::domain_error("El estado ya existe");
      estados[nombre] = {num_compromisarios, {}};
    }



    struct EstadoInfo
    {
      int num_compromisarios;
      unordered_map<Partido, int> votos; // dentro de cada estado no se pide ordenar los partidos alfabeticamente
      Partido ganador;
    };


    unordered_map<Estado, EstadoInfo> estados; // en ningun momento nos pide los estados ordenados alfabeticamente
    map<Partido, int> partidos_a_nivel_nacional;
  }
  
};


bool tratar_caso() {
  // Completar
}

int main() {
#ifndef DOMJUDGE
  std::ifstream in("sample.in");
  auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

  while (tratar_caso()) {  }

#ifndef DOMJUDGE
  std::cin.rdbuf(cinbuf);
  // Descomentar si se trabaja en Windows
  // system("PAUSE");
#endif
  return 0;
}
