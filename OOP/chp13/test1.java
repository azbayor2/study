package chp13;
import java.io.*;

class thread1 implements Runnable{
    
    //Thread t;
    FileOutputStream fis;
    
    public void run(){
        try {
            for(int i =0; i<100000; i++)fis.write('A');

        } catch (Exception e) {
        }
    }

    thread1(FileOutputStream fis){
        this.fis = fis;
    }


}

class thread2 extends Thread{
    FileOutputStream fis;
    public void run(){
        try {
            for(int i =0; i<100000; i++) fis.write('B');

        } catch (Exception e) {
        }
    }

    thread2(FileOutputStream fis){
        this.fis=fis;
    }
}

public class test1 {
    public static void main(String[] args) throws IOException {

        File f = new File("./threadtest.txt");
        f.createNewFile();
        FileOutputStream fis = new FileOutputStream(f);


        Thread th1 = new Thread(new thread1(fis));
        th1.start();

        Thread th2 = new thread2(fis);
        th2.start();
    }
}
