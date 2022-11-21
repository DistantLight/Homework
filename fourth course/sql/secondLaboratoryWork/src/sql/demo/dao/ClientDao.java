package sql.demo.dao;

import sql.demo.DB.SmartphoneStoreDB;
import sql.demo.Entity.Client;
import sql.demo.Entity.Smartphone;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

public class ClientDao {

    private static final ClientDao INSTANCE = new ClientDao();

    private static final String SAVE_SQL =
            "INSERT INTO clients " +
                    "(id, name, phone_number, smartphone_id) " +
                    "VALUES (?,?,?,?);";
    private static final String FIND_BY_ID_SQL =
            "SELECT * " +
                    "FROM clients " +
                    "WHERE id = ? ;";

    private static final String FIND_ALL =
            "SELECT * " +
                    "FROM clients ";


    private ClientDao(){

    }

    public static ClientDao getInstance(){
        return INSTANCE;
    }

    public Optional<Client> findById(int id){
        Client client = null;
        try {
            SmartphoneStoreDB.connect();
            Connection connection = SmartphoneStoreDB.getConnection();
            PreparedStatement preparedStatement = connection.prepareStatement(FIND_BY_ID_SQL);
            preparedStatement.setInt(1,id);

            ResultSet resultSet = preparedStatement.executeQuery();
            if (resultSet.next()){
                client = new Client(
                        resultSet.getInt("id"),
                        resultSet.getString("name"),
                        resultSet.getString("phone_number"),
                        resultSet.getInt("smartphone_id")
                );
            }
        } catch (SQLException e) {
            e.printStackTrace();
            System.out.println("Ошибка SQL !");
            System.out.println("NullPointerException !");
        } finally {
            SmartphoneStoreDB.disconnect();
            return Optional.ofNullable(client); //заворачиваем
        }
    }

    public List<Client> findAll(){
        List<Client> clients = new ArrayList<>();
        try {
            SmartphoneStoreDB.connect();
            Connection connection = SmartphoneStoreDB.getConnection();
            PreparedStatement preparedStatement = connection.prepareStatement(FIND_ALL);

            ResultSet resultSet = preparedStatement.executeQuery();
            while (resultSet.next()){
                clients.add(new Client(
                        resultSet.getInt("id"),
                        resultSet.getString("name"),
                        resultSet.getString("phone_number"),
                        resultSet.getInt("smartphone_id")
                ));
            }
        } catch (SQLException e) {
            e.printStackTrace();
            System.out.println("Ошибка SQL !");
            System.out.println("NullPointerException !");
        } finally {
            SmartphoneStoreDB.disconnect();
            return clients;
        }
    }

    public void save(Client client){
        try {
            SmartphoneStoreDB.connect();
            Connection connection = SmartphoneStoreDB.getConnection();
            PreparedStatement preparedStatement = connection.prepareStatement(SAVE_SQL);
            preparedStatement.setInt(1,client.getId());
            preparedStatement.setString(2,client.getName());
            preparedStatement.setString(3,client.getPhoneNumber());
            preparedStatement.setInt(4,client.getSmartphoneId());
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
