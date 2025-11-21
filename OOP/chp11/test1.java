

public class test1{

    enum Words{
        Harry(10, 20), Ron(11), Herm(12), Haha;
        private int price;
        private int secondprice;

        Words(int p){price = p;}
        Words(int p, int q){price = p; secondprice=q;}
        Words(){price =-1;}

        int getPrice(){return price;}
    }
    
    public static void main(String[] args) {
        Words w = Words.Harry;
        Words ww = Words.Haha;  //-1 대입

        System.out.println(ww.getPrice());

        Words [] wr = Words.values();
        for(Words www: wr){
            System.out.println(www.ordinal());
        }

        System.out.println(w.compareTo(ww));

    }
}
/*
    1. enum 생성자
    2. 열거형 상수: public static final
    3. enum type[] values()
    4. enum type valueOf(String str)
    5. int ordinal()
    6. final int compareTo(enum type e)
 */