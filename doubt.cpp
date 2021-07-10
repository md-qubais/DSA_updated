import java.io.*;
import java.util.*;

public class Main {
    static class Edge {
        int src;
        int nbr;
        int wt;

        Edge(int src, int nbr, int wt) {
            this.src = src;
            this.nbr = nbr;
            this.wt = wt;
        }
    }

    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int vtces = Integer.parseInt(br.readLine());
        ArrayList < Edge > [] graph = new ArrayList[vtces];
        for (int i = 0; i < vtces; i++) {
            graph[i] = new ArrayList < > ();
        }

        int edges = Integer.parseInt(br.readLine());
        for (int i = 0; i < edges; i++) {
            String[] parts = br.readLine().split(" ");
            int v1 = Integer.parseInt(parts[0]);
            int v2 = Integer.parseInt(parts[1]);
            int wt = Integer.parseInt(parts[2]);
            graph[v1].add(new Edge(v1, v2, wt));
            graph[v2].add(new Edge(v2, v1, wt));
        }

        boolean[] vis = new boolean[graph.length];
        boolean b=false;
        for(int i=0; i<graph.length; i++){
            if(vis[i]==false){
                if(isCyclic(graph,i,vis)){
                    b=true;
                    System.out.println(true);
                    break;
                }
            }
        }
        if(b==false) System.out.println(false);
    }
    
    public static boolean isCyclic(ArrayList<Edge>[] graph , int src,boolean[] vis) {
        boolean isCycle = false;
        Queue < Integer > q = new ArrayDeque < > ();
        q.offer(src);

        while (q.size()>0) {
            int size = q.size();

            while (size--> 0) {
                int rem = q.poll(); 
                
                if (vis[rem] == true) { 
                    isCycle = true;
                    continue;
                } 
                else vis[rem] = true;
            
                for (Edge e: graph[rem]) {
                    int nbr = e.nbr;
                    if (vis[nbr] == false) {
                        q.offer(nbr);
                    }
                }
            }
        }

        return isCycle;
    }
}