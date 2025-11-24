import java.io.*;

public class test2 {
    public static void main(String[] args) throws IOException, FileNotFoundException {
        
        File f1 = new File("./test.txt");
        File f2 = new File("./test2.txt");

        // f1.createNewFile();
        // f2.createNewFile();
        
        try(FileInputStream fis = new FileInputStream(f1);
            FileOutputStream fos = new FileOutputStream(f2)){

            int i;

            do{
                i = fis.read();
                if(i!=-1) fos.write(i);
            } while(i!=-1);
            
        } catch(Exception e){
            System.out.println(e);
        }
    }
}
