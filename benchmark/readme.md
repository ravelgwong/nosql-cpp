# Benchmarking
## Requirement
**Important: Some scripts here are written with UNIX spesific command, these *will not run* on Windows based machine**
- NodeJs & NPM
- UNIX system (Linux/MacOs)
- G++

## Usage
### Installation
To install the required library for node js please run:

`npm install`

### Commands
#### Building all source files
All source files to be tested for benchmarking are available on the code/ directory.</br></br>
**If you want to add a new test target:**
1. Create a new directory inside the codes/ directory and add your files inside
2. Add your folder name to target.js in this directory.

**PLEASE NOTE THAT EACH CODE FOLDER WILL NEED TO PROVIDE A HPP AND CPP FILE.**

**To build all files at once please run:**</br></br>
`npm run build`

#### Benchmarking
To benchmark the all files, please build all files and run this command:</br></br>
`npm run benchmark`
</br></br>This will result in a new file ./result.md in the directory

#### Generating Random Data
To generate random data please use:</br></br>
`npm run generate`
