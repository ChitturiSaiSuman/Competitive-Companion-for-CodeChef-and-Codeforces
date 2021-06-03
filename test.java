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