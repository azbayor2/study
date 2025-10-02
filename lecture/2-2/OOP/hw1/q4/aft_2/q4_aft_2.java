package q4.aft_2;
import java.io.*;
import java.util.*;


class SecureFile{
    final public void open(){
        System.out.println("인증 성공!");
    }
}

class EvilFile extends SecureFile{
    @Override
    public void open(){
        System.out.println("인증 없이 파일 오픈ㅋ");
    }
}


public class q4_aft_2 {
    
}
