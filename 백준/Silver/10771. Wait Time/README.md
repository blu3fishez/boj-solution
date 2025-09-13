# [Silver III] Wait Time - 10771 

[문제 링크](https://www.acmicpc.net/problem/10771) 

### 성능 요약

메모리: 32412 KB, 시간: 32 ms

### 분류

구현, 자료 구조, 시뮬레이션

### 제출 일자

2025년 9월 14일 01:14:05

### 문제 설명

<p>You exchange text messages with your friends. Since you receive so many messages, you want to measure how long your friends have to wait for your replies.</p>

<p>Your message device records each received and sent message in order using the following two kinds of entries:</p>

<ul>
	<li><code>R X</code> indicates a message was received from a friend numbered X;</li>
	<li><code>S X</code> indicates a message was sent to a friend numbered X.</li>
</ul>

<p>Your message device sends and receives messages instantaneously, and for each consecutive pair of entries described above, either</p>

<ul>
	<li>a single entry <code>W X</code> is recorded in between them indicating they occur X seconds apart, or</li>
	<li>there is no entry between them and they occur one second apart.</li>
</ul>

<p>Several rules of message etiquette are always followed:</p>

<ul>
	<li>the only messages you send are replies to messages that you have received;</li>
	<li>you send at most one reply to any message from any particular friend;</li>
	<li>your friends do not send a subsequent message until you have replied to their previous message.</li>
</ul>

<p>The wait time for a message is the time that passes between when you receive it and the time you reply to it. If a friend X received a reply to each message they sent, the total wait time for friend X is the sum of all wait times for all messages from friend X. Otherwise, the total wait time for friend X is −1.</p>

<p>Your job is to determine the total wait time for each friend.</p>

### 입력 

 <p>The input consists of the integer M (1 ≤ M ≤ 20), followed by M lines, where each line consists of one character (<code>W</code>, <code>R</code>, or <code>S</code>), followed by a space, followed by an integer X (1 ≤ X ≤ 100). These M lines are the entries described above (in order).</p>

### 출력 

 <p>Output one line for each friend that sent a message in the form X T where X is a friend number and T is the total wait time for friend X. The lines are in increasing order of the friend numbers.</p>

