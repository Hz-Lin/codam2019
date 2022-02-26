# philo

## Introduction 

The point of the project is to understand how to use multithreading and mutex locks using the dining philosophers problem as example.  
Each philosopher is represented by a thread and each fork by a mutex lock.  

The project is heavily reliant on the system's hardware. This should be taken into account when checking for sudden deaths that aren't intended or with very tight values ie. 2 201 100 100 or 3 180 60 60

When two philosophers go for the same fork at the same time they risk deadlocking, which leads to death as neither philosopher is able to grab the fork. This can be done by dividing philosophers up into priority groups. Philosophers with even numbers sleeps for a short while before trying to grab a fork.

[introduction parallel computing tutorial](https://hpc.llnl.gov/training/tutorials/introduction-parallel-computing-tutorial)

[POSIX Threads Programming](https://hpc-tutorials.llnl.gov/posix/)

## Terminology

- Thread management: Routines that work directly on threads - creating, detaching, joining, etc. They also include functions to set/query thread attributes (joinable, scheduling etc.)
- Mutexes: Routines that deal with synchronization, called a “mutex”, which is an abbreviation for “mutual exclusion”. Mutex functions provide for creating, destroying, locking and unlocking mutexes. These are supplemented by mutex attribute functions that set or modify attributes associated with mutexes.
- Condition variables: Routines that address communications between threads that share a mutex. Based upon programmer specified conditions. This group includes functions to create, destroy, wait and signal based upon specified variable values. Functions to set/query condition variable attributes are also included.
- Synchronization: Routines that manage read/write locks and barriers.

## PTHREAD Functions

### PTHREAD_CREATE

Creates a new thread, it will start running the start_routine function

**int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine) (void *), void *arg);**

- thread: This will contain the thread ID of the newly created thread
- attr: If NULL, default values are used, otherwise the given attributes are used to create the thread.
- start_routine: The function the newly created thread will execute
- arg: The only argument to the start_routine function

RETURN VALUE:
- succeeded: 0
- error: error number

### PTHREAD_JOIN

Specify a certain thread, the function halts until the thread terminates (if it is not already detached)

**int pthread_join(pthread_t thread, void **retval);**  
- thread: The thread we will wait for to terminate
- retval If not NULL, it will be filled with the exit status of the thread

RETURN VALUE:
- succeeded: 0
- error: error number

### PTHREAD_DETACH

Specify a certain thread, the thread is then marked as detached
this means it doesn't have to be joined for its resources to be released back to the system.

**int pthread_detach(pthread_t thread);**  
- thread: The thread specified is marked as detached

RETURN VALUE:
- succeeded: 0
- error: error number

## PTHREAD_MUTEX Functions

### PTHREAD_MUTEX_INIT

Creates a new mutex object

**int	pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *attr);**  
- mutex: A pointer to the mutex object you want to initialize
- attr: Optional attributes, NULL if you want to set default attributes

RETURN VALUE:
- succeeded: 0
- error: error number

### PTHREAD_MUTEX_DESTROY

Destroys (uninitializes) the mutex object

**int	pthread_mutex_destroy(pthread_mutex_t *mutex);**  
- mutex: The mutex object you want to destroy

RETURN VALUE:
- succeeded: 0
- error: error number

### PTHREAD_MUTEX_LOCK

Sets the state of the mutex object to locked, if it's not unlocked, the program will halt until it is unlocked.

**int	pthread_mutex_lock(pthread_mutex_t *mutex);**  
- mutex: The object you want to set as locked

RETURN VALUE:
- succeeded: 0
- error: error number

### PTHREAD_MUTEX_UNLOCK

Sets the state of the mutex object to unlocked.

**int	pthread_mutex_lock(pthread_mutex_t *mutex);**  
- mutex: The object you want to unlock.

RETURN VALUE:
- succeeded: 0
- error: error number

## pthread differences between exit, join and detach

- **pthread_exit** is called from the thread itself to terminate its execution (and return a result) early.
- **pthread_join** is called from another thread (usually the thread that created it) to wait for a thread to terminate and obtain its return value. It can be called before or after the thread you're waiting for calls **pthread_exit**. If before, it will wait for the exit to occur. If after, it simply obtains the return value and releases the pthread_t resources.
- **pthread_detach** can be called from either the thread itself or another thread, and indicates that you don't want the thread's return value or the ability to wait for it to finish. This is useful because otherwise, until you call **pthread_join**, the pthread_t value remains valid and consumes resources - at the very least, resources to store the return value and tying up one possible value of pthread_t. If you're using **pthread_detach**, normally you call it from either the new thread or the creating thread as soon as the new thread is created (right after **pthread_create**).

## usleep

**int usleep(useconds_t usec);**

The usleep() function suspends execution of the calling thread for (at least) usec microseconds. The sleep may be lengthened slightly by any system activity or by the time spent processing the call or by the granularity of system timers.  
Usleep can be very inaccurate as it's official definition is it will sleep for AT LEAST the amount of micro seconds given. In order to make a more accurate usleep one will have to alter it to compare the time passed to actual time and sleep in microseconds until the appropriate time is reached. The longer the usleep the more inaccurate it may become.
