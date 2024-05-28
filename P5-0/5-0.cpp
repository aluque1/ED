/*
 * ---------------------------------------------------
 *                ESTRUCTURAS DE DATOS
 * ---------------------------------------------------
 *              Facultad de Informática
 *         Universidad Complutense de Madrid
 * ---------------------------------------------------
 */
 
/*
  Indica el nombre y apellidos de los componentes del grupo
  ---------------------------------------------------------
  Componente 1:
  Componente 2:
*/

#include <iostream>
#include <fstream>
#include <cassert>
#include <list>

using namespace std;

void eliminar_pares(list<int> &list){
  auto it = list.begin();
  while(it != list.end()){
    if(*it % 2 == 0){
      it = list.erase(it);
    }else{
      ++it;
    }
  }
}

template <typename T>
bool ordenada_ascendente(const list<T> &list){
  auto it = list.begin();
  if(it == list.end()) return true;
  auto it_sig = ++list.begin();

  while(it_sig != list.end()){
    if(*it > *it_sig){
      return false;
    }
    ++it;
    ++it_sig;
  }
  return true;
}

bool es_palindromo(const string &cadena){
  auto it_iz = cadena.begin();
  if(it_iz == cadena.end()) return true;
  auto it_de = --cadena.end();
  while(it_iz < it_de){
    if(*it_iz != *it_de){
      return false;
    }
    ++it_iz;
    --it_de;
  }

  return true;
}


int main() {
  list<int> listQuitaPares = {1, 2, 3, 4, 5, 6, 7, 8, 9};

  eliminar_pares(listQuitaPares);

  for(int i : listQuitaPares)
    cout << i << " ";
  
  cout << endl;

  list<int> listOrdenada = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  list<int> listDesordenada = {1, 2, 5, 3, 6, 7};

  if (ordenada_ascendente(listOrdenada))
    cout << "La lista ordenada es ascendente" << endl;
  else
    cout << "La lista ordenada no es ascendente" << endl;
    
  if (ordenada_ascendente(listDesordenada))
    cout << "La lista desordenada es ascendente" << endl;
  else
    cout << "La lista desordenada no es ascendente" << endl;
  
  if(es_palindromo("hola"))
    cout << "hola es palindromo" << endl;
  else 
    cout << "hola no es palindromo" << endl;

  if(es_palindromo("alala"))
    cout << "alala es palindromo" << endl;
  else
    cout << "alala no es palindromo" << endl;

  return 0;
}
