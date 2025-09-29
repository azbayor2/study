import java.io.*;
//import java.util.*;

class HelloWorld{
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String [] args) throws IOException{
        bw.write("Hello world!");
        bw.flush();

        return;
    }
}