import java.io.*;


public class test1 {
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out, true);

        String s = br.readLine();
        pw.println(s);

        //char c = (char)br.read();
        char c = 'A';
        pw.print(c);
        pw.flush();

    }
}
