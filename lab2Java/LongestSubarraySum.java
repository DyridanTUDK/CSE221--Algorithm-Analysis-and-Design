import java.io.*;
public class LongestSubarraySum {
    public static void main(String[] args) throws IOException {
        BufferedReader br  = new BufferedReader(new InputStreamReader(System.in));
        String[] fl = br.readLine().split(" ");
        int N  = Integer.parseInt(fl[0]);
        long K  = Long.parseLong(fl[1]);

        String[] nums = br.readLine().split(" ");
        long[] arr = new long[N];
        for(int i=0; i<N;i++){
            arr[i] = Long.parseLong(nums[i]);
        }


        int left = 0;
        long sum = 0;
        int maxLen = 0;
        for(int right = 0 ; right<N; right++){
            sum += arr[right];
            while (sum>K && left<= right) {
                sum -= arr[left];
                left++;
            }
            maxLen = Math.max(maxLen,right-left+1);
        }


        System.out.println(maxLen);


    }
}
