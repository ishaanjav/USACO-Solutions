import java.util.*;
import java.io.IOException;

public class Probleme1 {

    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
		sc.nextLine();
		String s = sc.nextLine();
		// int[] positions = new int[n]; 
		ArrayList<Integer> positions = new ArrayList<>();
		int last = 0;

		//System.out.println(s);
		for(int i = 0; i < n; i++){
			if(s.charAt(i) == '1'){
				if(last == 0){
					positions.add(i * 2);
				}else {
					positions.add(i - last);
				}
				last = i;
			}
		}
		positions.add((n-1)*2 - last * 2);
		Collections.sort(positions);
		int answer = 0;
		answer = positions.get(positions.size() - 2)/2;
		for(int i = 1; i < positions.size()-1; i++){
			answer = Math.min(positions.get(i), answer);
			//System.out.println(positions.get(i));
		}
		System.out.println(answer);
    }
}
