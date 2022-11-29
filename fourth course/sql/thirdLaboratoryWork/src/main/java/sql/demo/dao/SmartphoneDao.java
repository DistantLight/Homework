package sql.demo.dao;

import org.hibernate.Session;
import org.hibernate.SessionFactory;
import sql.demo.DB.SmartphoneStoreDB;
import sql.demo.Entity.Smartphone;

import java.sql.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

public class SmartphoneDao {
    private static final SmartphoneDao INSTANCE = new SmartphoneDao();
    private static final SessionFactory sessionFactory = SmartphoneStoreDB.getSessionFactory();
    private static Session session = null;
    private SmartphoneDao(){

    }

    public static SmartphoneDao getInstance(){
        return INSTANCE;
    }



    public Optional<Smartphone> findById(int id){
        session = sessionFactory.getCurrentSession();
        session.beginTransaction();
        Smartphone smartphone = session.get(Smartphone.class,id);
        session.getTransaction().commit();
        return Optional.ofNullable(smartphone);
    }

    public void deleteById(int id){
        session = sessionFactory.getCurrentSession();
        session.beginTransaction();
        Smartphone smartphone = session.get(Smartphone.class,id);
        session.remove(smartphone);
        session.getTransaction().commit();
    }
    public List<Smartphone> findByPriceLessThan(int price){
        session = sessionFactory.getCurrentSession();
        session.beginTransaction();
        List <Smartphone> smartphones = session.createQuery("SELECT s FROM Smartphone s WHERE s.price < :price", Smartphone.class)
                .setParameter("price", price)
                .getResultList();
        session.getTransaction().commit();
        return smartphones;
    }

    public List<Smartphone> findAll(){
        session = sessionFactory.getCurrentSession();
        session.beginTransaction();
        List <Smartphone> smartphones = session.createQuery("SELECT list FROM Smartphone list", Smartphone.class)
                .getResultList();
        session.getTransaction().commit();
        return smartphones;
    }

    public void save(Smartphone smartphone){
        session = sessionFactory.getCurrentSession();
        session.beginTransaction();
        session.save(smartphone);
        session.getTransaction().commit();
    }

}
