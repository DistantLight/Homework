import  java.util.Scanner ;

class Phone {
    public String number;
    public String model;
    public String producer;
    public String os;

    public class Screen{
        public double width;
        public double height;
    }

}

public class Main {
    public static void main(String [] args) {

        Phone phone = new Phone();
        Phone.Screen screen = phone.new Screen();

        phone.number = "89205633067";
        phone.model = "vibe k5";
        phone.producer = "lenovo";
        phone.os = "android";

        screen.width = 250;
        screen.height = 150;

    }
}
