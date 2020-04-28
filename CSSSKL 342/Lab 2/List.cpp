#include <iostream>
using namespace std;

struct Node {  
    int val;  
    Node* next;  
    Node(int v) { val = v; next = NULL; }
};

class List {
private:  
    Node* head;

public:
    List() {}
    List(int a) {
        this->append(a);
    }
    List(int a,int b) {
        this->append(a);
        this->append(b);
    }
    List(int a, int b, int c) {
        this->append(a);
        this->append(b);
        this->append(c);
    }
    List(int a, int b, int c, int d) {
        this->append(a);
        this->append(b);
        this->append(c);
        this->append(d);
    }
    List& append(int v) {    
        Node* n = new Node(v);    
        Node* p = head;    
        if (p == NULL) {      
            head = n;    
        } else {      
            while (p->next != NULL) p = p->next;      
            p->next = n;    
        }    return *this;  
    }  
    
    void show() {    
        Node* p = head;    
        while (p != NULL) {      
            cout << p->val << " ";      
            p = p->next;    
        }    cout << endl;  
    }
};

int main() {
    List* p = new List(1);
    p->show();
    List* q= new List(2,3);
    q->show();
    List* r = new List(4,5,6);
    r->show();
    List* s = new List(7,8,9,10);
    s->show();

    return 0;
}