var sqlite3 = require("sqlite3").verbose();
//var db = new sqlite3.Database(":memory:");
var db = new sqlite3.Database("SmartphoneStore.db");


db.run(
	"CREATE TABLE IF NOT EXISTS smartphones (" +
	"id INT PRIMARY KEY," +
	"name VARCHAR(128)," +
	"price INT," +
	"available_in_stock BOOLEAN " +
	");", function(err) {
if(err) {
	console.log(err);
} else {
	var stmt = db.prepare("INSERT INTO smartphones VALUES (?, ?, ?, ?)");
	stmt.run(1, 'Samsung Galaxy A23 4/64GB', 16, false);
	stmt.run(2, 'Xiaomi Redmi 9A 2/32GB', 6, true);
	stmt.run(3, 'Xiaomi Redmi 10C 4/128GB', 15, true);
	stmt.run(4, 'realme C30 4/64GB', 10 ,false);
	stmt.run(5, 'Xiaomi Redmi 9C 3/64GB', 9, false);
	stmt.run(6, 'Motorola DEFY', 18, true);
	stmt.run(7, 'POCO С40 3/32GB', 7, true);
	stmt.run(8, 'Samsung Galaxy A33', 24, false);
	stmt.run(9, 'ITEL A17', 12, true);
	stmt.run(10, 'Xiaomi Redmi Note 11 Pro', 34, false);
	stmt.run(11, 'POCO M4 Pro 5G 6/128GB', 20, true);
	stmt.run(12, 'Apple iPhone 13 Pro 256GB', 90, false);
	stmt.run(13, 'Xiaomi Redmi 10C', 13, false);
	stmt.run(14, 'TECNO Spark 8c 4/64GB', 8, true);
	stmt.run(15, 'ITEL A25', 5, true);
	stmt.run(16, 'Infinix HOT 11S NFC 6/128GB', 16, true);
	stmt.run(17, 'Nokia G21 4/64GB', 13, false);
	stmt.run(18, 'TECNO Spark Go', 7, true);
	stmt.run(19, 'Huawei P50 8/256GB', 250, true);
	stmt.run(20, 'TECNO Pova 3 6/128GB', 16, false);
	stmt.finalize();

	console.log("created db: SmartphoneStore.db");
}
db.close();
});