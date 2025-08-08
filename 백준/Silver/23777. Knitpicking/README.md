# [Silver I] Knitpicking - 23777 

[문제 링크](https://www.acmicpc.net/problem/23777) 

### 성능 요약

메모리: 2164 KB, 시간: 0 ms

### 분류

구현, 자료 구조, 집합과 맵, 많은 조건 분기, 해시를 사용한 집합과 맵, 비둘기집 원리

### 제출 일자

2025년 8월 8일 20:55:50

### 문제 설명

<p>Kattis has many pairs of nice, warm, knit socks in her sock drawer that are perfect for the winter. These socks come in a wide range of colours and types, and have all been mixed together. Each morning Kattis needs to pick two matching socks.</p>

<p>To find matching socks, she simply randomly takes single socks out of the drawer until she has a matching pair. It may take a long time, for example when she keeps drawing right socks without a matching left one. How long does she need to keep drawing socks until she is guaranteed to have a pair to wear?</p>

### 입력 

 <p>The input consists of:</p>

<ul>
	<li>One line with an integer $n$ ($1 \leq n \leq 1\,000$), the number of groups of identical socks.</li>
	<li>$n$ lines, each describing a group of identical socks with the following:
	<ul>
		<li>A string $i$, the type of the socks in the group. The type $i$ consists of between $1$ and $20$ lowercase English letters. Socks with the same type are considered compatible for fashion purposes.</li>
		<li>A string $j$, the fit of the socks in the group, which is either <code>left</code>, <code>right</code> or <code>any</code>, indicating whether the socks fit on the left foot, the right foot or any foot.</li>
		<li>An integer $k$ ($1\leq k \leq 1\,000$), the number of socks in the drawer that are of this type and fit.</li>
	</ul>
	</li>
</ul>

<p>A given fit of a given type of sock appears at most once in the input.</p>

### 출력 

 <p>Output the minimum number of socks Kattis needs to draw to be guaranteed to get a matching pair. If it is not possible to get a matching pair at all, output <code>impossible</code>.</p>

