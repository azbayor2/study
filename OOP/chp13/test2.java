package chp13;

class Callme{
    void call(String msg){
        System.out.print("["+msg);
        try {
            Thread.sleep(1000);
        } catch (Exception e) {
        }

        System.out.println("]");
    }
}

class t1 implements Runnable{
    Callme cm;
    String msg;
    Thread th;

    public void run(){
        synchronized (cm) {
            cm.call(msg);
        }
    }

    t1(Callme cm, String msg){
        this.cm = cm;
        this.msg = msg;
        th = new Thread(this);
    }
}


public class test2 {
    public static void main(String[] args) {

        Callme cm = new Callme();

        Thread t11 = new Thread(new t1(cm, "hello"));
        Thread t22 = new Thread(new t1(cm, "world"));

        t11.start();
        t22.start();

    }
}
