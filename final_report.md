# Final Report - C++ Project

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

There are 2 data structure that is going to be tested with this system, which is:

- Hash Table
- Hash Tree

#### B Tree

A B-Tree is a variation of the binary search tree that allows nodes to have more than two children, it is a self balancing data structure where all the children are on the same level. It maintains sorted data sand allows insertions, deletions and searches.
Some advantages of using B-Trees include sorted keys for traversing, balances the index through a recursive algorithm, it does this through the movement and splitting of elements. However, B-Trees are also quite inefficient since deleting and inserting elements involves lots of movement between the key/values.

#### LSM Tree

An LSM tree also known as a log structured merge tree is a data structure composed of two or more tree like structures that is used for large volume log data, data that lists changes within a database, LSM trees store this data in key/value pairs like other data structures.
Some advantages of using an LSM tree over other data structures are its higher insert rates and better compression. However, data compaction which is the reduction of data elements, one good example is how we shorten our texts in every day life using acroyms, interferes with reads and writes.

#### Hash Table

A hash table is a data structure which stores data in an associative manner. In a hash table, the data is stored in an array format, where each data value has its own unique index value. The data inside a hash table is stored in key value pairs. It uses a technique called hashing to generate the indexes where these key value pairs are then stored.
An advantage of using a Hash Table is that they are efficient for inserting and searching data. However, when running into collisions they become quite inefficient.

## Result

There are 3 data structure to be tested:

1. Hash Tree (Build Passing)
2. Hash Table (Build Passing)

The test itself currently consisted of:

1. Insertion test (Implemented)
2. Deletion test (Implemented)

| Command | Mean [s] | Min [s] | Max [s] | Relative |
|:---|---:|---:|---:|---:|
| `codes/hashTable/hashTable` | 27.574 ± 2.311 | 24.941 | 29.266 | 1.08 ± 0.10 |
| `codes/hashTree/hashTree` | 32.561 ± 1.098 | 29.301 | 34.855 | 1.00 |