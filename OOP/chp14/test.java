package OOP.chp14;

import java.io.*;
import java.util.concurrent.ExecutionException;

interface lambda1{
    int func(int n) throws IndexOutOfBoundsException;
}

interface lambda2<T>{
    T func(T n);
}


public class test{
    public static void main(String [] args) throws IOException{
        lambda1 f = (n) ->{
            int ret=0;
            if(n<0) throw new IndexOutOfBoundsException();
            for(int i =0; i<=n; i++) ret+=i;
            return ret;
        };

        lambda2<Double> f2 = (n)->{
            double ret=0;
            for(int i =0; i<n; i++) ret+=i;

            return ret;
        };

        lambda2<String> f3 = (n)->{
            String ret="";
            for(int i =0; i<5; i++)
                ret+=n;

            return ret;
        };


        PrintWriter pw = new PrintWriter(System.out, true);

        
        pw.write(Integer.toString(f.func(10))+ "\n");
        pw.write(Double.toString(f2.func(10.0))+"\n");
        pw.write(f3.func("hello")+"\n");

        try{
            pw.write(Integer.toString(f.func(-1)));
        } catch(Exception e){
            pw.write(e.toString()+"\n");
        }
        pw.flush();
    }
}