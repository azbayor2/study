import java.util.*;
import java.io.*;

public class boj_24453{
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static StringBuilder sb = new StringBuilder();
    static StringTokenizer st;
    static int N, M, K, L;
    static boolean [] arr = new boolean[20000009];

    public static void main(String [] args) throws IOException{
        st = new StringTokenizer(br.readLine());
        N = Integer.parseInt(st.nextToken()); M = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());

        for(int i = 0; i<M; i++){
            int temp = Integer.parseInt(st.nextToken());
            arr[temp] = true;
        }

        st = new StringTokenizer(br.readLine());
        K = Integer.parseInt(st.nextToken()); L = Integer.parseInt(st.nextToken());

        int s =1, e = 2, count = arr[s] == false ? 0: 1;
        int ans = 20000001;

        while(e>s && e<=N+1){
            if((e-s)>=K && count>=L){
                ans = Math.min(ans, count);
            }
            if(e==s){
                count+=(arr[e]==false ? 0:1);
                e++;
                continue;
            }
            if(e-s<K){
                count+=(arr[e]==false ? 0:1);
                e++;
                continue;
            }
            else{
                if(count<L){
                    count+=(arr[e] ==  false ? 0:1);
                    e++;
                    continue;
                }

                else{
                    count-=(arr[s]==false?0:1);
                    s++;
                    continue;
                }
            }
        }

        sb.append((M-ans) + "\n");
        bw.write(sb.toString());
        bw.flush();

        return;
    }
}