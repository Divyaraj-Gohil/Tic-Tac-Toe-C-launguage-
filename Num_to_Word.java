import java.util.*;
public class Num_to_Word {
    public static String convert(int x){
        String first[]={"\0","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN",
        "EIGHT","NINE","TEN","ELEVEN","TWELVE","THIRTEEN","FOURTEEN","FIFTEEN"
         ,"SIXTEEN","SEVENTEEN","EIGHTEEN","NINETEEN","TWENTY"};

         String second[]={"\0","TEN","TWENTY","THIRTY","FOURTY","FIFTY","SIXETY","SEVENTY",
         "EIGHTY","NINETY"};
        
         if(x<=20){
            return first[x];
         }
         else if(x>20 && x<100){
            return second[(x/10)]+" "+first[(x%10)];
         }else if(x<1000 ){
            return first[x/100]+" HUNDRED "+convert(x%100);
         }else if(x<10000){
            return first[x/1000]+" THOUSAND "+convert(x%1000);
         }else if(x<100000){
            return convert(x/1000)+" THOUSAND "+convert(x%1000);
         }else if(x<1000000){
            return first[x/100000]+" LAKH "+convert(x%100000);
         }else if(x<10000000){
            return convert(x/100000)+" LAKH "+convert(x%100000);
         }else if(x<100000000){//9,99,99,999
            return first[x/10000000]+" CRORE "+convert(x%10000000);
         }else if(x<1000000000){//99,99,99,999
            return convert(x/10000000)+" CRORE "+convert(x%10000000);
         }

         return "*****SARKHO NUMBER NAAKH*****" ;
    }

    public static void main(String args[]){
        Scanner scr = new Scanner(System.in);
        System.out.print("Enter the number : ");
        int num=scr.nextInt();
        String ot=(num==0)?"ZERO":convert(num);
        System.out.println("("+ot+")");
    }

}
