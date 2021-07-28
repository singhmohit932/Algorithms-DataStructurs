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
 

 int cycle;

vector<int> TopSortKahns(vector<vector<pair<int,int>>>&gg,vector<int>&Indeg){
    
    int n = gg.size();
    queue<int>qq;
    
    int count = 0;
    vector<int>Ordering(n);
    
    int index = 0;
    for(int i=0;i<n;i++){
        if(!Indeg[i]){
            qq.push(i);
        }
    }


    while(!qq.empty()){
        
        int v = qq.front();
        qq.pop();
        Ordering[index]=v;
        index--;
        count++;
        for(auto u : gg[v]){
            Indeg[u.first]--;
            if(!Indeg[u.first])qq.push(u.first);
        }

    }

    if(count!=n)cycle = 1;
    return  Ordering;

}


vector<int> ShortestPathAlgorithm(vector<int>&Ordering,vectoir<vector<pair<int,int>>>&gg){
    
    int n = gg.size();
    vector<int>dist(n,INF);
    dist[Ordering[0]]=0;
    
    for(auto v : Ordering){
          if(dist[v]!=INF){
              for(auto u : gg[v]){
                  int nodeId = u.first;
                  int w = u.second;


                  if(dist[nodeId]==INF)dist[nodeId]=dist[v]+w;
                  else dist[nodeId]=min(dist[nodeId],dist[v]+w);
              }
          }      
    }

    return dist;
}
 
int main()
{
   cycle = 0;
   int n,m;cin>>n>>m;
   
   vector<vector<pair<int,int>>>gg(n);
   vector<int>Indeg(n,0);
   

   for(int i=0;i<m;i++){
      int v,u,w;cin>>v>>u>>w;
      v--;u--;
      gg[v].push_back({u,w});
      Indeg[u]++;
   }

   vector<int>Ordering = TopSortKahns(gg,Indeg);
   if(cycle)cout<<-1<<"\n";
   else {
       
       //    for(auto &it : Ordering)cout<<it<<" ";
       //    cout<<"\n";
       
       //  For the Longest path just multiply each egde weight by -1 and run the Algorthim of SSSP 
       //  and again multiply each dist[NodeId] and take longest of these dist[NodeId] 
       vector<int>dist = ShortestPathAlgorithm(gg,Ordering);



   }

 return 0;
   
}
 
