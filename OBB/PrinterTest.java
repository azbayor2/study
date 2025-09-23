import java.io.*;
import java.util.*;


class Printer{
    private int numofPapers;
    private BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    private StringBuilder sb = new StringBuilder();
    private StringTokenizer st;

    void addPaper(int amount){
        numofPapers+=amount;
        return;
    }


    public void print(int amount) throws IOException{
        if(!checkAmount(amount)){
            bw.write("not enough paper\n");
            bw.flush();
            return;
        }
        sb = new StringBuilder();
        sb.append("printing "+ amount + "\n");
        bw.write(sb.toString());
        bw.flush();
        numofPapers-=amount;
        return;
    }

    private boolean checkAmount(int amount){
        return (numofPapers-amount >=0 ? true: false);
    }

    Printer(int numofPapers){
        this.numofPapers = numofPapers;
        return;
    }
}

public class PrinterTest{
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st;
    
    public static void main(String [] args) throws IOException{
        Printer p = new Printer(100);

        while(true){
            st = new StringTokenizer(br.readLine());
            int num = Integer.parseInt(st.nextToken());

            if(num==0){
                break;
            }
            
            p.print(num);
        }

        return;
    }
}