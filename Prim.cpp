#include<bits/stdc++.h>
#include<vector>
using namespace std;

typedef pair<int,int> pii;

void PrimMST(vector<vector<pii>>&graph,int V){
    vector<int>key(V,INT_MAX);
    vector<bool>inMST(V,false);
    vector<int>parent(V,-1);
    priority_queue<pii,vector<pii>,greater<pii>>pq;

    key[0]=0;
    pq.push({0,0});

    while(!pq.empty()){
    int u=pq.top().second;
    pq.pop();

    inMST[u]=true;

    for(auto&edge:graph[u]){
        int v=edge.first;
        int weight=edge.second;

        if(!inMST[v]&& weight<key[v]){
            key[v]=weight;
            parent[v]=u;
            pq.push({key[v],v});
        }
        }
    }

    cout<<"Edge in MST:"<<endl;
    for(int i=1;i<V;i++){
        cout<<parent[i]<<"--"<<i<<"=="<<key[i]<<endl;
    }


}
  
int main () {
    int V=5;
    vector<vector<pii>>graph(V);
    graph[0].push_back({1,2});
    graph[0].push_back({3,6});
    graph[1].push_back({0,2});
    graph[1].push_back({2,3});
    graph[1].push_back({3,8});
    graph[1].push_back({4,5});
    graph[2].push_back({1,3});
    graph[2].push_back({4,7});
    graph[3].push_back({0,6});
    graph[3].push_back({1,8});
    graph[4].push_back({1,5});
    graph[4].push_back({1,7});

    PrimMST(graph,V);

return 0;
}