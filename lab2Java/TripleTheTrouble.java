import java.io.*;
import java.util.*;
public class TripleTheTrouble {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] fl = br.readLine().split(" ");
        int n = Integer.parseInt(fl[0]);
        long x = Long.parseLong(fl[1]);

        String[] nums = br.readLine().split(" ");
        long[][] arr = new long[n][2];
        for (int i = 0; i < n; i++) {
            arr[i][0] = Long.parseLong(nums[i]);
            arr[i][1] = i+1; 
        }

        Arrays.sort(arr, Comparator.comparingLong(a->a[0]));

        for(int i = 0; i < n; i++){
            int left = i+1;
            int right = n-1;

            while (left< right) {
                long sum = arr[i][0] + arr[left][0] + arr[right][0];
                if (sum == x) {
                    System.out.println(arr[i][1]+" "+arr[left][1]+" "+arr[right][1]);
                    return;                   
                }
                else if(sum<x){
                    left++;
                }
                else{
                    right--;
                }
                
            }

        }
        System.out.println(-1);
    }
}
