import java.lang.annotation.*;
import java.lang.reflect.*;


@Retention(RetentionPolicy.RUNTIME)
@interface Anno{
    String str();
    int vl();
}


public class test2 {

    @Anno(str="hello", vl=10)
    public static void test(){
        try {
            test2 t = new test2();
            Class<?> c = t.getClass();
            Method m = c.getMethod("test");
            Anno anno = m.getAnnotation(Anno.class);

            System.out.println(anno.str() + anno.vl());

        } catch (Exception e) {

        }
    }

    public static void main(String[] args) {
        test();
    }
}
