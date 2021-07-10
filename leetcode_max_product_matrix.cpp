class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid,int i,int j,int rows,int cols){
        if(i>rows or j>cols){
            return INT_MIN;
        }
        if(i==rows and j==cols){
            return grid[i][j];
        }
        int ans=max(maxProductPath(grid,i+1,j,rows,cols),maxProductPath(grid,i,j+1,rows,cols));
        cout<<grid[i][j]<<" "<<ans<<endl;
        return grid[i][j]*ans;
    }
    int maxProductPath(vector<vector<int>>& grid){
        int ans=maxProductPath(grid,0,0,grid.size()-1,grid[0].size()-1);
        return ans;
    }
};