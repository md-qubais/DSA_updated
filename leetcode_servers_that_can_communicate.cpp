class Solution {
public:

    int countServers(vector<vector<int>>& grid){
        unordered_map<int,int> row,col;
        vector<pair<int,int>> indices;
        int tot=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1){
                    tot+=grid[i][j];
                    row[i]++;
                    col[j]++;
                    indices.push_back({i,j});
                }
            }
        }
        for(int i=0;i<indices.size();i++){
            int rows=indices[i].first;
            int cols=indices[i].second;
            if(row[rows]==1 and col[cols]==1){
                row[rows]=col[cols]=0;
                tot--;
            }
        }
        return tot;
    }
    
};