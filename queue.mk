a.out: driver.o queue_imp.o
       gcc driver.o queue_impl.o

driver.o: driver.c queue.h
	  gcc -c driver.c

queue_impl.o: queue_impl.c queue.h
	      gcc -c queue_impl.c