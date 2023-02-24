#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int max_x;
int max_y;
int dx[4] = {0,1,0,-1};   // 위, 오른쪽, 아래, 왼쪽
int dy[4] = {1,0,-1,0};

struct Pos{
    int x;
    int y;
};


bool maps_in_range(int x, int y){
    return (0 <= x && x < max_x) && (0 <= y && y < max_y);
}


int dfs (vector<string> maps,Pos start, Pos current ,int (&visited)[100][100],int count){
    int start_x = start.x;
    int start_y = start.y;
    
    int current_x = current.x;
    int current_y = current.y;
    
    visited[current_x][current_y] = 1;
    
    count += maps[current_x][current_y] - '0';
    
    for(int i = 0 ;i < 4 ; i++){
        int next_x = current_x + dx[i];
        int next_y = current_y + dy[i];
        
        if(maps_in_range(next_x,next_y) && visited[next_x][next_y] != 1 && maps[next_x][next_y] != 'X'){
            return dfs(maps,start,{next_x,next_y},visited,count);
        }
    }
    
    int exit_start = false;
    
    for(int i = 0 ; i < 4 ; i++){
        int next_x = current_x + dx[i];
        int next_y = current_y + dy[i];
        
        if((next_x == start.x && next_y == start.y) || (current_x == start.x && current_y == start.y) ){
            exit_start = true;
            break;
        }
    }
    
    if(exit_start){
        return count;
    }else{
        return -1;
    }
}

int bfs (vector<string> maps,Pos start,int (&visited)[100][100]){
    queue<Pos> q;
    
    q.push(start);
    visited[start.x][start.y] = 1;
    
    int count = 0;
    
    while(!q.empty()){
        Pos current = q.front();
        q.pop();
        
        count += maps[current.x][current.y] - '0';
        
        for(int i = 0 ; i < 4 ; i++){
            int next_x = current.x + dx[i];
            int next_y = current.y + dy[i];
            
            if(maps_in_range(next_x,next_y) && visited[next_x][next_y] != 1 && maps[next_x][next_y] != 'X'){
            q.push({next_x,next_y});
            visited[next_x][next_y] = 1;
            
            }
        }
        
    }
    
    cout << count << endl;
    return count;
}


vector<int> solution(vector<string> maps) {
    vector<int> answer;
    
    int visited[100][100] = {0,};
    
    max_x = maps.size();
    max_y = maps[0].size();
    
    for(int x = 0 ; x < max_x ; x++){
        for(int y = 0 ; y < max_y ; y++){
            if(maps[x][y] == 'X' || visited[x][y] == 1){
                continue;
            }
            int count = 0;
            
            Pos start = {x,y};
            
            //int temp_count = dfs(maps,start,start,visited,count);
            int temp_count = bfs(maps,start,visited);
            if(temp_count > 0){
                answer.push_back(temp_count);
            }
        }
    }
    
    sort(answer.begin(),answer.end());
    
    if(answer.size() == 0){
        answer.push_back(-1);
    }
    

    return answer;
}