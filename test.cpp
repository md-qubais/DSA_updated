public static int journeyToMoon(int n, List<List<Integer>> astronaut) {
 List<Integer>[] graph = new List[n];
        for( int i = 0 ; i < n ; i++ ){
            graph[i] = new ArrayList<>();
        }
        for( List<Integer> list : astronaut ){
            int v1 = list.get(0);
            int v2 = list.get(1);
            graph[v1].add(v2);
            graph[v2].add(v1);
        }
        //*************
        
        // Get connected Component
        boolean[] visited = new boolean[n];
        List<Integer> list = new ArrayList<>();
        // geting the count of vertices in each component
        
        for( int i = 0 ; i < n ; i++ ){
            if( visited[i] == false ){
                int count = dfs(graph,i,visited);
                list.add(count);
            }
        }
        int ans = 0;
        int adder=list.get(0);
        for( int i = 1 ; i < list.size() ; i++ ){
            ans+=adder*list.get(i);
            adder+=list.get(i);
        }
        return ans;
    }
    public static int dfs(List<Integer>[] graph , int src , boolean[] visited){
        visited[src] = true;
        int count = 0;
        for( Integer nbr : graph[src] ){
            if( visited[nbr] == false ){
                count += dfs(graph,nbr,visited);
            }
        }
        return count+1;
    }