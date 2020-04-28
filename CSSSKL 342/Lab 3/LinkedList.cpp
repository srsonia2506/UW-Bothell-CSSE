#include <iostream>
using namespace std;
class Node {
public:
  int   data;
  Node* next;
  Node(int d) { data  = d; next  = nullptr; }
};

class List {
private:
  Node* head;
  Node* tail;
public:
  List() { }
  List(int v) { head  = new Node(v); }
  void print() {
    Node* p  = head;
    while (p  != nullptr) {
      cout  << p->data  << " ";
      p  = p->next;
    }
    cout << endl;
  }
  void prepend(Node n) {
      Node* tmp = new Node(n);
      tmp->next = head;
      head = tmp;
  }

  void append(Node n) {
      Node* tmp = new Node(n);
      tmp->next = NULL;

      if (head == NULL){
          head = tmp;
          tail = tmp;
      } else {
          tail->next = tmp;
          tail = tail->next;
      }
  }

  void penultimate(Node n) {
      Node* temp = head;
      Node* a = new Node(n);

      if (temp == NULL || temp->next == NULL)
          return;

      while (temp != NULL) {
          if (temp->next->next == NULL) {
              a->next = tail;
              temp->next=a;
              return;
          }
          temp = temp->next;
      }
  }

  int max() {
      Node* temp = head;

      if (temp == NULL) return -1;
      else if (temp->next == NULL) return temp->data;

      int max= temp->data;

      while (temp->next != NULL) {
          if (temp->data > max) {
              max = temp->data;
          }
          temp = temp->next;
      }
      return max;
  }
};

int main() {
    List* lis  = new List();
    lis->prepend(3);
    lis->prepend(5);
    lis->append(42);
    lis->penultimate(33);
    lis->print();

    cout  << "biggest = " << lis->max() << endl;
}
