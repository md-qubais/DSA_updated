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
class Edge{
public:
	int v,w;
	Edge(int v,int w){
		this->v=v;
		this->w=w;
	}
};

//O(E+V)
void add_edge(vector<vector<Edge*>>&graph,int u,int v,int w){
	graph[u].push_back(new Edge(v,w));
	graph[v].push_back(new Edge(u,w));

}


//time complex of display is O(2E)
//because for every vertex we are travelling
//its corresponding edges that why if we calcuate
//how many total number of edges are present in that 
//component and caluculate that total edges travel
//by display funtion we can get that its 2E
void display(vector<vector<Edge*>>&graph){
	for(int i=0;i<graph.size();i++){
		cout<<i<<"->";
		for(auto&it:graph[i]){
			cout<<"("<<it->v<<","<<it->w<<")";
		}
		cout<<endl;
	}

}


//O(Edges of u)
int find_edge(vector<vector<Edge*>>&graph,int u,int v){
	for(int i=0;i<graph[u].size();i++){
		if(graph[u][i]->v==v){
			return i;
		}
	}
	return -1;

}

//its time complex is O(E)
//O(E) where E is the total number of edges in that
//particular component
//O(V) means that there are V vertices in the entire graph
//comprising of all the components
//O(E+V) means the entire graphs in which it comprimises
//of total edges in some of the connected components
//and V number of vertices in the entire graphs which has 
//no connected edges
bool HasPath(vector<vector<Edge*>>&graph,int src,int dest,unordered_map<int,bool>&visited){
	if(src==dest){
		return true;
	}
	if(visited[src]){
		return false;
	}
	visited[src]=true;
	for(auto&it:graph[src]){
		if(HasPath(graph,it->v,dest,visited)){
			return true;
		}
	}
	return false;
}




//O(E^2) worst case tine complex
//or can be say like this O(VE)
int printAllPath(vector<vector<Edge*>>&graph,int src,int dest,string psf,int wsf,unordered_map<int,bool>&visited){
	if(src==dest){
		cout<<psf+to_string(src)<<" "<<wsf<<endl;
		return 1;
	}
	visited[src]=true;
	int count=0;
	for(auto&it:graph[src]){
		if(!visited[it->v]){
			count+=printAllPath(graph,it->v,dest,psf+to_string(src),wsf+it->w,visited);
		}
	}
	visited[src]=false;
	return count;
}

void get_GCC(vector<vector<Edge*>>&graph,int src,unordered_map<int,bool>&visited){
	visited[src]=true;
	for(auto&it:graph[src]){
		if(!visited[it->v]){
			get_GCC(graph,it->v,visited);
		}
	}

}

void getconnectedcomponents(vector<vector<Edge*>>&graph){
	int components=0;
	unordered_map<int,bool> visited;
	for(int i=0;i<graph.size();i++){
		//and here are considering all the 
		//vertices are present from 0 to n-1(grah.size()-1)
		if(!visited[i]){
			components++;
			get_GCC(graph,i,visited);
		}
	}
	cout<<"the total number of connected components are:"<<components<<endl;
}

void construct_graph(){
	int n=10;
	vector<vector<Edge*>> graph(n);
	for(int i=0;i<n;i++){
		vector<Edge*> temp;
		graph[i]=temp;
	}
	
	add_edge(graph,0,1,10);
	add_edge(graph,1,2,10);
	add_edge(graph,2,3,40);
	add_edge(graph,3,0,10);
	add_edge(graph,3,4,2);
	add_edge(graph,4,5,2);
	add_edge(graph,5,6,3);
	add_edge(graph,6,4,8);
	add_edge(graph,7,8,10);
	add_edge(graph,8,9,10);
	display(graph);
	unordered_map<int,bool> visited;
	if(HasPath(graph,0,5,visited)){
		cout<<"there is a path between "<<0<<" and "<<5<<endl;
	}else{
		cout<<"no path exists"<<endl;
	}
	visited.clear();
	cout<<printAllPath(graph,0,6,"",0,visited)<<endl;


	///here below the time complex of the getconnectedcomponents
	//is 
	//in the best case that means that the entire graph
	//is only the single connected component
	//that means O(E) is the time complex


	//and the next time complex can be O(V) that means 
	//the entire graph consists of different components
	//not evern a single components is connected

	//and the last time complex is O(E+V) that means there are
	//some connected components in the entire graph
	//and there are some vertices that means only vertices(nodes)
	//which are not connected to any component
	//where the graph is the combination of connected components
	//and non connected components
	getconnectedcomponents(graph);
}



//in graph time complex of total number of components 
//in the graph is O(V+E) Where E is the edges of that
//connected components and V are the vertices of 
//non Connected components in that entire graph

//and in graph time complex of a particular component
//is O(E) where E is the edges of thata connected component
int32_t main(){
	qubais_judge;
	IOS;
	construct_graph();
	return 0;
}

