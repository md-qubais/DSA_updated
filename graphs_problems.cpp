#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false);  cin.tie(NULL)
#define int long long
#define endl "\n"
#define pb push_back
#define p push
#define fori(n) for(int i=0;i<n;i++)
#define ford(n) for(int i=n-1;i>=0;i--)
#define fl(x,n) for(int i=x;i<n;i++)
#define Maxheap priority_queue<int>
#define Minheap priority_queue<int,vector<int>,greater<int>>
#define qubais_judge freopen("input.txt","r",stdin); freopen("output.txt","w",stdout)
using namespace std;

//question 1 
//connected components in the graph
int row_dir[]={1,-1,0,0};
int col_dir[]={0,0,1,-1};
void visit_all_dfs(vector<vector<int>>&mat,int i,int j,int visited[100][100]){
	if(i<0 or j<0 or i>=mat.size() or j>=mat[i].size() or visited[i][j] or mat[i][j]==0){
		return;
	}
	visited[i][j]=true;
	for(int k=0;k<4;k++){
		visit_all_dfs(mat,i+row_dir[k],j+col_dir[k],visited);
	}
}
int get_connected_dfs(vector<vector<int>>&mat){
	int ans=0;
	int visited[100][100]={false};
	for(int i=0;i<mat.size();i++){
		for(int j=0;j<mat[i].size();j++){
			if(!visited[i][j] and mat[i][j]==1){
				ans++;
				visit_all_dfs(mat,i,j,visited);
			}
		}
	}
	return ans;
}

int visit_all_bfs(vector<vector<int>>&mat,int i,int j,int visited[100][100]){
	//first i and second j
	queue<pair<int,int>> q;
	q.push(make_pair(i,j));
	while(!q.empty()){
		pair<int,int> temp=q.front();
		q.pop();
		if(visited[temp.first][temp.second]){
			continue;
		}
		visited[temp.first][temp.second]=true;
		for(int k=0;k<4;k++){
			int row=temp.first+row_dir[k];
			int col=temp.second+col_dir[k];
			if(row<0 or col<0 or row>=mat.size() or col>=mat[row].size() or visited[row][col] or mat[row][col]==0){
				continue;
			}
			q.push(make_pair(row,col));
		}
	}
}

int get_connected_bfs(vector<vector<int>>&mat){
	int ans=0;
	int visited[100][100]={false};
	for(int i=0;i<mat.size();i++){
		for(int j=0;j<mat[i].size();j++){
			if(!visited[i][j] and mat[i][j]==1){
				ans++;
				visit_all_bfs(mat,i,j,visited);
			}
		}
	}
	return ans;
}
int get_connected_components(vector<vector<int>>&mat){
	int ans_dfs=get_connected_dfs(mat);
	int ans_bfs=get_connected_bfs(mat);
	return ans_bfs;
}


//question 2
//path with lesser than self
bool is_path_1(vector<vector<int>>&mat){
	bool visited[100][100]={false};
	queue<pair<int,int>> q;
	q.push(make_pair(0,0));
	while(!q.empty()){
		pair<int,int> temp=q.front();
		q.pop();
		if(temp.first==mat.size()-1 and temp.second==mat[0].size()-1){
			return true;
		}
		if(visited[temp.first][temp.second]){
			continue;
		}
		visited[temp.first][temp.second]=true;
		for(int k=0;k<4;k++){
			int row=temp.first+row_dir[k];
			int col=temp.second+col_dir[k];
			if(row<0 or col<0 or row>=mat.size() or col>=mat.size() or mat[row][col]>=mat[temp.first][temp.second] or visited[row][col]){
				continue;
			}
			q.push(make_pair(row,col));
		}
	}
	return false;
}


bool is_path_2(vector<vector<int>>&mat){
	bool visited[100][100]={false};
	queue<pair<int,int>> q;
	q.push(make_pair(0,0));
	visited[0][0]=true;
	while(!q.empty()){
		pair<int,int> temp=q.front();
		q.pop();
		if(temp.first==mat.size()-1 and temp.second==mat[0].size()-1){
			return true;
		}
		for(int k=0;k<4;k++){
			int row=temp.first+row_dir[k];
			int col=temp.second+col_dir[k];
			if(row<0 or col<0 or row>=mat.size() or col>=mat.size() or mat[row][col]>=mat[temp.first][temp.second] or visited[row][col]){
				continue;
			}
			visited[row][col]=true;
			q.push(make_pair(row,col));
		}
	}
	return false;
}
int32_t main(){
	qubais_judge;
	IOS;
	int rows;
	int cols;
	cin>>rows>>cols;
	vector<vector<int>> mat(rows);
	for(int i=0;i<rows;i++){
		mat[i].resize(cols);
	}
	for(int i=0;i<rows;i++){
		for(int j=0;j<cols;j++){
			cin>>mat[i][j];
		}
	}
	
	return 0;
}