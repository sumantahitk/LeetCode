class Solution {
public:
    void dfs(vector<vector<int>>&adj,vector<vector<int>>&ans,vector<int>&a,int node,int dst){
        a.push_back(node);
        if(node==dst){
            ans.push_back(a);
            a.pop_back();
            return;
        }
        for(int i=0;i<adj[node].size();i++){
                dfs(adj,ans,a,adj[node][i],dst);
        }
        a.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>ans;
        vector<int>a;
   
        dfs(graph,ans,a,0,graph.size()-1);
        return ans;

    }
};