#include <iostream>
#include <fstream>

#include "list_linked_single.h"

// función que resuelve el problema
// comentario sobre el coste, O(n), donde N es es el numero de elementos de la lista
void resolver(ListLinkedSingle datos)
{
  datos.duplicate();
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
  // leer secuencia de números hasta el final de linea
  std::string caso;
  getline(std::cin, caso);

  
  ListLinkedSingle list;
  for (int i = 0; i < caso.size(); i++)
  {
    list.push_back(caso.substr(i, 1));
  }

  resolver(list);

  list.display();
}

int main()
{
  int numCasos;
  std::cin >> numCasos;
  for (int i = 0; i < numCasos; ++i)
    resuelveCaso();
  return 0;
}

