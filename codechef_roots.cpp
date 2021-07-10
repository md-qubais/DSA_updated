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
	int n;
	cin>>n;
	int q;
	cin>>q;
	vector<int> arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	bool flag=false;
	sort(arr.begin(),arr.end());
	while(q--){
		int num;
		cin>>num;
		int s=0;
		int e=arr.size()-1;
		int ans;
		while(s<=e){
			int mid=(s+e)/2;
			ans=mid;
			if(arr[mid]>num){
				e=mid-1;
			}else if(arr[mid]<num){
				s=mid+1;
			}else if(arr[mid]==num){
				cout<<0<<endl;
				flag=true;
				break;
			}
		}
		int count=0;
		if(!flag){
			if(arr[ans]<num){
				count+=arr.size()-ans-1;
			}else if(arr[ans]>num){
				count+=arr.size()-ans;
			}
			if(count&1){
				cout<<"NEGATIVE"<<endl;
			}else{
				cout<<"POSITIVE"<<endl;
			}
		}
	}

	return 0;
}

