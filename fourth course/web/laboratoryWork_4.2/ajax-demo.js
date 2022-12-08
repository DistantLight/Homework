var http = require("http");
var fs = require("fs");
var sqlite3 = require("sqlite3").verbose();
var db = new sqlite3.Database("SmartphoneStore.db");
// request, response
http.createServer(function (req, res) {
	console.log("request: " + req.url);
	let body;
	switch(req.url) {
		case "/":
			fs.readFile("./ajax_demo.html", function(err, content) {
				if(!err) {
					res.writeHead(200, {"Content-Type": "text/html; charset=utf-8"});
					res.end(content, "utf-8");
				} else {
					res.writeHead(500, {"Content-Type": "text/html; charset=utf-8"});
					res.end(err.message, "utf-8");
					console.log(err);
				}
			});
			break;
		case "/filterRecords":
			body = "";
			req.on('data', d => body += d);
			req.on('end', () => {
				let sqlString = "SELECT * FROM smartphones WHERE price =" + body;
				db.all(sqlString,function(err, rows){
					res.writeHead(200, {"Content-Type": "application/json; charset=utf-8"});
					res.write(JSON.stringify(rows));
					res.end();
				});
			});
			break;	
			case "/showAll":
				body = "";
				req.on('data', d => body += d);
				req.on('end', () => {
					let sqlString = "SELECT * FROM smartphones";
					db.all(sqlString,function(err, rows){
						res.writeHead(200, {"Content-Type": "application/json; charset=utf-8"});
						res.write(JSON.stringify(rows));
						res.end();
					});
				});
				break;	
		default:
				res.writeHead(404, {"Content-Type": "text/html; charset=utf-8"});
				res.write("<!DOCTYPE html>\n" +
					"<html>\n" +
					" <head>\n" +
					" <meta charset='utf-8'>\n" +
					" </head>\n" +
					" <body>\n"
				);
				res.write("404, NOT FOUND: " + req.url);
				res.end(
					" </body>\n" +
					"</html>\n");
	}
}).listen(3000);

console.log("Server running at http://localhost:3000/");