import java.io.*;
import java.util.*;

public class boj_11728{
    static BufferedReader br= new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringBuilder sb = new StringBuilder();
    static StringTokenizer st;
    static int input, idx=0;
    static int [] N = new int[2];
    static int [] arr = new int [2000001];

    public static void main(String [] args) throws IOException{
        st = new StringTokenizer(br.readLine());
        N[0] = Integer.parseInt(st.nextToken()); N[1] = Integer.parseInt(st.nextToken());

        for(int i =0; i<2; i++){
            st = new StringTokenizer(br.readLine());
            for(int j=0; j<N[i]; j++){
                arr[idx++] = Integer.parseInt(st.nextToken());
            }
        }

        Arrays.sort(arr, 0, idx);

        for(int i = 0; i<idx; i++){
            sb.append(arr[i] + " ");
        }

        bw.write(sb.toString());
        bw.flush();

        return;
    }


}