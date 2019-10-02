#!/usr/bin/env node

const express = require("express");
const http = require("http");

const documentRoot = process.env.DOCUMENT_ROOT || "/var/www";
const address = process.env.ADDRESS || "0.0.0.0";
const port = process.env.PORT || 80;

const app = express();

app.use(express.static(documentRoot));

app.get("/data", (req, res) => {
	try {
		res.status(200).send({
		});

	} catch (error) {
		res.status(500).send(error);
	}
});

const server = http.createServer(app);

server.listen(port, address, function() {
	console.log("Server is running at http://%s:%s/",
		server.address().address,
		server.address().port);
});
