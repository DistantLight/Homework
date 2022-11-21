package sql.demo.Entity;

public class Smartphone {

    private int id;
    private String name;
    private int price;
    private boolean available_in_stock;

    public Smartphone(int id, String name, int price, boolean available_in_stock) {
        this.id = id;
        this.name = name;
        this.price = price;
        this.available_in_stock = available_in_stock;
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

    public boolean isAvailable_in_stock() {
        return available_in_stock;
    }

    public void setAvailable_in_stock(boolean available_in_stock) {
        this.available_in_stock = available_in_stock;
    }

    @Override
    public String toString() {
        return "Smartphone{" +
                "id=" + id +
                ", name='" + name + '\'' +
                ", price=" + price +
                ", available_in_stock=" + available_in_stock +
                '}';
    }
}
