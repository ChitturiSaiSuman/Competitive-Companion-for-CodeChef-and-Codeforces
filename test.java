import java.util.*;
import java.io.*;

class Algo {
    public static long[] cumsum(int a[]) {
        int n = a.length;
        long sum[] = new long[n];
        sum[0] = a[0];
        for(int i = 1; i < n; i++)
            sum[i] = sum[i-1] + a[i];
        return sum;
    }

    public static long[] cumsum(long a[]) {
        int n = a.length;
        long sum[] = new long[n];
        sum[0] = a[0];
        for(int i = 1; i < n; i++)
            sum[i] = sum[i-1] + a[i];
        return sum;
    }

    static int gcd(int a, int b) {
        for(int rem; b > 0; rem = a % b, a = b, b = rem);
        return a;
    }

    static long gcd(long a, long b) {
        for(long rem; b > 0; rem = a % b, a = b, b = rem);
        return a;
    }

    static long lcm(int a, int b) {
        return ((long)a * (long)b) / gcd(a, b);
    }

    static long lcm(long a, long b) {
        return (a * b) / gcd(a, b);
    }


}

class Fraction {
    private long num = 0;
    private long den = 1;

    public Fraction(long num) {
        this.num = num;
    }

    private long gcd(long a, long b) {
        for(long rem; b > 0; rem = a % b, a = b, b = rem);
        return a;
    }

    private long lcm(long a, long b) {
        return (a * b) / gcd(a, b);
    }

    public Fraction(long num, long den) {
        this.num = num;
        this.den = den;
        long g = gcd(num, den);
        this.num /= g;
        this.den /= g;
    }

    public Fraction add(Fraction f2) {
        long num1 = this.num;
        long den1 = this.den;
        long num2 = f2.num;
        long den2 = f2.den;
        long den = lcm(den1, den2);
        return new Fraction(num1 * (den / den1) + num2 * (den / den2), den);
    }

    public Fraction sub(Fraction f2) {
        long num1 = this.num;
        long den1 = this.den;
        long num2 = f2.num;
        long den2 = f2.den;
        long den = lcm(den1, den2);
        return new Fraction(num1 * (den / den1) - num2 * (den / den2), den);
    }

    public Fraction mul(Fraction f2) {
        return new Fraction(this.num * f2.num, this.den * f2.den);
    }

    public Fraction div(Fraction f2) {
        return new Fraction(this.num * f2.den, this.den * f2.num);
    }
    
    public String toString() {
        if(this.den == 1)
            return Long.toString(this.num);
        return (this.num + "/" + this.den);
    }

}

class Heap {
    
    private PriorityQueue<Integer> heap;

    public Heap(boolean minHeap) {
        if(minHeap)
            heap = new PriorityQueue<Integer>();
        else
            heap = new PriorityQueue<Integer>(Collections.reverseOrder());
    }

    public void insert(int a) {
        heap.add(a);
    }

    public void add(int a) {
        heap.add(a);
    }

    public int get() {
        return heap.peek();
    }

    public int pop() {
        return heap.poll();
    }

    public void remove(int k) {
        heap.remove(k);
    }
}

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

    private int k = 18;

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

    public void setMillerConstant(int k) {
        this.k = k;
    }

    public void set(int k) {
        this.k = k;
    }

    private long power(long x, long y, long p) {
        long result = 1;
        for(result = 1; y > 0; x = (x % p * x % p) % p, y >>= 1)
            if((y&1) == 1)
                result = (result % p * x % p) % p;
        return result;
    }

    private boolean millerTest(long d, long n) {
        long a = 2 + (long) (Math.random() * (n - 5));
        long x = power(a, d, n);
        if(x == 1 || x == (n - 1))
            return true;
        while(d != (n - 1)) {
            x = (x % n * x % n) % n;
            d *= 2;
            if(x == 1)
                return false;
            else if(x == n - 1)
                return true;
        }
        return false;
    }

    public boolean test(long n) {
        if(n <= 1 || n == 4)
            return false;
        if(n <= 3)
            return true;
        long d = n - 1;
        while((d % 2) == 0)
            d /= 2;
        for(int i = 0; i < k ; i++)
            if(!millerTest(d, n))
                return false;
        return true;
    }
}

class Sieve {
    private int size = 0;
    private boolean prime[];
    private int spf[];
    private int phi[];

    public Sieve(int size) {
        this.size = size + 1;
    }

    public void setSize(int size) {
        this.size = size + 1;
    }

    public boolean[] sieve() {
        prime = new boolean[size];
        Arrays.fill(prime, false);

        prime[2] = true;

        for(int i = 3; i < size; i += 2)
            prime[i] = true;

        for(int i = 3; i <= Math.sqrt(size); i += 2)
            if(prime[i])
                for(int j = i * i; j < size; j += i)
                    prime[j] = false;
        return prime;
    }

    public int[] SPF() {
        spf = new int[size];

        for(int i = 2; i < size; i += 2)
            spf[i] = 2;

        for(int i = 3; i < size; i += 2)
            spf[i] = i;

        for(int i = 3; i < Math.sqrt(size); i += 2)
            if(spf[i] == i)
                for(int j = i * i; j < size; j += i)
                    if(spf[j] == j)
                        spf[j] = i;

        return spf;
    }

    public int[] getSPF() {
        return SPF();
    }

    public int[] computeSPF() {
        return SPF();
    }
    
    public int[] Totient() {
        phi = new int[size];

        for(int i = 0;i < size; i++)
            phi[i] = i;

        for(int i = 2;i < size; i++)
            if(phi[i] == i)
                for(int j = i;j < size;j += i)
                    phi[j] -= phi[j]/i;

        return phi;
    }

    public int[] getTotient() {
        return Totient();
    }

    public int[] computeTotient() {
        return Totient();
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

class Main {
    public static void main(String[] args) {
        Fraction f1 = new Fraction(50, 100);
        Fraction f2 = new Fraction(1);

        System.out.println(f1.div(f2));
    }
}