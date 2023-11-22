## Q2

# Ride-Sharing Program

## Problem Description
This problem contains a solution to a ride-sharing scenario with a car and multiple passengers using threads and semaphores in C. The ride-sharing system consists of a car and a queue for passengers to board and unboard.

#### Program Components:

1. **Semaphore Initialization:**
    - `car_mutex`: Semaphore to ensure exclusive access to critical sections.
    - `board_queue`: Semaphore for managing the boarding queue.
    - `unboard_queue`: Semaphore for managing the unboarding queue.

2. **Main Function:**
   - Takes user input for the total number of passengers and car capacity.
   - Initializes semaphores.
   - Creates a thread for the car and multiple threads for passengers.
   - Waits for threads to finish.
   - Destroys semaphores.

3. **Car Function (`car`):**
   - Loops indefinitely to simulate continuous car rides.
   - Loads passengers onto the car by posting to the `board_queue` semaphore.
   - Waits for passengers to finish unboarding by waiting on the `unboard_queue` semaphore.
   - Starts the ride, simulates ride duration, unloads passengers, and notifies passengers to unboard.

4. **Passenger Function (`passenger`):**
   - Waits for the car to signal boarding by waiting on the `board_queue` semaphore.
   - Boards the car, signals unboarding, waits for the car to finish the ride, and then unboards.

5. **Load, Unload, Board, and Offboard Functions:**
   - Functions simulating the car's loading, unloading, and passengers boarding and offboarding actions.
   - Include sleep statements to simulate real-world time durations.

#### Concurrency Management:

1. **Mutex (`car_mutex`):**
   - Ensures exclusive access to critical sections, preventing multiple threads from accessing shared variables simultaneously.

2. **Semaphores (`board_queue` and `unboard_queue`):**
   - Used for synchronization between the car and passengers.
   - Passengers wait on the `board_queue` semaphore until the car signals boarding.
   - The car waits on the `unboard_queue` semaphore until passengers signal unboarding.
   - Prevents race conditions and ensures orderly boarding and unboarding.

#### How Concurrency Bugs are Avoided:

1. **Semaphore Usage:**
   - Semaphores are employed to control access to shared resources, preventing conflicts.
   - Ensures that passengers board and unboard in a synchronized manner.

2. **Mutex for Critical Sections:**
   - The `car_mutex` semaphore ensures that critical sections are accessed by only one thread at a time, preventing race conditions.

3. **Synchronization with Semaphores:**
   - Proper use of semaphores ensures that the car and passengers synchronize their actions, avoiding inconsistencies.

## Building and Running

1. **Compile the Code**:

   ```bash
   gcc q2.c
   ```

2. **Run the Executable**:

   ```bash
   ./a.out
   ```

   Enter the number of passengers and maximum capacity of car to simulate the problem

### Additional Notes:

- The program includes sleep statements to simulate real-time delays.
- Proper synchronization is achieved through semaphores, preventing concurrency issues.
- The program may run indefinitely and should be manually terminated.

