Map Format
==========

We use a very simple format to represent our map (i.e. a graph). It is not intended to be reusable, it just does the work for what we want.

The syntax is:

```
nodes:
nameNode1,x1,y1[,z1]
nameNode2,x2,y2[,z2]
nameNode3,x3,y3[,z3]
…
edges:
nameNode1,nameNode3
nameNode2,nameNode1,nameNode3
nameNode3,nameNode2
```

To summarize:
* two sections delimited by the keywords `nodes:` and `edges:`
* nodes section is a list of nodes with their coordinates
* edges section is actually a list of adjacency lists (one for each node)

An example:

```
[BLE3] ---------- [BLE4]
  |             /    ^
  |          /       |
  |       /          |
  |    /             |
[BLE1] ---------> [BLE2]
```

corresponds to something like:

```
nodes:
beacon1,0.0,0.0
beacon2,0.0,1.0
beacon3,1.0,0.0
beacon4,1.0,1.0
edges:
beacon1,beacon2,beacon3,beacon4
beacon2,beacon4
beacon3,beacon1,beacon4
beacon4,beacon3,beacon1
```
