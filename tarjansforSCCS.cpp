#include<bits/stdc++.h>
using namespace std;
 
typedef vector <int> vi;
typedef pair< int ,int > pii;
#define endl "\n"
#define sd(val) scanf("%d",&val)
#define ss(val) scanf("%s",&val)
#define sl(val) scanf("%lld",&val)
#define debug(val) prllf("check%d\n",val)
#define all(v) v.begin(),v.end()
#define PB push_back
#define MP make_pair
#define FF first
#define SS second
#define ll long long
#define MOD 10000000007
#define clr(val) memset(val,0,sizeof(val))
#define what_is(x) cerr << #x << " is " << x << endl;
#define OJ \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
ll n,m;
vector<vector<ll>>gg,aa;
void dfs(ll v);
void Tarjans();
void dfs2(ll v);
vector<ll>pre_order;
vector<ll>id;
vector<ll>low;
stack<ll>ss;
ll preorder_counter;
ll number_SCCS;
vector<pii>edges;
vector<ll>mark;
vector<ll>number_paths;
 
 
void Tarjans(){
    ss = stack<ll>();
    pre_order = vector<ll>(n,-1);
    id =  vector<ll>(n,0);
    low = vector<ll>(n,0);
 
    number_SCCS = 0;
    preorder_counter = 0;
 
 
    for(ll i=0;i<n;i++)
        if(pre_order[i]==-1)dfs(i);
    
 
 
    // for(ll i=0;i<number_SCCS;i++){
    //     cout<<i+1<<" ";
    //     for(ll j=0;j<n;j++)
    //         if(id[j]==i)cout<<j+1<<" ";
    //     cout<<"\n";
    // }
 
 
    // cout<<number_SCCS<<"\n";
    
    aa=vector<vector<ll>>(number_SCCS);
    mark=vector<ll>(number_SCCS,0);
    number_paths=vector<ll>(number_SCCS,0);
    
    for(ll i=0;i<number_SCCS;i++)
       aa[i].clear();
 
    for(ll i=0;i<m;i++){
        // if(edges[i].FF==edges[i])
        //     number_paths[id[edges[i].FF]]=MOD;
        
        if(id[edges[i].FF]!=id[edges[i].SS]){
            aa[id[edges[i].FF]].push_back(id[edges[i].SS]);
        }else {
            number_paths[id[edges[i].FF]]=MOD;
        }
    }
 
 
    // for(ll i=0;i<number_SCCS;i++)
    //   if(!mark[i])dfs2(i);
    if(number_paths[id[0]]==0)number_paths[id[0]]=1;
    dfs2(id[0]);
    
    // for(int i=0;i<number_SCCS;i++){
    //     cout<<number_paths[i]<<" ";
    // }
    // cout<<"\n";
    for(int i=0;i<n;i++){
        if(mark[id[i]]==0)cout<<0<<" ";
        else if(number_paths[id[i]]==1)cout<<1<<" ";
        else if(number_paths[id[i]]!=MOD)cout<<2<<" ";
        else cout<<-1<<" ";
    }
    cout<<"\n";
    
 
 
    // if(number_SCCS==1)cout<<"YES\n";
    // else{
    //     cout<<"NO\n";
    //     ll v=-1,u=-1;
    //     for(ll i=0;i<n;i++){
    //       if(id[i]==0)v=i;
    //       else u=i;
    //     }
    //     cout<<v+1<<" "<<u+1<<"\n";
    // }
 
}
 
 
void dfs2(ll v){
    
    
    mark[v]=1;
    queue<ll>qq;
    qq.push(v);
    
    while(!qq.empty()){
        
         ll kk = qq.front();
         qq.pop();
         
         for(auto u : aa[kk]){
             if(!mark[u]){
                 mark[u]=1;
                 qq.push(u);
             }
             number_paths[u]=min(1ll*MOD,number_paths[u]+number_paths[kk]);
         }
    }
    
    
    // for(auto u : aa[v]){
    //     if(!mark[u]){
    //         number_paths[u]=min(1ll*MOD,number_paths[u]+number_paths[v]);
    //         dfs2(u);
    //     }else {
    //         number_paths[u]=min(1ll*MOD,number_paths[u]+number_paths[v]);
    //     }
        
    // } 
    
    
 
}
 
 
void dfs(ll v){
 
    pre_order[v] = preorder_counter;
    low[v] = preorder_counter;
    ss.push(v);
    preorder_counter++;
 
 
    for(auto u : gg[v]){
 
        // forward edge
        if(pre_order[u]==-1)
            dfs(u);
        
        //forward ,back,cross
        low[v]=min(low[v],low[u]);
    }
 
    //Are we the root??
    if(low[v]==pre_order[v]){
        while(true){
 
            ll u = ss.top();
            ss.pop();
            id[u] = number_SCCS;
            low[u] = n+1;
 
            if(u==v)break;
 
        }
 
        number_SCCS++;
    } 
 
}
 
 
int main()
{  
    FIO
    ll tt;cin>>tt;
    while(tt--){
        
        cin>>n>>m;
        gg=vector<vector<ll>>(n);
        edges.clear();
    
        for(ll i=0;i<n;i++)
          gg[i].clear();
     
        for(ll i=0;i<m;i++){
            ll v,u;
            cin>>v>>u;
            v--;
            u--;
            edges.push_back({v,u});
            gg[v].push_back(u);
        }
     
     
        Tarjans();
    
    }
 
 
return 0;
   
}