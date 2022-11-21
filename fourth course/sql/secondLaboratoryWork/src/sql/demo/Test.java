package sql.demo;

import sql.demo.Entity.Client;
import sql.demo.Entity.Smartphone;
import sql.demo.dao.ClientDao;
import sql.demo.dao.SmartphoneDao;

import java.util.Optional;

public class Test {


    public static void main(String[] args) {


        //SmartphoneDao.getInstance().deleteById(20);

        //SmartphoneDao.getInstance().save(new Smartphone(20, "TECNO Pova 3 6/128GB", 16, false));

        Optional<Smartphone> smartphone1 = SmartphoneDao.getInstance().findById(3);
        System.out.println(smartphone1.get());

        for (Smartphone smartphone : SmartphoneDao.getInstance().findAll() ) {
            System.out.print(smartphone.getId() + " ");
            System.out.print(smartphone.getName() + " ");
            System.out.print(smartphone.getPrice() + " ");
            System.out.print(smartphone.isAvailable_in_stock() + " ");
            System.out.println();
        }

        for (Smartphone smartphone : SmartphoneDao.getInstance().findByPriceLessThan(10) ) {
            System.out.print(smartphone.getId() + " ");
            System.out.print(smartphone.getName() + " ");
            System.out.print(smartphone.getPrice() + " ");
            System.out.print(smartphone.isAvailable_in_stock() + " ");
            System.out.println();
        }

        for (Client client : ClientDao.getInstance().findAll() ) {
            System.out.print(client.getId() + " ");
            System.out.print(client.getName() + " ");
            System.out.print(client.getPhoneNumber() + " ");
            System.out.print(client.getSmartphoneId() + " ");
            System.out.println();
        }

        Optional<Client> client = ClientDao.getInstance().findById(3);
        System.out.println(client.get());
    }
}
