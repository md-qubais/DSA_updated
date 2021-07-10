int row_dir[]={1,-1,0,0};
int col_dir[]={0,0,1,-1};
class Solution {
public:
    bool visited[1000][1000]={false};
    
    void visit_all(vector<vector<int>>& grid2,int i,int j){
        if(i<0 or j<0 or i>=grid2.size() or j>=grid2[i].size()){
            return;
        }
        if(grid2[i][j]==0){
            return;
        }
        if(visited[i][j]){
            return;
        }
        visited[i][j]=true;
        for(int k=0;k<4;k++){
            visit_all(grid2,i+row_dir[k],j+col_dir[k]);
        }
    }

    bool get_sub(vector<vector<int>>& grid1, vector<vector<int>>& grid2,int i,int j){
        if(i<0 or j<0 or i>=grid2.size() or j>=grid2[i].size()){
            return true;
        }
        if(visited[i][j]){
            return true;
        }
        if(grid2[i][j]==0 and grid1[i][j]==0){
            return true;
        }
        if(grid2[i][j]==0 and grid1[i][j]==1){
            return true;
        }
        if(grid2[i][j]==1 and grid1[i][j]==0){
            return false;
        }
        visited[i][j]=true;
        for(int k=0;k<4;k++){
            if(!get_sub(grid1,grid2,i+row_dir[k],j+col_dir[k])){
                visit_all(grid2,i+1,j);
                visit_all(grid2,i-1,j);
                visit_all(grid2,i,j+1);
                visit_all(grid2,i,j-1);
                return false;
            }
        }
        return true;
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2){
        int ans=0;
        for(int i=0;i<grid2.size();i++){
            for(int j=0;j<grid2[i].size();j++){
                if(grid2[i][j]==1 and !visited[i][j] and get_sub(grid1,grid2,i,j)){
                    ans++;
                }
            }
        }
        return ans;
    }
};