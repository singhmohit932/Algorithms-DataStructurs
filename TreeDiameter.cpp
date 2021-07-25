int ans;

void dfs(int v,int p, vector<int>&mark , vector<pair<int,int>>&dis ,vector<vector<int>>&gg){
    
    mark[v]++;
    int k1=0;
    int k2=0;
    
    for(auto u : gg[v]){
        if(!mark[u]){
            dfs(u,v,mark,dis,gg);
            dis[v].FF=max(dis[v].FF,1+dis[u].FF);
            if(dis[u].FF>=k1){
                k2=k1;
                k1=dis[u].FF;
            }else k2=max(k2,dis[u].FF);
        }
    }
    
    
    if((v==0&&gg[v].size()>=2)||(gg[v].size()>=3))ans=max(ans,2+k1+k2);
    else if(gg[v].size())ans=max(ans,1+k1);
 
    
 
 
}


int main()
{   
   ans=0;
   int n;cin>>n;
   vector<vector<int>>gg(n);
   vector<int>mark(n,0);
   vector<pair<int,int>>dis(n,{0,0});
   
   for(int i=0;i<n;i++)gg[i].clear();
 
   for(int i=0;i<n-1;i++){
       int v,u;cin>>v>>u;
       v--;u--;
       gg[v].PB(u);
       gg[u].PB(v);
   }
 
 
   dfs(0,-1,mark,dis,gg);
 
  cout<<ans<<'\n';
 
 
return 0;
   
}