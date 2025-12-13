# philosophers

### Description:
Basics of threading a process: Learn how to create threads and explore the use of mutexes.
The [philosophers problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem), is "an example problem (created by Edsger Dijkstra as a student exam exercise) often used in concurrent algorithm design to illustrate synchronization issues and techniques for resolving them".

### Requirements:
- Rules:
  - Your program(s) must take the following arguments:
    - number_of_philosophers: The number of philosophers and also the number of forks.
    - time_to_die (in milliseconds): If a philosopher has not started eating within time_to_die milliseconds since the start of their last meal or the start of the simulation, they die.
    - time_to_eat (in milliseconds): The time it takes for a philosopher to eat. During that time, they will need to hold two forks.
    - time_to_sleep (in milliseconds): The time a philosopher will spend sleeping.
    - number_of_times_each_philosopher_must_eat (optional argument): If all philosophers have eaten at least number_of_times_each_philosopher_must_eat times, the simulation stops. If not specified, the simulation stops when a philosopher dies.
  - Each philosopher has a number ranging from 1 to number_of_philosophers.
  - Philosopher number 1 sits next to philosopher number number_of_philosophers. Any other philosopher, numbered N, sits between philosopher N - 1 and philosopher N + 1.
  - Any state change of a philosopher must be formatted as follows:
    - timestamp_in_ms X has taken a fork
    - timestamp_in_ms X is eating
    - timestamp_in_ms X is sleeping
    - timestamp_in_ms X is thinking
    - timestamp_in_ms X died
  - A displayed state message should not overlap with another message.
  - A message announcing a philosopher’s death must be displayed within 10 ms of their actual death.
  - Again, philosophers should avoid dying!


### Learning process:
Key things learned from this project:
- Threads
- Race conditions
- Deadlocks: To prevent them I used the resource ordering solution
- Mutexes
- Parallelism and concurrency

### Useful sources:
- These video tutorials about [threads](https://www.youtube.com/watch?v=d9s_d28yJq0&list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2).

### Testing:
- Besides using valgrind for memory leaks, helgrind is useful to detect race conditions and other thread errors (`valgrind --tool=helgrind ./exec args`) .
