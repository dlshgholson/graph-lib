# graph-lib

A simple graph library written in C++. This library is probably not going to be very useful or efficient, but I want to document my development process as thoroughly as possible. In the development process I change my mind a lot and you will read a lot of self-contradictions.

# Rambling

## Initial Plan

At first, the primary planned features are:

- Constructing a graph with helper functions.
    - ``Graph.addNode``
    - ``Graph.addDirectedEdge``
- Implement various algorithms on a graph (note a lot of these will require some extension from the base graph structure).
    - BFS, DFS.
    - ``isConnected()``, ``isAcyclic()``.
    - Dijkstra's shortest path.
    - MST.
    - Ford Fulkerson's max flow.

## Early Development

After starting the node class I realize we need a way to compare nodes without them necessarily holding a value. Perhaps a unique ID will be generated for each node constructed. The same applies to edges.

We want to be able to extend nodes and edges to hold a value, but not initially require it. Thus I introduce ``ValuedNode`` and ``ValuedEdge`` which hold a value as a protected member.

After thinking about it for some time, I realize it would be better to externally define the structure as a function \(f: E \to X\) where \(E\) is the set of edges and \(X\) is an arbitrary type. The same applies for nodes. This way we can equip the same graph with multiple structures without having multiple copies of the graph. So I get rid of ``ValuedNode`` and ``ValuedEdge`` and introduce ``GraphStructure``.

I start adding some methods that start to clarify the interface of ``Graph``. Now that the most basic operations are completed, I can write some tests and a makefile, and make sure it compiles.
