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

After thinking about it for some time, I realize it would be better to externally define the structure as a function $f: E \to X$ where $E$ is the set of edges and $X$ is an arbitrary type. The same applies for nodes. This way we can equip the same graph with multiple structures without having multiple copies of the graph. So I get rid of ``ValuedNode`` and ``ValuedEdge`` and introduce ``GraphStructure``.

I start adding some methods that start to clarify the interface of ``Graph``. Now that the most basic operations are completed, I can write some tests and a makefile, and make sure it compiles.

I start to think more about how graph structures will be affected by altering the graph. More specifically, how ``EdgeWeights`` will behave when the graph is changed (edges are added/removed). In order for the external structure to remain usable at all, the unaffected nodes and edges must be accessible in the same way they were before. I decide that they will be stored in an associative array and indexed by ID. Storing them in an array with ID indexing works the same, until elements are removed and the indices suddenly change for certain objects.

Thus I implement the ``Map`` adapter class, since ``std::map`` and ``std::unordered_map`` may not be optimal candidates and I might use a 3rd party implementation.

Next I start thinking of how I'm going to organize the algorithms that operate on graphs. Since there could be potentially many algorithms, I want to keep them in a folder separate from the graph and graph structures.

As I further develop the interface of ``Graph`` I realize a lot of comments become out of date due to behavioral changes of some functions. Now I understand what "The Clean Coder" was talking about.

## The Great Redesign

I got embarrassingly far before noticing all the shortcomings of the initial design. As I think about how to actually write algorithms for the graph structure, I realize graph traversal is quite difficult. In addition to that, there is the problem of desynchronization between the graph and its structure. A structure (e.g. edge weights) initialized on a graph is not updated when the graph is manipulated.

To solve this, I make ``Graph`` an abstract data type whose interface contains traversal-related methods. I couldn't find a simple universal method to synchronize the graph and its external structures, so I make ``Graph`` a constant structure and completely delegate graph manipulation to the initial construction.

While I further abstract the ``Graph`` class, I un-abstract how nodes and edges are referred to. Since the graph will not be further modified after creation, nodes can be represented by an unsigned integer from ``0`` to ``numNodes - 1``. Edges are a trivial pair of nodes, and there is no need to make an entire class for it.

After this redesign, development went much more smoothly and I finished up a couple algorithms with test programs. All that's left is to write some documentation.

# Takeaway

This project wasn't exactly life-changing, but I learned again the importance of having a good initial design to build off of. This pretty much concludes my first test project on here, I don't plan on having my next projects be so trite.
