/*
 * Created by ishaanjav
 * github.com/ishaanjav
 * USACO Solutions: https://github.com/ishaanjav/USACO-Solutions
 */

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.StringTokenizer;
import java.io.IOException;
import java.io.PrintWriter;

public class meeting {
    static int[][] bessieGrid;
    static int[][] elsieGrid;

    static int n;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader("meeting.in"));
        // (string, ?delimiter, ?flag) -> flag is boolean whether to keep delimiter as
        // token.
        PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("meeting.out")));
        StringTokenizer in = new StringTokenizer(br.readLine());
        n = Integer.parseInt(in.nextToken());
        int m = Integer.parseInt(in.nextToken());
        bessieGrid = new int[n][n];
        elsieGrid = new int[n][n];

        for (int i = 0; i < m; i++) {
            in = new StringTokenizer(br.readLine());
            int x = Integer.parseInt(in.nextToken()) - 1;
            int y = Integer.parseInt(in.nextToken()) - 1;
            bessieGrid[x][y] = Integer.parseInt(in.nextToken());
            elsieGrid[x][y] = Integer.parseInt(in.nextToken());
            System.out.println(x + " " + y);
        }

        boolean[] bCan = solve(bessieGrid);
        boolean[] sCan = solve(elsieGrid);
        int ans = Integer.MAX_VALUE;
        for (int i = 0; i < bCan.length; i++) {
            if (bCan[i] && sCan[i]) {
                ans = i;
                break;
            }
        }
        if (ans == Integer.MAX_VALUE)
            pw.println("IMPOSSIBLE");
        else
            pw.println(ans);
        pw.close();
    }

    public static boolean[] solve(int[][] distances) {
        boolean[][] dp = new boolean[n][100 * n + 1];
        dp[0][0] = true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < dp[i].length; j++) {
                if (!dp[i][j])
                    continue;
                for (int k = i + 1; k < n; k++) {
                    if (distances[i][k] > 0)
                        dp[k][j + distances[i][k]] = true;
                }
            }
        }
        return dp[n - 1];
    }

}
