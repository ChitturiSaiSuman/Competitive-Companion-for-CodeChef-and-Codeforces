/*
Linkedin: https://www.linkedin.com/in/sai-suman-chitturi-9727a2196/
Hackerrank: https://www.hackerrank.com/skynetasspyder?hr_r=1
Codechef: https://www.codechef.com/users/suman_18733097
Codeforces: http://codeforces.com/profile/saisumanchitturi
Github: https://github.com/ChitturiSaiSuman
Hackerearth: https://www.hackerearth.com/@chitturi7
SPOJ: Sai Suman Chitturi @out_of_bound
*/

//    _____   _    _   __    __     ____     __    _
//   / ____| | |  | | |  \  /  |   /    \   |  \  | |
//   | |___  | |  | | |   \/   |  /   _  \  | . \ | |
//   \____ \ | |  | | | |\__/| | |   /_\  | | |\ \| |
//   ____| | | \__/ | | |    | | |   __   | | | \ ` |
//   |_____/ \______/ |_|    |_| |__|  |__| |_|  \__|
//

import java.io.*;
import java.util.*;

class Main {

    static IO io;

    public static void preCompute() {

        return;
    }

    public static void solve() {

        return;
    }

    public static void main(String[] args) {

        io = new IO();
        int testcases = 0;

        if(testcases == 0)
            testcases = io.nextInt();
        
        for(int test = 0; test < testcases; test++) {

            // io.print("Case #" + (test + 1) + ": ");

            solve();

        }
    }

    static final int shit = ((int)(998244353));
    static final int mod = ((int)(1e9+7));
    static final int hell = ((int)(1e9+9));
    static final long inf = ((long)(1e18));
    static final String yes = "yes";
    static final String Yes = "Yes";
    static final String YES = "YES";
    static final String no = "no";
    static final String No = "No";
    static final String NO = "NO";

    static int size = ((int)( 1e6 + 1 ));
    static long fact[];
    static long inv[];

    public static long gcd(long a, long b) {
        for(long rem; b > 0; rem = a % b, a = b, b = rem);
        return a;
    }

    public static long lcm(long a, long b) {
        return (a * b) / gcd(a, b);
    }

    public static long add(long a, long b, long p) {
        return (a % p + b % p) % p;
    }

    public static long sub(long a, long b, long p) {
        return add(a-b, p, p);
    }

    public static long mul(long a, long b, long p) {
        return (a % p * b % p) % p;
    }

    public static long inverse(long a, long p) {
        return power(a, p-2, p);
    }

    public static long power(long x, long y, long p) {
        long result = 1;
        for(result = 1; y > 0; x = (x % p * x % p) % p, y >>= 1)
            if((y&1) == 1)
                result = (result % p * x % p) % p;
        return result;
    }

    static void matmul(long a[][], long b[][], long res[][], long p) {
        int M = a.length;
        int N = a[0].length;
        int P = b[0].length;
        long result[][] = new long[M][P];
        for(int i = 0; i < M; i++) {
            for(int j = 0; j < P; j++) {
                result[i][j] = 0;
                for(int k = 0; k < N; k++) {
                    result[i][j] = add(result[i][j], mul(a[i][k], b[k][j], p), p);
                }
            }
        }
        for(int i = 0; i < M; i++)
            for(int j = 0;j < P; j++)
                res[i][j] = result[i][j];
    }

    static long[][] power(long a[][], long y, long p) {
        long result[][] = new long[a.length][a.length];
        for(int i = 0; i < a.length; i++)
            result[i][i] = 1;
        for(; y > 0; y >>= 1, matmul(a, a, a, p)) {
            if((y&1) == 1)
                matmul(a, result, result, p);
        }
        return result;
    }

    static long nthFibonacci(long n) {
        long base[][] = {{1, 1}, {1, 0}};
        return power(base, n, mod)[0][1];
    }

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

    public static long nCr_mod_p(int n, int r, long p) {
        return mul(fact[n], mul(inv[r], inv[n-r], p), p);
    }

    public static void computeFactorials(long p) {
        fact = new long[size];
        fact[0] = 1;
        for(int i = 1; i < size; i++)
            fact[i] = mul(fact[i-1], i, p);
    }

    public static void computeInverses(long p) {
        inv = new long[size];
        for(int i = 0; i < size; i++)
            inv[i] = inverse(i, p);
    }

    public static int binarySearch(int a[], int key) {
        int lb = 0;
        int ub = a.length - 1;
        while(lb <= ub) {
            int mid = (lb + ub)/2;
            if(a[mid] == key)
                return mid;
            else if(a[mid] < key)
                lb = mid + 1;
            else
                ub = mid - 1;
        }
        return -1;
    }

}

class Factorial {
    private long fact[];
    private int size;

    public Factorial(int size) {
        this.size = size + 1;
    }

    private long mul(long a, long b, long p) {
        return (a % p * b % p) % p;
    }

    public void compute() {
        fact = new long[size];
        fact[0] = 1;
        long mod = ((long)(1e9+7));
        for(int i = 1; i < size; i++)
            fact[i] = mul(fact[i-1], i, mod);
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

    private int size = 0;
    private int parent[];
    private int weight[];
    private boolean counted = false;
    private Counter count;
    private int root[];

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

    private static int k = 16;

    public static boolean check(int n) {
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

    public static void setMillerConstant(int k) {
        Primality.k = k;
    }

    public static void set(int k) {
        Primality.k = k;
    }

    private static long power(long x, long y, long p) {
        long result = 1;
        for(result = 1; y > 0; x = (x % p * x % p) % p, y >>= 1)
            if((y&1) == 1)
                result = (result % p * x % p) % p;
        return result;
    }

    private static boolean millerTest(long d, long n) {
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

    public static boolean test(long n) {
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


class IO {

    private BufferedReader reader;
    private StringTokenizer st;
    private BufferedWriter writer;
    private BufferedWriter debugWriter;
    public String end = "\n";
    public String sep = " ";

    public IO() {
        reader = new BufferedReader(new InputStreamReader(System.in));
        writer = new BufferedWriter(new OutputStreamWriter(System.out));
        debugWriter = new BufferedWriter(new OutputStreamWriter(System.err));
    }

    public String next() {
        while(st == null || !st.hasMoreElements()) {
            try {
                st = new StringTokenizer(reader.readLine());
            }
            catch(IOException e) {
                e.printStackTrace();
            }
        }
        return st.nextToken();
    }

    public int nextInt() {
        return Integer.parseInt(next());
    }

    public float nextFloat() {
        return Float.parseFloat(next());
    }

    public long nextLong() {
        return Long.parseLong(next());
    }

    public double nextDouble() {
        return Double.parseDouble(next());
    }

    public String nextLine() {
        String str="";
        try{
            str=reader.readLine();
        }
        catch(IOException e){
            e.printStackTrace();
        }
        return str;
    }

    public int[] intArray(int n) {
        int a[] = new int[n];
        for(int i = 0; i < n; i++)
            a[i] = nextInt();
        return a;
    }

    public long[] longArray(int n) {
        long a[] = new long[n];
        for(int i = 0; i < n; i++)
            a[i] = nextLong();
        return a;
    }

    public char[] charArray(int n) {
        char a[] = new char[n];
        for(int i = 0; i < n; i++)
            a[i] = next().charAt(0);
        return a;
    }

    public void println() {
        print("\n");
    }

    public void newLine() {
        println();
    }

    public void print(String s) {
        try {
            writer.write(s);
            writer.flush();
        }
        catch(Exception e) {
            e.printStackTrace();
        }
    }

    public void write(Object o) {
        print(o.toString() + end);
    }

    public void write(String s) {
        s = s + end;
        print(s);
    }

    public void write(String ... a) {
        String s = "" + a[0];
        for(int i = 1; i < a.length; i++)
            s = s + sep + a[i];
        s = s + end;
        print(s);
    }

    public void write(int ... a) {
        String s = "" + a[0];
        for(int i = 1; i < a.length; i++)
            s = s + sep + a[i];
        s = s + end;
        print(s);
    }

    public void write(long ... a) {
        String s = "" + a[0];
        for(int i = 1; i < a.length; i++)
            s = s + sep + a[i];
        s = s + end;
        print(s);
    }
    
    public void write(char ... a) {
        String s = "" + a[0];
        for(int i = 1; i < a.length; i++)
            s = s + sep + a[i];
        s = s + end;
        print(s);
    }

    public <E> void write(E[] a) {
        String s = "" + a[0].toString();
        for(int i = 1; i < a.length; i++)
            s = s + sep + a[i].toString();
        s = s + end;
        print(s);
    }

    public <E> void write(List<E> a) {
        Object arr[] = a.toArray();
        write(arr);
    }

    public void error(String s) {
        try {
            debugWriter.write(s);
            debugWriter.flush();
        }
        catch(Exception e) {
            e.printStackTrace();
        }
    }

    public void debug(Object o) {
        error(o.toString() + end);
    }

    public void debug(String s) {
        s = s + end;
        error(s);
    }

    public void debug(String ... a) {
        String s = "" + a[0];
        for(int i = 1; i < a.length; i++)
            s = s + sep + a[i];
        s = s + end;
        error(s);
    }

    public void debug(int ... a) {
        String s = "" + a[0];
        for(int i = 1; i < a.length; i++)
            s = s + sep + a[i];
        s = s + end;
        error(s);
    }

    public void debug(long ... a) {
        String s = "" + a[0];
        for(int i = 1; i < a.length; i++)
            s = s + sep + a[i];
        s = s + end;
        error(s);
    }
    
    public void debug(char ... a) {
        String s = "" + a[0];
        for(int i = 1; i < a.length; i++)
            s = s + sep + a[i];
        s = s + end;
        error(s);
    }

    public <E> void debug(E[] a) {
        String s = "" + a[0].toString();
        for(int i = 1; i < a.length; i++)
            s = s + sep + a[i].toString();
        s = s + end;
        error(s);
    }

    public <E> void debug(List<E> a) {
        Object arr[] = a.toArray();
        debug(arr);
    }



}