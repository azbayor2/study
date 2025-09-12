import java.io.*;
import java.util.*;


public class boj_1940{
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringBuilder sb = new StringBuilder();
    static StringTokenizer st;
    static int [] arr = new int[15001];
    static int N, M, ans=0;

    public static void main(String [] args) throws IOException{
        st = new StringTokenizer(br.readLine()); N = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine()); M = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        for(int i =0; i<N; i++){
            arr[i] = Integer.parseInt(st.nextToken());
        }

        Arrays.sort(arr, 0, N);

        int s = 0, e = N-1;

        while(s<e){
            int sum = arr[s] + arr[e];
            if(sum==M)
                ans++;
            if(sum>=M){
                e--;
            } else{
                s++;
            }
        }
        
        sb.append(ans + "\n");
        bw.write(sb.toString());
        bw.flush();

        return;
    }
}