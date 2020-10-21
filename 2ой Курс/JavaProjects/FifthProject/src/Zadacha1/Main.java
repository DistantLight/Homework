package Zadacha1;

import  java.util.Scanner;

public class Main {
    public static void main (String [] args) {
        Scanner scan = new Scanner(System.in);


        System.out.println("Введите 2 числа");
        double a = scan.nextInt();
        double b = scan.nextInt();
        double c;

        System.out.println("а поделить на б");
        try {
            System.out.println(c = a / b);
        } catch (Exception e ){

        }

        System.out.println("б поделить на а");
        try {
            System.out.println(c = b / a);
        } catch (Exception e){

        }

    }
}