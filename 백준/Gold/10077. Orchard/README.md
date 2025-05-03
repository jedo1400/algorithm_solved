# [Gold V] Orchard - 10077 

[문제 링크](https://www.acmicpc.net/problem/10077) 

### 성능 요약

메모리: 2200 KB, 시간: 140 ms

### 분류

누적 합

### 제출 일자

2025년 5월 3일 13:49:09

### 문제 설명

<p>Alex and Bert are brothers who had been working for many years in a big orchard of their uncle where they planted trees. The orchard is arranged as an array of size n by m of trees. Alex had been planting apple trees and Bert had been planting banana trees; however, the brothers were not systematic and so apple trees stand among banana trees and vice versa. Each of them has planted at least one tree.</p>

<p>When coming near to retirement, the uncle decided to officially transfer the ownership of the trees to the brothers. The uncle informed the brothers that he will first pass the orchard to Alex. Next, Alex and Bert can cut out a rectangular area from the orchard, and the ownerships of all trees in the rectangular area are to be transferred to Bert. All further adjustments of the splitting had to be done with a lawyer.</p>

<p>Alex would like to keep all apple trees and Bert would like to keep all banana trees, but do not want to replant any tree. When they talked to a lawyer, the lawyer informed them that the ownership of a tree can be transferred from one owner to another, but the lawyer would charge <span>$</span>1 to transfer the ownership of a tree. Therefore the brothers try to place the starting rectangle such that the legal fees are as low as possible.</p>

<p>The following figures show three examples, where 0 and 1 indicates an apple and banana tree respectively.</p>

<table class="table table-bordered" style="width: 100%;">
	<tbody>
		<tr>
			<td style="width: 33%; text-align: center; vertical-align: middle;"><img alt="" src="https://upload.acmicpc.net/2c39d542-b9e3-45e2-b144-fb314b06d874/-/preview/" style="width: 92px; height: 107px;"></td>
			<td style="width: 34%; text-align: center; vertical-align: middle;"><img alt="" src="https://upload.acmicpc.net/db53d755-72ae-41d4-a7f7-d089ab5fcd55/-/preview/" style="width: 129px; height: 96px;"></td>
			<td style="width: 33%; text-align: center; vertical-align: middle;"><img alt="" src="https://upload.acmicpc.net/8e114562-87ea-4dfa-b70b-af92f2edc929/-/preview/" style="width: 161px; height: 37px;"></td>
		</tr>
		<tr>
			<td style="width: 33%; text-align: center;">Example 1</td>
			<td style="width: 34%; text-align: center;">Example 2</td>
			<td style="width: 33%; text-align: center;">Example 3</td>
		</tr>
	</tbody>
</table>

<p>In the first example, the best way is to cut out the fourth column and to assign it to Bert, as indicated by the rectangular outline. Afterwards, there are two trees that are out of place, and their ownerships have to be transferred – one banana tree from Alex to Bert and one apple tree from Bert to Alex. Hence, the fees are <span>$</span>2.</p>

<p>In the second example, the best way is to cut out trees that are not at the border of the field and then to transfer the ownership of six trees. The fees are <span>$</span>6.</p>

<p>In the third example, the best way is to cut out the rectangle consisting of 3 banana trees, and then to transfer the ownership of the rightmost banana tree to Bert. The fee is <span>$</span>1. Note that there is an alternative way that costs <span>$</span>1 as well.</p>

### 입력 

 <p>Your program must read from standard input. The first line of the input are the two positive numbers n and m indicating the orchard’s size. Then follow n lines each consisting of m numbers, where 0 represents an apple tree and 1 represents a banana tree.</p>

### 출력 

 <p>You program must write to the standard output a number, which is the smallest fee required.</p>

