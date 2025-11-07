package lab3java;
import java.io.*;
import java.util.StringTokenizer;
public class FastPowerDrift {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        long a = Long.parseLong(st.nextToken());
        long b = Long.parseLong(st.nextToken());

        long mod = 107;
        long result = 1;

        a %= mod;

        while (b>0) {
            if(b%2==1){
                result = (result*a) % mod;
            }
            a = (a*a) % mod;
            b /=2;
        }
        System.out.println(result);
    }
    
}
