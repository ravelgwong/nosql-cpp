const { exec } = require("child_process");
const target = require("./target");

programNames = target.name;

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
