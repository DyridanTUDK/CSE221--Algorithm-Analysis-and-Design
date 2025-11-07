import java.io.*;
import java.util.*;

public class Twotwentytrees {
    static int[] inOrder,preOrder,postOrder;
    static int idx = 0;
    static Map<Integer,Integer> inIndexMap = new HashMap<>();
    public static void main(String[] args) throws IOException {
        BufferedReader br =  new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine().trim());
        inOrder = new int[n];
        preOrder = new int[n];
        postOrder = new int[n];

        String[] inParts = br.readLine().trim().split(" ");
        String[] preParts = br.readLine().trim().split(" ");

        for (int i = 0; i < n; i++) {
            inOrder[i] = Integer.parseInt(inParts[i]);
            inIndexMap.put(inOrder[i],i);
        }
        for (int i = 0; i < n; i++) {
            preOrder[i] = Integer.parseInt(preParts[i]);
        }

        buildPostOrder(0, n-1, 0, n-1);
        StringBuilder sb = new StringBuilder();

        for(int i=0;i<n;i++){
            sb.append(postOrder[i]).append(" ");
        }
        System.out.println(sb.toString().trim());
    }

    static void buildPostOrder(int inStart, int inEnd, int preStart, int preEnd){
        if (inStart>inEnd||preStart>preEnd) {
            return;
        }
        int root = preOrder[preStart];
        int rootIndex = inIndexMap.get(root);
        int leftSize = rootIndex-inStart;

        buildPostOrder(inStart, rootIndex-1, preStart+1, preStart+leftSize);
        buildPostOrder(rootIndex+1, inEnd, preStart+1+leftSize, preEnd);

        postOrder[idx++] = root;
    }
    
}