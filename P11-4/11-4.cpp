#include <iostream>
#include <fstream>
#include <map>
#include <list>
#include <unordered_map>
#include <queue>
#include <deque>
#include <set>
#include <unordered_set>
#include <stack>
#include <forward_list>
using namespace std;

bool resuelveCaso();

// resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso()
{

  std::string op;
  std::cin >> op;
  if (!std::cin)
    return false;

  Hospital hospital;

  while (op != "FIN")
  {

    try
    {

      if (op == "altaMedico")
      {

        medico m;
        std::cin >> m;

        hospital.altaMedico(m);
      }

      else if (op == "pedirConsulta")
      {

        paciente p;
        medico m;

        std::cin >> p >> m;

        hospital.pedirConsulta(p, m);
      }

      else if (op == "siguientePaciente")
      {

        medico m;
        std::cin >> m;
        std::cout << hospital.siguientePaciente(m) << '\n';
      }

      else if (op == "atenderConsulta")
      {

        medico m;
        std::cin >> m;
        hospital.atenderConsulta(m);
      }
      if (op == "abandonarConsulta")
      {
        paciente p;
        std::cin >> p;
        listaMedicos lista = hospital.abandonarConsulta(p);
        cout << "Medicos abandonados: ";
        int i = 0;
        for (medico m : lista)
        {
          cout << m;
          if (i < lista.size() - 1)
            cout << " ";
          i++;
        }
        cout << '\n';
      }
    }
    catch (std::domain_error &e)
    {

      std::cout << "ERROR: " << e.what() << "\n";
    }

    std::cin >> op;
  }

  std::cout << "---\n";

  return true;
}
int main()
{
  while (resuelveCaso())
    ;
  return 0;
}