package q3.aft_2;
import java.io.*;
import java.util.*;

class Group{
    private List<String> members = new ArrayList<>();
    private List<String> unmodifiable = Collections.unmodifiableList(members);

    public void addMember(String member){
        members.add(member);
    }

    public List<String> getList(){
        return unmodifiable;
    }
}

public class q3_aft_2 {
    public static void main(String [] args){

        Group g = new Group();
        g.addMember("한정연");
        List<String> ls = (ArrayList<String>)g.getList();
        ls.add("한정연2");
    }
}
