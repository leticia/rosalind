## [IPRB](https://rosalind.info/problems/iprb/)

### Problem

Probability is the mathematical study of randomly occurring phenomena. We will model such a phenomenon with a random variable, which is simply a variable that can take a number of different distinct outcomes depending on the result of an underlying random process.

For example, say that we have a bag containing 3 red balls and 2 blue balls. If we let _X_ represent the random variable corresponding to the color of a drawn ball, then the probability of each of the two outcomes is given by _Pr(X=red)=3/5_ and _Pr(X=blue)=2/5_.

Random variables can be combined to yield new random variables. Returning to the ball example, let _Y_ model the color of a second ball drawn from the bag (without replacing the first ball). The probability of _Y_ being red depends on whether the first ball was red or blue. To represent all outcomes of _X_ and _Y_, we therefore use a probability tree diagram. This branching diagram represents all possible individual probabilities for _X_ and _Y_, with outcomes at the endpoints ("leaves") of the tree. The probability of any outcome is given by the product of probabilities along the path from the beginning of the tree; see Figure 2 for an illustrative example.

An event is simply a collection of outcomes. Because outcomes are distinct, the probability of an event can be written as the sum of the probabilities of its constituent outcomes. For our colored ball example, let A be the event "Y is blue." _Pr(A)_ is equal to the sum of the probabilities of two different outcomes: _Pr(X=blue and Y=blue)+Pr(X=red and Y=blue)_, or _3/10+1/10=2/5_ (see Figure 2 above).

**Given**: Three positive integers _k_, _m_, and _n_, representing a population containing _k+m+n_ organisms: _k_ individuals are homozygous dominant for a factor, _m_ are heterozygous, and _n_ are homozygous recessive.

**Return**: The probability that two randomly selected mating organisms will produce an individual possessing a dominant allele (and thus displaying the dominant phenotype). Assume that any two organisms can mate.

#### Sample Dataset

`2 2 2 `

#### Sample Output

`0.78333`
