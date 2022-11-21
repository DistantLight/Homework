package sql.demo.DB;

import java.sql.*;

public class SmartphoneStoreDB {
    public static final String DB_URL = "jdbc:h2:g:/Java/Homework/db/smartphoneStore";    //для создания бд при первом подключении
    public static final String DB_Driver = "org.h2.Driver";

    private static Connection connection = null;
    private static Statement statement = null;

    public static Connection getConnection() {
        return connection;
    }

    public static Statement getStatement() {
        return statement;
    }


    public static void connect() throws SQLException {
        try {
            Class.forName(DB_Driver);
            connection = DriverManager.getConnection(DB_URL);
            statement = connection.createStatement();
        } catch (ClassNotFoundException e) {
            throw new SQLException("unable to connect");
        }
    }

    public static void disconnect() {
        try {
            statement.close();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

        try {
            connection.close();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    public static void main(String[] args) {
        try {
            SmartphoneStoreDB.connect();
            Connection connection = SmartphoneStoreDB.getConnection();
            PreparedStatement preparedStatement = connection.prepareStatement(
                    "CREATE TABLE IF NOT EXISTS smartphones(" +
                            "id INT PRIMARY KEY," +
                            "name VARCHAR(128)," +
                            "price INT," +
                            "available_in_stock BOOLEAN " +
                            ");"
            );
            preparedStatement.execute();

            preparedStatement = connection.prepareStatement(
                            "CREATE TABLE IF NOT EXISTS clients(" +
                            "id INT PRIMARY KEY," +
                            "name varchar(128)," +
                            "phone_number varchar(128), " +
                            "smartphone_id INT, " +
                            "FOREIGN KEY (smartphone_id) REFERENCES smartphones (id) " +
                            ");"
            );
            preparedStatement.execute();

            /*
            preparedStatement = connection.prepareStatement(
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
                            "(12, 'Apple iPhone 13 Pro 256GB', 90, false)," +
                            "(13, 'Xiaomi Redmi 10C', 13, false)," +
                            "(14, 'TECNO Spark 8c 4/64GB', 8, true)," +
                            "(15, 'ITEL A25', 5, true)," +
                            "(16, 'Infinix HOT 11S NFC 6/128GB', 16, true)," +
                            "(17, 'Nokia G21 4/64GB', 13, false)," +
                            "(18, 'TECNO Spark Go', 7, true)," +
                            "(19, 'Huawei P50 8/256GB', 250, true)," +
                            "(20, 'TECNO Pova 3 6/128GB', 16, false);"
            );
            preparedStatement.execute();
             */

            /*
            preparedStatement = connection.prepareStatement(
                    "INSERT INTO clients(id, name, smartphone_id, phone_number)" +
                            "VALUES" +
                            "(1, 'Sergey', 4, 89200512051)," +
                            "(2, 'Maxim', 1, 89200512053)," +
                            "(3, 'Alexey', 15, 89243542051)," +
                            "(4, 'Anton', 10 , 82202112051)," +
                            "(5, 'Alexander', 9, 89200012051)," +
                            "(6, 'Anastasia', 6, 87702112051)," +
                            "(7, 'Sonya', 7, 82202112345)," +
                            "(8, 'Danil', 1, 82202119999);"
            );
            preparedStatement.execute();

             */

        } catch (SQLException e) {
            e.printStackTrace();
            System.out.println("Ошибка SQL !");
            System.out.println("NullPointerException !");
        } finally {
            SmartphoneStoreDB.disconnect();
        }
    }
}