package sql.demo;

import sql.demo.Entity.Client;
import sql.demo.Entity.Smartphone;
import sql.demo.dao.ClientDao;
import sql.demo.dao.SmartphoneDao;

import java.util.List;
import java.util.Optional;


public class Test {


    public static void main(String[] args) {
        System.out.println(SmartphoneDao.getInstance().findById(3));


        for (Smartphone smartphone : SmartphoneDao.getInstance().findByPriceLessThan(10) ) {
            System.out.print(smartphone);
        }

        SmartphoneDao.getInstance().save(new Smartphone(21,"Samsung galaxy 5", 15, false));


        SmartphoneDao.getInstance().deleteById(21);

        for (Smartphone smartphone : SmartphoneDao.getInstance().findAll() ) {
            System.out.print(smartphone);
        }

        System.out.println(ClientDao.getInstance().findById(3));


        ClientDao.getInstance().save(new Client(9,"Ksenia", "89200512066", 1));


        ClientDao.getInstance().deleteById(9);

        for (Client client : ClientDao.getInstance().findAll() ) {
            System.out.print(client);
        }
    }
}
