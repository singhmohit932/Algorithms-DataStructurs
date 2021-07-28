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


vector<int> TopSort(vector<vector<int>>&gg){

    int n = gg.size();
    vector<int>mark(n,0);
    vector<int>Ordering(n);
    int index = n-1;

    for(int i=0;i<n;i++){
        if(!mark[v]){
           dfs(v,Ordering,index,gg);
        }
    }

    return Ordering;
}


void dfs(int v,vector<int>&Ordering,int &index,vector<vector<int>>&gg,vector<int>mark){
     mark[v]++;
     for(auto u : gg[v]){
         if(mark[u]==0){
             dfs(u,Ordering,index,gg,mark);

         }
     }

     Ordering[index]=v;
     index--;
}
 
 
int main()
{
 
 
 
 
 
return 0;
   
}