class Pair{
public:
    int row;
    int col;
    int tot;
    Pair(int row,int col,int tot){
        this->row=row;
        this->col=col;
        this->tot=tot;
    }
};
int row_dir[]={1,-1,0,0};
int col_dir[]={0,0,1,-1};
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat){
        queue<Pair*> q;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==0){
                    q.push(new Pair(i,j,0));
                }
            }
        }
        unordered_map<int,unordered_map<int,bool>> visited;
        while(!q.empty()){
            Pair*temp=q.front();
            q.pop();
            int rows=temp->row;
            int cols=temp->col;
            if(visited[rows][cols]){
                continue;
            }
            visited[rows][cols]=true;
            mat[rows][cols]=temp->tot;
            for(int k=0;k<4;k++){
                int i=rows+row_dir[k];
                int j=cols+col_dir[k];
                if(i>=0 and j>=0 and i<mat.size() and j<mat[i].size() and mat[i][j]!=0){
                    q.push(new Pair(i,j,temp->tot+1));
                }
            }
        }
        return mat;
    }
};