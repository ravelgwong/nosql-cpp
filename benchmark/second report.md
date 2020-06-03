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
- {ADDNAME}

In this version we removed btree and lsmtree as we have trouble to make it work.

#### {ADDNAME}

## Result

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
