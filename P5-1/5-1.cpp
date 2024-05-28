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
#include <cstdlib>

using namespace std;

void suavizar(list<int> &l) {
  auto it = l.begin();
  auto it_sig = ++l.begin();

  while (it_sig != l.end()) {
    if((*it - *it_sig == 1) || (*it - *it_sig == -1)){ // diferencia de 1
      ++it;
      ++it_sig;
    }
    else if(*it == *it_sig){
      it_sig = l.erase(it_sig);
    }
    else if(*it + 1 < *it_sig){
      l.insert(it_sig, *it + 1);
      --it_sig;
    }
    else if(*it > *it_sig + 1){
      l.insert(it_sig, *it_sig + 1);
      --it_sig;
    }
  }
  
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
  cout << endl;

  return true;
}

int main() {
/* #ifndef DOMJUDGE
  std::ifstream in("sample.in");
  auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif */

  while (tratar_caso()) { }

/* #ifndef DOMJUDGE
  std::cin.rdbuf(cinbuf);
#endif */
  return 0;
}
