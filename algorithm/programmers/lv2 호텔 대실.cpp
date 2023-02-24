#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <queue>

using namespace std;

bool compare(vector<string> a, vector<string> b){
    int a_start_hour = stoi(a[0].substr(0,2));
    int a_start_minute = stoi(a[0].substr(3,2));
    
    int a_end_hour = stoi(a[1].substr(0,2));
    int a_end_minute = stoi(a[1].substr(3,2));
    
    int b_start_hour = stoi(b[0].substr(0,2));
    int b_start_minute = stoi(b[0].substr(3,2));
    
    int b_end_hour = stoi(b[1].substr(0,2));
    int b_end_minute = stoi(b[1].substr(3,2));
    
    if(a_start_hour == b_start_hour){
        if(a_start_minute == b_start_minute){
            if(a_end_hour == b_end_hour){
                return a_end_minute < b_end_minute;
            }else{
                return a_end_hour < b_end_hour;
            }
        }else{
            return a_start_minute < b_start_minute;
        }
    }else{
        return a_start_hour < b_start_hour;
    }
    
}

pair<int,int> calcurate_use_time(int end_hour, int end_minute){
    int use_time_minute = end_minute + 10;
    int use_time_hour = end_hour;
    if(use_time_minute >= 60){
        use_time_hour += 1;
        use_time_minute -= 60;
    }
    
    return make_pair(use_time_hour,use_time_minute);
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    
    sort(book_time.begin(), book_time.end(),compare);
    
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    
    for(int i = 0 ; i < book_time.size() ; i++){
        
        int room_start_hour = stoi(book_time[i][0].substr(0,2));
        int room_start_minute = stoi(book_time[i][0].substr(3,2));
    
        int room_end_hour = stoi(book_time[i][1].substr(0,2));
        int room_end_minute = stoi(book_time[i][1].substr(3,2));
        
        // 사용 가능한 방이 없으면
        if(pq.empty()){
            
            // 방 하나 추가
            answer++;
            
            // 해당 방이 끝나고 청소도 다 끝난 시간을 사용 가능 시간에 넣는다.
            pair<int,int> use_time = calcurate_use_time(room_end_hour,room_end_minute);
            pq.push(use_time);
            continue;
        }
        
        // 젤 빨리 사용할 수 있는 방의 시간을 가지고 온다.
        int first_use_time_hour = pq.top().first;
        int first_use_time_minute = pq.top().second;
      
        // 젤 빨리 사용할 수 있는 방보다 시간이 뒤에 있다면 해당 방을 사용하면 된다.
        if(first_use_time_hour < room_start_hour || ((first_use_time_hour == room_start_hour) && (first_use_time_minute <= room_start_minute))){
            pq.pop();
            
        }else{
            answer++;
            
        }
        
        pair<int,int> use_time = calcurate_use_time(room_end_hour,room_end_minute);
        pq.push(use_time);
        
        // printf("현재 방 개수는 %d입니다.\n",pq.size());
        
    }
    
    
    
    return answer;
}