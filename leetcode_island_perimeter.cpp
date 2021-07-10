class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int one_count=0;
        int count=0;
        //count neighbour of present from down and right
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==1){
                    one_count++;
                    if(i+1<grid.size()){
                        if(grid[i+1][j]) count++;
                    }
                    if(j+1<grid[i].size()){
                        if(grid[i][j+1]) count++;
                    }
                }
            }
        }
        return 4*one_count-(2*count);
    }
};