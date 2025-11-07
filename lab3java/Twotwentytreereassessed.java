package lab3java;
import java.io.*;
import java.util.*;

public class Twotwentytreereassessed {
    static int[] inOrder, postOrder, preOrder;
    static int idx = 0;
    static Map<Integer, Integer> inIndexMap = new HashMap<>();
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine().trim());
        inOrder = new int[n];
        postOrder = new int[n];
        preOrder = new int[n];
        String[] inParts = br.readLine().trim().split(" ");
        String[] postParts = br.readLine().trim().split(" ");
        for (int i = 0; i < n; i++) {
            inOrder[i] = Integer.parseInt(inParts[i]);
            inIndexMap.put(inOrder[i], i); 
        }
        for (int i = 0; i < n; i++) {
            postOrder[i] = Integer.parseInt(postParts[i]);
        }
        buildPreOrder(0, n - 1, 0, n - 1);
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < n; i++) {
            sb.append(preOrder[i]).append(" ");
        }
        System.out.println(sb.toString().trim());
    }
    static void buildPreOrder(int inStart, int inEnd, int postStart, int postEnd) {
        if (inStart > inEnd || postStart > postEnd) return;
        int root = postOrder[postEnd];
        preOrder[idx++] = root;
        int rootIndex = inIndexMap.get(root);
        int leftSize = rootIndex - inStart;
        buildPreOrder(inStart, rootIndex - 1, postStart, postStart + leftSize - 1);
        buildPreOrder(rootIndex + 1, inEnd, postStart + leftSize, postEnd - 1);
    }
}
