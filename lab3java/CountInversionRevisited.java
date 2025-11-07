package lab3java;
import java.io.*;
import java.util.*;

public class CountInversionRevisited {
    public static long countPairs(long[] arr) {
        return mergeSortAndCount(arr, 0, arr.length - 1);
    }

    private static long mergeSortAndCount(long[] arr, int left, int right) {
        if (left >= right) return 0;
        int mid = left + (right - left) / 2;
        long count = mergeSortAndCount(arr, left, mid) + mergeSortAndCount(arr, mid + 1, right);
        int n1 = mid - left + 1;
        int n2 = right - mid;
        long[] L = new long[n1];
        long[] R = new long[n2];

        for (int i = 0; i < n1; i++) L[i] = arr[left + i];
        for (int i = 0; i < n2; i++) R[i] = arr[mid + 1 + i];
        Arrays.sort(R);
        for (int i = 0; i < n1; i++) {
            long target = L[i];
            int j = upperBound(R, target); 
            count += j;
        }
        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) arr[k++] = L[i++];
            else arr[k++] = R[j++];
        }
        while (i < n1) arr[k++] = L[i++];
        while (j < n2) arr[k++] = R[j++];

        return count;
    }
    private static int upperBound(long[] R, long target) {
        int low = 0, high = R.length;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (R[mid] * R[mid] < target) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        return low;
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine().trim());
        long[] A = new long[N];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < N; i++) {
            A[i] = Long.parseLong(st.nextToken());
        }
        System.out.println(countPairs(A));
    }
}
