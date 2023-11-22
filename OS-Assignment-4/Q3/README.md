# Thin Bridge Crossing Simulation

Q3 simulates cars crossing a thin bridge between two sides of a river. The bridge allows only one car to travel from the left side to the right and vice versa at any given time. Additionally, a maximum of five cars is allowed to travel on the bridge simultaneously. If two cars from opposite sides attempt to cross simultaneously, they will be unable to cross, and travel will halt.

## Program Structure

### Semaphores

1. `bridge`: Controls access to the bridge, limiting the number of cars allowed at once.
2. `left_queue` and `right_queue`: Ensure that only one car from each side can queue up for the bridge.
3. `opposite_dir`: Ensures that cars from opposite sides cannot cross simultaneously.
4. `left_mutex` and `right_mutex`: Control access to the respective queues and ensure mutual exclusion.
5. `queue_barrier`: Limits the number of cars allowed in the queue at any given time.

### Threads

- **Left Thread (`left`):** Represents cars on the left side. Waits for access to the bridge, then queues up, crosses the bridge, and releases the bridge. A delay is introduced before the next car starts crossing to ensure the 6th car from the left starts only after the 5th car has crossed.

- **Right Thread (`right`):** Similar to the left thread but for cars on the right side.

### Passing Function

The `passing` function simulates a car crossing the bridge. It prints information about the car, sleeps for one second (simulating crossing time), and prints that the car has crossed.

## Avoiding Concurrency Bugs

1. **Semaphore Usage:** Semaphores are used to manage access to critical sections of the code, ensuring mutual exclusion and proper synchronization between threads.

2. **Queue Mechanism:** A queue-like mechanism is implemented to regulate the order in which cars access the bridge, preventing race conditions and deadlocks.

3. **Barrier for Queue Limit:** A semaphore (`queue_barrier`) is employed to limit the number of cars allowed in the queue, avoiding contention issues.

4. **Delay for Sequential Crossing:** A delay is introduced before allowing the next car to start crossing, ensuring the 6th car from the left starts only after the 5th car has crossed. This helps in maintaining the order and avoiding concurrency issues.

## How to Run

To compile the code, use the following command:

```bash
gcc q1.c
```

To run the compiled program, use the following command:

```bash
./a.exe
```

Enter the number of cars on the left side and on the right side of the bridge

Adjustments to the delay can be made in the code based on specific requirements.