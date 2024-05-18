#include <iostream>
#include <fstream>

#include "list_linked_single.h"

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
  // leer los datos de la entrada
  std::string datos;

  // read data with getline, if 0 return false
  if (!std::getline(std::cin, datos) || *datos.begin() == '0')
    return false;
  
  // create list
  ListLinkedSingle list;
  // initialize list with data
  for (int i = 0; i < datos.size(); i++)
  {
    list.push_back(datos.substr(i, 1));
  }

  list.revert();
  list.display();

  return true;
}

int main()
{
  while (resuelveCaso())
    ;
  return 0;
}