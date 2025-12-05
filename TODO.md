---
title: TODO
---

- [x] Establish basic set of features.
- [x] Create general file structure.
- [x] Create makefile.
- [x] Compiles, but fix linker error(s).
- [ ] Complete ``isEquivalentTo()``.
    - Turns out this is the *graph isomorphism problem* and is currently thought to be strictly NP-Hard. I don't bother writing a brute force search.
- [ ] Add the following algorithms:
    - [x] ``bool isStronglyConnected(Graph)``
    - [x] ``bool isWeaklyConnected(Graph)``
    - [x] BFS.
    - [ ] DFS.
    - [x] ``bool isAcyclic(Graph)``.
    - [x] ``std::vector<Node> topologicalSort(Graph)``.
    - [x] Dijkstra's shortest path.
