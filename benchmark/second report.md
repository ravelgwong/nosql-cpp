# Progress Report 2 - C++ Project

Group Member:

1. Ravel Tanjaya 2301890320
2. Vincentius Gabriel 2301894804

## Introduction

Our project mainly focuses on finding which is the best data structure for storing specific non uniform data inside a nosql database.

## Current progress

All codes mentioned in this repository are available on https://github.com/ravelgwong/nosql-cpp

Up to this point of time, we mainly do the following things:

- Refine the features of the build system.
- finish benchmarking the data structure.
- choose with gui framework to use.

For our current progress of development going into our second report, we have made a number of changes towards our project and have begun moving forward towards a final application that will answer our provided problem. First of all, we have experimented with more data structures to better suit our benchmarking testss, these vary from the B-Tree, LSM Tree, Bloom Filter and currently the Cuckoo Filter which is undergoing testing. Within our current code, the structure's implementations are being added through online libraries, this was done to reduce workload and obtain results but these will be replaced by our own implementations in the final apllication. Additionally, we have made our first steps in creating a GUI application.

**The system is developed under unix based system , and command listed below may not run under Windows.**

_As development under windows is not possible, please use the online linux development environment on https://goor.me/1wDxJ_


### NodeJS build system

Currently we added a memory benchmarking system, previously we only do time based benchmark, adding memory benchmark allow us to understand deeper about our data structure.

We've also refined how the how the time benchmark run.

### Data Structure

There are 2 data structure that is going to be tested with this system, which is:

- Hash Table
- Cuckoo Filter


#### Cuckoo Filter
A cuckoo filter is a data structure that is typically used to check whether an item of data is a part of a set. A cuckoo filter is an optimization of the bloom filter, a similar structure but one that by standard, does not implement deletion. A cuckoo filter uses a 4-way set-associative hash table based on cuckoo hashing to store the fingerprints of all items. An advantage of using a cuckoo filter data structure over other structures such as a hash table is that it has a space advantage.

In this version we removed btree and lsmtree as we have trouble to make it work.


## Result

We are still not able to show the result of the benchmark as there is some structure benchmark that is not fully implemented

## GUI Toolkit

for this appication, we are also going to create the gui for the nosql database,
we have taken a look at several different gui toolkit such as:

_We only consider cross-platform gui for this app_

- WxWidgets
- Qt

After doing some research, we found out the following:

### Wxwidgets

A very mature gui framework, cross platform with a lot of bindings available.

Pro:

- Mature
- Native look and feel
- Fully free and open source

Cons:

- Uses gtk on x11 which will cause linux distro with non gtk+ desktop to look weird.
- Poor form designer
- Hard to learn

### QT

QT is a cross platform framework to build software with c++.

Pro:

- Cross platform (Desktop,mobile, and embedded)
- Free to use for open source projects
- bundled with qt creator (dedicated ide)
- Huge community
- great documentations
- Have a commercial version which is the same with open source, which means the software is commercial grade

Cons:


- Only free for open source projects
- quite pricy for commercial project

### Consideration

There are several consideration that we take into account before choosing the gui framework:

- QT is easier to learn
- Even though qt is expensive it's free for open source application (which we are)
- Wxwidget is harder to learn (especially considering the amount of time we had)
- It's easier to create gui with qt's ui designer

With this consideration, we concluded that we'll be using qt framework for the gui of the application

## Work Distribution

In this particular week, we distribute the workload with Vincent doing the creation of the data structure, and Ravel researching and doing the gui development
