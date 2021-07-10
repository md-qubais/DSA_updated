class Solution{
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int i=0;
        int j=people.size()-1;
        int boats=0;
        while(i<people.size() and i<=j){
            if(i==j){
                boats++;
                i++;
                j--;
                continue;
            }
            if(people[i]+people[j]<=limit){
                i++;
                j--;
                boats++;
                continue;
            }
            j--;
            boats++;
        }
        return boats;
    }
};