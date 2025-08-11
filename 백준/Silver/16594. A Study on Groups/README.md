# [Silver II] A Study on Groups - 16594 

[문제 링크](https://www.acmicpc.net/problem/16594) 

### 성능 요약

메모리: 2412 KB, 시간: 12 ms

### 분류

그리디 알고리즘, 정렬

### 제출 일자

2025년 8월 12일 01:30:34

### 문제 설명

<p>You are given a bag of N integers, and you are to put these integers into M distinct groups. When you distribute the integers, you have to make sure that each integer belongs to exactly one group and the size of any two different groups differs by at most 1.</p>

<p>The cost of a group is equal to the lowest integer in that group, while the total cost of M groups simply equals to the summation of the cost of each group. Note that the cost of an empty group is zero.</p>

<p>Now, your task in this problem is to find a way to put N given integers (not necessarily unique) into M distinct groups such that the total cost of those groups is minimum. Also, find a way such that the total cost is maximum. Output only the total costs.</p>

### 입력 

 <p>Input begins with two integers: N M (1 ≤ N, M ≤ 100000) representing the number of given integers and the number of groups to be made, respectively. The next line contains N integers: A<sub>i</sub> (0 ≤ A<sub>i</sub> ≤ 1000000) representing the given integers.</p>

### 출력 

 <p>Output in a line two integers (separated by a single space) representing the minimum total cost and the maximum total cost, respectively.</p>

