package sql.demo.dao;

import org.hibernate.Session;
import org.hibernate.SessionFactory;
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
    private static final SessionFactory sessionFactory = SmartphoneStoreDB.getSessionFactory();
    private static Session session = null;

    private ClientDao(){

    }


    public static ClientDao getInstance(){
        return INSTANCE;
    }

    public Optional<Client> findById(int id){
        session = sessionFactory.getCurrentSession();
        session.beginTransaction();
        Client client = session.get(Client.class,id);   //id
        session.getTransaction().commit();
        return Optional.ofNullable(client);
    }

    public List<Client> findAll(){
        session = sessionFactory.getCurrentSession();
        session.beginTransaction();
        List <Client> clients = session.createQuery("SELECT list FROM Client list", Client.class)
                .getResultList();
        session.getTransaction().commit();
        return clients;
    }

    public void deleteById(int id){
        session = sessionFactory.getCurrentSession();
        session.beginTransaction();
        Client client1 = session.get(Client.class,id);
        session.remove(client1);
        session.getTransaction().commit();
    }

    public void save(Client client){
        session = sessionFactory.getCurrentSession();
        session.beginTransaction();
        session.save(client);
        session.getTransaction().commit();
    }
}
