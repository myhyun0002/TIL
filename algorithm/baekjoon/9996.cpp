#include <iostream>
#include <queue>

using namespace std;

/*
  queue

  가장 먼저 넣은 것을 가장 먼저 내보낸다.

  삽입 : queue.push()
  첫번째 원소 삭제 : queue.pop()
  첫번째 원소 반환 : queue.front()
  마지막 원소 반환 : queue.back()


  string은 char로 나눠서 for문으로 비교하지 말고 그냥 == 으로 비교하면 된다.

*/

vector<string> split(string str, string delimiter)
{

  vector<string> answer;
  long long pos = 0;
  string token = "";
  while ((pos = str.find(delimiter)) != string::npos)
  {
    // 처음부터 구분자가 나오기 전까지의 string을 token에 저장.
    token = str.substr(0, pos);

    // token을 정답에 저쟝.
    answer.push_back(token);

    // token과 구분자 길이까지 포함해서 string에서 제거
    str.erase(0, pos + delimiter.length());
  }

  // 맨 마지막 구분자 뒤에 있는 문자열은 따로 저장을 해줘야 한다.
  answer.push_back(str);
  return answer;
}

int main()
{
  int n;
  cin >> n;

  string pattern;
  cin >> pattern;

  int pos = pattern.find("*");
  string pattern_prev = pattern.substr(0, pos);
  string pattern_after = pattern.substr(pos + 1);

  string problem;

  for (int i = 0; i < n; i++)
  {
    cin >> problem;

    bool is_result_Yes = true;

    if (problem.size() < pattern_after.size() + pattern_prev.size())
    {
      cout << "NE\n";
      continue;
    }

    if (pattern_prev == problem.substr(0, pattern_prev.size()) && pattern_after == problem.substr(problem.size() - pattern_after.size()))
    {
      cout << "DA\n";
    }
    else
    {
      cout << "NE\n";
    }
  }

  return 0;
}