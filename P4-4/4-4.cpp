/*
 * ---------------------------------------------------
 *                ESTRUCTURAS DE DATOS
 * ---------------------------------------------------
 *              Facultad de Inform�tica
 *         Universidad Complutense de Madrid
 * ---------------------------------------------------
 */

/*
 * MUY IMPORTANTE: Para realizar este ejercicio solo pod�is
 * modificar el c�digo contenido entre las etiquetas <answer>
 * y </answer>. Toda modificaci�n fuera de esas etiquetas est�
 * prohibida, pues no se tendr� en cuenta para la correcci�n.
 *
 * Tampoco esta permitido modificar las l�neas que contienen
 * las etiquetas <answer> y </answer>, obviamente :-)
 */

//@ <answer>
/*
  Indica el nombre y apellidos de los componentes del grupo
  ---------------------------------------------------------
  Componente 1:
  Componente 2:
*/
//@ </answer>

// A continuaci�n aparecen implementaciones de los TADs vistos esta semana.
//
// Puedes utilizar uno o varios de estos TADs, pero eso no significa que debas
// utilizarlos todos.

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cassert>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

//@ <answer>
// ===========================================================
// Escribe tu solución por debajo de esta línea
// ===========================================================
queue<int> vuelo_en_paravela(queue<int> torres)
{
  deque<int> aux;
  queue<int> paravela;
  int a;

  while (!torres.empty())
  {
    int n = torres.front();
    torres.pop();
    if (aux.empty())
    {
      paravela.push(-1);
      aux.push_back(n);
    }
    else
    {
      int num = -1;
      bool found = false;
      int ini = aux.back();
      aux.push_front(ini);
      aux.pop_back();
      while (aux.back() != ini)
      {
        if (aux.back() > n && !found)
        {
          found = true;
          num = aux.back();
        }
        else
        {
          aux.push_front(aux.back());
          aux.pop_back();
        }
      }
      paravela.push(num);
    }
  }
  return paravela;
}

// ¡No te olvides del coste!
bool tratar_caso()
{
  int n;
  queue<int> torres;

  if (!cin)
    return false;

  while ((cin >> n) && n != -1)
  {
    torres.push(n);
    if (!cin)
      return false;
  }

  queue<int> paravela = vuelo_en_paravela(torres);

  while (!paravela.empty())
  {
    /* n = paravela.front();
    (n == -1) ? cout << "NO HAY\n" : cout << n << "\n";
    paravela.pop(); */
    cout << paravela.front() << endl;
    paravela.pop();
  }
  cout << "---\n";
  return true;
}

//@ </answer>
// ===========================================================
// No modifiques nada por debajo de esta línea
// ===========================================================

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
#endif
  return 0;
}
