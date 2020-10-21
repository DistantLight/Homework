package Zadacha2;

import java.io.*;
import  java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception {     //предупреждение о том, что метод может выбросить исключение
        Scanner sc = new Scanner(System.in);

        File file = new File("temp.txt");
        if (!file.exists()) {                                     //создание нового файла, если его не существует
            file.createNewFile();

            PrintWriter printWriter = new PrintWriter(file);
            int rand;
            for (int i = 1; i <= 200; i++) {                                                                           //заполнение файла
                printWriter.println(String.valueOf(i) + ": " + (rand = (int) (Math.random() * (200 + 1)) - 100));      //преобразуем i в string, прибавляем строку ": " и прибавляем рандомное число от 100 до -100
            }
            printWriter.close();

        }

        Scanner scan = new Scanner(file);

        System.out.println("Введите индекс числа, которое нужно вывести");
        String str = sc.nextLine();
        str += ":";                         //прибавляем к введенному числу ":"
        String w ;
        while (scan.hasNext()){                 //проход по всему файлу
            w = scan.next();                    //сканирует строку до пробела
            if(w.equals(str)){
                System.out.println(scan.next());
            }
        }
        scan.close();
    }
}