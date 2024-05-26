/*
 * ---------------------------------------------------
 *                ESTRUCTURAS DE DATOS
 * ---------------------------------------------------
 */
 
 
/*
 * Introduce el nombre y apellidos de los/as componentes del grupo:
 *
 * Estudiante 1:
 * Estudiante 2:
 *
 */

#include <iostream>
#include <fstream>
#include <list>


using namespace std;


bool es_toeplitz(const list<list<int>> &matriz) {
  // Implementar
}

bool tratar_caso() {
  // Implementar
}

int main() {
#ifndef DOMJUDGE
  std::ifstream in("sample.in");
  auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

  while (tratar_caso()) { }

#ifndef DOMJUDGE
  std::cin.rdbuf(cinbuf);
  // Descomentar si se trabaja en Windows
  // system("PAUSE");
#endif

  return 0;
}