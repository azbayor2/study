package q4.bef;
import java.io.*;
import java.util.*;


class SecureFile{
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

public class q4_bef {
    public static void main(String args[]){
        new SecureFile().open();
        new EvilFile().open();
    }
    
}
