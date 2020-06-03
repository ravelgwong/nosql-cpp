# Progress Report 1 - C++ Project

Group Member:

1. Ravel Tanjaya 2301890320
2. Vincentius Gabriel 2301894804

## Introduction

Our project mainly focuses on finding which is the best data structure for storing specific non uniform data inside a nosql database.

## Current progress

All codes mentioned in this repository are available on https://github.com/ravelgwong/nosql-cpp

Up to this point of time, we mainly do the following things:

- Nodejs based build system to automate the build process.
- A hyperfine based benchmark system.
- Random Data generation based on faker.js.
- 3 data structure that is going to be tested with random generated data (Not all data structure have been implemented).

For our current progress of development going into our second report, we have made a number of changes towards our project and have begun moving forward towards a final application that will answer our provided problem. First of all, we have experimented with more data structures to better suit our benchmarking testss, these vary from the B-Tree, LSM Tree, Bloom Filter and currently the Cuckoo Filter which is undergoing testing. Within our current code, the structure's implementations are being added through online libraries, this was done to reduce workload and obtain results but these will be replaced by our own implementations in the final apllication. Additionally, we have made our first steps in creating a GUI application.

**The system is developed under unix based system , and command listed below may not run under Windows.**

_As development under windows is not possible, please use the online linux development environment on https://goor.me/1wDxJ_


### NodeJS build system

Currently to test the speed and efficiency of the data structure nodejs is used to automate the whole process including the building, generation of random data and benchmarking.

In order to use these scripts please make sure you have installed the following:

- NodeJs
- npm
- Hyperfine

To use this script please first, change directory to the benchmark folder with:

`cd benchmark`

the use npm to install all of the required depedency.

`npm install`

to install all required npm depedencies.

#### Automatically build all of the codes

To automatically build all of the available codes, we can run this command:

`npm run build`

The script will change directory to each of the codes and will use gcc to build all files with c++17 standard.

#### Generate the random data

The random data that is generated is of JSON(Javascript object notation) these data will later be loaded by the programs and used as a sample data to measure the speed of each data structure.

To generate/regenerate these random data please run:

`npm run generate`

#### Benchmarking

In order to benchmark, please make sure you have already build for the latest changes and generate the json data,then run:

`npm run benchmark`

### Data Structure

There are 2 data structures that are going to be tested with this system, which is:


- Cuckoo Filter
- Hash Table

#### Cuckoo Filter
A cuckoo filter is a data structure that is typically used to check whether an item of data is a part of a set. A cuckoo filter is an optimization of the bloom filter, a similar structure but one that by standard, does not implement deletion. A cuckoo filter uses a 4-way set-associative hash table based on cuckoo hashing to store the fingerprints of all items. An advantage of using a cuckoo filter data structure over other structures such as a hash table is that it has a space advantage.


#### Hash Table

A hash table is a data structure which stores data in an associative manner. In a hash table, the data is stored in an array format, where each data value has its own unique index value. The data inside a hash table is stored in key value pairs. It uses a technique called hashing to generate the indexes where these key value pairs are then stored.
An advantage of using a Hash Table is that they are efficient for inserting and searching data. However, when running into collisions they become quite inefficient.

## Result

There are 2 data structures, that are currrently being tested:

1. Btree (Build Failed)
2. LSM Tree (Build Failed)
3. Hash Table (Build Passing)
4. Cuckoo Filter(Build in Final Stages)
The test itself currently consisted of:

1. Insertion test (Implemented)
2. Deletion test (Implemented)

| Command                              |      Mean [ms] | Min [ms] | Max [ms] |         Relative |
| :----------------------------------- | -------------: | -------: | -------: | ---------------: |
| `codes/bTree/bTree BUILD FAILED`     |      2.3 ± 0.7 |      1.7 |      5.1 |      1.20 ± 0.37 |
| `codes/hashTable/hashTable`          | 9196.6 ± 162.1 |   9009.8 |   9300.7 | 4796.34 ± 256.59 |
| `codes/lsmTree/lsmTree BUILD FAILED` |      1.9 ± 0.1 |      1.7 |      2.6 |             1.00 |
| `codes/cuckooFilter/cuckooFilter` | 24.658 ± 0.657 | 24.159 | 25.403 | 1.07 ± 0.03 |
