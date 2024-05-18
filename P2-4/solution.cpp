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
    void duplicate();
    void inverse();

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
    void merge(ListLinkedSingle & l2);
    void interseccion(const ListLinkedSingle & l2);
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

template <class Type>
void ListLinkedSingle<Type>::merge(ListLinkedSingle & l2) {
    assert( head != l2.head && ordenada() && l2.ordenada());
    
}


template <class Type>
void ListLinkedSingle<Type>::inverse(){
    Node * prev = nullptr; //anterior nodo visitado
    Node * cur = head;     //nodo actual visitado
    while(cur != nullptr){
        Node * sig = cur->next; //nodo siguiente a visitar.
        cur->next = prev; //el nodo siguiente del actual pasa a ser el anterior.
        prev = cur; //actualizamos los punteros, el anterior pasa a ser el actual.
        cur = sig;  //el actual pasa a ser el siguiente.
    }
    head = prev;
}

template <class Type>
void ListLinkedSingle<Type>::duplicate(){
    Node * cur = head;  //nodo actual visitado.
    while(cur != nullptr){
        cur->next = new Node {cur->value, cur->next}; //el siguiente del actual es el duplicado
        cur = cur->next->next; //avanzo dos nodos para llegar al siguiente a duplicar.
        num_elems++;
    }
}


// O(N), siendo N el numero de elementos de las listas
void tratar_caso() {
  // Implementar. Aquí se procesa cada caso de prueba
    int num1, num2;
    cin >> num1;
    ListLinkedSingle<int> listThis;
    ListLinkedSingle<int> listOther;
    for (int i = 0; i < num1; i++) {
        int elem;
        cin >> elem;
        listThis.push_back(elem);
    }
    cin >> num2;
    for (int i = 0; i < num2; i++) {
        int elem;
        cin >> elem;
        listOther.push_back(elem);
    }

    ListLinkedSingle<int> listMerge;
    int indexL1 = 0, indexL2 = 0;
    int valorL1, valorL2;
    
    while(indexL1 < listThis.size() && indexL2 < listOther.size()){
        valorL1 = listThis.at(indexL1);
        valorL2 = listOther.at(indexL2);
        if(valorL1 <= valorL2){
            listMerge.push_back(valorL1);
            indexL1++;
        } else if(valorL1 > valorL2){
            listMerge.push_back(valorL2);
            indexL2++;
        }
    }

    listMerge.display();


    listThis.merge(listOther);
    listOther.display();
    listThis.display();
    listThis.inverse();
    listThis.display();
    listThis.duplicate();
    listThis.display();
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

