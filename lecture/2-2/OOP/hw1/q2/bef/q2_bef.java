package q2.bef;
import java.util.*;
import java.io.*;


class User{
    private String id;
    private String name;

    User(String id, String name){
        this.id=id; this.name=name;
    }

    @Override
    public boolean equals(Object o){
        User u2 = (User)o;
        return this.id.equals(u2.id);
    }

    String get_id(){
        return id;
    }
}

public class q2_bef {
    public static void main(String args[]){

        User [] users = new User[5];
        users[0] = new User("10", "한정연");
        users[1] = new User("10", "강현서");
        users[2] = new User("10", "강한결");
        users[3] = new User("10", "권건우");
        users[4] = new User("10", "이강우");

        HashSet<User> set = new HashSet<>();
        HashMap<String, User> map = new HashMap<>();

        for(int i =0; i<5; i++) set.add(users[i]);
        for(int i =0; i<5; i++) map.put(users[i].get_id(), users[i]);
        System.out.println(set.size() + " " + map.size());
        System.out.println("\n" + users[0].hashCode() + " " + users[1].hashCode());
    }
}
