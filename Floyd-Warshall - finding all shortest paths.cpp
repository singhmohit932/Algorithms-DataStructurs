#include<bits/stdc++.h>
#include<string>
#include<set>
#include<vector>
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
#define INF 1000000000000000
 
 
int main()
{
 
    int n,m,q;cin>>n>>m>>q;
    vector<vector<ll>>d(n,vector<ll>(n));
    for(int i=0;i<n;i++)
      d[i].assign(n,INF);
      
    ll v,u,w;
    for(int i=0;i<m;i++){
        cin>>v>>u>>w;
        v--;u--;
        d[v][u]=min(d[v][u],w);
        d[u][v]=min(d[u][v],w);
    }
 
 
    for(int i=0;i<n;i++)
       d[i][i]=0;    
    
    
 
    for(int k=0;k<n;k++){
      for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
        }
      }
    }
    for(int i=0;i<q;i++){
        cin>>v>>u;
        v--;u--;
        if(d[v][u]==INF)cout<<"-1\n";
        else cout<<d[v][u]<<"\n";
    }
 
    
 
 
 
 
 
return 0;
   
}