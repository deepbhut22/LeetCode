class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        //we just need to get topological ordering of graph and that will be our answer.
        //if no valid topological sort is found then cycle is detected hence null vector will be answer.

        vector<int> adj[numCourses];
        vector<int> indegree(numCourses,0);

        for(auto i : prerequisites) {
            adj[i[1]].push_back(i[0]);
            indegree[i[0]]++;
        }
        queue<int> q;
        for(int i=0 ; i<numCourses ; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        int front;
        vector<int> ans;
        while(!q.empty()) {
            front = q.front();
            q.pop();
            ans.push_back(front);

            for(auto i: adj[front]) {
                indegree[i]--;
                if(indegree[i] == 0) 
                    q.push(i);
            }
        }
        if(ans.size() == numCourses)
            return ans;
        else return {};
    }
};