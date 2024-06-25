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

bool es_toeplitz(const list<list<int>> &matriz)
{
  auto it_f = matriz.begin();
  auto it_aux = it_f;

  while(it_f != --matriz.end()){ // aqui es antes ya que estamos siempre mirando tambien la fila + 1
    list<int> current = *it_aux; // la fila actual
    list<int> next = *(++it_aux);// la fila siguiente
    auto it_current = current.begin(); // primer elem de la fila actual
    auto it_next = ++next.begin(); // segundo elem de la fila siguiente

    while(it_next != next.end()){
      if(*it_current != *it_next) // Si el elem i-esimo de la fila actual != elem (i + 1)-esimo de la fila siguiente -> no es toeplitz
        return false;
      ++it_current;
      ++it_next;
    }

    ++it_f;
    
  }
  return true;
}

bool tratar_caso()
{
  list<list<int>> matriz;
  list<int> fila;
  int n;

  while (cin >> n && n != 0)
  {
    fila.push_back(n);
    while (cin >> n && n != 0)
    {
      fila.push_back(n);
    }
    matriz.push_back(fila);
    fila.clear();
  }

  if (matriz.empty())
  {
    return false;
  }

  es_toeplitz(matriz) ? cout << "SI\n" : cout << "NO\n";

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
  // Descomentar si se trabaja en Windows
  // system("PAUSE");
#endif

  return 0;
}