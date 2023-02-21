#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies)
{
  vector<int> answer;
  vector<char> terms_name;
  vector<int> terms_int;

  int term_index = 0;
  map<char, int> terms_map;

  for (auto term : terms)
  {
    int value = stoi(term.substr(term.find(" ") + 1, term.length()));
    terms_map.insert({term[0], value});
  }
  int count = 0;
  for (auto privacy : privacies)
  {
    count++;
    string privacy_name = privacy.substr(privacy.find(" ") + 1, privacy.length());
    string privacy_date = privacy.substr(0, privacy.find(" "));

    int year = stoi(privacy_date.substr(0, 4));
    int month = stoi(privacy_date.substr(5, 2));
    int day = stoi(privacy_date.substr(8, 2));

    day -= 1; // 해당 파기일은 하루 전날 까지다.

    if (day < 1)
    {
      month--;
      day = 28;
    }
    printf("day에 -1을 한 후 %d.%d.%d \n", year, month, day);
    month += terms_map[*privacy_name.c_str()]; // 파기 월 만큼 더한다.
    printf("month term을 더한 후 %d.%d.%d \n", year, month, day);
    if (month < 1)
    {
      year--;
      month = 12;
    }
    else if (month > 12)
    {
      year += month / 12;
      month = month % 12;
      if (month == 0)
      {
        year--;
        month = 12;
      }
    }

    // 2019.8.01    5개월
    // 2019.7.28
    // 2019.12.28

    printf("%d 사람의 파기일은 %d.%d.%d 입니다.\n", count, year, month, day);

    int today_year = stoi(today.substr(0, 4));
    int today_month = stoi(today.substr(5, 2));
    int today_day = stoi(today.substr(8, 2));

    printf("오늘은 %d.%d.%d 입니다.\n\n", today_year, today_month, today_day);

    // 계약 파기일이 오늘보다 +1 이상이면 파기해야 한다.
    if (today_year > year)
    { // 오늘 년도가 파기일의 년도보다 크면 바로 파기
      answer.push_back(count);
      continue;
    }
    else if (today_year < year)
    { // 파기일 년도가 크면 파기 x
      continue;
    }
    else
    { // 오늘 year이 파기 년도와 같으면 month 끼리 비교
      if (today_month > month)
      { // 파기일의 년도가 오늘보다 작으면 month 비교 없이 파기
        answer.push_back(count);
        continue;
      }
      else if (today_month < month)
      { // 오늘 월이 파기 월보다 작으면 파기 x
        continue;
      }
      else
      { // 오늘 month 가 파기 month와 같다면
        if (today_day > day)
        {
          answer.push_back(count);
          continue;
        }
        else
        {
          continue;
        }
      }
    }
  }
  return answer;
}
