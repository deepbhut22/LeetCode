class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int> adj[n];
        vector<int> indegree(n,0);

        for(auto i : pre) {
            adj[i[1]].push_back(i[0]);
            indegree[i[0]]++;
        }
        queue<int> q;
        for(int i=0 ; i<n ; i++) {
            if(indegree[i] == 0) q.push(i);
        } 

        int front;
        int c = 0;
        while(!q.empty()) {
            front = q.front();
            q.pop();
            c++;

            for(auto i: adj[front]) {
                indegree[i]--;
                if(indegree[i] == 0) q.push(i);
            }
        }
        return c >= n;
    }
};