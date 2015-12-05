Map Format
==========

We use a very simple format to represent our map (i.e. a graph). It is not intended to be reusable, it just does the work for what we want. Its main advantage is to be parsable like a csv file.

The syntax is:

<code>
nodes:
nameNode1,x1,y1[,z1]
nameNode2,x2,y2[,z2]
nameNode3,x3,y3[,z3]
…
edges:
nameNode1,nameNode3
nameNode2,nameNode1,nameNode3
nameNode3,nameNode2
</code>

To summarize:
* two sections delimited by the keywords "nodes:" and "edges:"
* nodes section is a list of nodes with their coordinates
* edges section is actually a list of adjacency lists (one for each node)
  <code>
  nameNode1,nameNode3
  nameNode2,nameNode1,nameNode3
  </code>
  means that one can go from node1 to node3 (but not from node3 to node1) and from node2 to node1 and node3.

An example:

<code>
[BLE3] ---------- [BLE4]
  |             /    ^
  |          /       |
  |       /          |
  |    /             |
[BLE1] ---------> [BLE2]
</code>

corresponds to something like:

<code>
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
</code>
