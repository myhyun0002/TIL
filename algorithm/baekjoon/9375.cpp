#include <iostream>
#include <map>
#include <vector>

using namespace std;

/*
  경우의 수 구하는 문제

  종류마다 하나씩 입어야 하고 하나의 종류에 여러가지 옷이 있을 수 있음
  다만 아무것도 안 입을 수는 없음

  어떻게 풀어야 할까?


  해당 종류마다 안 입는 경우를 하나씩 추가해 주면 각 종류를 다 곱하면 끝이다.

  왜냐? 각 종류마다 안 입는 경우를 고려해 하나씩 다 넣어놨다. 따라서 6종류가 있고 각 종류마다 원래는 2가지의 옷이 있다고 했을 때
  이 때 안 입는 경우 하나씩 추가하여 여섯 종류에다가 각각 3가지 경우가 있고 그걸 다 곱하면 3*3*3*3*3*3 이 되는데 이 때 6개가 다 안 입는 경우가 있을 수 있으니
  하나를 빼주면 정답은 3*3*3*3*3*3 -1 이다.

*/
void comvination(int start,vector<int> v,int n,int k){
  if(v.size() ==  k){

  }
}
int main(){
  int n;
  cin >> n;

  int case_n;

  for(int i = 0 ; i < n; i++){
    cin >> case_n;

    map<string,int> m;
    string name,category;

    // <옷 종류, 옷 개수>
    for(int j = 0 ; j < case_n ; j++){
      cin >> name >> category;
      m[category]++;
    }
     
    int count = 0;

    // 옷 종류에 따라 매칭
    long long ret = 1;

    // 각 종류마다 안 입는 경우를 하나씩 더 추가한 다음 곱하면 옷을 입는 모든 경우의 수가 나온다.
    for(auto it : m){
      ret *= (long long)(it.second + 1);
    }

    // 모두 안 입는 경우가 나올 경우가 1개 나오니까 뺀다.
    ret--;

    cout << ret << "\n";
  }

  return 0;
}