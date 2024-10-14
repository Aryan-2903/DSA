
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<int,int>>adj[n];
        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<long long >dist(n,LONG_MAX);
        vector<long long >ways(n,0);
        priority_queue<vector<long long>,vector<vector<long long>>,greater<vector<long long>>>q;
        q.push({0,0});
        dist[0]=0;
        ways[0]=1;
        int mod = (int)(1e9+7);
        while(!q.empty()){
            auto it = q.top();
            long long  dis = it[0];
            long long node = it[1];
            q.pop();
            for(auto iter: adj[node]){
                long long adjNode = iter.first;
                long long eW = iter.second;
                //first time coming with a short distance
                if(eW+dis<dist[adjNode]){
                    dist[adjNode]=eW+dis;
                    q.push({dist[adjNode],adjNode});
                    ways[adjNode]=ways[node];
                }
                //when we found other route to a node with same distance
                else if(eW+dis==dist[adjNode]){
                    ways[adjNode]=(ways[adjNode]+ways[node])%mod;
                }

            }
        }
        return ways[n-1]%mod;
        
    }