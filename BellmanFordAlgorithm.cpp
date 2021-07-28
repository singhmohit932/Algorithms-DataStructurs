#include<bits/stdc++.h>
using namespace std;
 
typedef vector <int> vi;
typedef pair< int ,int > pii;
#define endl "\n"
#define sd(val) scanf("%d",&val)
#define ss(val) scanf("%s",&val)
#define sl(val) scanf("%lld",&val)
#define debug(val) printf("check%d\n",val)
#define all(v) v.begin(),v.end()
#define PB push_back
#define MP make_pair
#define FF first
#define SS second
#define ll long long
#define MOD 1000000007
#define clr(val) memset(val,0,sizeof(val))
#define what_is(x) cerr << #x << " is " << x << endl;
#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
 
int main()
{
 
  int n,m;cin>>n>>m;
  vector<vector<pair<int,int>>>gg(n);
  
  for(int i=0;i<m;i++){
      int v,u,w;cin>>v>>u>>w;
      v--;u--;
      gg[v].push_back({u,w});
  }


  int start = 0;
  vector<int>dist(n,MOD);
  dist[start]=0;
  
  /**
   * An implementation of the Bellman-Ford algorithm. The algorithm finds the shortest path between
   * a starting node and all other nodes in the graph. The algorithm also detects negative cycles.
   * If a node is part of a negative cycle then the minimum cost for that node is set to
   * Double.NEGATIVE_INFINITY.
   *
   * @param graph - An adjacency list containing directed edges forming the graph
   * @param V - The number of vertices in the graph.
   * @param start - The id of the starting node
   */

  for(int i=0;i<n-1;i++){
      for(auto u : gg[i]){
          if(dist[u.first] > dist[i] + u.second;)
          dist[u.first] = dist[i] + u.second;
      }
  }


  for(int i=0;i<n-1;i++){
      for(auto u : gg[i]){
          if(dist[u.first] > dist[i] + u.second;)
            dist[u.first] = -1*MOD;
      }
  }



  
 
 
 
return 0;
   
}