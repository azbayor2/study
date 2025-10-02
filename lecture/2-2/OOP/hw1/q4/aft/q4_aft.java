package q4.aft;
import java.io.*;
import java.util.*;


final class SecureFile{
    public void open(){
        System.out.println("인증 성공!");
    }
}

class EvilFile extends SecureFile{
    @Override
    public void open(){
        System.out.println("인증 없이 파일 오픈ㅋ");
    }
}


public class q4_aft {
    public static void main(String args[]){
        new SecureFile().open();
        new EvilFile().open();
    }
}
