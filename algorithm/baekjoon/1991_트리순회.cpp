#include <iostream>
#include <string>
#include <map>
using namespace std;

map<char,pair<char,char>> bst;

void preorder(char node){
  cout << node;

  if(bst[node].first != '.'){
    preorder(bst[node].first);
  }

  if(bst[node].second != '.'){
    preorder(bst[node].second);
  }
}

void inorder(char node){
  if(bst[node].first != '.'){
    inorder(bst[node].first);
  }

  cout << node;

  if(bst[node].second != '.'){
    inorder(bst[node].second);
  }
}

void postorder(char node){

  if(bst[node].first != '.'){
    postorder(bst[node].first);
  }

  if(bst[node].second != '.'){
    postorder(bst[node].second);
  }

  cout << node;
}

int main(){
  int N;
  cin >> N;

  char parent,left,right;

  for(int i = 0 ; i < N ; i++){
    cin >> parent >> left >> right;

    bst[parent] = make_pair(left,right);
  }

  preorder('A');
  cout << endl;
  inorder('A');
  cout << endl;
  postorder('A');

  return 0;
}