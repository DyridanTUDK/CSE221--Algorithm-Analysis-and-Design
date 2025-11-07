import java.io.*;
public class OrdinaryBinaryTree {
    static int[] result;
    static int idx = 0;

    public static void main(String[] args)throws IOException {
        BufferedReader br =  new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine().trim());
        String[] parts = br.readLine().trim().split(" ");
        int[] arr = new int[n];
        for(int i=0;i <n;i++){
            arr[i] = Integer.parseInt(parts[i]);
        }
        result = new int[n];
        buildMinHeightBSTOrder(arr,0,n-1);

        StringBuilder sb = new StringBuilder();
        for(int i=0;i<n;i++){
            sb.append(result[i]).append(" " );
        }
        System.out.println(sb.toString().trim());
    }
    static void buildMinHeightBSTOrder(int[]arr,int left,int right){
        if (left>right) {
            return;
        }
        int mid = (left+right)/2;
        result[idx++] = arr[mid];
        buildMinHeightBSTOrder(arr, left, mid-1);
        buildMinHeightBSTOrder(arr, mid+1,right);
    }
}
