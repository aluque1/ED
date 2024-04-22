#include <iostream>
#include <stdexcept>
#include <cassert>
#include <fstream>
#include <vector>
#include <utility>

using namespace std;

using Linea = string;
using Parada = string;

class MapaMetro {
  struct lineaInfo
  {
    map<int, Estacion> paradas; // usamon un map en vez de una lista para poder insertar nuevas paradas en en medio sin costes grandes
  };

  struct EstacionInfo
  {
    map<Linea, int> paradas; // usamos un map en vez de una lista para poder insertar nuevas lineas en medio sin grandes
  };
  
  
  unordered_map<Linea, lineaInfo> lineas;
  unordered_map<Estacion, EstacionInfo> estaciones;
};

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
   
	std::string op;
	std::cin >> op;
	if (!std::cin)
		return false;
	
	Ferrovistan ferrovistan;
	
	while (op != "FIN") {
		
		try {
			
			if (op == "nueva_linea") {
				
				linea l;
				std::cin >> l;
				
				ferrovistan.nueva_linea(l);
				
			}
			
			else if (op == "nueva_estacion") {
				
				linea l;
				estacion e;
				distancia d;

				std::cin >> l >> e >> d;
				
				ferrovistan.nueva_estacion(l, e, d);
				
			}
			
			else if (op == "eliminar_estacion") {
				
				estacion e;
				std::cin >> e;
				ferrovistan.eliminar_estacion(e);
			}
		
			else if (op == "lineas_de") {
				
				estacion e;
				std::cin >> e;
				vector<linea> lineas = ferrovistan.lineas_de(e);
				cout << "Lineas de " << e << ": ";
				int i = 0;
				for (linea l : lineas) {
					cout << l;
					if (i < lineas.size() - 1) cout << " ";
					i++;
				}
				cout << '\n';
				
			}
			if (op == "proxima_estacion") {
				linea l;
				estacion e;
				std::cin >> l >> e;
				
				cout << ferrovistan.proxima_estacion(l, e) << '\n';
			}
			
		}
		catch(std::domain_error& e) {
			
			std::cout << "ERROR: " << e.what() << "\n";
		}
		
		std::cin >> op;
		
	}
	
	std::cout << "---\n";
	
	return true;
}


int main() {
   
   while (resuelveCaso());
   return 0;
}