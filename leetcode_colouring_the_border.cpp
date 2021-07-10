class Solution {
public:
    bool visited[1000][1000]={false};
    void color(vector<vector<int>>&grid,int i,int j,int replace,int num){
        if(i<0 or j<0 or i>=grid.size() or j>=grid[i].size() or visited[i][j] or grid[i][j]!=num){
            return;
        }
        visited[i][j]=true;
        if(i==0 or j==0 or i==grid.size()-1 or j==grid[i].size()-1){
            grid[i][j]=replace;
        }
        int row_dir[]={1,-1,0,0};
        int col_dir[]={0,0,1,-1};
        for(int k=0;k<4;k++){
            color(grid,i+row_dir[k],j+col_dir[k],replace,num);
        }
    }
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int i, int j, int number) {
        color(grid,i,j,number,grid[i][j]);
        return grid;
    }
};