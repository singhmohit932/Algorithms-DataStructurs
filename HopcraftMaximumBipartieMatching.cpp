#include<bits/stdc++.h>
#include<vector>
#include<queue>
#include<set>
#include<map>
using namespace std;
 
typedef vector <int> vi;
typedef pair< int ,int > pii;
#define endl "\n"
#define INF INT_MAX 
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
 
int n,m,ma;
vector<vector<pii>>adj;
vector<int>pairU,pairV,dist;
 
 
 
 
bool bfs(int w){
     queue<int>q;
     
     
 
 
     for(int i=1;i<n+1;i++){
         if(!pairU[i]){
             
             q.push(i);
             dist[i]=0;
 
         }else  dist[i]=INF;
     }
     
     dist[0]=INF;
     
 
     while(!q.empty()){
 
         int v = q.front();
         q.pop();
         
   
            
             for(auto u : adj[v]){
                
                if(u.second<=w){ 
                       
                     if(dist[pairV[u.first]]==INF){
                         
                         dist[pairV[u.first]]=dist[v]+1;
                         q.push(pairV[u.first]);
                     }
                }     
             }
             
             
         
     }
     
     // If we could come back to NIL i.e. returning to zero using alternating path of distinct 
     // vertices then there is an augmenting path 
     return (dist[0]!=INF);
}
 
// Returns true if there is an augmenting path beginning with free vertex u
bool dfs(int u,int w){
 
    if(u!=0){
       // transversing the adjacent edges   
       for(auto i : adj[u]){
           
           
           if(i.SS<=w){
           
               int v = pairV[i.first];
               
               // Following the distance setup by the bfs()
               if(dist[v]==dist[u]+1){
                   
                   if(dfs(v,w)){
                       // If dfs for pair of v also returns 
                       // true 
                       pairU[u]=i.first;
                       pairV[i.first]=u;
                       return true;
                   }
               }
           
           }
 
       }
       
       // If there is no augmenting path beginning with u.
      return false; 
       
 
    }
    // We have reached the last vertex of augumented path i.e. the NIL (0) vertex
    return true;
}
 
 
bool solve(int w){
    
    int ans=0;
    
    
    pairU.assign(n+1,0);
    pairV.assign(n+1,0);
     
 
    while (bfs(w))
    {
        /* code */
        for(int u=1 ; u<n+1 ; u++){
           if(pairU[u]==0&&dfs(u,w))
               ans++;
        }
           
    }
    
    return (ans==n);
    
    
    
}
 
int search(){
    
    int x=0,y=ma;
    
    while(x+1!=y){
        
        int mm=(x+y)/2;
        
        if(solve(mm))y=mm;
        else x=mm;
        
        
    }
    
    if(solve(x))return x;
    else if(solve(y))return y;
    else return -1;
    
}
 
 
 
 
int main()
{
   cin>>n>>m;
   ma=0;
   adj=vector<vector<pii>>(n+1);
   dist=pairU=pairV=vector<int>(n+1);
 
    
 
   for(int i=0;i<n+1;i++)
     adj.clear();
     
   
 
   for(int i=0;i<m;i++){
       int v,u,w;
       cin>>v>>u>>w;
       adj[v].push_back({u,w});
       ma=max(ma,w);
   }
   
   
   cout<<search()<<"\n";

 
return 0;
   
}