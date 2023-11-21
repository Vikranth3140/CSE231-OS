import matplotlib.pyplot as plt
import numpy as np

process1_execution_time = 4.374246
process2_execution_time = 4.341518
process3_execution_time = 4.103305

scheduling_policies = ['SCHED_OTHER', 'SCHED_RR', 'SCHED_FIFO']
execution_times = [process1_execution_time, process2_execution_time, process3_execution_time]

policy_colors = {'SCHED_OTHER': 'b', 'SCHED_RR': 'g', 'SCHED_FIFO': 'r'}

figure, axis = plt.subplots()
bar_width = 0.4
index = np.arange(len(scheduling_policies))

for i, policy in enumerate(scheduling_policies):
    axis.bar(index[i], execution_times[i], bar_width, label=f'Policy: {policy}', color=policy_colors[policy])

axis.set_xlabel('Scheduling Policies')
axis.set_ylabel('Execution Time (s)')
axis.set_title('Execution Time vs Scheduling Policies')
axis.set_xticks(index)
axis.set_xticklabels(scheduling_policies)
axis.legend()

plt.show()