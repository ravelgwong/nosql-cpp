const { exec } = require("child_process");
const target = require("./target");

programNames = target.name;

console.log("Compiling files...");
programNames.forEach((element) => {
  exec(
    "cd codes/" +
      element +
      " && g++ *.cpp *.hpp -o " +
      element +
      " && cd ../..",
    (error, stdout, stderr) => {
      if (error) {
        console.log(`Error: ${error.message}`);
        return;
      }
      if (stderr) {
        console.log(`Error: ${stderr}`);
        return;
      }
      console.log("Succesfully compiled " + element);
    }
  );
});
