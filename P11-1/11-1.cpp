/*
 * ---------------------------------------------------
 *                ESTRUCTURAS DE DATOS
 * ---------------------------------------------------
 *              Facultad de Informática
 *         Universidad Complutense de Madrid
 * ---------------------------------------------------
 */
  
/*
  Indica el nombre y apellidos de los componentes del grupo
  ---------------------------------------------------------
  Componente 1:
  Componente 2:
*/

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>
// Añade los #include que necesites
#include <map>
#include <list>
#include <unordered_map>
#include <set>

using jugador = string;
using sospechosho = string;
using rasgo = string;
using culpable = string;

using namespace std;

class MisteriosDePekin {
public:
  // Interfaz pública de la clase.
  // ¡No olvides el coste de cada método!

  MisteriosDePekin(const string &culpable) {
    this->culpable = culpable;
  }

  void anyadir_rasgo(const string &sospechoso, const string &rasgo) {
    if(!jugadores.empty())
      throw domain_error("Juego ya empezado");
    if(listaSospsechosos.count(sospechoso) == 0){
      
    } else {

    }
  }

  vector<string> sospechosos() const {
    // Implementar
  }

  void nuevo_jugador(const string &nombre) {
    // Implementar
  }

  void jugador_descarta(const string &jugador, const string &rasgo) {
    // Implementar
  }

  bool jugador_enganyado(const string &jugador) const {
    // Implementar
  }

  bool puede_detener_culpable(const string &jugador) const {
    // Implementar
  }


private:
  // Representación interna del TAD
  culpable culpable;

  map<sospechosho, set<rasgo>> listaSospsechosos;

  struct infoSospechosos{
    sospechosho s;
    set<rasgo> rasgos;
  };

  unordered_map<jugador, infoSospechosos> jugadores;
  

  // También puedes añadir aquí las operaciones privadas que creas necesarias
};

bool tratar_caso() {
  // Implementa aquí el código para tratar un caso de prueba
  // Devuelve false si no se puede leer el caso de prueba porque
  // se ha encontrado el fin de fichero. Devuelve true en caso contrario
}

int main() {
#ifndef DOMJUDGE
  std::ifstream in("sample.in");
  auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
  
  while (tratar_caso()) {  }

#ifndef DOMJUDGE
  std::cin.rdbuf(cinbuf);
#endif
  return 0;
}
