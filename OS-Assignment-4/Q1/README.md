## Q1

# Dining Philosophers Problem

## Problem Description

The dining philosophers problem is a classic synchronization problem. It is a model for concurrent processes that compete for a limited number of resources.

In this problem, there are 5 philosophers sitting around a table. Each philosopher spends their life alternating between thinking and eating. In order to eat, a philosopher needs to pick up the two forks that are placed between them and their neighbors. However, each philosopher can only hold one fork at a time, and a philosopher cannot eat until they have both forks.

Additionally, there are 2 bowls at the center of the table. Each philosopher also needs to acquire a bowl in order to eat.

## Deadlocks

A deadlock can occur in this setup if each philosopher picks up the fork on their left at the same time. Since each philosopher holds one fork, none of them can start eating because they need two forks to eat. As a result, all philosophers will keep waiting indefinitely for the other fork to become available, leading to a deadlock.

## Solution to Avoid Deadlock

The provided solution avoids deadlock by imposing an order on how forks are picked up. Each philosopher, except the last one, picks up the fork on their left first, and then the fork on their right. The last philosopher picks up the fork on their right first, and then the fork on their left. This breaks the circular wait condition, preventing deadlock.

When a philosopher finishes eating, they put down both forks and release the bowl, allowing other philosophers to use them.

## Fairness and Performance

The solution is fair in the sense that every philosopher gets a chance to eat if they wait long enough. However, the frequency at which each philosopher gets to eat depends on the scheduling of threads by the operating system, which can be influenced by various factors and is generally not predictable.

In terms of performance, the maximum number of philosophers that can eat at the same time is equal to the number of bowls, since each philosopher needs a bowl to eat. Therefore, at most 2 philosophers can eat at the same time in this setup.

Please note that while this solution avoids deadlock and ensures that every philosopher can eventually eat, it does not guarantee that philosophers get to eat in a strictly alternating order or that they get to eat at regular intervals. The actual order and intervals at which philosophers eat can vary depending on the specifics of the system's thread scheduling behavior. However, over a long enough period of time, each philosopher should be able to eat roughly the same number of times. This is an inherent trade-off in this kind of concurrent system. To enforce a stricter eating order or regular eating intervals, additional synchronization mechanisms would be needed.



## Code Description

The code creates a thread for each philosopher. Each philosopher thinks for a second, then tries to get the forks on their left and right and a bowl. If they're successful, they eat for a second, then put the forks and the bowl down. This process repeats indefinitely.

The `get_forks_and_bowl` function uses a different order for philosopher 4 to avoid deadlock. The forks and bowls are represented by semaphores, which are initialized to 1 because each fork and bowl can be used by one philosopher at a time.

## How to Run

To compile the code, use the following command:

```bash
gcc q1.c
```

To run the compiled program, use the following command:

```bash
./a.exe
```

The program will run indefinitely. To stop it, press Ctrl+C.

## Output

The program prints a message every time a philosopher starts thinking or eating. For example:

```
Philosopher 0 is thinking
Philosopher 1 is thinking
Philosopher 2 is thinking
Philosopher 3 is thinking
Philosopher 4 is thinking
Philosopher 0 is eating
Philosopher 1 is eating
```

This indicates that philosophers 0 and 1 have successfully acquired their forks and a bowl and are currently eating, while philosophers 2, 3, and 4 are thinking.