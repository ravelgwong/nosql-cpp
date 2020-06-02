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

**The system is developed under unix based system , and command listed below may not run under Windows.**

_As development under windows is not possible, please use the online linux development environment on https://goor.me/1wDxJ_

### NodeJS build system

Currently we added a memory benchmarking system, previously we only do time based benchmark, adding memory benchmark allow us to understand deeper about our data structure.

We've also refined how the how the time benchmark run.

### Data Structure

There are 2 data structure that is going to be tested with this system, which is:

- Hash Table

In this version we removed btree and lsmtree as we have trouble to make it work.

#### Hash Table

A hash table is a data structure which stores data in an associative manner. In a hash table, the data is stored in an array format, where each data value has its own unique index value. The data inside a hash table is stored in key value pairs. It uses a technique called hashing to generate the indexes where these key value pairs are then stored.
An advantage of using a Hash Table is that they are efficient for inserting and searching data. However, when running into collisions they become quite inefficient.

## Result

## GUI Toolkit

for this appication, we are also going to create the gui for the nosql database,
we have taken a look at several different gui toolkit such as:

_We only consider cross-platform gui for this app_

- WxWidgets
- Qt
- Nana

After doing some research, we found out the following:

### Wxwidgets

A very mature gui framework, cross platform.

### QT

### Nana

Finally after some consideration we have choosen to use Qt, because:

- Cross platform (Desktop,mobile, and embedded)
- Free to use for open source projects
- bundled with qt creator (dedicated ide)
- Huge community
- great documentations
