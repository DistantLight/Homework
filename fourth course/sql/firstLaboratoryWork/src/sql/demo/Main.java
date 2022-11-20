package sql.demo;

import java.sql.*;

public class Main {
    public static final String DB_URL = "jdbc:h2:g:/Java/Homework/db/smartphoneStore";    //для создания бд при первом подключении
    public static final String DB_Driver = "org.h2.Driver";

    public static void main(String[] args) {
        Connection connection = null;
        try {
            Class.forName(DB_Driver); //загружаем драйвер в память
            connection = DriverManager.getConnection(DB_URL); //соединение с бд

            Statement statement = connection.createStatement();
            statement.execute (
                    "CREATE TABLE IF NOT EXISTS smartphones(" +
                            "id INT NOT NULL," +
                            "name varchar(128)," +
                            "price int," +
                            "available_in_stock boolean " +
                            ");"
            );

            /*
            statement.executeUpdate (
                            "INSERT INTO smartphones(id, name, price, available_in_stock)" +
                            "VALUES" +
                            "(1, 'Samsung Galaxy A23 4/64GB', 16, false)," +
                            "(2, 'Xiaomi Redmi 9A 2/32GB', 6, true)," +
                            "(3, 'Xiaomi Redmi 10C 4/128GB', 15, true)," +
                            "(4, 'realme C30 4/64GB', 10 ,false)," +
                            "(5, 'Xiaomi Redmi 9C 3/64GB', 9, false)," +
                            "(6, 'Motorola DEFY', 18, true)," +
                            "(7, 'POCO С40 3/32GB', 7, true)," +
                            "(8, 'Samsung Galaxy A33', 24, false)," +
                            "(9, 'ITEL A17', 12, true)," +
                            "(10, 'Xiaomi Redmi Note 11 Pro', 34, false)," +
                            "(11, 'POCO M4 Pro 5G 6/128GB', 20, true)," +
                            "(12, 'Apple iPhone 13 Pro 256GB';90;false)," +
                            "(13, 'Xiaomi Redmi 10C', 13, false)," +
                            "(14, 'TECNO Spark 8c 4/64GB', 8, true)," +
                            "(15, 'ITEL A25', 5, true)," +
                            "(16, 'Infinix HOT 11S NFC 6/128GB', 16, true)," +
                            "(17, 'Nokia G21 4/64GB', 13, false)," +
                            "(18, 'TECNO Spark Go', 7, true)," +
                            "(19, 'Huawei P50 8/256GB', 250, true)," +
                            "(20, 'TECNO Pova 3 6/128GB', 16, false);"
            );
             */

            ResultSet resultSet = statement.executeQuery (
                    "SELECT * FROM smartphones;"
            );
            while (resultSet.next()){
                System.out.println( resultSet.getInt("id") + " " +
                        resultSet.getString("name") + " " +
                        resultSet.getInt("price") + " " +
                        resultSet.getBoolean("available_in_stock"));
            }

            resultSet = statement.executeQuery (
                    "SELECT * " +
                            "FROM smartphones " +
                            "WHERE id = 3 ;"

            );
            while (resultSet.next()){
                System.out.println( resultSet.getInt("id") + " " +
                        resultSet.getString("name") + " " +
                        resultSet.getInt("price") + " " +
                        resultSet.getBoolean("available_in_stock"));
            }

            resultSet = statement.executeQuery (
                    "SELECT * " +
                            "FROM smartphones " +
                            "WHERE available_in_stock IS TRUE ;"

            );
            while (resultSet.next()){
                System.out.println( resultSet.getInt("id") + " " +
                        resultSet.getString("name") + " " +
                        resultSet.getInt("price") + " " +
                        resultSet.getBoolean("available_in_stock"));
            }

        } catch (ClassNotFoundException e) {
            e.printStackTrace(); // обработка ошибки  Class.forName
            System.out.println("JDBC драйвер для СУБД не найден!");
        } catch (SQLException e) {
            e.printStackTrace(); // обработка ошибок  DriverManager.getConnection
            System.out.println("Ошибка SQL !");
        } finally {
            try {
                connection.close();       // отключение от БД
            } catch (SQLException e) {
                throw new RuntimeException(e);
            }
        }

    }
}