class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix){
        int ans=0;
        if(matrix.size()==0){
            return ans;
        }
        vector<vector<int>> mat(matrix.size());
        for(int i=0;i<mat.size();i++){
            mat[i].resize(matrix[i].size());
        }
        int rows=mat.size();
        int cols=mat[0].size();
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                mat[i][j]=0;
            }
        }
       for(int j=0;j<cols;j++){
            for(int i=0;i<rows;i++){
                if(i==0){
                    mat[i][j]=matrix[i][j]-'0';
                }else{
                    if(matrix[i][j]=='1'){
                        mat[i][j]+=mat[i-1][j]+(matrix[i][j]-'0');
                    }
                }
            }
        }
        vector<vector<int>> left_small(rows);//stores indices
        vector<vector<int>> right_small(rows);//stores indices
        for(int i=0;i<rows;i++){
            left_small[i].resize(matrix[i].size());
            right_small[i].resize(matrix[i].size());
        }
        stack<int> s;//stores indices
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                while(!s.empty() and mat[i][s.top()]>=mat[i][j]){
                    s.pop();
                }
                if(s.empty()){
                    left_small[i][j]=0;
                }else{
                    left_small[i][j]=s.top()+1;
                }
                s.push(j);
            }
            while(!s.empty()){
                s.pop();
            }
        }
        for(int i=0;i<rows;i++){
            for(int j=cols-1;j>=0;j--){
                while(!s.empty() and mat[i][s.top()]>=mat[i][j]){
                    s.pop();
                }
                if(s.empty()){
                    right_small[i][j]=cols-1;
                }else{
                    right_small[i][j]=s.top()-1;
                }
                s.push(j);
            }
            while(!s.empty()){
                s.pop();
            }
        }
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                ans=max(ans,mat[i][j]*(right_small[i][j]-left_small[i][j]+1));
            }
        }
        return ans;
    }
};