#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

void print_queue(queue<int> &q1)
{
  int data = 0;
  int i = 0;
  const int SIZE = q1.size();

  while (i < SIZE)
  {
    data = q1.front();
    cout << data << " ";
    q1.pop();
    q1.push(data);
    i++;
  }
}

// Coste O(n) siendo n el tamaño de la cola
queue<int> pepsi_cola(queue<int> &cola_ini, queue<int> &colegas, const int &pringao)
{
  int data;
  queue<int> cola_final;
  bool encontrado = false;

  while (!cola_ini.empty() && !encontrado)
  {
    data = cola_ini.front();
    cola_final.push(data);
    cola_ini.pop();
    if (data == pringao)
      encontrado = true;
  }

  if(encontrado){
    while(!colegas.empty()){
      data = colegas.front();
      cola_final.push(data);
      colegas.pop();
    }
  }

  while (!cola_ini.empty())
  {
    data = cola_ini.front();
    cola_final.push(data);
    cola_ini.pop();
  }

  return cola_final;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso()
{
  int data;
  cin >> data;
  queue<int> cola_inicial;
  while (data != -1)
  {
    cola_inicial.push(data);
    cin >> data;
  }
  int pringao;
  queue<int> colegas;
  cin >> pringao;
  cin >> data;
  while (data != -1)
  {
    colegas.push(data);
    cin >> data;
  }

  print_queue(cola_inicial);
  queue<int> cola = pepsi_cola(cola_inicial, colegas, pringao);
  cout << endl;
  while (!cola.empty())
  {
    cout << cola.front() << " ";
    cola.pop();
  }

  cout << endl;
}

int main()
{
// Para la entrada por fichero.
// Comentar para acepta el reto
#ifndef DOMJUDGE
  std::ifstream in("datos.txt");
  auto cinbuf = std::cin.rdbuf(in.rdbuf()); // save old buf and redirect std::cin to casos.txt
#endif

  int numCasos;
  std::cin >> numCasos;
  for (int i = 0; i < numCasos; ++i)
    resuelveCaso();

// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
  std::cin.rdbuf(cinbuf);
  // system("PAUSE");
#endif

  return 0;
}