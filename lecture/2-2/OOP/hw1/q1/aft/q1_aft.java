package q1.aft;
import java.io.*;
import java.util.*;



class Rectangle{
    protected int width;
    protected int height;

    public void setWidth(int width){
        this.width=width;
    }
    public void setHeight(int height){
        this.height=height;
    }
    public int getWidth(){
        return width;
    }

    public int getHeight(){
        return height;
    }
}

class Square{
    private Rectangle r = new Rectangle();
    void setLength(int length){
        r.setHeight(length);
        r.setWidth(length);
    }

    int getLength(){
        return r.getHeight();
    }
}

public class q1_aft {
    public static void main(String args[]){
        Square s = new Square();
        s.setLength(10);
        System.out.println(s.getLength());
    }
}
