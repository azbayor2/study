package chp13;

class Q{
    int n;

    synchronized int get(){

        try{
        if(n==-1) wait();
        } catch(Exception e){
            System.out.println(e);
        }
        int ret = n;
        n = -1;
        notify();
        return ret;
    }

    synchronized void put(int i){
        try{
            if(n!=-1) wait();
        }catch(Exception e){
            System.out.println(e);
        }
        n = i;
        notify();
        return;
    }

    Q(){
        n=-1;
    }
}

class Producer implements Runnable{
    Q q;

    Producer(Q q){
        this.q=q;
    }

    public void run(){
        for(int i =0; i<100; i++){
            q.put(i);
        }
    }
}

class Consumer implements Runnable{
    Q q;

    Consumer(Q q){
        this.q=q;
    }

    public void run(){
        for(int i =0; i<100; i++){
            System.out.println(q.get());
        }
    }
}

public class test3 {
    public static void main(String[] args) {

        Q q = new Q();
        Thread th1 = new Thread(new Producer(q));
        Thread th2 = new Thread(new Consumer(q));

        th1.start(); th2.start();
    }
}
