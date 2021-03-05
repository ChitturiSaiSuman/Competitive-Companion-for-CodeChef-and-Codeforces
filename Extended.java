
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