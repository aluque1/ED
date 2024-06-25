#include <iostream>
#include <fstream>
#include <assert.h>
using namespace std;

template <class Type>
class ListLinkedSingle{
    public:

    ListLinkedSingle() : num_elems(0), head(nullptr) {
        //head = nullptr;
    }
    bool ordenada() const;

    int size() const { return num_elems; } //O(1) => O(n) si tuviesemos que recorrer la lista.
    void remove(int pos); //O(num_elems) 
    void insert(int pos, Type elem); //O(num_elems) 
    void pop_front(){ //O(1)
        assert(head != nullptr);
        Node * aux = head;
        head = head->next;
        delete aux;
        num_elems--;
    }
    void push_back(Type elem); //O(num_elems) => tenemos que recorrer la lista. 
    void push_front(Type elem){ //O(1)
        head = new Node {elem, head};
        num_elems++;
    }
    void intersect(const ListLinkedSingle & l2);
    void pop_back();
    const Type& front() const { assert(head != nullptr); return head->value;} //O(1)
    Type& front() { assert(head != nullptr); return head->value;} //O(1)
    const Type& back() const; //O(N)
    Type& back(); //O(N)
    const Type& at(int pos) const ; //O(N)
    Type& at(int pos); //O(num_elems)

    void display() const; //O(num_elems)

    private:

    struct Node {
        Type value;
        Node * next;
    };

    int num_elems;
    Node * head;
};


template <class Type>
void ListLinkedSingle<Type>::pop_back() {
    assert(head != nullptr);
    Node * prev = nullptr;
    Node * cur = head;
    while(cur->next != nullptr){
        prev = cur;
        cur = cur->next;
    }
    //cur->next == nullptr => es el último. => prev es el penúltimo o nullptr.
    delete cur;
    if(prev == nullptr){
        head = nullptr;
    } else{
        prev->next = nullptr;
    }
    num_elems--;
}

template <class Type>
const Type& ListLinkedSingle<Type>::back() const{
    assert(head != nullptr);
    Node * cur = head;
    while(cur->next !=nullptr){
        cur = cur->next;
    }
    return cur->value;
}

template <class Type>
Type& ListLinkedSingle<Type>::back(){
    assert(head != nullptr);
    Node * cur = head;
    while(cur->next !=nullptr){
        cur = cur->next;
    }
    return cur->value;
}

template <class Type>
void ListLinkedSingle<Type>::insert(int pos, Type elem){
    assert(0 <= pos && pos < num_elems);
    if(pos == 0){
        head = new Node {elem, head};
    } else{
        Node * cur = head;
        for(int i = 1; i < pos; i++){
            cur = cur->next; // Esta instrucción se ejecuta pos-1 veces.
        }
        //Entonces, cur apunta al nodo pos-1. Justo antes de donde tenemos que insertar el nuevo.
        cur->next = new Node {elem, cur->next};
    }
    num_elems++;
}

template <class Type>
void ListLinkedSingle<Type>::remove(int pos){
    assert(0 <= pos && pos < num_elems);
    Node * aux;
    if(pos == 0){
        aux = head;
        head = head->next;
        delete aux;
    } else{
        Node * cur = head;
        for(int i = 1; i < pos; i++){
            cur = cur->next; // Esta instrucción se ejecuta pos-1 veces.
        }
        aux = cur->next;
        cur->next = cur->next->next;
        delete aux;
    }
    num_elems--;
}

template <class Type>
Type& ListLinkedSingle<Type>::at(int pos){
    assert(0 <= pos && pos < num_elems);
    Node * cur = head;
    for(int i = 0; i < pos; i++){
        cur = cur->next;
    }
    return cur->value;
}

template <class Type>
const Type& ListLinkedSingle<Type>::at(int pos) const{
    assert(0 <= pos && pos < num_elems);
    Node * cur = head;
    for(int i = 0; i < pos; i++){
        cur = cur->next;
    }
    return cur->value;
}

template <class Type>
void ListLinkedSingle<Type>::push_back(Type elem){
    if(head == nullptr){
        head = new Node {elem, nullptr};
    } else{
        Node * cur = head;
        while(cur->next !=nullptr){
            cur = cur->next;
        }
        //cur->next == nullptr.
        cur->next = new Node {elem, nullptr};
    }
    num_elems++;
}

template <class Type>
void ListLinkedSingle<Type>::display() const{
    Node * cur = head;
    cout << "[";
    while(cur != nullptr){
        cout << cur->value;
        cur = cur->next;
        if(cur != nullptr) cout << ", ";
    }
    cout << "]";
}

template <class Type>
bool ListLinkedSingle<Type>::ordenada() const{
   if (num_elems > 0){
        Node * cur = head;
        while(cur->next != nullptr){
            if(cur->value > cur->next->value){
                return false;
            }
            cur = cur->next;
        }
    }
    return true;
}

// La complejidad de esta funcion es O(n) siendo n el número de elementos de la lista this
template <class Type>
void ListLinkedSingle<Type>::intersect(const ListLinkedSingle & l2) {
    Node *cur1 = head;
    Node *cur2 = l2.head;
    Node *prev = nullptr;

    while (cur1 != nullptr && cur2 != nullptr) {
        if (cur1->value < cur2->value) {
            Node *temp = cur1;
            cur1 = cur1->next;
            delete temp;
            if (prev == nullptr) {
                head = cur1;
            } else {
                prev->next = cur1;
            }
            num_elems--;
        } else if (cur1->value > cur2->value) {
            cur2 = cur2->next;
        } else {
            prev = cur1;
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
    }

    while (cur1 != nullptr) {
        Node *temp = cur1;
        cur1 = cur1->next;
        delete temp;
        if (prev == nullptr) {
            head = cur1;
        } else {
            prev->next = cur1;
        }
        num_elems--;
    }
}

void tratar_caso() {
    int num_elems;

    cin >> num_elems;

    ListLinkedSingle<int> lista1;
    ListLinkedSingle<int> lista2;

    for (int i = 0; i < num_elems; i++) {
        int elem;
        cin >> elem;
        lista1.push_back(elem);
    }

    cin >> num_elems;

    for (int i = 0; i < num_elems; i++) {
        int elem;
        cin >> elem;
        lista2.push_back(elem);
    }

    lista1.intersect(lista2);

    lista1.display();

    cout << endl;
}


//@ </answer>

// ¡No modificar nada debajo de esta línea!
// ----------------------------------------------------------------

int main() {
#ifndef DOMJUDGE
  std::ifstream in("sample.in");
  auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

  // Leemos el número de casos de prueba que vendrán a continuación
  int num_casos;
  cin >> num_casos;

  for (int i = 0; i < num_casos; i++) {
    if(i == 33){
      cout << "Para";
    }
    tratar_caso();
  }

#ifndef DOMJUDGE
  std::cin.rdbuf(cinbuf);
 // system("PAUSE");
#endif
  return 0;
}
