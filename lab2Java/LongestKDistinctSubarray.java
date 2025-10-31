import java.io.*;
public class LongestKDistinctSubarray {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] first  = br.readLine().split(" ");

        int N = Integer.parseInt(first[0]);
        int K = Integer.parseInt(first[1]);

        String[] nums =  br.readLine().split(" ");
        int[] arr = new int[N];

        for (int i = 0; i < N; i++) {
            arr[i]=Integer.parseInt(nums[i]);
        }

        int[] freq = new int[N+1];
        int distinct = 0;
        int left = 0 ;
        int maxLen = 0;

        for(int right=0; right<N; right++){
            if (freq[arr[right]]==0) {
                distinct++;
            }
            freq[arr[right]]++;
            while(distinct>K){
                freq[arr[left]]--;
                if(freq[arr[left]]==0){
                    distinct--;
                }
                left++;
            }
            maxLen = Math.max(maxLen, right-left+1);

        }
        System.out.println(maxLen);
    }
}
