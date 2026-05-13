#include<bits/stdc++.h>
#include<vector>
using namespace std;

struct Edge{
    int src,dest,weight;
};
class DisjoinSet{
    vector<int>parent,rank;

    public:
    DisjoinSet(int n){
        parent.resize(n);
        rank.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
    }

        int find(int x){
            if(parent[x]!=x)
            parent[x]=find(parent[x]);
            return parent[x];
        }

        void units(int x,int y){
            int rootX=find(x);
            int rootY=find(y);

            if(rootX!=rootY){
                if(rank[rootX]<rank[rootY])
                parent[rootX]=rootY;

                else if(rank[rootX]>rank[rootY])
                parent[rootY]==rootY;

                else{
                    parent[rootY]==rootX;
                    rank[rootX]++;
                }
            }
        }
    };
  

    int kruskal(vector<Edge>&edges,int V){
        sort(edges.begin(),edges.end(),[](Edge a,Edge b){
            return a.weight<b.weight;
        });

        DisjoinSet ds(V);
        int mstWeight=0;
        vector<Edge>mst;

        for(Edge& edge:edges){
            if(ds.find(edge.src)!=ds.find(edge.dest)){
                ds.units(edge.src,edge.dest);
                mstWeight+=edge.weight;
                mst.push_back(edge);

            }
        }
        cout<<"Edge in MST :"<<endl;
        for(Edge& e:mst){
            cout<<e.src<<"--"<<e.dest<<"=="<<e.weight<<endl;
        }
        return mstWeight;
    }
int main () {
    int V=4;
    vector<Edge>edges={
        {0,1,10},{0,2,6},{0,3,5},{1,3,15},{2,3,4}

    };

    int mstWeight=kruskal(edges,V);
    cout<<"weight of MST :"<<mstWeight<<endl;

  
  
return 0;
}