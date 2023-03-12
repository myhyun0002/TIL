#include <iostream>
#include <map>
using namespace std;

/*
  시간 초과가 빡센 문제 같은 경우
  cin.tie(NULL);
  cout.tie(NULL);
  ios_base::sync_with_stdio(false);
  사용
*/
int main(){
  cin.tie(NULL);
  cout.tie(NULL);
  map<int,string> m_key_int;
  map<string,int> m_key_string;

  int n,m;
  cin >> n >> m;

  string str;
  
  for(int i = 1 ; i <= n ; i++){
    cin >> str;
    m_key_int[i]=str;
    m_key_string[str] = i;
  }

  string problem;

  for(int i = 0 ; i < m ; i++){
    cin >> problem;

    if('0' <= problem[0] && problem[0] <= '9' ){ // 숫자라면
      cout << m_key_int[stoi(problem)] << "\n";
    }else{
      cout << m_key_string[problem] << "\n";
    }
  }


  return 0;
}