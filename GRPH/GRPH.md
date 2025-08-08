## [GRPH](https://rosalind.info/problems/grph/)

### Problem

A graph whose nodes have all been labeled can be represented by an adjacency list, in which each row of the list contains the two node labels corresponding to a unique edge.

A directed graph (or digraph) is a graph containing directed edges, each of which has an orientation. That is, a directed edge is represented by an arrow instead of a line segment; the starting and ending nodes of an edge form its tail and head, respectively. The directed edge with tail _v_
and head _w_ is represented by _(v,w)_ (but not by _(w,v)_). A directed loop is a directed edge of the form _(v,v)_.

For a collection of strings and a positive integer _k_, the overlap graph for the strings is a directed graph _O(k)_ in which each string is represented by a node, and string _s_ is connected to string _t_ with a directed edge when there is a length _k_ suffix of s that matches a length _k_ prefix of _t_, as long as _s≠t_; we demand _s≠t_ to prevent directed loops in the overlap graph (although directed cycles may be present).

**Given**: A collection of DNA strings in FASTA format having total length at most 10 kbp.

**Return**: The adjacency list corresponding to _O(3)_. You may return edges in any order.

#### Sample Dataset

```
>Rosalind_0498
AAATAAA
>Rosalind_2391
AAATTTT
>Rosalind_2323
TTTTCCC
>Rosalind_0442
AAATCCC
>Rosalind_5013
GGGTGGG
```

#### Sample Output

```
Rosalind_0498 Rosalind_2391
Rosalind_0498 Rosalind_0442
Rosalind_2391 Rosalind_2323
```
