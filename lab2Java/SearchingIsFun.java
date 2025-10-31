import java.io.*;
// import java.util.*;
public class SearchingIsFun {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine());
        StringBuilder sb = new StringBuilder();
        while (T-->0) {
            String[] parts = br.readLine().split(" ");
            long k  = Long.parseLong(parts[0]);
            long x  = Long.parseLong(parts[1]);

            long fullBlock = k/(x-1);
            long remainder = k%(x-1);
            
            long ans;
            if(remainder==0){
                ans = x*fullBlock-1;
            }else{
                ans = x*fullBlock+remainder;
            }
            sb.append(ans).append("\n");
        }
        System.out.println(sb);
    }
}