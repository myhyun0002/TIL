#include <iostream>
#include <map>

using namespace std;

int main(){
  int n;
  cin >> n;

  int case_n;

  for(int i = 0 ; i < n; i++){
    cin >> case_n;

    map<string,int> m;
    string name,category;

    for(int j = 0 ; j < case_n ; j++){
      cin >> name >> category;
      m[category]++;
    }
     
    int count = 0;

    for(int k = 1 ; k <= m.size() ; k++){
      
    }
  }

  return 0;
}