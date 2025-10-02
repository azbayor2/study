package q3.bef;
import java.util.*;
import java.io.*;


class Group{
    private String [] members = new String[100];
    private int num = 0;
    void addMember(String name){
        members[num++] = name;
    }
    String[] getMembers(){
        return members;
    }
}


public class q3_bef {
    public static void main(String args[]){
        Group g = new Group();
        g.addMember("한정연");
        System.out.println(g.getMembers()[0] + "\n");
        g.getMembers()[0] = "Alice";

        System.out.println(g.getMembers()[0]);
    }
}
