class Solution {
public:
    void shift_grid(vector<vector<int>>& grid,int k){
        vector<int> row;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                row.push_back(grid[i][j]);
            }
            int n=row.size();
            int n=k%n;
            

        }
    }
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k){
        for(int i=0;i<k;i++){
            shift_grid(grid,k);
        }
        return grid;
    }
};