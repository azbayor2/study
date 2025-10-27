package OBB.annotation;

import java.lang.annotation.*;
import java.lang.reflect.*;
import java.util.*;

@Retention(RetentionPolicy.RUNTIME)
@interface MyAnno{
    String str();
    int val();
}


public class Test{
    @MyAnno(str = "hello world", val = 100)
    public void MyMeth(){
        try{
            Class<?> c = this.getClass();
            Method m = c.getMethod("MyMeth");
            MyAnno anno = m.getAnnotation(MyAnno.class);

            System.out.println(anno.str() + " " + anno.val());
        }catch(Exception e){
            System.out.println(e);
        }
    }

    public static void main(String [] args){
        Test ts = new Test();
        ts.MyMeth();
    }
}