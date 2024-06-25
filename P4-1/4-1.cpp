#include <iostream>
#include <fstream>
#include <stack>

// Alejandro Luque Villegas

using namespace std;

// función que resuelve el problema
bool resolver(string str)
{
  bool correct = true;
  stack<char> pila;

  long unsigned i = 0;
  
  while(i < str.length() && correct){
    if(str[i] == '(' || str[i] == '[' || str[i] == '{')
      pila.push(str[i]);
    else if(str[i] == ')'){
      if(pila.empty() || pila.top() != '(')
        correct = false;
      else
        pila.pop();
    }
    else if(str[i] == ']'){
      if(pila.empty() || pila.top() != '[')
        correct = false;
      else
        pila.pop();
    }
    else if(str[i] == '}'){
      if(pila.empty() || pila.top() != '{')
        correct = false;
      else
        pila.pop();
    }
    ++i;
  }
  return correct;
}

bool resuelveCaso()
{
	string h;
	getline(cin, h);
	if (!std::cin)
		return false;

	bool sol = resolver(h);

	cout << (sol ? "SI" : "NO") << "\n";

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
