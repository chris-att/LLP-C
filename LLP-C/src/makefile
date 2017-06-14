default: debug release

debug:
	-mkdir debug
	gcc -Wall -g -o0 -o debug/myQueue Queue.c

release: 
	gcc -Wall -c Queue.c
	-mkdir release
	gcc Queue.o -Wall -o release/myQueue

clean:
	-rm debug/*
	-rm release/*

rebuild: clean debug release
