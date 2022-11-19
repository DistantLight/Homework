import java.util.Scanner;

public class Main {


    static String[] digits = {"", "one ", "two ", "three ", "four ", "five ", "six ", "seven ", "eight ", "nine ", "ten "};
    static String[] mas={"","eleven ", "twelve ", "thirteen ", "fourteen ", "fifteen ", "sixteen ", "seventeen ", "eighteen ", "nineteen "};
    static String[] dozens = {"", "ten ", "twenty ", "thirty ", "forty ", "fifty ", "sixty ", "seventy ", "eighty ", "ninety "};
    static String[] thousandAndMore = {"", "thousand ", "million ", "billion "};

    public static String DigitInWord(long digit){
        int num = (int)digit;
        int counter = 0;
        int mod = 0;
        String res = "";

        if (num>10&&num<20){
            res = mas[(num%10)];
            return res;
        }



        while (num!=0){
            counter++;

            mod = num%10;
            num = num/10;
            switch (counter){
                case 1:
                    res = digits[mod] + res;
                    break;
                case 2:
                    res = dozens[mod]  + res;
                    break;
                case 3:
                    res = digits[mod]  + "hundred " + res ;
                    break;
                default:
                    break;
            }

        }
        return res;
    }


    public static void main(String[] args)  {


        Scanner sc = new Scanner(System.in);
        System.out.println("Введите число");
        long var = sc.nextLong();
        long num=0 ;                       //хранит остаток от деления на 1000
        int count=-1;                      //счётчик для массива hundredAndMore
        String res = "";

        if (var==0){
            System.out.println("zero");
            return;
        }


        while (var!=0){
            num = var%1000;
            var = var/1000;
            count++;
            String str="";

            if(num!=0){
                str = thousandAndMore[count];
            }

            res = DigitInWord(num) + str + res ;

        }
        System.out.println(res);

    }
}