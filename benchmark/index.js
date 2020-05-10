var faker = require("faker");
var fs = require("fs");
const { exec } = require("child_process");
const target = require("./target");

customers = [];
for (let i = 0; i < 10000; i++) {
  customers.push({
    money: faker.commerce.price(),
    firstname: faker.name.firstName(),
    lastname: faker.name.lastName(),
    email: faker.internet.email(),
  });
}

orders = [];
for (let i = 0; i < 10000; i++) {
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

console.log("Running benchmarks...");

getPath = () => {
  x = "";
  programNames.forEach((element) => {
    x += "codes/" + element + "/" + element + " ";
  });
  return x;
};

exec(
  "hyperfine -w 2 -m 3 --export-markdown result.md " + getPath(),
  (error, stdout, stderr) => {
    if (error) {
      console.log(`Error: ${error.message}`);
    }
    if (stderr) {
      console.log(`Warning: ${stderr}`);
    }
    console.log("Benckmark Finished, please open result.md to see result");
  }
);
