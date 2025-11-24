package chp13;

class A{
    synchronized void testA(B b){

        System.out.println("hello from A");
        try{
            Thread.sleep(1000);
        }catch(Exception e){
        
        }
        b.last();

    }

    synchronized void last(){
        System.out.println("From A, byebye");
    }
}

class B{

    synchronized void testB(A a){

        System.out.println("hello from B");
        try{
            Thread.sleep(1000);
        } catch(Exception e){

        }
        a.last();

    }

    synchronized void last(){
        System.out.println("From B, byebye");
    }
}

class deadlockA implements Runnable{
    A a;
    B b;

    deadlockA(A a, B b){
        this.a=a;
        this.b=b;
    }

    public void run(){
        a.testA(b);
    }
}

class deadlockB implements Runnable{
    A a;
    B b;

    deadlockB(A a, B b){
        this.a=a;
        this.b=b;
    }

    public void run(){
        b.testB(a);
    }
}

public class test4 {
    public static void main(String[] args) {
        A a = new A();
        B b = new B();

        Thread th1 = new Thread(new deadlockA(a, b));
        Thread th2 = new Thread(new deadlockB(a, b));

        th1.start(); th2.start();


    }
}
