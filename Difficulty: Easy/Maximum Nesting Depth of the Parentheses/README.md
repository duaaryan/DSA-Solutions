<h2><a href="https://www.geeksforgeeks.org/problems/maximum-nesting-depth-of-the-parentheses/1">Maximum Nesting Depth of the Parentheses</a></h2><h3>Difficulty Level : Difficulty: Easy</h3><hr><div class="problems_problem_content__Xm_eO" style="--text-color: var(--problem-text-color);"><p><span style="font-size: 18px;">Given a valid arithmetic expression <strong>s</strong> consisting of digits, operators, and parentheses, determine the maximum nesting depth of the parentheses.</span></p>
<p><span style="font-size: 18px;">The nesting depth is defined as the maximum number of opening parentheses '(' that are open simultaneously at any position while traversing the expression from left to right.</span></p>
<p><span style="font-size: 18px;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 18px;"><span style="font-size: 18px;"><strong>Input: </strong>s = "((5+2)(3+4)((6)))"<strong>
Output: </strong>3<strong>
Explanation: </strong>The digit 6 is enclosed within three pairs of parentheses, so the maximum nesting depth is 3.</span></span></pre>
<pre><span style="font-size: 18px;"><span style="font-size: 18px;"><strong>Input</strong>: s = "(43+4++3)((3)(9))+1"
<strong>Output</strong>: 2
<strong>Explanation</strong>: <br>The deepest level of nesting in the expression is 2. <br>Both the digits 3 and 9 in the second part of the expression are enclosed within two pairs of parentheses.</span>
</span></pre>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>1 ≤ |s| ≤ 100<br>s consists of digits <strong>0-9</strong> and characters '<strong> + </strong>' , '<strong> - </strong>' ,<strong> </strong>'<strong> * </strong>' , '<strong> / </strong>' , '<strong> ( </strong>' , and '<strong> ) </strong>'.<br></span></p>
<div id="professor_prebid-root"></div></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Strings</code>&nbsp;<code>Stack</code>&nbsp;