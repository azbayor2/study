package OOP.chp14;

interface lambda2{
    int func(int n);
}


public class test2 {
    public static void main(String [] args){

        int num = 10;

        lambda2 l2 = (n)->{
            int ret = num+n;
            return ret;
        };

        System.out.println(l2.func(10));
        //num++;
    }
}
