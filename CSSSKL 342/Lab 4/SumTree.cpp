#include <iostream>
using namespace std;

class B {
private:
  int val;
  B* left;
  B* right;
public:
  B(int v, B* l, B* r) : val(v), left(l), right(r) { }
   int sum() {
       return sum(this);
   }

   int sum(B* root) {
       if (root == NULL) return 0;
       return (root->val + sum(root->left) + sum(root->right));
   }

   int findMax(){
       return findMax(this);
   }

   int findMax(B* root){
       if (root == NULL) return INT_MIN;

       int value = root->val;
       int lvalue = findMax(root->left);
       int rvalue = findMax(root->right);
       if (lvalue > value)
           value = lvalue;
       if (rvalue > value)
           value = rvalue;
       return value;
   }

};

int main() { 
    B* B01 = new B(1, nullptr, nullptr);  
    B* B09 = new B(9, nullptr, nullptr);  
    B* B13 = new B(13, nullptr, nullptr);  
    B* B16 = new B(16, nullptr, nullptr);  
    B* B22 = new B(22, nullptr, nullptr); 
    B* B28 = new B(28, nullptr, nullptr);  
    B* B50 = new B(50, nullptr, nullptr); 
    B* B61 = new B(61, nullptr, nullptr);
    B* B07 = new B(7, B01, B09);  
    B* B14 = new B(14, B13, B16);  
    B* B25 = new B(25, B22, B28);  
    B* B60 = new B(60, B50, B61);  
    B* B12 = new B(12, B07, B14);  
    B* B42 = new B(42, B25, B60);  
    B* B18 = new B(18, B12, B42);  
    
    int total = B18->sum();  
    cout << "sum of Binary Tree = " << total << endl;

    int max = B18->findMax();
    cout << "max value of Binary Tree = " << max << endl;
}