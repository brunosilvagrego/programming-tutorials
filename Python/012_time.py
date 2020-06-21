import time
import calendar

# time.time()
print("time.time() = ", time.time())    # Epoch
print()

# time.localtime()
print("time.localtime() = ", time.localtime())
print()

# time.asctime()
print("time.asctime() = ", time.asctime())
print()

# time.altzone - This method returns the offset of the local DST timezone, in seconds west of UTC, if one is defined.
print("time.altzone = ", time.altzone)
print()

# time.sleep()
t0 = time.time()
time.sleep(1.5)
print("Elapsed Time = ", time.time() - t0)
print()

# time.gmtime()
print("time.gmtime() = ", time.gmtime())
print()

# time.mktime()
t = (2020, 6, 21, 10, 13, 38, 1, 48, 0)
print("time.mktime(t) = ", time.mktime(t))
print()

# time.strftime()
print(time.strftime("%b %d %Y %H:%M:%S", time.localtime()))
print()

# time.strftime()
print(time.strptime("21 06 2020", "%d %m %Y"))
print()

# calendar.month()
cal = calendar.month(1993, 4)
print(cal)
print()

# calendar.calendar()
cal = calendar.calendar(2020)
print(cal)
print()