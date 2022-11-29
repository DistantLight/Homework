package sql.demo.Entity;

import javax.persistence.*;

@Entity
@Table(name = "smartphones")
public class Smartphone {
    @Id
    @Column(name = "id")
    private int id;
    @Column(name = "name")
    private String name;
    @Column(name = "price")
    private int price;
    @Column(name = "available_in_stock")
    private boolean availableInStock;

    public Smartphone(int id, String name, int price, boolean available_in_stock) {
        this.id = id;
        this.name = name;
        this.price = price;
        this.availableInStock = available_in_stock;
    }

    public Smartphone() {
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getPrice() {
        return price;
    }

    public void setPrice(int price) {
        this.price = price;
    }

    public boolean isAvailableInStock() {
        return availableInStock;
    }

    public void setAvailableInStock(boolean availableInStock) {
        this.availableInStock = availableInStock;
    }

    @Override
    public String toString() {
        return "Smartphone{" +
                "id=" + id +
                ", name='" + name + '\'' +
                ", price=" + price +
                ", available_in_stock=" + availableInStock +
                "} + \n";
    }
}
