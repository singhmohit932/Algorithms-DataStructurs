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
 
int n,f;
vector<vector<int>>gg;
vector<int>mark,siz;
void dfs(int v){
       mark[v]=1;
       siz[v]=1;
       bool ff=false;
       
       for(auto u : gg[v]){
           if(!mark[u]){
                dfs(u);
                if(2*siz[u]>n)ff=true;
                siz[v]+=siz[u];
           }
       }
 
       if(n>2*siz[v])ff=true;
       if(!ff)f=v;
}
 
int main()
{   
    f=-1;
    cin>>n;
    gg=vector<vector<int>>(n);
    mark=siz=vector<int>(n,0);
 
    int v,u;
    for(int i=0;i<n-1;i++){
        cin>>v>>u;
        v--;u--;
        gg[v].push_back(u);
        gg[u].push_back(v);
    }
 
 
 
    dfs(0);
 
    cout<<f+1<<"\n";
 
 
 
 
 
 
 
 
 
 
 
 
 
 
return 0;
   
}