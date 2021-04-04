---
## Assignment-6

**Team Members**
|  Enrollment No |   Name         | GithubId        |
 --------------  |   ----         | --------        |
|    IIT2019189  |   Nidhi Kamewar  | Nidhikamewar15         |
|    IIT2019190  |   Rishi Gupta   | InvincibleR18      | 
|    IIT2019191  |   Pechetti Venkata Karthik | iit2019191  |

**Group No-**"2"
**Faculty Name-**"Rahul kala"

**Mentor Name-** "Md. Meraz"

---
## Problem Statement

Given weights and values of n items we have to design an algorithm to find out the maximum value subset of the values of final items which must be included in the knapsack such that the total value of the weight of the final items included in the knapsack should be less than or equal to the given capacity of the knapsack
---
## How to use code
<br> To use this code on your computer, just clone this repository on your system, after which you can look all the resources such as report, ppt and c++ implementation of this problem statement. Just GitBash in the folder where you want to clone the repo and download it-
```
#Download project
https://github.com/Invincible/DAA-Assignments/C2_Assignment_06.git
```

---

Run the code
```
g++ code.cpp
./a.out
```

Input : 
```
Wt[] : 6 4 6 1 4
Val[] : 3 9 2 1 6
```
output : 
```
Maximum value of the items included in the knapsack such that the weight of the items included does not exceed the given weight of the knapsack.
```
---

### Test Cases
```
Test Case-1

Input: 
Wt[]: 10,20,30 
Val[]: 60,100,120

Output:
220

Test Case-2
Input: 
Wt[]: 6 4 6 1 4
Val[] : 3 9 2 1 6

Output:
10
```



### Theory
In this problem , we have to maximize the value of the items included in the knapsack such that the weight of the items included does not exceed the given weight of the knapsack.
The given problem has–
1)	Overlapping sub-problems of recalculating the total value sum of the items included in the knapsack for a given limit of the knapsack.
2)	Optimal substructure property i.e., the given problem can be solved by solving the sub problems of the problem.


---

### Analysis

**Time Complexity**
<br>
The algorithm-1 computes every possible subsets to find the solution to the main problem hence it takes O(2^n) time.
The algorithm-2 does not computes the solutions to the overlapping sub-problems instead looks for them in the lookup table which stores the values of sub-problems which occurred before, hence it takes O(n*cap) time.

**Space Complexity**
<br>
The algorithm-1 uses O(1) auxillary space as no extra data structure is required.
The algorithm-2 uses O(n*cap) auxillary space for the lookup table.
---

### References
https://www.geeksforgeeks.org/
<br>
Introduction to Algorithms (CLRS)
