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

using namespace std;

class ListLinkedDouble {
private:
  struct Node {
    int value;
    Node *next;
    Node *prev;
  };

public:
  ListLinkedDouble() : num_elems(0) {
    head = new Node;
    head->next = head;
    head->prev = head;
  }

  ListLinkedDouble(const ListLinkedDouble &other) : ListLinkedDouble() {
    copy_nodes_from(other);
    num_elems = other.num_elems;
  }

  ~ListLinkedDouble() { delete_nodes(); }

  void push_front(const int &elem) {
    Node *new_node = new Node{elem, head->next, head};
    head->next->prev = new_node;
    head->next = new_node;
    num_elems++;
  }

  void push_back(const int &elem) {
    Node *new_node = new Node{elem, head, head->prev};
    head->prev->next = new_node;
    head->prev = new_node;
    num_elems++;
  }

  void pop_front() {
    assert(num_elems > 0);
    Node *target = head->next;
    head->next = target->next;
    target->next->prev = head;
    delete target;
    num_elems--;
  }

  void pop_back() {
    assert(num_elems > 0);
    Node *target = head->prev;
    target->prev->next = head;
    head->prev = target->prev;
    delete target;
    num_elems--;
  }

  int size() const { return num_elems; }

  bool empty() const { return num_elems == 0; };

  const int &front() const {
    assert(num_elems > 0);
    return head->next->value;
  }

  int &front() {
    assert(num_elems > 0);
    return head->next->value;
  }

  const int &back() const {
    assert(num_elems > 0);
    return head->prev->value;
  }

  int &back() {
    assert(num_elems > 0);
    return head->prev->value;
  }

  const int &operator[](int index) const {
    assert(0 <= index && index < num_elems);
    Node *result_node = nth_node(index);
    return result_node->value;
  }

  int &operator[](int index) {
    assert(0 <= index && index < num_elems);
    Node *result_node = nth_node(index);
    return result_node->value;
  }

  ListLinkedDouble &operator=(const ListLinkedDouble &other) {
    if (this != &other) {
      delete_nodes();
      head = new Node;
      head->next = head->prev = head;
      copy_nodes_from(other);
      num_elems = other.num_elems;
    }
    return *this;
  }

  void display(std::ostream &out) const;

  void display() const { display(std::cout); }
  
  
  // Nuevo método
  // Se implementa más abajo
  void add_to(int index, int val);
  

private:
  Node *head;
  int num_elems;

  Node *nth_node(int n) const;
  void delete_nodes();
  void copy_nodes_from(const ListLinkedDouble &other);
  
  // Nuevos métodos
  // Se implementan más abajo
  static void attach(Node *node, Node *before);  
  static void detach(Node *node);
};

ListLinkedDouble::Node *ListLinkedDouble::nth_node(int n) const {
  int current_index = 0;
  Node *current = head->next;

  while (current_index < n && current != head) {
    current_index++;
    current = current->next;
  }

  return current;
}

void ListLinkedDouble::delete_nodes() {
  Node *current = head->next;
  while (current != head) {
    Node *target = current;
    current = current->next;
    delete target;
  }

  delete head;
}

void ListLinkedDouble::copy_nodes_from(const ListLinkedDouble &other) {
  Node *current_other = other.head->next;
  Node *last = head;

  while (current_other != other.head) {
    Node *new_node = new Node{current_other->value, head, last};
    last->next = new_node;
    last = new_node;
    current_other = current_other->next;
  }
  head->prev = last;
}

void ListLinkedDouble::display(std::ostream &out) const {
  out << "[";
  if (head->next != head) {
    out << head->next->value;
    Node *current = head->next->next;
    while (current != head) {
      out << ", " << current->value;
      current = current->next;
    }
  }
  out << "]";
}

std::ostream &operator<<(std::ostream &out, const ListLinkedDouble &l) {
  l.display(out);
  return out;
}

//@ <answer>
//---------------------------------------------------------------
// Modificar a partir de aquí
// --------------------------------------------------------------

// Tiene coste O(1) ya que las operaciones que se realizan son de coste constante
void ListLinkedDouble::attach(Node *node, Node *before) {
  Node *prev = before->prev;
  node->next = before;
  node->prev = prev;
  prev->next = node;
  before->prev = node;
}

// Tiene coste O(1) ya que las operaciones que se realizan son de coste constante
void ListLinkedDouble::detach(Node *node) {
  Node *prev = node->prev;
  Node *next = node->next;
  prev->next = next;
  next->prev = prev;
  node->next = node->prev = nullptr;
}

// Tiene coste O(n) donde n es el index del nodo que se quiere modificar. Esto se debe
// a que nth_node recorre hasta que lleguemos a index
void ListLinkedDouble::add_to(int index, int val) {
  Node *nodo = nth_node(index);
  nodo->value += val;

  Node *next = nodo->next;
  Node *prev = nodo->prev;
  detach(nodo);

  if(prev->value > nodo->value) {
    while(prev->value > nodo->value && prev != head) {
      prev = prev->prev;
    }
    attach(nodo, prev->next);
  } else {
    while(next->value < nodo->value && next != head) {
      next = next->next;
    }
    attach(nodo, next);
  }
}

//}}}  


bool tratar_caso() {
  // Introduce aquí el código para tratar un caso de prueba.
  // Devuelve false si se ha leído la marca de fin de entrada;
  // true en caso contrario.
  int N, i, m;

  cin >> N;
  cin >> i;
  cin >> m;

  if(N == 0 && i == 0 && m == 0) {
    return false;
  }

  ListLinkedDouble lista;

  for(int j = 0; j < N; j++) {
    int elem;
    cin >> elem;
    lista.push_back(elem);
  }

  lista.add_to(i, m);

  cout << lista << endl;

  return true;
}

//---------------------------------------------------------------
// No modificar por debajo de esta línea
// --------------------------------------------------------------
//@ </answer>


int main() {
#ifndef DOMJUDGE
  std::ifstream in("sample.in");
  auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
  
  while(tratar_caso()) { }

#ifndef DOMJUDGE
  std::cin.rdbuf(cinbuf);
  // Descomentar si se trabaja en Windows
  // system("PAUSE");
#endif
  return 0;
}
