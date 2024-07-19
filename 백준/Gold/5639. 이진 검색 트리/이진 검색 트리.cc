#include <iostream>


using namespace std;

struct Node{
    int value;
    Node* left;
    Node* right;
    Node(int val): value(val),left(nullptr),right(nullptr) {};
};

class Tree{
private:
    Node* root;
    void insertNode(int val, Node* parent){
        if(val > parent->value){
            if(parent->right == nullptr){
                parent->right = new Node(val);
            }
            else{
                insertNode(val,parent->right);
            }
        }
        else if(val < parent->value){
            if(parent->left == nullptr){
                parent->left = new Node(val);
            }
            else{
                insertNode(val,parent->left);
            }
        }
    }

public:
    Tree(): root(nullptr) {};
    void insert(int val){
        if (root == nullptr){
            root = new Node(val);
        }
        else{
            insertNode(val,root);
        }
    }
    void print(Node* parent){
        if(parent == nullptr){
            return;
        }
        print(parent->left);
        print(parent->right);
        cout<<parent->value<<endl;
        

   }
    Node* getRoot(){
        return root;
    }
};


int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    Tree tr;
    int a;
	while (cin >> a) {
        if (cin.eof())break;
        tr.insert(a);
    }
    tr.print(tr.getRoot());
    return 0;
}

