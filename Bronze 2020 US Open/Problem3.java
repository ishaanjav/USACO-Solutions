import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;
import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;

public class Problem3 {

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(new File("tracing.in"));
        int n = sc.nextInt();
        int t = sc.nextInt();
        boolean sick[] = new boolean[n];
        sc.nextLine();
        String line = sc.nextLine();
        for (int i = 0; i < n; i++) {
            if (line.charAt(i) == '1') {
                sick[i] = true;
            } else {
                sick[i] = false;
            }
        }
        ArrayList<Interaction> list = new ArrayList<>();
        for (int i = 0; i < t; i++) {
            int time = sc.nextInt();
            int x = sc.nextInt() - 1;
            int y = sc.nextInt() - 1;
            list.add(new Interaction(time, x, y));
        }
        Collections.sort(list);
        for (int i = 0; i < t; i++) {
            System.out.println(list.get(i).time + " | " + list.get(i).x + "," + list.get(i).y);
        }
        int count = 0;
        int smallest = t + 1;
        int largest = 0;
        for (int i = 0; i < n; i++) {
            boolean possible = false;
            for (int k = 0; k <= t; k++) {
                boolean hasIt[] = new boolean[n];
                int left[] = new int[n];
                for (int j = 0; j < n; j++) {
                    left[j] = k;
                }
                hasIt[i] = true;
                for (int interaction = 0; interaction < t; interaction++) {
                    int x = list.get(interaction).x;
                    int y = list.get(interaction).y;
                    boolean before = hasIt[y];
                    if (hasIt[x] && left[x] != 0) {
                        hasIt[y] = true;
                        left[x]--;
                    }
                    if (before && left[y] != 0) {
                        hasIt[x] = true;
                        left[y]--;
                    }
                }
                boolean canDo = true;
                for (int cow = 0; cow < n; cow++) {
                    if (hasIt[cow] != sick[cow]) {
                        canDo = false;
                        break;
                    }
                }
                if (canDo) {
                    possible = true;
                    System.out.println("  " + k);
                    smallest = Math.min(k, smallest);
                    largest = Math.max(k, largest);
                }
            }
            if (possible) {
                count += 1;
                System.out.println(i);
                smallest = Math.min(smallest, smallest);
                largest = Math.max(largest, largest);
            }
        }
        PrintWriter pw = new PrintWriter(new File("tracing.out"));
        if (largest == t) {
            pw.print(count + " " + smallest + " Infinity");
            System.out.println(count + " " + smallest + " Infinity");
        } else {
            pw.print(count + " " + smallest + " " + largest);
            System.out.println(count + " " + smallest + " " + largest);
        }
        pw.close();
    }

    static class Interaction implements Comparable<Interaction> {
        int time, x, y;

        Interaction(int a, int b, int c) {
            time = a;
            x = b;
            y = c;
        }

        @Override
        public int compareTo(Interaction o) {
            return Integer.compare(time, o.time);
        }
    }
}