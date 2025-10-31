import java.io.*;
public class CountTheNumbers {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] first = br.readLine().split(" ");
        int n = Integer.parseInt(first[0]);
        int q = Integer.parseInt(first[1]);
        long[] arr = new long[n];
        String[] sla = br.readLine().split(" ");
        for (int i = 0; i < n; i++) {
            arr[i] = Long.parseLong(sla[i]);
        }
        for(int i = 0;i<q;i++){
            String[] range = br.readLine().split(" ");
            long low = Long.parseLong(range[0]);
            long high = Long.parseLong(range[1]);

            int left = lowerBound(arr, low);
            int right = upperBound(arr, high);
            System.out.println(right-left);
        }
    }

    static int lowerBound(long[] arr, long target){
        int low = 0, high = arr.length;
        while (low<high) {
            int mid = (low+high)/2;
            if (arr[mid]>=target) {
                high = mid;
            }
            else{
                low = mid +1;
            }
        }
        return low;
    }
    static int upperBound(long[] arr, long target){
        int low = 0, high = arr.length;
        while (low<high) {
            int mid = (low+high)/2;
            if (arr[mid]>target) {
                high = mid;
            }
            else{
                low = mid +1;
            }
        }
        return low;
    }
}
