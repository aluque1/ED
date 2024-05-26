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

// A continuación aparecen implementaciones de los TADs vistos esta semana.
//
// Puedes utilizar uno o varios de estos TADs, pero eso no significa que debas
// utilizarlos todos.

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cassert>

using namespace std;

// --------------------------------------------------------------------------------
// Implementación del TAD Pila mediante arrays
// --------------------------------------------------------------------------------

const int DEFAULT_CAPACITY = 10;

template <typename T>
class StackArray
{
public:
  StackArray(int initial_capacity = DEFAULT_CAPACITY)
      : num_elems(0), capacity(initial_capacity), elems(new T[capacity]) {}

  ~StackArray() { delete[] elems; }

  StackArray(const StackArray &other);
  StackArray &operator=(const StackArray<T> &other);

  void push(const T &elem)
  {
    if (num_elems == capacity)
    {
      resize_array(capacity * 2);
    }

    elems[num_elems] = elem;
    num_elems++;
  }

  void pop()
  {
    assert(num_elems > 0);
    num_elems--;
  }

  const T &top() const
  {
    assert(num_elems > 0);
    return elems[num_elems - 1];
  }

  T &top()
  {
    assert(num_elems > 0);
    return elems[num_elems - 1];
  }

  bool empty() const { return num_elems == 0; }

private:
  int num_elems;
  int capacity;
  T *elems;

  void resize_array(int new_capacity);
};

template <typename T>
StackArray<T>::StackArray(const StackArray<T> &other)
    : num_elems(other.num_elems), capacity(other.capacity),
      elems(new T[other.capacity])
{
  for (int i = 0; i < num_elems; i++)
  {
    elems[i] = other.elems[i];
  }
}

template <typename T>
void StackArray<T>::resize_array(int new_capacity)
{
  T *new_elems = new T[new_capacity];

  for (int i = 0; i < num_elems; i++)
  {
    new_elems[i] = elems[i];
  }

  delete[] elems;
  elems = new_elems;
  capacity = new_capacity;
}

template <typename T>
StackArray<T> &StackArray<T>::operator=(const StackArray<T> &other)
{
  if (this != &other)
  {
    if (capacity < other.num_elems)
    {
      delete[] elems;
      elems = new T[other.capacity];
      capacity = other.capacity;
    }
    num_elems = other.num_elems;
    for (int i = 0; i < num_elems; i++)
    {
      elems[i] = other.elems[i];
    }
  }

  return *this;
}

// --------------------------------------------------------------------------------
// Implementación del TAD Cola mediante listas enlazadas simples con puntero al
// último elemento
// --------------------------------------------------------------------------------

template <typename T>
class QueueLinkedList
{
public:
  QueueLinkedList() : front_node(nullptr), back_node(nullptr) {}
  QueueLinkedList(const QueueLinkedList &other)
  {
    copy_nodes_from(other.front_node);
  }

  ~QueueLinkedList() { free_nodes_from(front_node); }

  QueueLinkedList &operator=(const QueueLinkedList &other)
  {
    if (this != &other)
    {
      free_nodes_from(front_node);
      copy_nodes_from(other.front_node);
    }
    return *this;
  }

  void push(const T &elem)
  {
    Node *new_node = new Node{elem, nullptr};
    if (back_node == nullptr)
    {
      back_node = new_node;
      front_node = new_node;
    }
    else
    {
      back_node->next = new_node;
      back_node = new_node;
    }
  }

  void pop()
  {
    assert(front_node != nullptr);
    Node *target = front_node;
    front_node = front_node->next;
    if (back_node == target)
    {
      back_node = nullptr;
    }
    delete target;
  }

  T &front()
  {
    assert(front_node != nullptr);
    return front_node->value;
  }

  const T &front() const
  {
    assert(front_node != nullptr);
    return front_node->elem;
  }

  bool empty() const { return (front_node == nullptr); }

private:
  struct Node
  {
    T value;
    Node *next;
  };

  void copy_nodes_from(Node *other);
  void free_nodes_from(Node *other);

  Node *front_node;
  Node *back_node;
};

template <typename T>
void QueueLinkedList<T>::copy_nodes_from(Node *other)
{
  if (other == nullptr)
  {
    front_node = nullptr;
    back_node = nullptr;
  }
  else
  {
    front_node = new Node{other->value, nullptr};
    back_node = front_node;
    Node *current = other->next;
    while (current != nullptr)
    {
      Node *new_node = new Node{current->value, nullptr};
      back_node->next = new_node;
      current = current->next;
      back_node = new_node;
    }
  }
}

template <typename T>
void QueueLinkedList<T>::free_nodes_from(Node *other)
{
  Node *current = other;
  while (current != nullptr)
  {
    Node *next = current->next;
    delete current;
    current = next;
  }
}

// --------------------------------------------------------------------------------
// Implementación del TAD doble cola mediante listas doblemente enlazadas
// --------------------------------------------------------------------------------

template <typename Elem>
class Dequeue
{
private:
  struct Node
  {
    Elem value;
    Node *next;
    Node *prev;
  };

public:
  Dequeue()
  {
    head = new Node;
    head->next = head;
    head->prev = head;
  }

  Dequeue(const Dequeue &other) : Dequeue() { copy_nodes_from(other); }

  ~Dequeue() { delete_nodes(); }

  void push_front(const Elem &elem)
  {
    Node *new_node = new Node{elem, head->next, head};
    head->next->prev = new_node;
    head->next = new_node;
  }

  void push_back(const Elem &elem)
  {
    Node *new_node = new Node{elem, head, head->prev};
    head->prev->next = new_node;
    head->prev = new_node;
  }

  void pop_front()
  {
    assert(head->next != head);
    Node *target = head->next;
    head->next = target->next;
    target->next->prev = head;
    delete target;
  }

  void pop_back()
  {
    assert(head->next != head);
    Node *target = head->prev;
    target->prev->next = head;
    head->prev = target->prev;
    delete target;
  }

  bool empty() const { return head->next == head; };

  const Elem &front() const
  {
    assert(head->next != head);
    return head->next->value;
  }

  Elem &front()
  {
    assert(head->next != head);
    return head->next->value;
  }

  const Elem &back() const
  {
    assert(head->next != head);
    return head->prev->value;
  }

  Elem &back()
  {
    assert(head->next != head);
    return head->prev->value;
  }

  Dequeue &operator=(const Dequeue &other)
  {
    if (this != &other)
    {
      delete_nodes();
      head = new Node;
      head->next = head->prev = head;
      copy_nodes_from(other);
    }
    return *this;
  }

private:
  Node *head;

  void delete_nodes();
  void copy_nodes_from(const Dequeue &other);
};

template <typename Elem>
void Dequeue<Elem>::delete_nodes()
{
  Node *current = head->next;
  while (current != head)
  {
    Node *target = current;
    current = current->next;
    delete target;
  }

  delete head;
}

template <typename Elem>
void Dequeue<Elem>::copy_nodes_from(const Dequeue &other)
{
  Node *current_other = other.head->next;
  Node *last = head;

  while (current_other != other.head)
  {
    Node *new_node = new Node{current_other->value, head, last};
    last->next = new_node;
    last = new_node;
    current_other = current_other->next;
  }
  head->prev = last;
}

//@ <answer>
// ===========================================================
// Escribe tu solución por debajo de esta línea
// ===========================================================

// ¡No te olvides del coste!
bool tratar_caso()
{
  int pilar;
  cin >> pilar;
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

  while(tratar_caso()){}

/* #ifndef DOMJUDGE
  std::cin.rdbuf(cinbuf);
#endif */
  return 0;
}
