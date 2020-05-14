#include <iostream> 
using namespace std; 
template <class E>
class Node{
   int *keys; // array of keys
   int m;     //order of tree
   Node **C; // array of child pointers
   int n; // current number of keys
   bool leaf; // to check if leaf or not
public:
   Node(int _m, bool _leaf){
       m = _m;
       leaf = _leaf;
       keys = new int [2*m-1];
       C = new Node * [2*m];
       n = 0;
   }
   
   void traverse(){
       int i = 0;
       for(i=0; i < n; i++){
           if(leaf == false){
               C[i] -> traverse();
               cout << " " << keys[i];
           }
       }
       if (leaf == false){ 
        C[i]->traverse(); 
       }
   }
   Node* search(int k){
       int i = 0;
       while(i < n && k>keys[i]){
           i++;
       }
       if (keys[i] == k){
           return this;
       }
       if (leaf == true) {
        return NULL; 
       }
       return C[i]->search(k);
   }
   void insertNonFull(E data){
       int i = n-1; 
       if (leaf == true) { 
\
        while (i >= 0 && keys[i] > data) { 
            keys[i+1] = keys[i]; 
            i--; 
        } 
    } 
    else { 
        while (i >= 0 && keys[i] > data) 
            i--; 
        if (C[i+1]->n == 2*m-1) { 
            splitChild(i+1, C[i+1]); 
            if (keys[i+1] < data) {
                i++; 
            }
        } 
        C[i+1]->insertNonFull(data); 
    } 
   }
   void splitChild(int i, Node *y) { 
  Node *z = new Node(y->m, y->leaf); 
    z->n = m - 1; 
    for (int j = 0; j < m-1; j++) 
        z->keys[j] = y->keys[j+m]; 
    if (y->leaf == false) 
    { 
        for (int j = 0; j < m; j++) {
            z->C[j] = y->C[j+m]; 
            
        }
    } 
    y->n = m - 1; 
    for (int j = n; j >= i+1; j--) {
        C[j+1] = C[j]; 
        C[i+1] = z; 
        
    }
    for (int j = n-1; j >= i; j--) {
        keys[j+1] = keys[j]; 
        keys[i] = y->keys[m-1]; 
        n = n + 1; 
    
    }
} 
friend class Btree;
};
template <class D>
class Btree{
    Node *root;
    int m;
public:
    Btree(int _m){
        root = NULL;
        m = _m;
    }
    void insert(D data){
        if (root == NULL) { 
            root = new Node(m, true); 
            root->keys[0] = data;  
            root->n = 1;   
            
        
    } else { 
    
        if (root->n == 2*m-1) { 
            Node *s = new Node(m, false); 
            s->C[0] = root;  
            s->splitChild(0, root); 
            int i = 0; 
            if (s->keys[0] < data) 
                i++; 
            s->C[i]->insertNonFull(data); 
            root = s; 
        } 
        else{
            root->insertNonFull(data); 
    } 
    }
    }
        
    };

