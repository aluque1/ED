#include <iostream>
#include <map>
#include <unordered_map>
#include <queue>
#include <list>

using namespace std;
using nombre = string;
using ataque = string;

class SistemaBatallas {
  private:

  struct heroeInfo {
    int salud;
    map<string, int> ataques;
    list<nombre>::iterator turno; // esto hay que ir actualizandolo cuando lo cambiemos de pos
  };

  struct villanoInfo { 
    int salud;
    int danyo;
    list<nombre>::iterator turno;
  };

  unordered_map<nombre, heroeInfo> heroes;
  unordered_map<nombre, villanoInfo> villanos;

  list<nombre> turnos;

  public:

  void aparece_villano(nombre villano, int s, int a) {
    if(villanos.count(villano) != 0 || heroes.count(villano) != 0) // O(1)
      throw std::invalid_argument("Personaje ya existente");
    else{
      turnos.push_back(villano); // O(1)
      villanos[villano] = {s, a, --turnos.end()}; // O(1) el --turnos.end() es O(1) para coger la posicion en la que esta.
      // ya que turnos.end() es la posicion de fin de la lista
    }
  }

  void aparece_heroe(nombre heroe, int puntos) {
    if(villanos.count(heroe) != 0 || heroes.count(heroe) != 0) // O(1)
      throw std::invalid_argument("Personaje ya existente");
    else {

    }
  }

  void aprende_ataque(nombre heroe, string ataque, int daño){
    if(heroes.count(heroe) == 0) // O(1)
      throw std::invalid_argument("Heroe no existente");
    
  }


};

bool tratar_caso() {
  SistemaBatallas sb;
  string comando;
  cin >> comando;
  if (cin.eof()) return false;

  while (comando != "FIN") {
    try {
      if (comando == "aparece_villano") {
        string nombre;
        int puntos, ataque;
        cin >> nombre >> puntos >> ataque;
        sb.aparece_villano(nombre, puntos, ataque);
      } else if (comando == "aparece_heroe") {
        string nombre; int puntos;
        cin >> nombre >> puntos;
        sb.aparece_heroe(nombre, puntos);
      } else if (comando == "aprende_ataque") {
        string nombre; string ataque; int valor;
        cin >> nombre >> ataque >> valor;
        sb.aprende_ataque(nombre, ataque, valor);
      } else if (comando == "mostrar_ataques") {
        string nombre;
        cin >> nombre;
        vector<pair<string, int>> ataques = sb.mostrar_ataques(nombre);
        cout << "Ataques de " << nombre << "\n";
        for (const auto &[at, v] : ataques) {
          cout << at << " " << v << "\n";
        }
      } else if (comando == "mostrar_turnos") {
        vector<pair<string, int>> turnos = sb.mostrar_turnos();
        cout << "Turno:" << "\n";
        for (const auto &[nombre, pv] : turnos) {
          cout << nombre << " " << pv << "\n";
        }
      } else if (comando == "villano_ataca") {
        string villano, heroe;
        cin >> villano >> heroe;
        bool derrotado = sb.villano_ataca(villano, heroe);
        cout << villano << " ataca a " << heroe << "\n";
        if (derrotado) {
          cout << heroe << " derrotado\n";
        }
      } else if (comando == "heroe_ataca") {
        string heroe, ataque, villano;
        cin >> heroe >> ataque >> villano;
        bool derrotado = sb.heroe_ataca(heroe, ataque, villano);
        cout << heroe << " ataca a " << villano << "\n";
        if (derrotado) {
          cout << villano << " derrotado\n";
        }
      }
    } catch (invalid_argument &e) {
      cout << "ERROR: " << e.what() << "\n";
    }
    cin >> comando;
  }

  cout << "---\n";

  return true;

}

int main() {
#ifndef DOMJUDGE
  std::ifstream in("sample3.in");
  auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

  while (tratar_caso()) { }

#ifndef DOMJUDGE
  std::cin.rdbuf(cinbuf);
#endif
  return 0;
}