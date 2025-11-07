import java.io.*;
import java.util.StringTokenizer;;

public class FastMatrixDrift {
    static final long MOD = 1000000007;
    static long [][] c = new long[2][2];
    static void multiply(long[][]A, long[][]B, long[][] result){
        c[0][0] = (A[0][0]*B[0][0] % MOD + A[0][1]*B[1][0]%MOD)%MOD;
        c[0][1] = (A[0][0]*B[0][1] % MOD + A[0][1]*B[1][1]%MOD)%MOD;
        c[1][0] = (A[1][0]*B[0][0] % MOD + A[1][1]*B[1][0]%MOD)%MOD;
        c[1][1] = (A[1][0]*B[0][1] % MOD + A[1][1]*B[1][1]%MOD)%MOD;

        result[0][0] = c[0][0];
        result[0][1] = c[0][1];
        result[1][0] = c[1][0];
        result[1][1] = c[1][1];

    }

    static void power(long[][] A, long exp,long[][]result){

        result[0][0] = 1; result[0][1]=0;
        result[1][0] = 0; result[1][1]=1;

        
        long[][] base = { {A[0][0], A[0][1]}, {A[1][0], A[1][1]} };
        long[][] temp =  new long[2][2];

        while (exp>0) {
            if ((exp & 1)==1) {
                multiply(result,base,temp);
                result[0][0] = temp[0][0];
                result[0][1] = temp[0][1];
                result[1][0] = temp[1][0];
                result[1][1] = temp[1][1];
            }
            multiply(base, base, temp);
            base[0][0] = temp[0][0];
            base[0][1] = temp[0][1];
            base[1][0] = temp[1][0];
            base[1][1] = temp[1][1];
            exp >>= 1;
        }
    }

    public static void main (String[] args)throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int T = Integer.parseInt(br.readLine());

        long[][] A =  new long[2][2];
        long[][] R =  new long[2][2];
        for (int i = 0; i < T; i++) {
            String[] line = br.readLine().split(" ");

            A[0][0] = Long.parseLong(line[0]);
            A[0][1] = Long.parseLong(line[1]);
            A[1][0] = Long.parseLong(line[2]);
            A[1][1] = Long.parseLong(line[3]);
            
            long X = Long.parseLong(br.readLine());


            power(A, X, R);

            bw.write(R[0][0]+" "+R[0][1]+"\n");
            bw.write(R[1][0]+" "+R[1][1]+"\n");
        }
        bw.flush();
    }
}
