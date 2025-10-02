package q3.aft;
import java.util.*;


import java.io.*;


class Group{
    private String [] members = new String[100];
    private int num = 0;
    void addMember(String name){
        members[num++] = name;
    }
    String[] getMembers(){
        String [] strcpy = new String[100];
        for(int i =0; i<num; i++) strcpy[i] = members[i];
        return strcpy;
    }
}


public class q3_aft {
    public static void main(String args[]){
        Group g = new Group();
        g.addMember("한정연");
        System.out.println(g.getMembers()[0] + "\n");
        g.getMembers()[0] = "Alice";

        System.out.println(g.getMembers()[0]);
    }
}
