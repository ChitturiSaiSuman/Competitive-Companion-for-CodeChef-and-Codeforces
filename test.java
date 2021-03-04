import java.util.*;
import java.io.*;


class DSU {

    int size = 0;
    int parent[];
    int weight[];
    boolean counted = false;
    Counter count;
    int root[];

    public DSU(int size) {
        this.size = size + 1;
        this.parent = new int[this.size];
        this.weight = new int[this.size];
        this.root = new int[this.size];
        for(int i = 0; i < this.size; i++) {
            parent[i] = i;
            weight[i] = i;
            root[i] = -1;
        }
    }

    public int get(int a) {
        int temp = a;
        while(parent[a] != a) {
            parent[a] = parent[parent[a]];
            a = parent[a];
        }
        root[temp] = a;
        return a;
    }

    public int getParent(int a) {
        return get(a);
    }

    public boolean find(int a, int b) {
        return get(a) == get(b);
    }

    public void join(int a, int b) {
        union(a, b);
    }

    public void union(int a, int b) {
        int parentA = get(a);
        int parentB = get(b);
        if(weight[parentA] <= weight[parentB]) {
            parent[parentA] = parent[parentB];
            weight[parentB] += weight[parentA];
        }
        else {
            parent[parentB] = parent[parentA];
            weight[parentA] += weight[parentB];
        }
    }

    public int getCount(int a) {
        if(!counted) {
            for(int i = 0; i < size; i++) {
                if(root[i] == -1) {
                    root[i] = get(i);
                }
            }
            count = new Counter(root);
            counted = true;
        }
        return count.get(a);
    }

    public int[] getParents() {
        if(!counted) {
            for(int i = 0; i < size; i++) {
                if(root[i] == -1) {
                    root[i] = get(i);
                }
            }
            count = new Counter(root);
            counted = true;
        }
        return root;
    }
}

class Primality {
    public boolean check(int n) {
        if(n == 0 || n == 1)
            return false;
        else if(n == 2 || n == 3)
            return true;
        else if(n % 2 == 0 || n % 3 == 0)
            return false;
        for(int i = 5; i <= Math.sqrt(n); i += 6) {
            if(n % i == 0 || n % (i + 2) == 0)
                return false;
        }
        return true;
    }
    public boolean test(long n) {
        
        return true;
    } 
}

class Counter {

    Map <Integer, Integer> intMap;
    Map <Character, Integer> charMap;
    Map <Long, Integer> longMap;

    public Counter(int a[]) {
        int n = a.length;
        intMap = new HashMap<Integer, Integer>();
        for(int i = 0; i < n; i++) {
            try {
                intMap.put(a[i], intMap.get(a[i]) + 1);
            }
            catch (Exception e) {
                intMap.put(a[i], 1);
            }
        }
    }

    public Counter(long a[]) {
        int n = a.length;
        intMap = new HashMap<Integer, Integer>();
        for(int i = 0; i < n; i++) {
            try {
                longMap.put(a[i], longMap.get(a[i]) + 1);
            }
            catch (Exception e) {
                longMap.put(a[i], 1);
            }
        }
    }

    public Counter(String s) {
        int n = s.length();
        charMap = new HashMap<Character, Integer>();
        for(int i = 0; i < n; i++) {
            char ch = s.charAt(i);
            try {
                charMap.put(ch, charMap.get(ch) + 1);
            }
            catch(Exception e) {
                charMap.put(ch, 1);
            }
        }
    }

    public int get(int a) {
        return intMap.get(a);
    }

    public void put(int a) {
        try {
            intMap.put(a, intMap.get(a) + 1);
        }
        catch(Exception e) {
            intMap.put(a, 1);
        }
    }

    public int get(char a) {
        return charMap.get(a);
    }

    public void put(char a) {
        try {
            charMap.put(a, charMap.get(a) + 1);
        }
        catch(Exception e) {
            charMap.put(a, 1);
        }
    }

    public int get(long a) {
        return longMap.get(a);
    }

    public void put(long a) {
        try {
            longMap.put(a, longMap.get(a) + 1);
        }
        catch(Exception e) {
            longMap.put(a, 1);
        }
    }
}


class FastReader {
    BufferedReader br;
    StringTokenizer st;
    public FastReader() {
        br = new BufferedReader(new InputStreamReader(System.in));
    }
    String next() {
        while(st==null || !st.hasMoreElements()) {
            try {
                st=new StringTokenizer(br.readLine());
            }
            catch(IOException e) {
                e.printStackTrace();
            }
        }
        return st.nextToken();
    }
    int nextInt() {
        return Integer.parseInt(next());
    }
    float nextFloat() {
        return Float.parseFloat(next());
    }
    long nextLong() {
        return Long.parseLong(next());
    }
    double nextDouble() {
        return Double.parseDouble(next());
    }
    String nextLine() {
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