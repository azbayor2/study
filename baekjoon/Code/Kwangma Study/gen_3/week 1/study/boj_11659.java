import java.io.*;
import java.util.*;


public class boj_11659{
    static int [] arr = new int[100001];
    static int a, b, N, K;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringTokenizer st;
    static StringBuilder sb = new StringBuilder();

    public static void main(String [] args) throws IOException{

        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken()); K = Integer.parseInt((st.nextToken()));
        st = new StringTokenizer(br.readLine());
        for(int i = 1; i<=N ;i++){
            arr[i] = Integer.parseInt(st.nextToken());
            arr[i]+=arr[i-1];
        }


        for(int i =0; i<K; i++){
            st = new StringTokenizer(br.readLine());
            a = Integer.parseInt(st.nextToken()); b = Integer.parseInt(st.nextToken());
            int temp = arr[b] - arr[a-1];
            sb.append(temp); sb.append("\n");
        }

        bw.write(sb.toString());
        bw.flush();

    }

}

