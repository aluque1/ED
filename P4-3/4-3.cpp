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
  Componente 1: Jose Villacres Zumaeta C109
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

struct Action
{
  string word;
  string action;
};

deque<string> facundo(const vector<string> &texto)
{
  stack<Action> last_action;
  deque<string> save_data;

  string element;
  for (int i = 0; i < texto.size(); i++)
  {
    element = texto[i];
    if (element != "*" && element != "+")
    {
      save_data.push_back(element);
      last_action.push({element, "word"});
    }
    else
    {
      if (element == "*") // delete
      {
        if (!last_action.empty() && !save_data.empty())
        {
          string before = save_data.back();
          save_data.pop_back();
          last_action.push({before, "*"});
        }
      }
      else // undo
      {
        if (!last_action.empty() && last_action.top().action == "*") // reescribimos la palabra anterior
        {
          string ant = last_action.top().word;
          save_data.push_back(ant);
          last_action.pop();
        }
        else if (!last_action.empty() && last_action.top().action != "*" && !save_data.empty()) // borramos la palabra anterior
        {
          save_data.pop_back();
          last_action.pop();
        }
      }
    }
  }
  return save_data;
}

// ¡No te olvides del coste!
void tratar_caso()
{
  string data = "";
  getline(cin, data);

  // quitamos el carriage return
  if (!data.empty() && (data.find('\r') == data.size() - 1))
    data = data.replace(data.find("\r"), 1, "");

  vector<string> palabras;
  string letras;

  for (int i = 0; i < data.size(); i++)
  {
    if (data[i] != ' ')
    {
      letras += data[i];
    }

    if (data[i] == ' ' || i == data.size() - 1)
    {
      palabras.push_back(letras);
      letras = "";
    }
  }

  deque<string> textoFinal = facundo(palabras);

  while (!textoFinal.empty())
  {
    cout << textoFinal.front() << " ";
    textoFinal.pop_front();
  }
  cout << endl;
}

//@ </answer>
// ===========================================================
// No modifiques nada por debajo de esta línea
// ===========================================================

int main()
{
  /* #ifndef DOMJUDGE
    std::ifstream in("sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
  #endif */

  // El primer dato leído indica el número de casos de prueba
  int num_casos;
  cin >> num_casos;
  // El puntero de lectura ahora mismo se sitúa detrás del número de casos de prueba
  // Si se queda ahí, la próxima llamada a getline() leería el resto de esa línea, que
  // no es lo que queremos. Por tanto, avanzamos la lectura de la entrada hasta el
  // fin de línea.
  cin.ignore(10, '\n');

  // Llamamos a tratar_caso tantas veces como indica num_caso
  for (int i = 0; i < num_casos; i++)
  {
    tratar_caso();
  }

  /* #ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
  #endif */
  return 0;
}
