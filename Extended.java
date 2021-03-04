import java.io.*;
import java.util.*;
class Extended{
    static final int mod = 1000000007;
    static final int size = 1000001;
    static class FastReader{
        BufferedReader br;
        StringTokenizer st;
        public FastReader(){
            br=new BufferedReader(new InputStreamReader(System.in));
        }
        String next(){
            while(st==null || !st.hasMoreElements()){
                try{
                    st=new StringTokenizer(br.readLine());
                }
                catch(IOException e){
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }
        int nextInt(){
            return Integer.parseInt(next());
        }
        float nextFloat(){
            return Float.parseFloat(next());
        }
        long nextLong(){
            return Long.parseLong(next());
        }
        double nextDouble(){
            return Double.parseDouble(next());
        }
        String nextLine(){
            String str="";
            try{
                str=br.readLine();
            }
            catch(IOException e){
                e.printStackTrace();
            }
            return str;
        }
    }
    public static void main(String[] args){
        
    }
}
class Sieve {
    int mxN;
    boolean isPrime[];
    int spf[];
    int phi[];
    Sieve(int mxN) {
        this.mxN = mxN;
        isPrime = new boolean[mxN];
        spf = new int[mxN];
        phi = new int[mxN];
        Arrays.fill(isPrime,false);
        for(int i=0;i<mxN;i++)
            spf[i] = phi[i] = i;
        for(int i=2;i<mxN;i++)
            if(phi[i]==i)
                for(int j=i;j<mxN;j+=i)
                    phi[j] -= phi[j]/i;
        for(int i=3;i<mxN;i+=2)
            isPrime[i] = true;
        isPrime[2] = true;
        for(int i=3;i*i<mxN;i+=2)
            if(isPrime[i])
                for(int j=i*i;j<mxN;j+=i)
                    isPrime[j] = false;
        for(int i=2;i<mxN;i+=2)
            spf[i] = 2;
        for(int i=3;i*i<mxN;i+=2)
            if(spf[i]==i)
                for(int j=i*i;j<mxN;j+=i)
                    if(spf[j]==j)
                        spf[j] = i;
    }
    public int factorize(int n) {
        int ans = 1;
        while(n>1) {
            int temp = spf[n];
            int c = 0;
            while(temp==spf[n]) {
                n/=spf[n];
                c++;
            }
            ans*=c+1;
        }
        return ans;
    }
    public static boolean check(int n) {
        if(n==0 || n==1)
            return false;
        else if(n==2 || n==3)
            return true;
        else if(n%2==0 || n%3==0)
            return false;
        for(int i=5;i*i<=n;i+=6)
            if(n%i==0 || n%(i+2)==0)
                return false;
        return true;
    }
}
class Graph {
    class Node {
        LinkedList<Integer> friends;
        Node() {
            friends = new LinkedList<Integer>();
        }
        void add(int friend) {
            friends.add(friend);
        }
    }
    Node[] graph;
    int V,E;
    Graph(int V, int E) {
        this.V = V;
        this.E = E;
        graph = new Node[V];
        for(int i=0;i<V;i++)
            graph[i] = new Node();
    }
    void addEdge(int a, int b) {
        this.graph[a].add(b);
    }
    void bfs(int start) {
        Queue<Integer> queue = new LinkedList<Integer>();
        queue.add(start);
        boolean visited[] = new boolean[this.V];
        Arrays.fill(visited,false);
        visited[start] = true;
        while(!queue.isEmpty()) {
            start = queue.poll();
            System.out.print(start+" ");
            for(int i: this.graph[start].friends) {
                if(!visited[i]) {
                    visited[i] = true;
                    queue.add(i);
                }
            }
        }
    }
}