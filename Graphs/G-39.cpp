//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        if(start==end) return 0;
        queue<pair<int,int>>q;
        int n = arr.size();
        vector<int>dist(100000,1e9);
        q.push({0,start});
        dist[start]=0;
        int mod = 100000;

        //Tc - no of edges = 10000*n at worst case
        
        while(!q.empty()){
            auto it = q.front();
            int node = it.second;
            int steps = it.first;
            q.pop();
            for(int i=0;i<n;i++){
                int adjNode = (node*arr[i])%mod;
                if(steps+1<dist[adjNode]){
                    if(adjNode==end) return steps+1;
                dist[adjNode]=steps+1;
                 q.push({steps+1,adjNode});
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends