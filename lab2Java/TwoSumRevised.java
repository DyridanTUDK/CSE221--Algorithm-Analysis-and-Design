import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class TwoSumRevised {
    public static void main(String[] args) throws IOException {
        BufferedReader br  =  new BufferedReader(new InputStreamReader(System.in));
        String[] first_line = br.readLine().split(" ");
        int N = Integer.parseInt(first_line[0]);
        int M = Integer.parseInt(first_line[1]);
        long K = Long.parseLong(first_line[2]);
        Long[] A = new Long[N];
        Long[] B = new Long[M];

        String[] second_line = br.readLine().split(" ");
        for(int i =0; i<N; i++){
            A[i] = Long.parseLong(second_line[i]);
        }
        String[] third_line = br.readLine().split(" ");
        for(int i =0; i<M; i++){
            B[i] = Long.parseLong(third_line[i]);
        }

        int i = 0;
        int j = M-1;

        long bestDiff = Long.MAX_VALUE;
        int bestI = -1,  bestJ = -1;

        while (i<N && j>=0) {
            long sum = A[i] + B[j];
            long diff = Math.abs(sum-K);
            if(diff<bestDiff){
                bestDiff = diff;
                bestI = i + 1;
                bestJ = j + 1;

            }
            if(sum>K){
                j--;
            }
            else{
                i++;
            }
        }
        System.out.println(bestI+ " "+ bestJ);

    }
}
