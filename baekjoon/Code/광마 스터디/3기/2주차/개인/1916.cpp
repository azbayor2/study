#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int N, M;
int sNode, eNode;
vector<vector<pair<int, int>>> graph;//money, node
vector<bool> visited;
vector<int> cost;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
void dis(void) {
   cost[sNode] = 0;
   //visited[sNode] = true;
   pq.push({ 0,sNode });
   while (!pq.empty()) {
      pair<int, int> n = pq.top();
      int costSector = n.first;//cost가 제일 적은 cost
      int nodeSector = n.second;//cost가 제일 작은 node
      pq.pop();
      if(cost[nodeSector]<costSector) continue;
      //if(visited[nodeSector]) continue;

      for (pair<int, int> iter : graph[nodeSector]) {
         int nextCost = iter.first;
         int nextNode = iter.second;
         if (cost[nodeSector] + nextCost < cost[nextNode]){
            cost[nextNode] = cost[nodeSector] + nextCost;
            pq.push({ cost[nextNode],nextNode });
            //visited[nextNode] = true;
         }
      }
   }
}
int main(void) {
   cin >> N >> M;
   graph.resize(N + 1);
   visited.resize(N + 1);
   cost.resize(N + 1, 1000000000);
   for (int i = 0; i < M; i++) {
      int s, a, m;
      cin >> s >> a >> m;
      graph[s].push_back({ m,a });
   }
   cin >> sNode >> eNode;
   dis();
   cout << cost[eNode];
   /*for (int iter : cost) {
      cout << iter << ' ';
   }*/
   return 0;
}