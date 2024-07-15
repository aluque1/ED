#include <iostream>
#include <list>
#include <string>
#include <cctype>
using namespace std;

// includes añadidos para la solucion
#include <stack>


//O(n) en el número de lineas.
int comprueba_indentacion(const list<pair<int, char>> lineas) {
  auto it = lineas.begin();
  stack<int> ind; // Un stack para guardar las indentaciones actuales

  int num_linea = 1;
  ind.push(0);
  while(it != lineas.end()){
    auto [indent, letra] = *it;
    if(letra == '{') {
        if(indent <= ind.top())
            return num_linea;
        ind.push(indent);
    } else {
        if(indent != ind.top())
            return num_linea;
        if(letra == '}')
            ind.pop();
    }
    ++it;
    ++num_linea;
  }
  return -1;
}

bool tratar_caso() {
    int num_lineas;
    cin >> num_lineas;

    if (num_lineas == 0) return false;

    list<pair<int, char>> lineas;
    cin.ignore(10, '\n');
    for (int i = 0; i < num_lineas; i++) {
        string l;
        getline(cin, l);
        int indent = 0;
        while (isspace(l[indent])) {
            indent++;
        }
        lineas.push_back({ indent, l[indent] });
    }

    int result = comprueba_indentacion(lineas);

    if (result == -1) {
        cout << "CORRECTO\n";
    }
    else {
        cout << result << "\n";
    }

    return true;
}

int main() {
    while (tratar_caso()){}

    return 0;
}
