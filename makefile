all: profiling

profiling: objs
	gcc -o profiling profiling.o utils.o -Wall

objs:
	gcc -c profiling.c utils.c

clean:
	rm profiling.o utils.o profiling
