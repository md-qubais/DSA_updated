#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'journeyToMoon' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY astronaut
 */


class Graph{
public:
    unordered_map<long long,list<long long>> l;
    void add_edge(long long u,long long v){
        l[u].push_back(v);
        l[v].push_back(u);
    }
    long long dfs(long long src,unordered_map<long long,bool>&visited){
        long long ans=0;
        visited[src]=true;
        for(auto&it:l[src]){
            if(!visited[it]){
                ans+=dfs(it,visited);
            }
        }
        return ans+1;
    }
    long long ChoosePair(long long n){
        vector<long long> arr;
        long long ans=0;
        unordered_map<long long,bool> visited;
        for(long long i=0;i<n;i++){
            if(!visited[i]){
                long long count=dfs(i,visited);
                arr.push_back(count);
            }
        }
        long long count=arr[0];
        for(long long i=1;i<arr.size();i++){
            ans+=count*arr[i];
            count+=arr[i];
        }
        return ans;
    }
};
//time complexity is O(V+E)
long long journeyToMoon(int n, vector<vector<int>> astronaut){
    Graph g;
    for(int i=0;i<astronaut.size();i++){
        g.add_edge(astronaut[i][0],astronaut[i][1]);
    }
    return g.ChoosePair(n);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int p = stoi(first_multiple_input[1]);

    vector<vector<int>> astronaut(p);

    for (int i = 0; i < p; i++) {
        astronaut[i].resize(2);

        string astronaut_row_temp_temp;
        getline(cin, astronaut_row_temp_temp);

        vector<string> astronaut_row_temp = split(rtrim(astronaut_row_temp_temp));

        for (int j = 0; j < 2; j++) {
            int astronaut_row_item = stoi(astronaut_row_temp[j]);

            astronaut[i][j] = astronaut_row_item;
        }
    }

    long long result = journeyToMoon(n, astronaut);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
