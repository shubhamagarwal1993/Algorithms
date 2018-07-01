var http = require('http');

var server = http.createServer(function(req, res) {
    res.writeHead(200, {"Content-Type": "text/html"});
    res.write('<!DOCTYPE html>'+
        '<html>'+
        ' <head>'+
        ' <meta charset="utf-8" />'+
        ' <title>My Node.js page!</title>'+
        ' </head>'+ 
        ' <body>'+
        ' <p>Hi i am <strong>priii</strong>!</p>'+
        ' </body>'+
        '</html>');
    res.end();
});
server.listen(8080);

// defining object using object literal
var human = {
    firstName: "abcd",
    lastName: "efgh",
    age: 30,
    fullName: function() {
        return this.firstName + " " + this.lastName
    }
}

