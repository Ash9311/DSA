//https://leetcode.com/problems/is-graph-bipartite/submissions/

//BFS
class Solution {
public:
    
    bool checkBipartite(int src,vector<int> &color,vector<vector<int>>& graph){
        queue<int> q;
        q.push(src);
        color[src]=1;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it: graph[node]){
                if(color[it]==color[node]){
                    return false;
                }
                else if(color[it]==-1){
                    color[it]=1-color[node];
                    q.push(it);
                }
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(!checkBipartite(i,color,graph)){
                    return false;
                }
            }
        }
        return true;
    }
};






//DFS
class Solution {
public:
    
    bool checkBipartiteDFS(int node,vector<int> &color,vector<vector<int>>& graph){
      if(color[node]==-1){
          color[node]=1;
      }
        for(auto it:graph[node]){
            if(color[it]==color[node]){
                return false;
            }
            else if(color[it]==-1){
                color[it]=1-color[node];
                if(!checkBipartiteDFS(it,color,graph)){
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(!checkBipartiteDFS(i,color,graph)){
                    return false;
                }
            }
        }
        return true;
    }
};







