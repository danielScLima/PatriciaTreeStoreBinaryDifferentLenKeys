PatriciaTreeStoreBinaryDifferentLenkeys
====================
Building with AppVeyor: [![Build status](https://ci.appveyor.com/api/projects/status/vulhclw3hkfbys8p?svg=true)](https://ci.appveyor.com/project/DanielSLima/patriciatreestorebinarydifferentlenkeys)

Building with Travis: [![Build Status](https://www.travis-ci.com/danielScLima/PatriciaTreeStoreBinaryDifferentLenKeys.svg?branch=master)](https://www.travis-ci.com/danielScLima/PatriciaTreeStoreBinaryDifferentLenKeys)

This repository has a project with the implementation of a PatriciaTreeStoreBinaryDifferentLenkeys.

It is written in C++.

The code of the PatriciaTreeStoreBinaryDifferentLenkeys is independent of platform.

Is has two possible main files:

* [Codes](#markdown-header)
	* [A main that triggers unit test;](#markdown-header-emphasis)

	* [A Qt project to manage the queue (With Gui).](#markdown-header-strikethrough)
	
The library used to make the Unit Test is the Catch v2.12.3. The code is already in this repository.

The Qt project generates images of the PatriciaTreeStoreBinaryDifferentLenkeys, using the lib Graphviz.
Install this lib in your computer for you to be able to create such images.

The code was written containing the Doxygen documentation.

- - -

You have several options to build the project: 
====================

* [Build tools](#markdown-header)
	* [Makefile (using the file named MakefileGeneral);](#markdown-header-emphasis)
	* [CMake.](#markdown-header-emphasis)
	* [Qt Project (With QMake).](#markdown-header-emphasis)

The project has no leaks (Fully tested with Valgrind).

All the unit tests are ok.

- - -


Qt gui project: 
====================
The qt gui application gui is shown below:

![Alt text](images/guisample.png)

Tree sample: 
====================
A sample of the tree is shown below:

![Alt text](images/sample.png)

- - -


The functionalities available are: 
====================

* [Functionalities](#markdown-header)
	* [Insert;](#markdown-header-emphasis)
	* [Search;](#markdown-header-emphasis)	
	* [Remove;](#markdown-header-emphasis)
	
- - -

Insertion demo steps: 
====================

## Initial

![Alt text](images/inserting/0.png)

## Inserting 01010

![Alt text](images/inserting/1.png)

## Inserting 01011

![Alt text](images/inserting/2.png)

## Inserting 11010

![Alt text](images/inserting/3.png)

## Inserting 11110

![Alt text](images/inserting/4.png)

## Inserting 11

![Alt text](images/inserting/5.png)

## Inserting 0101

![Alt text](images/inserting/6.png)

## Inserting 010

![Alt text](images/inserting/7.png)

- - -

Remove demo steps: 
====================

## Initial 

![Alt text](images/removing/0.png)

## Removing 11010

![Alt text](images/removing/1.png)

## Removing 11110

![Alt text](images/removing/2.png)

## Removing 01011

![Alt text](images/removing/3.png)

## Removing 01010

![Alt text](images/removing/4.png)


