# [Gold V] Change Making - 17600 

[문제 링크](https://www.acmicpc.net/problem/17600) 

### 성능 요약

메모리: 2412 KB, 시간: 16 ms

### 분류

다이나믹 프로그래밍, 그리디 알고리즘

### 제출 일자

2025년 8월 8일 23:28:30

### 문제 설명

<p>The change-making problem is a classical competitive programming problem. The problem is about a currency system. In this system, there are n available denominations of coins <span>$</span>c<sub>1</sub>, <span>$</span>c<sub>2</sub>, . . . , <span>$</span>c<sub>n</sub> where c<sub>1</sub> = 1 and c<sub>2</sub>, . . . , c<sub>n</sub> are all integers. Assume you can have unlimited supply of each denomination of coins. The change-making problem is: given a target x, make a change of <span>$</span>x with minimum number of coins.</p>

<p>The change-making problem has appeared so many times in programming contest. Many contestants know how to solve this problem. However, there are also many contestants doing it wrongly. For example, many of them use greedy algorithm which does not work. This greedy algorithm repeatedly takes the coin with greatest value which does not exceed x. This algorithm actually works for some currency system but not for this case: <span>$</span>1, <span>$</span>3, <span>$</span>4 and the target x = 6. We call such case a counterexample to this greedy algorithm, and x = 6 is a witness of the currency system <span>$</span>1, <span>$</span>3, <span>$</span>4.</p>

<p>Please write a program to find the minimum witness for a given currency system. If there does not exist a witness or the minimum witness is greater than 10<sup>5</sup>, your program should output −1.</p>

### 입력 

 <p>The first line contains an integer n to indicate the number of denominations in the currency system. The second line contains n integers c<sub>1</sub>, . . . , c<sub>n</sub> where the currency system has <span>$</span>c<sub>1</sub>, . . . , <span>$</span>c<sub>n</sub>.</p>

### 출력 

 <p>Output the minimum witness x if x ≤ 10<sup>5</sup>. Otherwise output −1.</p>

