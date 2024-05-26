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
#include <cassert>
#include <list>

using namespace std;

void suavizar(list<int> &l) {
  // Implementa aquí la función pedida
}

bool tratar_caso() {
  // Escribe aquí el código para leer y tratar un caso de prueba.
  // La función debe devolver false si no se puede leer ningún caso de prueba
  // porque se ha llegado al fin de la entrada, o true en caso contrario.

  int num_elem;
  cin >> num_elem;
  if (!cin) return false;

  list<int> l;
  for (int i = 0; i < num_elem; i++) {
    int elem;
    cin >> elem;
    l.push_back(elem);
  }

  suavizar(l);

  for (int elem : l) {
    cout << elem << " ";
  }
}

int main() {
#ifndef DOMJUDGE
  std::ifstream in("sample.in");
  auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

  while (tratar_caso()) { }

#ifndef DOMJUDGE
  std::cin.rdbuf(cinbuf);
#endif
  return 0;
}
