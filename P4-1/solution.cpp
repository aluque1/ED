#include <iostream>
#include <fstream>
#include <stack>

// Alejandro Luque Villegas

using namespace std;

// función que resuelve el problema
string resolver(stack<char> pila)
{
  /* 
      1. leer con un readline
      2. Si es un parentesis
   */

  bool correct = true;
  
  return correct == true ? "SI" : "NO";
}

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
  char elem;
  stack<char> pila;

  // Read the input with a readline
  string line;
  getline(std::cin, line);  

  if (!std::cin) // fin de la entrada
    return false;

  string sol = resolver(pila);

  std::cout << sol << "\n";

  return true;
}


int main()
{
  // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
  std::ifstream in("casos.txt");
  auto cinbuf = std::cin.rdbuf(in.rdbuf());
  std::ofstream out("datos.out");
  auto coutbuf = std::cout.rdbuf(out.rdbuf());
#endif

  while (resuelveCaso())
    ;

    // para dejar todo como estaba al principio
#ifndef DOMJUDGE
  std::cin.rdbuf(cinbuf);
  std::cout.rdbuf(coutbuf);
  //system("PAUSE");
#endif
  return 0;
}
