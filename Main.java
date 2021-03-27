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

// Graph Constructor Signature: (V: int, E: int, directed: boolean, weighted: boolean)

public class Main {

    static IO io;
    static int size = ((int)( 1e6 + 1 ));

    public static void preCompute() {
        // Precompute some values here
        // 
    }

    public static void solve() {
        // Solve Test Cases here
        // 
    }

    public static void main(String[] args) {

        io = new IO();
        int testcases = 0;

        // testcases++;

        if(testcases == 0)
            testcases = io.nextInt();

        preCompute();
        
        for(int test = 0; test < testcases; test++) {

            // io.print("Case #" + (test + 1) + ": ");

            solve();

        }
    }

    static final int shit = ((int)(998244353));
    static final int mod = ((int)(1e9+7));
    static final int hell = ((int)(1e9+9));
    static final long inf = ((long)(1e18));
    static final double pi = Math.PI;
    static final String yes = "yes";
    static final String Yes = "Yes";
    static final String YES = "YES";
    static final String no = "no";
    static final String No = "No";
    static final String NO = "NO";

    public static long add(long a, long b, long p) {
        return (a % p + b % p) % p;
    }

    public static long sub(long a, long b, long p) {
        return add(a-b, p, p);
    }

    public static long mul(long a, long b, long p) {
        return (a % p * b % p) % p;
    }

}

class Algo {

    static long fact[];
    static long inv[];

    static final int mod = ((int)(1e9+7));

    public static long add(long a, long b, long p) {
        return (a % p + b % p) % p;
    }

    public static long sub(long a, long b, long p) {
        return add(a-b, p, p);
    }

    public static long mul(long a, long b, long p) {
        return (a % p * b % p) % p;
    }

    public static long gcd(long a, long b) {
        for(long rem; b > 0; rem = a % b, a = b, b = rem);
        return a;
    }

    public static long lcm(long a, long b) {
        return (a * b) / gcd(a, b);
    }

    public static long power(long x, long y, long p) {
        long result = 1;
        for(result = 1; y > 0; x = (x % p * x % p) % p, y >>= 1)
            if((y&1) == 1)
                result = (result % p * x % p) % p;
        return result;
    }

    public static long inverse(long a, long p) {
        return power(a, p - 2, p);
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

    public static long[] prefixSum(int a[]) {
        int n = a.length;
        long sum[] = new long[n];
        sum[0] = a[0];
        for(int i = 1; i < n; i++)
            sum[i] = sum[i - 1] + a[i];
        return sum;
    }

    public static long[] prefixSum(long a[]) {
        int n = a.length;
        long sum[] = new long[n];
        sum[0] = a[0];
        for(int i = 1; i < n; i++)
            sum[i] = sum[i - 1] + a[i];
        return sum;
    }

    public static long[] suffixSum(int a[]) {
        int n = a.length;
        long sum[] = new long[n];
        sum[n - 1] = a[n - 1];
        for(int i = n - 2; i >= 0; i--)
            sum[i] = sum[i + 1] + a[i];
        return sum;
    }

    public static long[] suffixSum(long a[]) {
        int n = a.length;
        long sum[] = new long[n];
        sum[n - 1] = a[n - 1];
        for(int i = n - 2; i >= 0; i--)
            sum[i] = sum[i + 1] + a[i];
        return sum;
    }

    public static long nCr_mod_p(int n, int r, long p) {
        return mul(fact[n], mul(inv[r], inv[n-r], p), p);
    }

    public static void computeFactorials(int nax, long p) {
        fact = new long[nax];
        fact[0] = 1;
        for(int i = 1; i < nax; i++)
            fact[i] = mul(fact[i-1], i, p);
    }

    public static void computeInverses(int nax, long p) {
        if(fact == null)
            computeFactorials(nax, p);
        inv = new long[nax];
        for(int i = 0; i < nax; i++)
            inv[i] = inverse(fact[i], p);
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

    int numberOfDigits(long a) {
        return Long.toString(a).length();
    }

    int sumOfDigits(long a) {
        int c = 0;
        while(a > 0) {
            c += a % 10;
            a /= 10;
        }
        return c;
    }

    int setBitCount(long a) {
        int c = 0;
        while(a > 0) {
            c += a % 2;
            a /= 2;
        }
        return c;
    }

    static int bisect_left(int a[], int key) {
        int ind = binarySearch(a, key);
        double k = key;
        if(ind != -1) {
            k = ((double)(key)) - 0.5;
        }
        int lb = 0, ub = a.length - 1;
        while(lb <= ub) {
            int mid = (lb + ub) / 2;
            if(a[mid] < k)
                lb = mid + 1;
            else
                ub = mid - 1;
        }
        return lb;
    }

    static int bisect_right(int a[], int key) {
        int ind = binarySearch(a, key);
        double k = key;
        if(ind != -1) {
            k = ((double)(key)) + 0.5;
        }
        int lb = 0, ub = a.length - 1;
        while(lb <= ub) {
            int mid = (lb + ub) / 2;
            if(a[mid] < k)
                lb = mid + 1;
            else
                ub = mid - 1;
        }
        return lb;
    }

    static long sum(int a[]) {
        long s = 0;
        for(int i = 0; i < a.length; i++)
            s = s + a[i];
        return s;
    }

    static long sum(long a[]) {
        long s = 0;
        for(int i = 0; i < a.length; i++)
            s = s + a[i];
        return s;
    }

    private static long merge(int a[], int lb, int ub) {
        int temp[] = new int[ub + 1 - lb];
        long ans = 0;
        int i = lb;
        int mid = (lb + ub)/2;
        int j = (mid + 1);
        int ind = 0;
        while(i <= mid && j <= ub) {
            if(a[i] <= a[j]) {
                temp[ind++] = a[i++];
            }
            else {
                ans = ans + mid + 1 - i;
                temp[ind++] = a[j++];
            }
        }
        while(i <= mid) {
            temp[ind++] = a[i++];
        }
        while(j <= ub) {
            temp[ind++] = a[j++];
        }
        for(i = lb, ind = 0; i <= ub; i++, ind++)
            a[i] = temp[ind];
        return ans;
    }

    private static long mergeSort(int a[], int lb, int ub) {
        long ans = 0;
        if(lb < ub) {
            int mid = (lb + ub)/2;
            ans += mergeSort(a, lb, mid);
            ans += mergeSort(a, mid + 1, ub);
            ans += merge(a, lb, ub);
        }
        return ans;
    }

    public static long countInversions(int a[]) {
        return mergeSort(a, 0, a.length - 1);
    }
    
    public static int lcs(int a[], int b[]) {
        int m = a.length;
        int n = b.length;
        int dp[][] = new int[m+1][n+1];
        for(int i = 0; i <= m; i++) {
            for(int j = 0; j <= n; j++) {
                if(i == 0 || j == 0) {
                    dp[i][j] = 0;
                }
                else if(a[i-1] == b[j-1]) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else {
                    dp[i][j] = Math.max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }

    public static int lcs(String s1, String s2) {
        int m = s1.length();
        int n = s2.length();
        int dp[][] = new int[m+1][n+1];
        for(int i = 0; i <= m; i++) {
            for(int j = 0; j <= n; j++) {
                if(i == 0 || j == 0) {
                    dp[i][j] = 0;
                }
                else if(s1.charAt(i-1) == s2.charAt(j-1)) {
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else {
                    dp[i][j] = Math.max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }

    static void matmul(Fraction f1[][], Fraction f2[][], Fraction res[][]) {
        int m = f1.length;
        int n = f1[0].length;
        int p = f2[0].length;
        Fraction result[][] = new Fraction[m][p];
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < p; j++) {
                result[i][j] = new Fraction(0);
                for(int k = 0; k < n; k++) {
                    result[i][j] = result[i][j].add(f1[i][k].mul(f2[k][j]));
                }
            }
        }
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < p; j++) {
                res[i][j] = result[i][j];
            }
        }
    }

    static Fraction[][] power(Fraction f[][], int y) {
        int n = f.length;
        Fraction res[][] = new Fraction[n][n];
        for(int i = 0; i < n; i++)
            res[i][i] = new Fraction(1);
        while(y > 0) {
            if((y&1) == 1) {
                matmul(f, res, res);
            }
            matmul(f, f, f);
            y >>= 1;
        }
        return res;
    }

}

class Fraction implements Comparable<Fraction> {
    
    private long num = 0;
    private long den = 1;

    private long gcd(long a, long b) {
        for(long rem; b > 0; rem = a % b, a = b, b = rem);
        return a;
    }

    private long lcm(long a, long b) {
        return (a * b) / gcd(a, b);
    }

    public Fraction(long num) {
        this.num = num;
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

    public int compareTo(Fraction f2) {
        Fraction f1 = this;
        long l = lcm(f1.den, f2.den);
        long num1 = (l/f1.den) * f1.num;
        long num2 = (l/f2.den) * f2.num;
        if(num1 == num2)
            return 0;
        return ((num1>num2)?1:-1);
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

    private static long power(long x, long y, long p) {
        long result = 1;

        for(result = 1; y > 0; x = (x % p * x % p) % p, y >>= 1)
            if((y&1) == 1)
                result = (result % p * x % p) % p;

        return result;
    }

    private static boolean check_composite(long n, long a, long d, long s) {
        long x = power(a, d, n);

        if(x == 1 || x == n - 1)
            return false;

        for(int r = 1; r < s; r++) {
            x = (x % n * x % n) % n;
            if(x == n - 1)
                return false;
        }

        return true;
    }

    public static boolean test(long n) {
        if(n < 2)
            return false;

        int r = 0;
        long d = n - 1;

        while((d&1) == 0) {
            d >>= 1;
            r++;
        }

        int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

        for(int i = 0; i < primes.length; i++) {
            int a = primes[i];
            if(n == a)
                return true;
            if(check_composite(n, a, d, r))
                return false;
        }

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

class Edge implements Comparable<Edge> {

    int start = 0, end = 0, cost = 0;

    Edge(Edge e) {
        this.start = e.start;
        this.end = e.end;
        this.cost = e.cost;
    }

    Edge(int start, int end, int cost) {
        this.start = start;
        this.end = end;
        this.cost = cost;
    }
    public String toString() {
        return "(" + start + ", " + end + ", " + cost + ")";
    }

    public int compareTo(Edge e2) {
        Edge e1 = this;
        int cost1 = e1.cost;
        int cost2 = e2.cost;
        if(cost1 == cost2) {
            if(e1.start == e2.start) {
                if(e1.end == e2.end) {
                    return 0;
                }
                return (e1.end > e2.end ? 1 : -1);
            }
            return (e1.start > e2.start ? 1 : -1);
        }
        return ((cost1 > cost2) ? 1 : -1);
    }
}

class Graph {

    private int V, E;
    private ArrayList<LinkedList<Integer>> graph;
    private Edge edges[];
    private Edge included[];
    private long cost = 0;
    private boolean weighted = false;
    private boolean directed = true;

    public Graph(int V, int E, boolean directed, boolean weighted) {
        this.V = V;
        this.E = E;
        this.weighted = weighted;
        this.directed = directed;

        graph = new ArrayList<LinkedList<Integer>>();
        for(int i = 0; i < this.V; i++)
            graph.add(new LinkedList<Integer>());

        edges = new Edge[E];
    }

    public void addEdge(int a, int b) {
        graph.get(a).add(b);
    }

    public void readGraph(IO io) {

        for(int i = 0; i < this.E; i++) {
            int a = io.nextInt();
            int b = io.nextInt();
            addEdge(a, b);
            if(!directed)
                addEdge(b, a);
            int c = 0;
            if(weighted)
                c = io.nextInt();
            edges[i] = new Edge(a, b, c);
        }
    }

    void MST() {
        included = new Edge[(this.V - 1)];
        Arrays.sort(edges);
        int includedSoFar = 0;
        DSU dsu = new DSU(V);
        int ind = 0;
        while(includedSoFar != (V - 1) && ind < E) {
            if(!dsu.find(edges[ind].start, edges[ind].end)) {
                dsu.union(edges[ind].start, edges[ind].end);
                included[includedSoFar] = edges[ind];
                cost = cost + edges[ind].cost;
                includedSoFar += 1;
            }
            ind += 1;
        }
    }

    long mstCost() {
        if(included == null) {
            MST();
        }
        return cost;
    }

    Edge[] mstIncluded() {
        if(included == null) {
            MST();
        }
        return included;
    }

    public boolean bfs(int start, int end) {

        if(!(0 <= end && end < this.V))
            return false;

        boolean visited[] = new boolean[this.V];
        Arrays.fill(visited, false);
        Queue<Integer> queue = new LinkedList<>();
        queue.add(start);
        visited[start] = true;
        while(!queue.isEmpty() && !visited[end]) {
            start = queue.poll();
            for(int i: this.graph.get(start)) {
                if(!visited[i]) {
                    visited[i] = true;
                    queue.add(i);
                }
            }
        }
        return visited[end];
    }

}

class Pair implements Comparable<Pair> {
    long x = 0, y = 0;
    Pair(long x, long y) {
        this.x = x;
        this.y = y;
    }
    public int compareTo(Pair p2) {
        Pair p1 = this;
        if(p1.x == p2.x) {
            if(p1.y == p2.y)
                return 0;
            return ((p1.y > p2.y) ? 1 : -1);
        }
        return ((p1.x > p2.x) ? 1 : -1);
    }
    public String toString() {
        return "(" + this.x + ", " + this.y + ")";
    }
}