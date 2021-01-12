import queue
import threading
import time

exitFlag = 0

def print_time(threadName, delay, counter):
    while counter:
        if (exitFlag):
            threadName.exit()

        time.sleep(delay)
        print("%s: %s" % (threadName, time.ctime(time.time())))
        counter -= 1

# Simple Threads
class SimpleThread (threading.Thread):
    def __init__(self, threadID, name, counter, delay):
        threading.Thread.__init__(self)
        self.threadID = threadID
        self.name = name
        self.counter = counter
        self.delay = delay

    def run(self):
        print("Starting " + self.name)
        print_time(self.name, self.delay, self.counter)
        print("Exiting " + self.name)

# Create new threads
thread1 = SimpleThread(1, "Thread-1", 5, 1)
thread2 = SimpleThread(2, "Thread-2", 5, 2)

# Start new Threads
thread1.start()
thread2.start()
thread1.join()
thread2.join()

print()

# Synchronizing Threads
class SynchronizingThread (threading.Thread):
    def __init__(self, threadID, name, counter, delay):
        threading.Thread.__init__(self)
        self.threadID = threadID
        self.name = name
        self.counter = counter
        self.delay = delay

    def run(self):
        print("Starting " + self.name)
        threadLock.acquire()    # Get lock to synchronize threads
        print_time(self.name, self.delay, self.counter)
        threadLock.release()    # Free lock to release next thread
        print("Exiting " + self.name)

threadLock = threading.Lock()
threads = []

# Create new threads
thread3 = SynchronizingThread(1, "Thread-3", 3, 2)
thread4 = SynchronizingThread(2, "Thread-4", 3, 3)

# Start new Threads
thread3.start()
thread4.start()

# Add threads to thread list
threads.append(thread3)
threads.append(thread4)

# Wait for all threads to complete
for t in threads:
   t.join()

print()