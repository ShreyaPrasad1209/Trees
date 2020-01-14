#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  		Node* insert(Node* root, int data) {       //Insertion Code
            if(root == NULL) {
                return new Node(data);      // Insert the first node, if root is NULL. 
            } else {
                Node* cur;
                if(data <= root->data) {
                    cur = insert(root->left, data);
                    root->left = cur;
                } else {
                    cur = insert(root->right, data);
                    root->right = cur;
               }

               return root;
           }
        }

/* you only have to complete the function given below.  
Node is defined as  

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/

    void preOrder(Node *root) {
        if(root==NULL)
          return;
        else
        {
            cout<<root->data<<" ";
            preOrder(root->left);
            preOrder(root->right);  
        }  

    }

}; //End of Solution

int main() {
  
    Solution myTree;     //created object myTree of class Solution
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);    //accessing member function by dot operator
    }
  
	myTree.preOrder(root);
    return 0;
}
