#include<bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
        int value;
        TreeNode *left;
        TreeNode *right;

        TreeNode(){
            value = 0;
            left = NULL;
            right = NULL;
        }

        TreeNode(int value){
            this->value = value;
            left = NULL;
            right = NULL;
        }
};

class Tree{
    public:
        TreeNode *root;
        Tree(){ root = NULL; }
        Tree(TreeNode *root){this->root = root;}

        void createTree();
        void insertNode(TreeNode * new_node);
       

        // Recursive Traversals
        void printPreorder(TreeNode* r);
        void printPostorder(TreeNode* r); 
        void printInorder(TreeNode* r);
    
};


void Tree::createTree(){
    TreeNode *p, *t;
    root = new TreeNode;
    int x;
    queue<TreeNode*> q; 
    cout<<"Enter root value\n";
    cin>>x;
    root->value = x;
    root->left = root->right = NULL;
    q.push(root);

    while (!q.empty())
    {
        p = q.front();
        q.pop();
        cout<<"Enter left child of "<<p->value<<": \n";
        cin>>x;
        if(x != -1){
            t = new TreeNode;
            t->value = x;
            t->left = t->right=NULL;
            p->left = t;
            q.push(t);
        }

        cout<<"Enter right child of "<<p->value<<": \n";
        cin>>x;
        if(x != -1){
            t = new TreeNode;
            t->value = x;
            t->left = t->right=NULL;
            p->right = t;
            q.push(t);
        }
    }
    

}
  
  void Tree::printPreorder(TreeNode* root){
      if(root){
          cout<<root->value<<" ";
          printPreorder(root->left);
          printPreorder(root->right);
      }
  }

void Tree::printPostorder(TreeNode* root) {
    if(root){
        printPostorder(root->left);
        printPostorder(root->right);
        cout<<root->value<<" ";

    }
}

void Tree::printInorder(TreeNode* root){
    if(root){
        printInorder(root->left);
        cout<<root->value<<" ";
        printInorder(root->right);
    }
}







  int main(){

      Tree t;
      int option, val;

      do{
          cout<<"\n\nMenu - Enter the operation code to perform the operation:"<<"\n"
          <<"1. To insert a Node."<<"\n"
          <<"2. To display the tree(PRE-ORDER)."<<"\n"
          <<"3. To display the tree(IN-ORDER)."<<"\n"
          <<"4. To display the tree(POST-ORDER)."<<"\n"
          <<"0. To Exit."<<"\n";

          cin>>option;
          TreeNode* new_node = new TreeNode();

          switch (option)
          {
          
          case 0:
              break;

          case 1:
              cout<<"INSERT\n";
              t.createTree();
              break;


          case 2:
              cout<<"PRINT TREE\n";
              cout<<"PRE-ORDER\n";
              t.printPreorder(t.root);
              cout<<endl;
              break;

          case 3:
              cout<<"PRINT TREE\n";
              cout<<"IN-ORDER\n";
              t.printInorder(t.root);
              cout<<endl;
              break;
          
          case 4:
              cout<<"PRINT TREE\n";
              cout<<"POST-ORDER\n";
              t.printPostorder(t.root);
              cout<<endl;
              break;
          }


      } while (option != 0);
      
      return 0;
  }