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
  Indica el nombre y apellidos de los componentes del grupo
  ---------------------------------------------------------
  Componente 1:
  Componente 2:
*/
//@ </answer>

#include <iostream>
#include <fstream>
#include <cassert>
#include <memory>
#include <utility>

template <class T>
class BinTree
{
public:
  BinTree() : root_node(nullptr) {}

  BinTree(const T &elem)
      : root_node(std::make_shared<TreeNode>(nullptr, elem, nullptr)) {}

  BinTree(const BinTree &left, const T &elem, const BinTree &right)
      : root_node(std::make_shared<TreeNode>(left.root_node, elem,
                                             right.root_node)) {}

  bool empty() const { return root_node == nullptr; }

  const T &root() const
  {
    assert(root_node != nullptr);
    return root_node->elem;
  }

  BinTree left() const
  {
    assert(root_node != nullptr);
    BinTree result;
    result.root_node = root_node->left;
    return result;
  }

  BinTree right() const
  {
    assert(root_node != nullptr);
    BinTree result;
    result.root_node = root_node->right;
    return result;
  }

  void display(std::ostream &out) const { display_node(root_node, out); }

private:
  // Las definiciones de TreeNode y NodePointer dependen recursivamente
  // la una de la otra. Por eso declaro 'struct TreeNode;' antes de NodePointer
  // para que el compilador sepa, cuando analice la definición de NodePointer,
  // que TreeNode va a ser definida más adelante.

  struct TreeNode;
  using NodePointer = std::shared_ptr<TreeNode>;

  struct TreeNode
  {
    TreeNode(const NodePointer &left, const T &elem, const NodePointer &right)
        : elem(elem), left(left), right(right) {}

    T elem;
    NodePointer left, right;
  };

  NodePointer root_node;

  static void display_node(const NodePointer &root, std::ostream &out)
  {
    if (root == nullptr)
    {
      out << ".";
    }
    else
    {
      out << "(";
      display_node(root->left, out);
      out << " " << root->elem << " ";
      display_node(root->right, out);
      out << ")";
    }
  }
};

template <typename T>
std::ostream &operator<<(std::ostream &out, const BinTree<T> &tree)
{
  tree.display(out);
  return out;
}

// lee un árbol binario de la entrada estándar
template <typename T>
inline BinTree<T> readTree(T vacio) {
   T raiz;
   std::cin >> raiz;
   if (raiz == vacio) { // es un árbol vacío
      return {};
   } else { // leer recursivamente los hijos
      auto iz = readTree(vacio);
      auto dr = readTree(vacio);
      return {iz, raiz, dr};
   }
}

using namespace std;

// ----------------------------------------------------------------
// Escribe tu solución a continuación.
//
// Puedes definir funciones auxiliares. En ese caso, asegúrate de que están
// entre las etiquetas <answer> y </answer>, e indica el coste de cada una
// de ellas.
//@ <answer>

struct sol{
  bool esZurdo;
  int numHijos;
};

// Implementa la función pedida aquí. ¡No te olvides del coste!
template <typename T>
sol zurdo(const BinTree<T> &tree)
{
  if (tree.empty()) // CB : arbol vacio => zurdo = true;
    return {true, 0};
  else if(tree.left().empty() && tree.right().empty()) // CB : arbol es hoja => zurdo = true;
    return {true, 1};
  else{ // CR : arbol no vacio y no hoja : zurdo = true si ambos hijos son zurdo y el hijo izquierdo tiene mas hijos que el derecho
    sol iz = zurdo(tree.left());
    sol dr = zurdo(tree.right());
    if(iz.esZurdo && dr.esZurdo && iz.numHijos > dr.numHijos) 
      return {true, 1 + iz.numHijos + dr.numHijos};
    else
      return {false, 1 + iz.numHijos + dr.numHijos};
  }
}

//@ </answer>
// No modifiques nada por debajo de esta línea
// ----------------------------------------------------------------

void tratar_caso()
{
  BinTree<char> tree;
  tree = readTree('.');
  
  sol s = zurdo(tree);
  s.esZurdo ? cout << "SI\n" : cout << "NO\n";
}

int main()
{
  #ifndef DOMJUDGE
    std::ifstream in("sample.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf());
  #endif
  int num_casos;
  cin >> num_casos;
  for (int i = 0; i < num_casos; ++i)
    tratar_caso();
  
  
  #ifndef DOMJUDGE
    std::cin.rdbuf(cinbuf);
  #endif
  return 0;
}
