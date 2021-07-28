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
 

class Edge {
     public:
       int from,to;
       Edge residual;
       long flow;
       long capacity;

       Edge(int from,int to, long capacity){
           this.from = from;
           this.to = to;
           this.capacity = capacity; 
       }

       bool isResidual()
           return capacity==0;
       
       long remainingCapacity()
         return capacity-flow;
       
       void augment(long bottleneck){
           flow+=bottleneck;
           residual-=bottleneck;
       }

};


static class NetworkFlowSolverBase{

    const long INF = INT64_MAX/2;

    int n,source,sink;

    int visitedToken = 1;
    vector<int> visited;
      
    bool solved;
    long MaxFlow;
    vector<vector<Edge>>graph;


    NetworkFlowSolverBase(int n,int source,int sink){
        this.n = n;
        this.source = source;
        this.sink = sink;
        initializeEmptyFlowGraph();
        visited = vector<int>(n);
    }

    void initializeEmptyFlowGraph(){
        graph = vector<vector<Edge>>(n);
        for(int i=0;i<n;i++)
           graph[i].clear();
    }


    void addEdge(int from,int to, long capacity){

        Edge e1 = new Edge(from,to,capacity);
        Edge e2 = new Edge(to,from,0);

        e1.residual = e2;
        e2.residual = e1;

        graph[from].push_back(e1);
        graph[to].push_back(e2);
    }
    

    vector<vector<Edge>> getGraph(){
        execute();
        return graph;
    }

    long maxFlow(){
        execute();
        return MaxFlow;
    }


    void execute(){
        if(solved)return;
        solved = true;
        solve();
    }


    void solve();

};



class FordFulkersonDfsSolver extends NetworkFlowSolverBase{
      

    FordFulkersonDfsSolver(int n,int source, int sink){
        super(n,source,sink);
    }


    void solve(){

        for(long f = dfs(s,INF);f!=0;f=dfs(s,INF)){
            visitedToken++;
            MaxFlow+=f;
        }

    }


    long dfs(int node,int flow){
       
       if(node==sink)return flow;
       visited[node]=visitedToken;
       vector<Edge>edges = graph[node];

       for(auto edge : edges){
           if(edge.remainingCapacity() > 0 && visited[edge.to]!=visitedToken){
               long bottleNeck = dfs(edge.to,min(flow,edge.remainingCapacity()));

               if(bottleNeck > 0){
                   edge.augment(bottleNeck);
                   return bottleNeck;
               }
           }
       }

       return (long)0;
    } 
};




 
int main()
{

    int n,m;
    cin>>n>>m;
    
    int source,sink;
    cin>>source>>sink;
    
    // vector<vector<pair<int,int>>gg(n);
    // for(auto &it : gg)it.clear();

    NetworkFlowSolverBase solver = new FordFulkersonDfsSolver(n,source,sink);


    for(int i=0;i<m;i++){
        int v,u,w;
        cin>>v>>u>>w;
        v--;u--;
        // gg[v].push_back({v,w});
        solver.addEdge(v,u,w);
    }

    cout<<solver.maxFlow()<<"\n";


 
 
return 0;
   
}