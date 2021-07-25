// LCAUsingEulerian_path.cpp

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
vector<int>mark;
vector<int>parent;
vector<int>dist;
vector<vector<int>>dp;
 
 
void dfs(int v){
    mark[v]=1;
    for(auto u : gg[v]){
        if(!mark[u]){
           dist[u]=dist[v]+1;
           dfs(u);
        }
    } 
}
 
 
int Kth_anscestor(int v,int k){ 
    
    int u=0;
    // cout<<v<<" "<<k<<"\n";
    while(u<20){
        if(k&(1<<u))v=dp[v][u];
        // cout<<v<<" ";
        u++;
    }
    // cout<<"\n";
    return v;
}
 
 
 
int lca(int v,int u){
    
    if(dist[v]>dist[u])swap(v,u);
    // cout<<dist[u]-dist[v]<<"\n";
    u=Kth_anscestor(u,dist[u]-dist[v]);
    // cout<<v<<" "<<u<<"\n";
    int k=ceil(log2(n))-1;
    // cout<<dist[v]<<" "<<dist[u]<<"\n";
    // cout<<v<<" "<<u<<'\n';
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
 
int main()
{
 
   cin>>n>>q;
   gg=vector<vector<int>>(n);
   dist=mark=vector<int>(n,0);
   parent=vector<int>(n,-1);
   
   for(int i=0;i<n;i++)gg[i].clear();
   
   for(int i=1;i<n;i++){
       int v;cin>>v;
       v--;
       parent[i]=v;
       gg[v].push_back(i);
   } 
 
   dfs(0);
   int l = ceil(log2(n));
   dp=vector<vector<int>>(n,vector<int>(l,-1));
 
//   memset(dp,-1,sizeof(dp));
 
 
   for(int i=0;i<n;i++)
      dp[i][0]=parent[i];
   
 
   for(int j=1;j<=log2(n);j++){
       for(int i=0;i<n;i++){
           if(dp[i][j-1]!=-1)dp[i][j]=dp[dp[i][j-1]][j-1];
       }
   } 
/**************************************************************/
//distance calculator//
//    dist[v]+dist[u]-2*dist[lca(v,u)]
/**************************************************************/
   

   
//   for(int i=0;i<n;i++){
//       for(int j=0;j<=log2(n);j++)
//           cout<<dp[i][j]<<" ";
       
//       cout<<"\n";
//   }
   
//   cout<<ceil(log2(2))<<"\n";
//   for(int i=0;i<n;i++)
//      cout<<dist[i]<<" ";
//   cout<<"\n";
 
   while(q--){
       
       int v,u;cin>>v>>u;
       v--;u--;
       cout<<lca(v,u)+1<<"\n";
   }  
 
 
 
 
return 0;
   
}