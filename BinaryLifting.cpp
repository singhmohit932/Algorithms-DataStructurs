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
 
vector<vector<int>>gg;
vector<int>mark;
vector<int>parent;
vector<int>dist;
 
 
void dfs(int v){
    mark[v]=1;
    for(auto u : gg[v]){
        if(!mark[u]){
           dist[u]=dist[v]+1;
           dfs(u);
        }
    } 
}
 
int main()
{
 
   int n,q;cin>>n>>q;
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
   int l =ceil(log2(n));
   int dp[n][l];
 
   memset(dp,-1,sizeof(dp));
 
 
   for(int i=0;i<n;i++)
      dp[i][0]=parent[i];
   
 
   for(int j=1;j<=log2(n);j++){
       for(int i=0;i<n;i++){
           if(dp[i][j-1]!=-1)dp[i][j]=dp[dp[i][j-1]][j-1];
       }
   } 
   
   
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
       
       int v,k;cin>>v>>k;
       v--;
       if(dist[v]<k)cout<<-1<<"\n";
       else {
           int u = 0;
           while(u<32){
             if(k&(1<<u))v = dp[v][u];
             u++;
            }
           
 
           cout<<v+1<<"\n";
       }
       
   }  
 
 
 
 
return 0;
   
}