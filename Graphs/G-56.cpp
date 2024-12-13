//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    private:
    int timer=0;
    private:
    void dfs(int node, int parent, vector<int>&vis, vector<int>&tin,
    vector<int>&low, vector<int>&marks,vector<int>adj[]){
        vis[node]=1;
        tin[node]=low[node]=timer;
        timer++;
        int child=0;
        for(auto it: adj[node]){
            if(it==parent) continue;
            if(!vis[it]){
                dfs(it,node,vis,tin,low,marks,adj);
                low[node]=min(low[node],low[it]);
                if(low[it]>=tin[node]&&parent!=-1){
                    marks[node]=1;
                }
                child++;
            }
            else{
                low[node]=min(low[node],tin[it]);
            }
        }
        if(child>1 && parent ==-1){
            marks[node]=1;
        }
        
    }
    
    
  public:
    vector<int> articulationPoints(int n, vector<int>adj[]) {
        vector<int>vis(n,0);
        vector<int>tin(n,0);
        vector<int>low(n,0);
        vector<int>marks(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,-1,vis,tin,low,marks,adj);
            }
        }
        
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(marks[i]==1){
                ans.push_back(i);
            }
            
        }
        if(ans.size()==0) return {-1};
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends