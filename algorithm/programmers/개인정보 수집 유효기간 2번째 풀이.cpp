#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <sstream>

using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    int today_year = stoi(today.substr(0,4));
    int today_month = stoi(today.substr(5,2));
    int today_day = stoi(today.substr(8,2));
    
    int today_date = today_year * 12 * 28 + (today_month-1) * 28 + today_day;
    
    
    map<char,int> term_map;
    
    for(auto term : terms){
        
        stringstream sstream;
        sstream.str(term);
        
        char c;
        int term_period;
        
        sstream >> c >> term_period;
        
        term_map[c] = term_period;
    }
    
    int count = 0;
    
    for(auto privacy : privacies){
        count++;
        stringstream sstream;
        sstream.str(privacy);
        
        string privacy_period;
        char c;
        
        sstream >> privacy_period >> c;
        
        int privacy_year = stoi(privacy_period.substr(0,4));
        int privacy_month = stoi(privacy_period.substr(5,2));
        int privacy_day = stoi(privacy_period.substr(8,2));
    
        int privacy_date = privacy_year * 12 * 28 + (privacy_month-1) * 28 + privacy_day + term_map[c] * 28 - 1;
        
        if(today_date > privacy_date){
            answer.push_back(count);
        }
        
    }
    return answer;
}

