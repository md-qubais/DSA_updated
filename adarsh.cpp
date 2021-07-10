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
int32_t main(){
	qubais_judge;
	IOS;
	string s1;
	cin>>s1;
	s1+=",";
	string s2;
	cin>>s2;
	s2+=",";
	vector<string> arr1;
	vector<string> arr2;
	string temp="";
	for(int i=0;i<s1.length();i++){
		if(s1[i]==','){
			if(temp.length()>0){
				arr1.push_back(temp);
			}
			temp="";
			continue;
		}
		temp+=s1[i];
	}
	temp="";
	for(int i=0;i<s2.length();i++){
		if(s2[i]==','){
			if(temp.length()>0){
				arr2.push_back(temp);
			}
			temp="";
			continue;
		}
		temp+=s2[i];
	}
	return 0;
}