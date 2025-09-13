# graph-lib

A simple graph library written in C++. This library is probably not going to be very useful or efficient, but I want to document my development process as thoroughly as possible.

# Development Process

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

## Rambling

After starting the node class I realize we need a way to compare nodes without them necessarily holding a value. Perhaps a unique ID will be generated for each node constructed. The same applies to edges.

We want to be able to extend nodes and edges to hold a value, but not initially require it. Thus I introduce ``ValuedNode`` and ``ValuedEdge``.
