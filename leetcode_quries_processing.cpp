class Solution{
public:
    vector<int> processQueries(vector<int>& queries, int m){
    	deque<int> arr;
    	for(int i=1;i<=m;i++){
    		arr.push_back(i);
    	}
    	vector<int> res;
    	for(int i=0;i<queries.size();i++){
    		int number=queries[i];
    		deque<int>::iterator it1=find(arr.begin(),arr.end(),number);
            deque<int>::iterator it2=arr.begin();
    		int index=it1-it2;
            res.push_back(index);
    		arr.erase(it1,it1+1);
    		arr.push_front(number);
    	}
    	return res;
    }
};