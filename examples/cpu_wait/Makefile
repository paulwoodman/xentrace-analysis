CC=gcc -g -Wall -m32
INC=-I../../include

OBJS=	Event.o\
	EventHandler.o\
	Reader.o\
	CpuList.o\
	Switch_infprev.o\
	Switch_infnext.o\
	Domain_wake.o\
	Switch_sched.o\
	Lost_records.o

vpath %.h ../../include
vpath %.h .
vpath %.c ../../src
vpath %.c .

all: main.c $(OBJS) Macros.h Externals.h
	$(CC) $(INC) $<  *.o -o ../../bin/Cpu_wait.out	
	rm -f *.o

Event.o: Event.c Event.h Macros.h
	$(CC) $(INC) -c $< -o $@

EventHandler.o: EventHandler.c EventHandler.h Macros.h list.h
	$(CC) $(INC) -c $< -o $@

Reader.o: Reader.c Reader.h Macros.h
	$(CC) $(INC) -c $< -o $@

CpuList.o: CpuList.c CpuList.h list.h Event.h
	$(CC) $(INC) -c $< -o $@

Switch_infprev.o: Switch_infprev.h Switch_infprev.c Macros.h Externals.h
	$(CC) $(INC) -c Switch_infprev.c

Switch_infnext.o: Switch_infnext.h Switch_infnext.c Macros.h Externals.h
	$(CC) $(INC) -c Switch_infnext.c

Domain_wake.o: Domain_wake.h Domain_wake.c Macros.h Externals.h Switch_sched.h
	$(CC) $(INC) -c Domain_wake.c

Switch_sched.o: Switch_sched.h Switch_sched.c Macros.h Externals.h Switch_infnext.h Switch_infprev.h Domain_wake.h
	$(CC) $(INC) -c Switch_sched.c

Lost_records.o: Lost_records.c Lost_records.h Macros.h Externals.h Switch_sched.h Switch_infnext.h Switch_infprev.h Domain_wake.h
	$(CC) $(INC) -c Lost_records.c

clean: 
	rm -rf ../../bin/Cpu_wait.out
	rm -rf *.o
