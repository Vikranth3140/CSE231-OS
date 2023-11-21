<html>
<h1>Process Scheduling</h1>
<p>This program explores different scheduling policies (SCHED_OTHER, SCHED_RR, SCHED_FIFO) by executing three processes with distinct scheduling policies: <code>process1</code>, <code>process2</code>, and <code>process3</code>. The execution times of these processes under each scheduling policy are measured and plotted to compare their performance.</p>

<h2>Program Logic</h2>

<p>The <code>main.c</code> file is the main program that forks three child processes (<code>process1</code>, <code>process2</code>, <code>process3</code>) and measures the execution time for each process under different scheduling policies. It utilizes <code>clock_gettime</code> for time measurement and <code>waitpid</code> for process synchronization.</p>

<p><code>process1.c</code>, <code>process2.c</code>, and <code>process3.c</code> are similar in structure. They set the scheduling policy (<code>SCHED_OTHER</code>, <code>SCHED_RR</code>, <code>SCHED_FIFO</code>, respectively) using <code>sched_setscheduler</code> and then execute the <code>count</code> program.</p>

<p><code>count.c</code> simply performs a count loop and prints a message every 1,000,000,000 counts.</p>

<h2>How to Run</h2>

<p>To compile and run the program, use the provided <code>Makefile</code>. Use the following commands:</p>

<pre><code>make run
</code></pre>

<p>This will compile the necessary programs and execute the main program, which forks child processes with different scheduling policies.</p>

<p>To clean up compiled files, use:</p>

<pre><code>make clean
</code></pre>

<h2>Outcome Analysis</h2>

<p>The <code>histogram.py</code> script generates a histogram comparing the execution times for each process under the different scheduling policies. The resulting plot visually demonstrates the impact of scheduling policies on execution time.</p>

<h2>Outputs</h2>

<p>The program will output the execution time for each process under the corresponding scheduling policy:</p>

<ul>
    <li>Execution time (SCHED_OTHER): ... seconds</li>
    <li>Execution time (SCHED_RR): ... seconds</li>
    <li>Execution time (SCHED_FIFO): ... seconds</li>
</ul>

<p>Additionally, the <code>histogram.py</code> script will generate and display a histogram illustrating the execution times for each process under the different scheduling policies.</p>

<p>Feel free to adjust the <code>process1_execution_time</code>, <code>process2_execution_time</code>, and <code>process3_execution_time</code> variables in <code>histogram.py</code> to match your actual measurements for a more accurate histogram.</p>

</html>
