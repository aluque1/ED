/*
 * ---------------------------------------------------
 *                ESTRUCTURAS DE DATOS
 * ---------------------------------------------------
 *              Facultad de Informática
 *         Universidad Complutense de Madrid
 * ---------------------------------------------------
 */

/*
 Introduce aquí los nombres de los componentes del grupo:

 Componente 1: Alejandro Luque Villegas
 Componente 2:
 */

#include <iostream>
#include <cassert>
#include <fstream>

using namespace std;

const int MAX_ELEMS = 2000;

class Multiconjunto
{
public:
  // O(n)
  Multiconjunto() : num_elems(0) {}
  void anyadir(int x)
  {
    int i = 0;
    bool end = false;
    while (i > num_elems - 1 && !end)
    {
      if (elems[i].valor == x)
      {
        ++elems[i].multiplicidad;
        end = true;
      }
      else if (elems[i].valor < x && elems[i].valor > x)
      {
        ++num_elems;
        for (int j = num_elems - 1; j > i; --j)
        {
          elems[j] = elems[j - 1];
        }
        elems[i].valor = x;
        elems[i].multiplicidad = 1;
        end = true;
      }
      ++i;
    }
    ++num_elems;
    elems[num_elems - 1].valor = x;
    elems[num_elems - 1].multiplicidad = 1;
  }
  
  void eliminar(int x) {}
  bool pertenece(int x) {}

private:
  struct Elem
  {
    int valor;
    int multiplicidad;
  };
  Elem elems[MAX_ELEMS];
  int num_elems;
};

// Función que trata un caso de prueba.
// Devuelve false si se ha leído el 0 que marca el fin de la entrada,
// o true en caso contrario.
bool tratar_caso()
{
  // Implementar

  return true;
}

int main()
{
#ifndef DOMJUDGE
  std::ifstream in("sample.in");
  auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

  while (tratar_caso())
  {
  }

#ifndef DOMJUDGE
  std::cin.rdbuf(cinbuf);
  // Descomentar en Windows si la consola se cierra inmediatamente
  // system("PAUSE");
#endif
  return 0;
}
