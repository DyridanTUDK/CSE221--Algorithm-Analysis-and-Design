import java.util.*;
import java.io.*;

public class FastSeriesDrift {
    static long modPow(long a, long n, long m){
        long result  = 1;
        a%=m;
        while (n>0) {
            if ((n&1)==1) {
                result = (result*a) %m;
            }
            a = (a*a)%m;
            n>>=1;
        }
        return result;
    }    

    static long geometricSum(long a, long n, long m){
        if (n==0) {
            return 0;
        }
        if (n==1) {
            return a%m;
        }
        if (n%2==0) {
            long half =  geometricSum(a,n/2,m);
            long pow = modPow(a, n/2,m );
            return (half*(1+pow)) %m;
        }
        else{
            return (geometricSum(a,n-1,m) + modPow(a, n, m) ) %m;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
        
        while (T-->0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            long a = Long.parseLong(st.nextToken());
            long n = Long.parseLong(st.nextToken());
            long m = Long.parseLong(st.nextToken());
            if (a%m==1) {
                sb.append(n%m).append("\n");
            }
            else{
                sb.append(geometricSum(a,n,m)).append("\n");
            }
        }
        System.out.println(sb.toString());
    }
}
