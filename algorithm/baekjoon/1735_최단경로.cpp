#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MAX_V 20000
#define MAX_E 300000
#define INF 1e9

/*
  - dijkstra 함수 공부

  - 시간 초과 안나게 하는 방법
    - cin.tie(NULL)
    - endl 대신 "\n" 사용
*/

vector<pair<int, int>> graph[MAX_V + 1];
int Distance[MAX_V + 1];

void dijkstra(int V, int start, vector<pair<int, int>> graph[])
{
  // pair<해당 지점의 최소 거리 값, 해당 지점>
  priority_queue<pair<int, int>> q;
  q.push({0, start});
  Distance[start] = 0;

  while (!q.empty())
  {
    int current_node_dist = -q.top().first;
    int current_node = q.top().second;
    q.pop();

    for (int i = 0; i < graph[current_node].size(); i++)
    {
      int next_node = graph[current_node][i].first;
      int next_node_weight = graph[current_node][i].second;

      int next_node_dist = next_node_weight + current_node_dist;

      if (Distance[next_node] > next_node_dist)
      {
        Distance[next_node] = next_node_dist;

        // 해당 노드의 최단 거리가 갱신이 되었으니 다른 노드에도 영향이 갈 수 있으니 다시 queue에 넣어서 알아본다.
        q.push({-1 * Distance[next_node], next_node});
      }

      // printf("현재 노드는 %d, 다음 노드는 %d, 가중치는 %d, 그래서 다음 노드 distance = %d\n",current_node,next_node,next_node_weight,distance[next_node]);
    }
  }
}

int main()
{

  cin.tie(NULL);
  ios_base::sync_with_stdio(false);

  int V, E; // v : 노트 개수, e : 간선 개수
  cin >> V >> E;
  int k; // k : 시작 노드
  cin >> k;

  // 간선마다 u노드에서 v노드로 가는 가중치 w인 간선을 e개 입력받는다.
  int u, v, w;
  for (int i = 0; i < E; i++)
  {
    cin >> u >> v >> w;

    // 시작 노드를 키로 하는 간선 정보를 graph에 담는다.
    graph[u].push_back({v, w});
  }

  // 거리값을 전부 INF로 초기화한다.
  fill(Distance, Distance + V + 1, INF);

  dijkstra(V, k, graph);

  for (int i = 1; i <= V; i++)
  {
    if (Distance[i] == INF)
    {
      cout << "INF"
           << "\n";
      continue;
    }
    cout << Distance[i] << "\n";
  }

  return 0;
}
