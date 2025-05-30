class Solution {
  public:
    bool detectcycle(int i,map<int,vector<int>> mpp,vector<bool>& vis){
        queue<pair<int,int>> q;
        q.push({i,-1});
        vis[i] = true;
        while(!q.empty()){
            int currnode = q.front().first;
            int parnode = q.front().second;
            q.pop();
            for(auto childnode : mpp[currnode]){
                if(!vis[childnode]){
                    q.push({childnode,currnode});
                    vis[childnode]=true;
                }
                else if(parnode != childnode)    return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        map<int, vector<int>> mpp;
        for(int i=0;i<edges.size();i++){
            mpp[edges[i][0]].push_back(edges[i][1]);
            mpp[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> vis(V, false);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(detectcycle(i,mpp,vis))  return true;
            }
        }
        return false;
    }
};