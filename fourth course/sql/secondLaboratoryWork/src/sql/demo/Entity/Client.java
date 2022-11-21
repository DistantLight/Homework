package sql.demo.Entity;

public class Client {
    private int id;
    private String name;
    private int smartphoneId;
    private String phoneNumber;

    public Client(int id, String name, String phone_number, int smartphoneId) {
        this.id = id;
        this.name = name;
        this.smartphoneId = smartphoneId;
        this.phoneNumber = phone_number;
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

    public int getSmartphoneId() {
        return smartphoneId;
    }

    public void setSmartphoneId(int smartphoneId) {
        this.smartphoneId = smartphoneId;
    }

    public String getPhoneNumber() {
        return phoneNumber;
    }

    public void setPhoneNumber(String phoneNumber) {
        this.phoneNumber = phoneNumber;
    }

    @Override
    public String toString() {
        return "Client{" +
                "id=" + id +
                ", name='" + name + '\'' +
                ", smartphoneId=" + smartphoneId +
                ", phone_number=" + phoneNumber +
                '}';
    }
}
