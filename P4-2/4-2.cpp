/*
 * ---------------------------------------------------
 *                ESTRUCTURAS DE DATOS
 * ---------------------------------------------------
 *              Manuel Montenegro Montes
 *              Facultad de Informática
 *         Universidad Complutense de Madrid
 * ---------------------------------------------------
 */

/*
 * Implementación del TAD Cola mediante listas enlazadas.
 */

#include <cassert>
#include <iostream>

using namespace std;

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

  void colar(QueueLinkedList colegas, T pringao)
  {
    Node *curr = front_node;
    if (colegas.empty())
    {
      return;
    }
    while (curr != nullptr)
    {
      if (curr->value == pringao)
      {
        Node *aux = curr->next;
        curr->next = colegas.front_node;
        colegas.back_node->next = aux;
      }
      curr = curr->next;
    }
  }

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

void tratar_caso()
{
  int elem, pringao;
  QueueLinkedList<int> cola;
  QueueLinkedList<int> colegas;

  while (cin >> elem && elem != -1)
  {
    cola.push(elem);
  }

  cin >> pringao;

  while (cin >> elem && elem != -1)
  {
    colegas.push(elem);
  }

  cola.colar(colegas, pringao);
}

int main()
{

  int numCasos;
  cin >> numCasos;
  for (int i = 0; i < numCasos; ++i)
  {
    tratar_caso();
  }

  return 0;
}
