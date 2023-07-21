class Solution {
public:

    void dfs(int r, int c, vector<vector<bool>> &generalTerm, vector<vector<int>>& heights, int prevHeight) {
        if(r<0 || c<0 || r>=heights.size() || c>=heights[0].size() || generalTerm[r][c] || heights[r][c] <  prevHeight) return;

        generalTerm[r][c] = 1;

        dfs(r,c-1,generalTerm,heights,heights[r][c]);
        dfs(r,c+1,generalTerm,heights,heights[r][c]);
        dfs(r-1,c,generalTerm,heights,heights[r][c]);
        dfs(r+1,c,generalTerm,heights,heights[r][c]);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if(heights.empty() || heights[0].empty()) return {};
        int row = heights.size();
        int col = heights[0].size();

        vector<vector<bool>> pacific(row, vector<bool>(col,false));
        vector<vector<bool>> atlantic(row, vector<bool>(col,false));

        for(int i=0 ; i<col ; i++) {
            dfs(0, i, pacific, heights, heights[0][i]);
            dfs(row-1, i, atlantic, heights, heights[row-1][i]);
        }
        for(int i=0 ; i<row ; i++) {
            dfs(i, 0, pacific, heights, heights[i][0]);
            dfs(i, col-1, atlantic, heights, heights[i][col-1]);
        }
        vector<vector<int>> ans;

        for(int i=0 ; i<row ; i++) {
            for(int j=0 ; j<col ; j++) {
                if(pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i,j});
                }
            }
        }
        return ans;
    }
};