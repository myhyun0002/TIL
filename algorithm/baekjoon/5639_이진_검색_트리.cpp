#include <iostream>
#include <string>
#include <map>

using namespace std;

struct Node{
  public:
  int data;
  Node* leftChild;
  Node* rightChild;

  Node(int data, Node* leftChild, Node* rightChild){
    this->data = data;
    this->leftChild = leftChild;
    this->rightChild = rightChild;
  }
};


void BST_insert(Node* tree,Node* node){
  if(tree->data > node->data){      // 왼쪽에 위치
    if(tree->leftChild == NULL){
      tree->leftChild = node;
    }else{
      BST_insert(tree->leftChild,node);
    }
  }else{                      // 오른쪽에 위치
    if(tree->rightChild == NULL){
      tree->rightChild = node;
    }else{
      BST_insert(tree->rightChild,node);
    }
  }
}


void postorder(Node *node){
  if(node->leftChild != NULL){
    postorder(node->leftChild);
  }

  if(node->rightChild != NULL){
    postorder(node->rightChild);
  }

  cout << node->data << endl;

}


int main(){
  int node;
  Node* tree = NULL;

  while(!cin.eof()){
    cin >> node;

    if(tree == NULL){
      tree = new Node(node,NULL,NULL);
      continue;
    }
    
    Node* insert_node = new Node(node,NULL,NULL);

    BST_insert(tree,insert_node);
  }

  postorder(tree);

  return 0;
}