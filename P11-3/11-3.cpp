// Include y definiciones para las marcas
#include <stdio.h>
#ifndef INICIO_CASOS
#define INICIO_CASOS
#define FIN_CASO
#define FIN_CASOS
#endif

#include <iomanip>
#include <iostream>
#include <string>
#include <stdexcept>
#include <unordered_map>
#include <list>
#include <map>
#include <fstream>

using namespace std;

using entrenador = string;
using pokemon = string;
using nivel = int;

class CentroPokemon
{
  struct info
  {                                                                                   // Para cada entrenador tenemos.
    list<pokemon> listaPokemon;                                                       // No necesitamos ningun tipo de orden en cuanto al nombre del pokemon
    map<nivel, pokemon> t_niveles;                                                    // Necestiamos para mantener en orden los niveles de los pokemons capturados
    unordered_map<pokemon, pair<nivel, list<pokemon>::iterator>> t_pokemon;           // no necesitamos ningun orden
  };
  unordered_map<entrenador, info> infoEntrenador;

  // Otra opción igualmente válida y correcta es tener t_pokemon a nivel global ne lugar de en info almacenando el entrenador :
  // unordered_map<pokemon, unordered_map<entrenador, pair<nivel, list<pokemon>::iterator>> t_pokemon;
  // Con este último, se podía hacer un poco más eficiente día de liberación.
  // Ya que recorres directamente el unordered_map de los entrenadores del pokemon a liberar, en lugar de todos los entrenadores.public :
  // E: Num de Entrenadores. P: Num de Pokemons.

  public:
  // O(log(P)).
  void capturar_pokemon(entrenador const &e, pokemon const &p, nivel n)
  {
                
  }

  // O(1).
  pair<pokemon, nivel> vencer_pokemon(entrenador const &e, nivel n)
  {
    
  }

  // O(E*log(P))
  int dia_de_liberacion(pokemon const &p)
  {
    
  }

  // O(log(P))
  pokemon gimnasio(entrenador const &e)
  {
    
  }
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{
  // leer los datos de la entrada

  string op;
  cin >> op;
  if (!cin)
    return false;

  CentroPokemon centro;

  while (op != "FIN")
  {

    try
    {

      if (op == "capturar_pokemon")
      {

        entrenador e;
        pokemon p;
        nivel n;
        cin >> e >> p >> n;

        centro.capturar_pokemon(e, p, n);
      }

      else if (op == "vencer_pokemon")
      {

        entrenador e;
        int n;
        cin >> e >> n;

        pair<pokemon, nivel> p = centro.vencer_pokemon(e, n);
        cout << e << " utiliza el pokemon " << p.first << " con nivel " << p.second << " para vencer a un nivel " << n << '\n';
      }

      else if (op == "dia_de_liberacion")
      {
        pokemon p;
        cin >> p;
        int n = centro.dia_de_liberacion(p);
        cout << "Liberados " << n << " pokemon " << p << '\n';
      }

      if (op == "gimnasio")
      {
        entrenador e;
        cin >> e;
        pokemon p = centro.gimnasio(e);
        cout << e << " deja el pokemon " << p << " en un gimnasio\n ";
      }
    }
    catch (invalid_argument &e)
    {

      cout << "ERROR: " << e.what() << "\n";
    }

    cin >> op;
  }

  cout << "---\n";

  return true;
}

int main()
{
#ifndef DOMJUDGE
  ifstream in("datos.txt");
  auto cinbuf = cin.rdbuf(in.rdbuf()); // save old buf and redirect cin to casos.txt
#endif

  while (resuelveCaso())
    ; // Resolvemos todos los casos

#ifndef DOMJUDGE // para dejar todo como estaba al principio
  cin.rdbuf(cinbuf);
  //system("PAUSE");
#endif
}