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



void dfs(int v,vector<int>&mark,vector<vector<int>>&gg,vector<int>&dist){
    
    mark[v]=1;

    for(auto u : gg[v]){
        if(!mark[u]){
            dist[u]=dist[v]+1;
            dfs(u,mark,gg,dist);
        }
    }

}


 
int main()
{
  int tt;cin>>tt;
  while(tt--){
      
      int n;cin>>n>>k;
      vector<vector<int>>gg(n);
       
      for(int i=0;i<n;i++)gg[i].clear();

      for(int i=0;i<n-1;i++){
          int v,u;cin>>v>>u;
          v--;u--;
          gg[v].push_back(u);
          gg[u].push_back(v);
      }



      for(int i=0;i<n;i++){

          vector<int>mark(n,0);
        

          int kk = gg[i].size()+1;
          vector<pair<int,int>>layer;
          layer.clear();
          vector<int>count(kk,0)     
          for(int j=0;j<gg[i].size();j++){
             layer.push_back({gg[i][j],j});
             count[j]++;
             mark[gg[i][j]]=1;
          }
          vector<vecotr<int>>dp(kk,vecotr<int>(k+1,0));
          ll ans = 0;
          while(!layer.empty()){


              memset(dp,0,sizeof(dp));
              dp[0][0]=1;

              for(int j=0;i<kk;j++){
                  for(int hh=0;hh<=k;hh++){
                      dp[j+1][hh]=(dp[j+1][hh]+dp[j][hh])%MOD;
                      dp[j+1][hh+1]=(dp[j+1][hh+1]+(count[j]*dp[j][hh])%MOD)%MOD;
                  }
              }


              ans=(ans+dp[kk-1]][k])%MOD;
              

              vector<pair<int, int>> newlayer;
              newlayer.clear();
              for (auto p : layer)
              {
                    cnt[p.second]--;
                    for (auto y : g[p.first]){
                        if (!used[y])
                        {
                            newlayer.emplace_back(y, p.second);
                            used[y] = true;
                            cnt[p.second]++;
                        }
                    }
              }

			  layer = newlayer;

          }


          cout<<ans<<"\n";
          



      
      
      
      }



      }



  }
 
 
 
return 0;
   
}