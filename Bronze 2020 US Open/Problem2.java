import java.util.*;
import java.io.IOException;

public class Problem2 {

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        ArrayList<Cow> list = new ArrayList<>();

        int radius = 1000000000; // really big
        int last = -100000;
        int firstsick = -1;
        int first = 0;
        boolean hadnotsick = false;
        boolean notsick = false;
        for (int i = 0; i < n; i++) {
            int x = sc.nextInt();
            int sick = sc.nextInt();
            list.add(new Cow(x, sick));
        }
        Collections.sort(list);
        for(int i = 0; i < n; i++){
            int x = list.get(i).x;
            int sick = list.get(i).sick;
            if(sick == 0){
                if(i > 0 && list.get(i-1).sick == 1){
                    radius = Math.min(radius, x - list.get(i-1).x);
                }
                if(i < n-1 && list.get(i+1).sick == 1){
                    radius = Math.min(radius, list.get(i+1).x - x);
                }
            }
        }
        /* for (int i = 0; i < n; i++) {
            int x = list.get(i).x;
            int sick = list.get(i).sick;
            if (sick == 0) {
                // System.out.println(x + " " + sick);
                radius = Math.min((x - last) / 2, radius);
                System.out.println(radius);
                last = x;
                hadnotsick = true;
                if (notsick == false) {
                    first = x;
                }
                notsick = true;
            } else {
                if (hadnotsick == false) {
                    firstsick = x;
                    hadnotsick = true;
                }
            }
        }
        boolean done = false;
        for (int i = 0; i < n; i++) {
            if (list.get(i).sick == 1) {
                for (int j = 0; j < n; j++) {
                    if (list.get(j).sick == 0) {
                        if (list.get(j).x >= list.get(i).x) {
                            radius = Math.min(radius, list.get(j).x - list.get(i).x);
                            System.out.println("A: " + radius);
                            done = true;
                            break;
                        }
                    }
                }
                break;
            }
        } 
        radius = Math.min(list.get(list.size() - 1).x - last, radius);
        */
        radius -= 1;
        // System.out.println("R: "  + radius);
        int answer = 0;
        for (int i = 0; i < n;) {
            while (i < n && list.get(i).sick == 0) {
                i++;
            }
            int cownow = list.get(i).x;
            int later = cownow + radius;
            while (i < n && list.get(i).sick == 1 && list.get(i).x <= later) {
                later = radius + list.get(i).x;
                i++;
            }
            answer++;
            while (i < n && list.get(i).sick == 0) {
                i++;
            }
            // System.out.println(i);
        }

        System.out.println(answer);
    }

    static class Cow implements Comparable<Cow> {
        int x;
        int sick;

        Cow(int a, int b) {
            x = a;
            sick = b;
        }

        @Override
        public int compareTo(Cow cow) {
            return Integer.compare(x, cow.x);
        }
    }
}
/*
6
0 0
3 1
5 1
9 1
12 1
15 0
 */