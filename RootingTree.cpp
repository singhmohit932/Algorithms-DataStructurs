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
 

int Root_Tree(int rootId = 0,vector<vector<int>>&gg,vector<vector<int>>&aa,vector<int>&parent){
    parent[rootId]=-1;
    return buildtree(rootId,gg,aa,-1,parent);
}

//Build tree recursively depth first 
int buildTree(int NodeId,vector<vector<int>>&gg,vector<vector<int>>&aa,int parentId,vector<int>&parent){
        
        for(auto childId : gg[NodeId]){
            // Ignore adding an edge pointing back to parent.
            if(childId==parentId)continue;

            parent[childId]=NodeId;
            aa[NodeId].push_back(childId);
            buildTree(childId,gg,aa,NodeId,parent);
        }

        return NodeId;
}

 
int main()
{ 


    int n;cin>>n;
    vector<vector<int>>gg(n);
    vector<vector<int>>aa(n);

    for(int i=0;i<n;i++){
        gg[i].clear();
        aa[i].clear();
    }


    for(int i=0;i<n-1;i++){
        int v,u;cin>>v>>u;
        v--;u--;
        gg[v].push_back(u);
        gg[u].push_back(v);
    
    }
      
    vector<int>parent(n,-1);
    Root_Tree(rootId,gg,aa,parent);






    
 
 
 
 
return 0;
   
}