// 57:69:74:68:20:4C:4F:56:45
//    _____   _    _   __    __     ____     __    _
//   / ____| | |  | | |  \  /  |   /    \   |  \  | |
//   | |___  | |  | | |   \/   |  /   _  \  | . \ | |
//   \____ \ | |  | | | |\__/| | |   /_\  | | |\ \| |
//   ____| | | \__/ | | |    | | |   __   | | | \ ` |
//   |_____/ \______/ |_|    |_| |__|  |__| |_|  \__|
//

import java.io.*;
import java.util.*;

// Graph: Graph(V: int, E: int, directed: boolean, weighted: boolean)
// Bit (0-based Indexing): BIT(int a[]); methods: pointUpdate(ind, val), addRange(l, r, val), rangeSum(l, r)

public class Main implements Runnable { // Make sure the class is Public

    static IO io = new IO();
    static int size = ((int)(2e6 + 1));

    public static void preCompute() {
        // Precompute some values here
        // 
    }

    public static void solve() {
        // Solve Test Cases here
        // 
    }

    public void run() {
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

    public static void main(String[] args) { // This way the recursion depth can be increased
        new Thread(null, new Main(), "Main Thread", 1 << 30).start();
    }

    static final int shit = ((int)(998244353));
    static final int mod = ((int)(1e9 + 7));
    static final int hell = ((int)(1e9 + 9));
    static final long inf = ((long)(1e18 + 3));
    static final double pi = Math.PI;

    static final int dc[] = {1, 0, 0, -1, -1, -1, 1, 1};
    static final int dr[] = {0, 1, -1, 0, -1, 1, -1, 1};

    public static long add(long a, long b, long p) {
        return ((a % p + b % p) % p + p) % p;
    }
    public static long sub(long a, long b, long p) {
        return (p + a % p - b % p) % p;
    }
    public static long mul(long a, long b, long p) {
        return (a % p * b % p) % p;
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
        String str = "";
        try {
            str = reader.readLine();
        }
        catch(IOException e) {
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

    public void print(String s) {
        try {
            writer.write(s);
            writer.flush();
        }
        catch(Exception e) {
            e.printStackTrace();
        }
    }

    public void println() {
        print("\n");
    }

    public void newLine() {
        println();
    }

    public void write(Object o) {
        print(o.toString().concat(end));
    }

    public void write(String s) {
        print(s.concat(end));
    }

    public void write(StringBuilder s) {
        s.append(end);
        print(s.toString());
    }

    public void write(String ... a) {
        StringBuilder s = new StringBuilder();
        s.append(a[0]);
        for(int i = 1; i < a.length; i++)
            s.append(sep + a[i]);
        s.append(end);
        print(s.toString());
    }

    public void write(int ... a) {
        StringBuilder s = new StringBuilder();
        s.append(a[0]);
        for(int i = 1; i < a.length; i++)
            s.append(sep + a[i]);
        s.append(end);
        print(s.toString());
    }

    public void write(long ... a) {
        StringBuilder s = new StringBuilder();
        s.append(a[0]);
        for(int i = 1; i < a.length; i++)
            s.append(sep + a[i]);
        s.append(end);
        print(s.toString());
    }
    
    public void write(char ... a) {
        StringBuilder s = new StringBuilder();
        s.append(a[0]);
        for(int i = 1; i < a.length; i++)
            s.append(sep + a[i]);
        s.append(end);
        print(s.toString());
    }

    public <E> void write(E[] a) {
        StringBuilder s = new StringBuilder();
        s.append(a[0]);
        for(int i = 1; i < a.length; i++)
            s.append(sep + a[i].toString());
        s.append(end);
        print(s.toString());
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
        s = s.concat(end);
        error(s);
    }

    public void debug(String ... a) {
        StringBuilder s = new StringBuilder();
        s.append(a[0]);
        for(int i = 1; i < a.length; i++)
            s.append(sep + a[i]);
        s.append(end);
        error(s.toString());
    }

    public void debug(int ... a) {
        StringBuilder s = new StringBuilder();
        s.append(a[0]);
        for(int i = 1; i < a.length; i++)
            s.append(sep + a[i]);
        s.append(end);
        error(s.toString());
    }

    public void debug(long ... a) {
        StringBuilder s = new StringBuilder();
        s.append(a[0]);
        for(int i = 1; i < a.length; i++)
            s.append(sep + a[i]);
        s.append(end);
        error(s.toString());
    }
    
    public void debug(char ... a) {
        StringBuilder s = new StringBuilder();
        s.append(a[0]);
        for(int i = 1; i < a.length; i++)
            s.append(sep + a[i]);
        s.append(end);
        error(s.toString());
    }

    public <E> void debug(E[] a) {
        StringBuilder s = new StringBuilder();
        s.append(a[0]);
        for(int i = 1; i < a.length; i++)
            s.append(sep + a[i].toString());
        s.append(end);
        error(s.toString());
    }

    public <E> void debug(List<E> a) {
        Object arr[] = a.toArray();
        debug(arr);
    }
}