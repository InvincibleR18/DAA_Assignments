
---
## Assignment-5

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

Given a string S, count the number of non-empty sub strings that are palindromes. 
A sub string is any continuous sequence of characters in the string. A string is said 
to be palindrome, if the reverse of the string is same as itself. Two sub strings are 
different if they occur at different positions in S. Solve using Dynamic 
programming.

---
## How to use code
<br> To use this code on your computer, just clone this repository on your system, after which you can look all the resources such as report, ppt and c++ implementation of this problem statement. Just GitBash in the folder where you want to clone the repo and download it-
```
#Download project
https://github.com/Invincible/DAA-Assignment-5.git
```

---

Run the code
```
g++ code.cpp
./a.out
```

Input : 
```
Enter length of string(a random string of this length will be generated and used).
You can uncomment line 101: cin>>s; in the code.cpp file to give a string as manual input.
```
output : 
```
Number of non-empty substrings that are palindromes.
```
---

### Test Cases
```
Test Case-1
Input: 
abaab
Output:
3
Test Case-2
Input: 
abbaeae
Output:
4
```



### Theory
In this problem,we have to find the count of all the substrings of a given string which are palindromic. A sub string is any continuous sequence of characters in the string. A string is said to be palindrome, if the reverse of the string is same as itself.As the given problem has Overlapping subproblems of recalculating the palindromic substrings of substrings in the given string and Optimal substructure property i.e the given problem can be solved by  solving the subproblems of the problem
Hence We can solve the given problem using Dynamic programming.


---

### Analysis

**Time Complexity**
<br>
The algorithm will have a O(n^2) time complexity where n is the length of the string. This is because all possible substrings are being visited and are checked whether they are a palindrome or not. The total number of substrings is n*(n+1)/2 which is in the order of n^2. Using the memorization table, it can be checked whether a substring is palindrome or not in O(1). Hence, the total time complexity is O(n^2).


**Space Complexity**
<br>
The algorithm will have a O(n^2) space complexity where n is the length of the string.This is because a memorization table (n x n 2d array) is used to store the results of the 
sub-problems.Therefore, O(n^2) auxiliary space is required.

---

### References
https://www.geeksforgeeks.org/count-palindrome-sub-strings-string/
<br>
Introduction to Algorithms by Thomas.H.cormen



