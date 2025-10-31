import java.io.*;

public class TwoSumTrouble {
    public static void main(String[] args ) throws IOException {
        BufferedReader br  = new BufferedReader(new InputStreamReader(System.in));

        String[] input_first = br.readLine().split(" ");
        int N = Integer.parseInt(input_first[0]);
        long S = Long.parseLong(input_first[1]);

        String[] nums = br.readLine().split(" ");
        long[] arr = new long[N];
        for(int i=0; i<N;i++){
            arr[i] = Long.parseLong(nums[i]);
        }
        
        int left = 0;
        int right = N-1;
        boolean found = false;
        while (left<right) {
            long sum  = arr[left] + arr[right];
            if(sum==S){
                System.out.println((left+1)+ " "+ (right+1));
                found = true;
                break;
            }
            else if(sum<S){
                left++;
            }
            else{
                right--;
            }
        }
        if(!found){
            System.out.println(-1);
        }

    }
}