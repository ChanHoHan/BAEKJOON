import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.HashSet;

public class Main {
    public static void main(String[] args) {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        try{
            String[] a = br.readLine().split(" ");
            String[] b = br.readLine().split(" ");
            Integer N = Integer.parseInt(a[0]);
            Integer S = Integer.parseInt(a[1]);
            Integer M = Integer.parseInt(a[2]);

            HashSet<Integer> s = new HashSet<>();
            s.add(S);
            for (int i = 0 ; i < N ; i++) {
                HashSet<Integer> tmp = new HashSet<>();
                for(Integer element : s) {
                    if (element + Integer.parseInt(b[i]) <= M) tmp.add(element + Integer.parseInt(b[i]));
                    if (element - Integer.parseInt(b[i]) >= 0) tmp.add(element - Integer.parseInt(b[i]));
                }
                s = tmp;
            }
            int t = -1;
            for(Integer x : s) {
                if (x >= t) t = x;
            }
            System.out.println(t);
        } catch (Exception e) {
            e.printStackTrace();
        }

    }
}

