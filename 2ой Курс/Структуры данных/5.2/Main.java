

public class Main {
    public static void main(String [] args) {


        System.out.println("Hello World");
        String s1 = "Hello";
        String s2 = "Hello";
        String s3 = new String("Hello");
        String s4 = "World";

        System.out.println(s1==s2);
        System.out.println(s1==s3);
        System.out.println(s1==s4);

        System.out.println("\n");

        System.out.println(s1.equals(s2));
        System.out.println(s1.equals(s3));
        System.out.println(s1.equals(s4));

    }
}
