#define ll long long
const int INF = 1000000000;
int n,m;
using pii = pair<ll,ll>;
vector<vector<pii>>g;
vector<vector<pii>>a;

 
void Djikstra_s(int s,vector<vector<pii>>&g,vector<ll>&d,vector<ll> & p){
 
    priority_queue<pii, vector<pii>, greater<pii>>q;
    d.assign(n,INF);
    p.assign(n, -1);
    d[s]=0;
    q.push({0,s});
 
    ll v,u,d_v,d_u;
 
    while(!q.empty()){
       
       v = q.top().second;
       d_u = q.top().first;
       q.pop();
       
       if(d[v]!=d_u)continue;
 
       for(auto to : g[v]){
           
           u = to.first;
           d_v = to.second;
 
           if(d_v+d[v]<d[u]){
               q.erase({d[u],u});
               d[u]=d[v]+d_v;
               p[u] = v;
               q.insert({d[u],u});
               
           }
       }
 
    }
    
 
} 


int main()
{
   cin>>n>>m;
   vector<vi>eg(m,vi(3));
   g=a=vector<vector<pii>>(n);
   ll v,u,w;
   for(int i=0;i<m;i++){
       cin>>v>>u>>w;
       v--;u--;
       g[v].PB(MP(u,w));
       a[u].PB(MP(v,w));
       eg[i][0]=v;eg[i][1]=u;eg[i][2]=w;
   }
 
   vi d1(n),d2(n);
   Djikstra_s(0,g,d1);
   Djikstra_s(n-1,a,d2);
   ll max=INF;
   for(int i=0;i<m;i++){
        v=eg[i][0];
        u=eg[i][1];
        w=eg[i][2];
        if(d1[v]+d2[u]+w/2<max)max=d1[v]+d2[u]+w/2;
   }
 
   cout<<max<<"\n";
 
 
 
 
 
 
return 0;
   
}


vector<vector<pair<ll, ll>>> adj;

void dijkstra(int s, vector<ll> & d, vector<ll> & p) {
    int n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);

    d[s] = 0;
    using pii = pair<ll, ll>;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, s});
    while (!q.empty()) {
        ll v = q.top().second;
        ll d_v = q.top().first;
        q.pop();
        if (d_v != d[v])
            continue;

        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
                q.push({d[to], to});
            }
        }
    }
}