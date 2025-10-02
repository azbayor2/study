package q1.bef;
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

class Square extends Rectangle{
    public void setWidth(int width){
        this.width = this.height = width;
    }

    public void setHeight(int height){
        this.height=this.width=height;
    }
}

public class q1_bef{
    public static void main(String args[]){
        Rectangle r = new Square(); r.setWidth(10); r.setHeight(5);
        System.out.println(r.getWidth() + " " + r.getHeight());
    }
}

