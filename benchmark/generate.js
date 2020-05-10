var faker = require("faker");
var fs = require("fs");
const { exec } = require("child_process");
const target = require("./target");

customers = [];
for (let i = 0; i < 100000; i++) {
  customers.push({
    money: faker.commerce.price(),
    firstname: faker.name.firstName(),
    lastname: faker.name.lastName(),
    email: faker.internet.email(),
  });
}

orders = [];
for (let i = 0; i < 100000; i++) {
  orders.push({
    email: customers[faker.random.number(customers.length - 1)].email,
    price: faker.commerce.price(),
    food: [faker.commerce.product(), faker.commerce.product()],
    status: faker.random.boolean() ? "waiting" : "finished",
  });
}

data = {
  orders: orders,
  customers: customers,
};

programNames = target.name;

programNames.forEach((e) => {
  fs.writeFile("codes/" + e + "/data.json", JSON.stringify(data), function (
    err
  ) {
    if (err) throw err;
    console.log("Data Saved!");
  });
});

fs.writeFile("data.json", JSON.stringify(data), function (err) {
  if (err) throw err;
  console.log("Data Saved!");
});
