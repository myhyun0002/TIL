#include <iostream>

using namespace std;

int main(){
  int person_num;
  cin >> person_num;

  int arr[26] = {0,};

  string input_name;

  for(int i = 0 ; i < person_num ; i++){
    cin >> input_name;
    arr[input_name[0]-'a']++;
  }

  int result = 0;

  for(int i = 0 ; i < 26 ; i++){
    if(arr[i] >= 5){
      cout << (char)(i + 'a');
      result = 1;
    }
  }

  if(!result){
    cout << "PREDAJA";
  }

  return 0;
}