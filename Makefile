default: bin/limit

clean:
	test -d bin && rm bin/* && rmdir bin

bin/limit: bin/
	gcc -o bin/limit limit.c -lSDL2

bin/:
	test -d bin || mkdir bin
