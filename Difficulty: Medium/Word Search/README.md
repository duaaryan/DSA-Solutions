<h2><a href="https://www.geeksforgeeks.org/problems/word-search/1">Word Search</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO" style="--text-color: var(--problem-text-color);"><p><span style="font-size: 14pt;">You are given a matrix <strong>mat[][]</strong> of size <strong>n*m</strong> containing english alphabets and a string word. Check if the word exists<strong> </strong>on the mat[][] or not. </span></p>
<ul>
<li><span style="font-size: 14pt;">The word can be constructed by using letters from adjacent cells, either horizontally or vertically. </span></li>
<li><span style="font-size: 14pt;">The same cell cannot be used more than once.</span></li>
</ul>
<p><span style="font-size: 14pt;"><strong>Examples :</strong></span></p>
<pre><span style="font-size: 14pt;"><strong style="font-size: 14pt;">Input: </strong><span style="font-size: 14pt;">mat[][] = [['T', 'E', 'E'], ['S', 'G', 'K'], ['T', 'E', 'L']], word = "GEEK"
</span><strong style="font-size: 14pt;">Output: </strong><span style="font-size: 14pt;">true
</span><strong style="font-size: 14pt;">Explanation: </strong><span style="font-size: 18.6667px;">Word "GEEK" can be found in the given grid as follows.</span><span style="font-size: 14pt;">
<img src="https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/886266/Web/Other/blobid4_1737981964.png" alt="" width="220" height="200"><br></span></span></pre>
<pre><span style="font-size: 14pt;"><strong style="font-size: 14pt;">Input: </strong><span style="font-size: 14pt;">mat[][] = [['T', 'E', 'U'], ['S', 'G', 'K'], ['T', 'E', 'L']], word = "GEEK"
</span><strong style="font-size: 14pt;">Output: </strong><span style="font-size: 14pt;">false
</span><strong style="font-size: 14pt;">Explanation: </strong><span style="font-size: 18.6667px;">Word "GEEK" cannot be found in the given grid.</span><span style="font-size: 14pt;">
<img src="https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/886266/Web/Other/blobid5_1737981964.png" alt="" width="220" height="199"></span></span></pre>
<pre><span style="font-size: 14pt;"><strong style="font-size: 14pt;">Input: </strong><span style="font-size: 14pt;">mat[][] = [['A', 'B', 'A'], ['B', 'A', 'B']], word = "AB"
</span><strong style="font-size: 14pt;">Output: </strong><span style="font-size: 14pt;">true
</span><strong style="font-size: 14pt;">Explanation: </strong><span style="font-size: 18.6667px;">There are multiple ways to construct the word "AB".</span><span style="font-size: 14pt;">
<img src="https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/886266/Web/Other/blobid6_1737981964.png" alt="" width="222" height="184"><br></span></span></pre>
<p><span style="font-size: 14pt;"><strong style="font-size: 14pt;">Constraints:</strong><br><span style="font-size: 14pt;">1 ≤ n, m ≤ 6</span><br><span style="font-size: 14pt;">1 ≤ word.size() ≤ 15<br>mat[] and word contain bot lower case and uppercase English characters</span></span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Amazon</code>&nbsp;<code>Microsoft</code>&nbsp;<code>Intuit</code>&nbsp;<code>Apple</code>&nbsp;<code>NPCI</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Recursion</code>&nbsp;<code>DFS</code>&nbsp;<code>Graph</code>&nbsp;<code>Backtracking</code>&nbsp;