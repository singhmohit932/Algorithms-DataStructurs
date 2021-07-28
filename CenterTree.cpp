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
 

vector<int> Tree_centers(vector<vector<int>>&gg){

    int n = gg.size();
    vector<int>deg(n,0);
    queue<int>qq;
    int leaves = 0;
    for(int i=0;i<n;i++){
        deg[i]=gg[i].size();
        if(deg[i]==1){
           qq.push(i);
           leaves++;
        }
    }

    while(leaves<n){
        
        int v = qq.front();
        qq.pop();
        
        for(auto u : gg[v]){
            deg[u]--;
            if(deg[u]==1){
                qq.push(u);
                leaves++;
            }
        }

        deg[v]=0;

    }

    vector<int>centers;
    centers.clear();
    while(!qq.empty()){
        centers.push_back(qq.front());
        qq.pop();
    }

    return centers;
}
 
int main()
{
 
 
 
 
 
return 0;
   
}