var http = require("http");
http.createServer(function (request, response) {
	response.writeHead(200, {"Content-Type": "text/html; charset=utf-8"});
	response.write("<!DOCTYPE html>\n" +
		"<html>\n" +
		" <head>\n" +
		" <meta charset='utf-8'>\n" +
		" </head>\n" +
		" <body>\n"
	);

	response.write(
	"Smartphones table\n" +
	"<table>\n" +
	"<tr><th>id</th><th>name</th><th>price</th><th>available_in_stock</th></tr> \n" +
	"<tr><td>1</td><td>Samsung Galaxy A23 4/64GB</td><td>16</td><td>false</td></tr>\n " +
	"<tr><td>2</td><td>Xiaomi Redmi 9A 2/32GB</td><td>6</td><td>true</td></tr>\n " +
	"<tr><td>3</td><td>Xiaomi Redmi 10C 4/128GB</td><td>15</td><td>true</td></tr>\n " +
	"<tr><td>4</td><td>realme C30 4/64GB</td><td>10</td><td>false</td></tr>\n " +
	"<tr><td>5</td><td>POCO С40 3/32GB</td><td>9</td><td>true</td></tr>\n " +
	"<tr><td>6</td><td>Samsung Galaxy A33</td><td>18</td><td>true</td></tr>\n " +
	"<tr><td>7</td><td>ITEL A17</td><td>7</td><td>false</td></tr>\n " +
	"</table>\n" +
	"<br>\n" +
	"<br>\n" +

	"Clients table\n" +
	"<table>\n" +
	"<tr><th>id</th><th>name</th><th>smartphone_id</th><th>phone_number</th></tr> \n" +
	"<tr><td>1</td><td>Sergey</td><td>4</td><td>89200512051</td></tr>\n " +
	"<tr><td>2</td><td>Maxim</td><td>1</td><td>89200512053</td></tr>\n " +
	"<tr><td>3</td><td>Alena</td><td>15</td><td>89243542051</td></tr>\n " +
	"</table>\n"
	);

	response.end(
		" </body>\n" +
		"</html>\n"
	);
}).listen(3000);

console.log("Server running at http://localhost:3000/");