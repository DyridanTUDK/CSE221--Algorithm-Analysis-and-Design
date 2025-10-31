import java.io.*;
public class ABeautifulSortedList {
    public static void main(String[] args) throws IOException {
        BufferedReader br =  new BufferedReader(new InputStreamReader(
            System.in
        ));
        BufferedWriter bw =  new BufferedWriter(new OutputStreamWriter(System.out));
        int N = Integer.parseInt(br.readLine());

        String[] fla = br.readLine().split(" ");
        int[] arrN = new int[N];
        for (int i = 0; i < N; i++) {
            arrN[i] = Integer.parseInt(fla[i]);
        }
        
        int M = Integer.parseInt(br.readLine());
        String[] sla = br.readLine().split(" ");
        int[] arrM = new int[M];
        for (int i = 0; i < M; i++) {
            arrM[i] = Integer.parseInt(sla[i]);
        }

        int[] finalarr = new int[N+M];
        int i = 0,j=0,k=0;

        while (i<N && j<M) {
            if (arrN[i]<=arrM[j]) {
                finalarr[k++] = arrN[i++];
            }
            else{
                finalarr[k++] = arrM[j++];
            }
        }
        while (i<N) {
            finalarr[k++] = arrN[i++];
        }
        while (j<M) {
            finalarr[k++] = arrM[j++];
        }

        for (int idx = 0; idx < finalarr.length; idx++) {
            if (idx>0) {
                bw.write(" ");
            }
            bw.write(String.valueOf(finalarr[idx]));
        }

        bw.newLine();
        bw.flush();
    }
}
