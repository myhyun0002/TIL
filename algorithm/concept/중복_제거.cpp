#include <iostream>
#include <map>
#include <vector>
using namespace std;

/*
  중복된 요소 제거 방법 2가지
  
  - map 사용
  - unique 함수 사용

*/


// map을 이용한 중복 요소 제거
void use_map(){
  map<int,int> mp;
  vector<int> v{1,1,2,2,3,3};

  // v의 값을 key로 해서 map에 넣는다 같은 키가 있으면 pass 아니면 삽입
  for(int i : v){
    if(mp[i]){
      continue;
    }else{
      mp[i] = 1;
    }
  }
  
  // 중복이 제거되었는지 확인
  for(auto it : mp){          // 1,2,3 출력됨
    cout << it.first << endl;   
  }
  cout << endl;
}

/*

    unique 함수

  ex) 1,1,2,2,3,3,4,4
  
  1. 처음에 1부터 시작해서 바로 옆에 녀석이랑 비교한다.
  2. 같은 1이기 때문에 2번째 1을 제거한다.
  3. 세번째 있는 2랑 비교해서 다르니까 냅둔다.
  4. 세번째 2랑 네번째 2랑 비교하니 같으니까 지운다.
  이걸 계속 반복하면 1,2,3,4가 된다.
  5. 원래 요소가 8개인데 4개만 추출 됐으니 나머지 뒤에 4개는 그대로 온다.
  그러면
  1,2,3,4,3,3,4,4 (3,3,4,4 뒤에 4개가 그대로 오기 때문)

  - unique 함수는 iterator 반환
  - 여기서 중복제거된 값은 1,2,3,4까지이고 나머지는 그대로 붙여넣기 한거기 때문에
    unique는 4번째 요소인 4을 가리키게 된다.


  ex) v = {1,1,2,2,3,3,5,6,7,8,9};
      unique(v.begin(),v.end());
      unique함수 이후 v = {1,2,3,5,6,7,8,9,7,8,9}

  unique 함수 쓰기 전에는 항상 sort()를 하고 써야한다.

  v = {2,2,1,2,3,4,5,5,5}
  인 경우 unique함수 취하면 v = {2,1,2,3,4,5,5,5,5}가 되기 때문에
  중복 제거가 되지 않았다.
  sort()를 한 뒤에 해야 한다.

*/

// unique함수를 이용한 중복 요소 제거
void use_unique(){
  vector<int> v = {2,2,1,1,2,2,3,3,5,6,7,8,9};

  // unique() 함수 쓰기 전에 sort() 진행
  sort(v.begin(),v.end());

  // unique함수 실행 후 unique함수는 중복제거를 끝난 가장 마지막 원소를 가리키고 그 뒤에는 그냥 붙여넣기 한거다.
  // 따라서 마지막 요소 이후부터 끝까지 v에 있는 요소는 제거를 해준다.
  v.erase(unique(v.begin(),v.end()),v.end());

  // v = {1,2,3,5,6,7,8,9} 가 된다.
  for(int i : v) cout << i << " ";
}





int main(){
  use_map();
  use_unique();
  return 0;
}