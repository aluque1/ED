/*
 * ---------------------------------------------------
 *                ESTRUCTURAS DE DATOS
 * ---------------------------------------------------
 *              Facultad de Informática
 *         Universidad Complutense de Madrid
 * ---------------------------------------------------
 */
 
/*
 * MUY IMPORTANTE: Para realizar este ejercicio solo podéis
 * modificar el código contenido entre las etiquetas <answer>
 * y </answer>. Toda modificación fuera de esas etiquetas está
 * prohibida, pues no se tendrá en cuenta para la corrección.
 *
 * Tampoco esta permitido modificar las líneas que contienen
 * las etiquetas <answer> y </answer>, obviamente :-)
 */
 
//@ <answer>
/*
  Introduce aquí los nombres de los componentes del grupo:
  
  Componente 1:
  Componente 2:
*/
//@ </answer>

#include <iostream>
#include <cassert>
#include <fstream>
#include <cassert>
#include <list>

using namespace std;


enum class Categoria { Primero, Segundo, Postre };

struct Plato {
  Categoria categoria;
  string nombre;
};

// Sobrecarga del operador << para imprimir platos
ostream &operator<<(ostream &out, const Plato &plato) {
  switch (plato.categoria) {
    case Categoria::Primero:
      out << "1";
      break;
    case Categoria::Segundo:
      out << "2";
      break;
    case Categoria::Postre:
      out << "P";
      break;
  }
  out << " " << plato.nombre;
  return out;
}

//@ <answer>
//---------------------------------------------------------------
// Modificar a partir de aquí
// --------------------------------------------------------------


// Indica el coste en función del tamaño del parámetro de entrada
void ordenar_menu(list<Plato> &platos) {
  auto it = platos.begin();
  auto it_sig = ++platos.begin();

  while (it_sig != platos.end()) {
    if (it->categoria > it_sig->categoria) {
      platos.splice(it, platos, it_sig);
      it = platos.begin();
      it_sig = ++platos.begin();
    } else {
      ++it;
      ++it_sig;
    }
  }

}


bool tratar_caso() {
  // Introduce aquí el código para tratar un caso de prueba.
  // Devuelve false si ya no hay más casos de prueba que leer,
  // true en caso contrario.

  int n;  // Número de platos del menú

  cin >> n;

  if (n == 0) return false;

  list<Plato> platos;

  for (int i = 0; i < n; ++i){
    Plato p;
    char c;
    string nombre;
    cin >> c;
    switch (c)
    {
    case '1': // es un primer plato
      p.categoria = Categoria::Primero;
      getline(cin, nombre);
      p.nombre = nombre;
      platos.push_back(p);
      break;
    case '2': // es un segundo
      p.categoria = Categoria::Segundo;
      getline(cin, nombre);
      p.nombre = nombre;
      platos.push_back(p);
      break;
    case 'P': // es un postre
      p.categoria = Categoria::Postre;
      getline(cin, nombre);
      p.nombre = nombre;
      platos.push_back(p);
      break;
    default:
      break;
    }
  }

  ordenar_menu(platos);

  for (const Plato &p : platos) {
    cout << p << '\n';
  }

  cout << "---\n";

  return true;
}


//---------------------------------------------------------------
// No modificar por debajo de esta línea
// --------------------------------------------------------------
//@ </answer>


int main() {
/* #ifndef DOMJUDGE
  std::ifstream in("sample.in");
  auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif */
  
  while (tratar_caso()) {  }

/* #ifndef DOMJUDGE
  std::cin.rdbuf(cinbuf);
  // Descomentar si se trabaja en Windows
  // system("PAUSE");
#endif */
  return 0;
}

