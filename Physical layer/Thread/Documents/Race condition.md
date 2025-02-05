# One thread function handler to increase a shared value

```cpp
#include <iostream>
#include <thread>

#define RANGE 1000000

int shared_value;

void thread_func()
{
    for (int i = 0; i < RANGE; i++) shared_value++;
}

int main()
{
    std::thread thread_1(thread_func), thread_2(thread_func);
    thread_1.join();
	thread_2.join();
	printf("shared_value after executing 2 threads: %d\n", shared_value);
    return 0;
}
```
**Result**: ``share_value after executing 2 threads: 1053188`` (expected ``2000000``)

# [std::mutex](Mutex.md)

Use [std::mutex::lock](Mutex.md#lock) for [one thread function handler to increase a shared value](#one-thread-function-handler-to-increase-a-shared-value).

# std::atomic

An atomic operation is an indivisible operation. CPP atomic provides atomic types and operations that ensure safe access to variables, preventing data races and potential issues in multithreaded code, allowing threads to access and modify variables safely, without explicit locks or synchronization mechanisms.

Use std::atomic for [one thread function handler to increase a shared value](#one-thread-function-handler-to-increase-a-shared-value):

```cpp
#include <iostream>
#include <thread>
#include <atomic>

#define RANGE 1000000

std::atomic<int> shared_value;

void thread_func()
{
    for (int i = 0; i < RANGE; i++) shared_value++;
}

int main()
{
	shared_value = 0;// Must init value inside main(), not init globally
    std::thread thread_1(thread_func), thread_2(thread_func);
    thread_1.join();
	thread_2.join();
	std::cout << shared_value << std::endl;
    return 0;
}
```
**std::atomic_int** can also be used, as **std::atomic_int** is simply as typedef of **std::atomic<int>** 
```cpp
std::atomic_int shared_value; 
```
# Producer and consumer problem

Given a buffer, i.e a vector, where the **producer thread** writes data to it for every TIME_INTERVAL seconds. The **consumer thread** will pop out the data from that buffer to read, whenever that buffer isn't empty. A synchronization mechanism like [condition variable](Mutex.md#condition-variable) is needed to apply so that the **consumer thread** can know when to start reading from the buffer, e.g whenever the **consumer thread** has written data to the buffer, instead of checking the buffer for the data repeatedly.

**Program**: [producer_consumer.cpp](../src/producer_consumer.cpp)
# Deadlock
Deadlock doesn't occur when using a mutex for 2 threads to print odd and even numbers respectively: [deadlock_with_mutex_for_threads_print_odd_and_even_numbers.cpp](../src/deadlock_with_mutex_for_threads_print_odd_and_even_numbers.cpp)
