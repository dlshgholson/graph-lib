# Intro

Welcome to graph-lib. The project is small enough that I expect all guides to go in this file.

# Build and Structure

The only requirement to build is a g++ compiler capable of building C++20. In the root directory simply run ``make``. After building, the basic structure should contain the following directories:

- ``docs``: documentation.
- ``include``: header files.
- ``lib``: the final ``libGraph.a`` to be used in other projects.
- ``obj``: the compiled ``.o`` files.
- ``src``: definition files.
- ``tests``: test programs.

Feel free to change the compiler flags in the makefile accordingly, I did not separate debug and optimized builds.

# Graph

The ``Graph`` class is the crux of this library. It is an abstract class with some methods to view node and edge info. Graphs were designed to be equipped with additional structure such as edge weights, node positions, and so on. These structures are defined externally without using inheritance since algorithms require different combinations of these structures to be passed around.

Due to limitations in synchronizing graphs with external structures, the ``Graph`` interface is designed so that modifications to the graph cannot be made (although child classes can manually add non-const methods at their own risk). Thus once an instance of (a child class of) ``Graph`` has been created, its structure is solidified so that external structures can build up their own state.

# External Structures and Algorithms

The (quite few) default stateless algorithms are defined in ``/include/algos.h``, with additional classes being declared in their own headers such as ``BFS`` and ``Dijkstra``. Since this project is mostly creating the framework itself, I don't add too many algorithms and external structures. The project design allows easily adding new structures however.

