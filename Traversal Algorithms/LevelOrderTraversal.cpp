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
  		Node* insert(Node* root, int data) {
            if(root == NULL) {
                return new Node(data);
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
/*
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
  int max(int a,int b)
  {
    return a>b?a:b;
  }

  void getK(Node *root, int K)
  {
      if(root==NULL)
      {
          return;
      }
      if(K==1)
      {
          cout<<root->data<<" ";
          return;
      }
      getK(root->left,K-1);
      getK(root->right,K-1);
  }

  int Level(Node *root)
  {
   if(root==NULL)
        {
            return 0;
        }
        int lh=Level(root->left);
        int rh=Level(root->right);
        int H=max(lh,rh)+1;
     return H;   
  }
    void levelOrder(Node * root) {
         int H = Level(root);
     
        for(int i=1;i<=H;i++)
        {
              getK(root,i);
              
        } 
        return;
    }

}; //End of Solution

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  
	myTree.levelOrder(root);
    return 0;
}
