## [SUBS](https://rosalind.info/problems/subs/)

### Problem

Given two strings _s_ and _t_, _t_ is a substring of _s_ if _t_ is contained as a contiguous collection of symbols in _s_ (as a result, _t_ must be no longer than _s_).

The position of a symbol in a string is the total number of symbols found to its left, including itself (e.g., the positions of all occurrences of 'U' in "AUGCUUCAGAAAGGUCUUACG" are 2, 5, 6, 15, 17, and 18). The symbol at position _i_ of s is denoted by _s[i]_.

A substring of _s_ can be represented as _s[j:k]_, where _j_ and _k_ represent the starting and ending positions of the substring in s; for example, if _s = "AUGCUUCAGAAAGGUCUUACG"_, then _s[2:5] = "UGCU"_.

The location of a substring _s[j:k]_ is its beginning position _j_; note that t will have multiple locations in _s_ if it occurs more than once as a substring of _s_ (see the Sample below).

**Given**: Two DNA strings _s_ and _t_ (each of length at most 1 kbp).

**Return**: All locations of _t_ as a substring of _s_.

#### Sample Dataset

```
GATATATGCATATACTT
ATAT
```

#### Sample Output

`2 4 10`
