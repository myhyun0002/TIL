#include <iostream>
#include <vector>
using namespace std;

/*
  split

  - 특정 문자열 기준으로 쪼개어서 배열화 시키는 것
  - 시간복잡도 : O(n)
*/

// str : 불기하고 싶은 문자 
// delimiter : 구분자
vector<string> split(string str, string delimiter){

  vector<string> answer;
  long long pos = 0;
  string token = "";
  while((pos = str.find(delimiter)) != string::npos){
    // 처음부터 구분자가 나오기 전까지의 string을 token에 저장.
    token = str.substr(0,pos);

    // token을 정답에 저쟝.
    answer.push_back(token);

    // token과 구분자 길이까지 포함해서 string에서 제거
    str.erase(0,pos + delimiter.length());
  }

  // 맨 마지막 구분자 뒤에 있는 문자열은 따로 저장을 해줘야 한다.
  answer.push_back(str);
  return answer;
}

void print(vector<string> const & a){
  for(int i = 0; i < a.size() ; i++){
    cout << a[i] << endl;
  }
}



int main(){

  vector<string> split_str = split("안녕하세용 저의 이름은 뭘까용?"," ");
  print(split_str);

  return 0;
}