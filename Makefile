default: bin/limit

clean:
	test -d bin && rm bin/* && rmdir bin

bin/limit: bin/
	gcc -o bin/limit limit.c -I/usr/local/include -L/usr/local/lib -Wl,-rpath=/usr/local/lib -lSDL2

bin/:
	test -d bin || mkdir bin
