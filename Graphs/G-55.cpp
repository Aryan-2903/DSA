class Solution {
private: 
    int timer = 1;

    void dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& vis, 
             vector<int>& timein, vector<int>& low, vector<vector<int>>& bridges) {
        vis[node] = 1;
        timein[node] = low[node] = timer;
        timer++;

        for(auto it : adj[node]) {
            // Skip the parent node to avoid immediate backtracking
            if(it == parent) continue;

            if(!vis[it]) {
                dfs(it, node, adj, vis, timein, low, bridges);
                
                low[node] = min(low[node], low[it]);

                // Bridge detection condition
                if(low[it] > timein[node]) {
                    bridges.push_back({node, it});
                }
            } else {

                low[node] = min(low[node], timein[it]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(auto& it : connections) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> vis(n, 0);
        vector<int> timein(n, 0);
        vector<int> low(n, 0);
        vector<vector<int>> bridges;

        dfs(0, -1, adj, vis, timein, low, bridges);

        return bridges;
    }
};