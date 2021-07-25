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
 
 
void dfs(int v,int p, vector<int>&mark , vector<pair<int,int>>&dis ,vector<vector<int>>&gg){
    
    mark[v]++;
    
    for(auto u : gg[v]){
        if(!mark[u]){
            dfs(u,v,mark,dis,gg);
            dis[v].SS+=dis[u].FF;
        }
    }
 
    for(auto u : gg[v]){
       if(u!=p){
           dis[v].FF = max(dis[v].FF,1+dis[v].SS-dis[u].FF+dis[u].SS);
       }
    }
 
 
 
}
 
int main()
{
   int n;cin>>n;
   vector<vector<int>>gg(n);
   vector<int>mark(n,0);
   vector<pair<int,int>>dis(n,{0,0});
   
   for(int i=0;i<n;i++)gg[i].clear();
 
   for(int i=0;i<n-1;i++){
       int v,u;cin>>v>>u;
       v--;u--;
       gg[v].PB(u);
       gg[u].PB(v);
   }
 
 
   dfs(0,-1,mark,dis,gg);
 
   int ans=0;
 
   for(int i=0;i<n;i++)
     ans=max(ans,dis[i].FF);
   
   cout<<ans<<'\n';
 
 
return 0;
   
}
Share code to others
Test details