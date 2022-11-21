package sql.demo.dao;

import sql.demo.DB.SmartphoneStoreDB;
import sql.demo.Entity.Smartphone;

import java.sql.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

public class SmartphoneDao {
    private static final SmartphoneDao INSTANCE = new SmartphoneDao();
    private static final String SAVE_SQL =
            "INSERT INTO smartphones " +
            "(id, name, price, available_in_stock)" +
            "VALUES (?,?,?,?);";
    private static final String FIND_BY_ID_SQL =
            "SELECT * " +
            "FROM smartphones " +
            "WHERE id = ? ;";

    private static final String FIND_BY_PRICE_LESS_THAN =
            "SELECT * " +
            "FROM smartphones " +
            "WHERE price < ? ;";

    private static final String FIND_ALL =
            "SELECT * " +
            "FROM smartphones ";


    private SmartphoneDao(){

    }

    public static SmartphoneDao getInstance(){
        return INSTANCE;
    }

    public Optional<Smartphone> findById(int id){
        Smartphone smartphone = null;
        try {
            SmartphoneStoreDB.connect();
            Connection connection = SmartphoneStoreDB.getConnection();
            PreparedStatement preparedStatement = connection.prepareStatement(FIND_BY_ID_SQL);
            preparedStatement.setInt(1,id);

            ResultSet resultSet = preparedStatement.executeQuery();
            if (resultSet.next()){
                smartphone = new Smartphone(
                        resultSet.getInt("id"),
                        resultSet.getString("name"),
                        resultSet.getInt("price"),
                        resultSet.getBoolean("available_in_stock")
                );
            }
        } catch (SQLException e) {
            e.printStackTrace();
            System.out.println("Ошибка SQL !");
            System.out.println("NullPointerException !");
        } finally {
            SmartphoneStoreDB.disconnect();
            return Optional.ofNullable(smartphone); //заворачиваем
        }
    }

    public List<Smartphone> findByPriceLessThan(int price){
        List<Smartphone> smartphones = new ArrayList<>();
        try {
            SmartphoneStoreDB.connect();
            Connection connection = SmartphoneStoreDB.getConnection();
            PreparedStatement preparedStatement = connection.prepareStatement(FIND_BY_PRICE_LESS_THAN);
            preparedStatement.setInt(1, price);

            ResultSet resultSet = preparedStatement.executeQuery();
            while (resultSet.next()){
                smartphones.add(new Smartphone(
                        resultSet.getInt("id"),
                        resultSet.getString("name"),
                        resultSet.getInt("price"),
                        resultSet.getBoolean("available_in_stock")
                ));
            }
        } catch (SQLException e) {
            e.printStackTrace();
            System.out.println("Ошибка SQL !");
            System.out.println("NullPointerException !");
        } finally {
            SmartphoneStoreDB.disconnect();
            return smartphones;
        }
    }

    public List<Smartphone> findAll(){
        List<Smartphone> smartphones = new ArrayList<>();
        try {
            SmartphoneStoreDB.connect();
            Connection connection = SmartphoneStoreDB.getConnection();
            PreparedStatement preparedStatement = connection.prepareStatement(FIND_ALL);

            ResultSet resultSet = preparedStatement.executeQuery();
            while (resultSet.next()){
                smartphones.add(new Smartphone(
                        resultSet.getInt("id"),
                        resultSet.getString("name"),
                        resultSet.getInt("price"),
                        resultSet.getBoolean("available_in_stock")
                ));
            }
        } catch (SQLException e) {
            e.printStackTrace();
            System.out.println("Ошибка SQL !");
            System.out.println("NullPointerException !");
        } finally {
            SmartphoneStoreDB.disconnect();
            return smartphones;
        }
    }

    public void save(Smartphone smartphone){
        try {
            SmartphoneStoreDB.connect();
            Connection connection = SmartphoneStoreDB.getConnection();
            PreparedStatement preparedStatement = connection.prepareStatement(SAVE_SQL);
            preparedStatement.setInt(1,smartphone.getId());
            preparedStatement.setString(2,smartphone.getName());
            preparedStatement.setInt(3,smartphone.getPrice());
            preparedStatement.setBoolean(4,smartphone.isAvailable_in_stock());
            preparedStatement.executeUpdate();
        } catch (SQLException e) {
            e.printStackTrace();
            System.out.println("Ошибка SQL !");
            System.out.println("NullPointerException !");
        } finally {
            SmartphoneStoreDB.disconnect();
        }
    }

}
