import java.util.*;
import java.io.*;


class twoD{
    int x;
    int y;
    public twoD(int x, int y){
        this.x = x;
        this.y = y;
    }

    public void show(){
        System.out.println(x + " " + y);
    }
}

class threeD extends twoD{
    int z;
    
    public threeD(int x, int y, int z){
        super(x, y);
        this.z = z;
    }

    public void show(){
        System.out.println(x + " " + y + " " + z);
    }

}

class fourD extends threeD{
    int l;
    
    public fourD(int x, int y, int z, int l){
        super(x, y, z);
        this.l = l;
    }

    public void show(){
        System.out.println(x + " " + y + " " + z + " " + l);
    }
}

class Coords<T extends twoD>{
    public T[] coords;
    Coords(T[] o){
        coords = o;
        return;
    }
}

class test{
    static void showxy(Coords<?> c){
        for(int i =0; i<c.coords.length; i++){
            System.out.println(c.coords[i].x + " " + c.coords[i].y);
        }
    }

    static void showxyz(Coords<? extends threeD> c){
        for(int i =0; i<c.coords.length; i++){
            System.out.println(c.coords[i].x + " " + c.coords[i].y + " " + c.coords[i].z);
        }
    }

    static void showxyzl(Coords<? extends fourD> c){
        for(int i =0; i<c.coords.length; i++){
            System.out.println(c.coords[i].x + " " + c.coords[i].y + " " + c.coords[i].z + " " + c.coords[i].l);
        }
    }
}

public class gen{
    public static void main(String [] args){
        twoD [] ang = new twoD[10];
        threeD [] ang2 = new threeD[10];
        fourD [] ang3 = new fourD[10];
        for(int i =0; i<10; i++){
            ang[i] = new twoD(i, i);
        }
        for(int i =0; i<10; i++){
            ang2[i] = new threeD(i, i, i);
        }
        for(int i =0; i<10; i++){
            ang3[i] = new fourD(i, i, i, i);
        }

        Coords<twoD> cc = new Coords<twoD>(ang);
        Coords<threeD> cc2 = new Coords<threeD>(ang2);
        Coords<fourD> cc3 = new Coords<fourD>(ang3);

        test.showxy(cc);
        System.out.println();
        test.showxyz(cc2);
        System.out.println();
        test.showxyzl(cc3);

        return;
    }
}