from threading import Thread, Semaphore
from math import ceil, sqrt

sem = Semaphore()
primes = []
begin = 10
end = 20
size = end - begin

def isPrime(a):

    for i in range(2, ceil(sqrt(a))):
        if a % i == 0:
            return
    sem.acquire()
    primes.append(a)
    sem.release()

threads = []

for i in range(begin, end):
    t = Thread(target = isPrime, args = (i,))
    threads.append(t)
    t.start()
    
    
for t in threads:
    t.join()

for p in primes:
    print(p)
