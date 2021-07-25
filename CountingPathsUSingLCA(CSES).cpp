// Counting Paths
 
 
// Company Queries I
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
 
int n,q;
vector<vector<int>>gg;
vector<int>mark,prefix;
vector<int>parent;
vector<int>dist;
vector<vector<int>>dp;
 
 
void dfs(int v){
    mark[v]=1;
    for(auto u : gg[v]){
        if(!mark[u]){
           parent[u]=v;
           dist[u]=dist[v]+1;
           dfs(u);
        }
    } 
}
 
 
int Kth_anscestor(int v,int k){ 
    
    int u=0;
    while(u<20){
        if(k&(1<<u))v=dp[v][u];
        u++;
    }
    return v;
}
 
 
 
int lca(int v,int u){
    
    if(dist[v]>dist[u])swap(v,u);
    u=Kth_anscestor(u,dist[u]-dist[v]);
    int k=ceil(log2(n))-1;
  
    while(k>=0){
        if(dp[v][k]!=dp[u][k]){
            v=dp[v][k];
            u=dp[u][k];
        }
        k--;
    }
 
    if(v==u)return v;
    return parent[v];
 
}
 
 
void dfs2(int v){
      mark[v]=1;
      for(auto u : gg[v]){
          if(!mark[u]){
              dfs2(u);
              prefix[v]+=prefix[u];
          }
      }
}
 
int main()
{
 
   cin>>n>>q;
   gg=vector<vector<int>>(n);
   prefix=dist=mark=vector<int>(n,0);
   parent=vector<int>(n,-1);
   
   for(int i=0;i<n;i++)gg[i].clear();
   
   for(int i=0;i<n-1;i++){
       int v,u;cin>>v>>u;
       v--;u--;
       gg[v].push_back(u);
       gg[u].push_back(v);
   } 
 
   dfs(0);
   int l = ceil(log2(n));
   dp=vector<vector<int>>(n,vector<int>(l,-1));
 
   for(int i=0;i<n;i++)
      dp[i][0]=parent[i];
   
 
   for(int j=1;j<=log2(n);j++){
       for(int i=0;i<n;i++){
           if(dp[i][j-1]!=-1)dp[i][j]=dp[dp[i][j-1]][j-1];
       }
   } 
 
   fill(all(mark),0);
 
   while(q--){
       
       int v,u;cin>>v>>u;
       v--;u--;
       int w = lca(v,u);
    //   cout<<v<<" "<<u<<" "<<w<<"\n";
       prefix[v]++;
       prefix[u]++;
       prefix[w]--;
       if(w!=0)prefix[parent[w]]--;
    
       
       
   }  
   
//   for(auto &it : prefix)cout<<it<<" ";
//   cout<<"\n";
 
   dfs2(0);
 
   for(auto &it : prefix)cout<<it<<" ";
   cout<<"\n";
 
 
 
 
return 0;
   
}