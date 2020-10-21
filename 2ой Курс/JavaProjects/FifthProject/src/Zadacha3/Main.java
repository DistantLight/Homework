package Zadacha3;

import java.io.*;
import  java.util.Scanner;

public class Main {

    static String reverseString(String str) {                               //метод переворота строки
        return new StringBuilder(str).reverse().toString();
    }

    public static void main(String[] args) throws Exception {           //предупреждение о том, что метод может выбросить исключение


        File file1 = new File("text1.txt");
        File file2 = new File("text2.txt");

        if (!file1.exists()&&!file2.exists()) {                             //создание двух файлов, если их нет
            file1.createNewFile();
            file2.createNewFile();


        }

        PrintWriter printWriter1 = new PrintWriter(file1);
        PrintWriter printWriter2 = new PrintWriter(file2);


        printWriter1.println("hello");                              //записываем данные в первый файл
        printWriter1.close();
        printWriter2.println("world!!!");                           //записываем данные во второй файл
        printWriter2.close();

        Scanner scan = new Scanner(file1);
        Scanner sc = new Scanner(file2);



        String str1 = scan.nextLine();                  //переменная, хранящая строку из первого файла
        str1 = reverseString(str1);                     //переворот строки
        String str2 = sc.nextLine();                    //переменная, хранящая строку из второго файла
        str2 = reverseString(str2);                     //переворот строки


        PrintWriter writer1 = new PrintWriter(file1);           //создание нового экземпляра класса PrintWriter для файла 1, чтобы стереть предыдущие данные
        writer1.print(str2);                                    //запись в файл1 перевёрнутой строки из файл2
        writer1.flush();
        writer1.close();

        PrintWriter writer2 = new PrintWriter(file2);           //создание нового экземпляра класса PrintWriter для файла 2, чтобы стереть предыдущие данные
        writer2.print(str1);                                    //запись в файл2 перевёрнутой строки из файл1
        writer2.flush();
        writer2.close();


    }
}