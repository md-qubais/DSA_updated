class Solution {
public:
	void set_zero(vector<vector<int>>& matrix,int rows,int cols){
		for(int i=0;i<matrix.size();i++){
			matrix[i][cols]=0;
		}
		for(int i=0;i<matrix[0].size();i++){
			matrix[rows][i]=0;
		}
	}
    void setZeroes(vector<vector<int>>& matrix){
    	vector<int> rows;
    	vector<int> cols;
    	for(int i=0;i<matrix.size();i++){
    		for(int j=0;j<matrix[i].size();j++){
    			if(matrix[i][j]==0){
    				rows.push_back(i);
    				cols.push_back(j);
    			}
    		}
    	}
    	int size=rows.size();
    	for(int i=0;i<size;i++){
    		set_zero(matrix,rows[i],cols[i]);
    	}
    }
};