_OBJS = level/1.o intro/2.o level/2.o level/3.o level/4.o level/5.o outro/5.o main.o
OBJS = $(patsubst %,obj/%,$(_OBJS))

default: bin/limit

clean: clean-bin/ clean-obj/

clean-bin/:
	test -d bin && find bin/ -type f -exec rm {} \; || echo "No files to remove in bin/"
	test -d bin && rmdir bin || echo "Directory has already been removed."

clean-obj/: clean-obj/intro/ clean-obj/level/ clean-obj/outro/
	test -d obj && find obj/ -type f -exec rm {} \; || echo "No files to remove in obj/"
	test -d obj && rmdir obj || echo "Directory has already been removed."

clean-obj/intro/:
	test -d obj/intro/ && find obj/intro/ -type f -exec rm {} \; || echo "No files to remove in obj/"
	test -d obj/intro/ && rmdir obj/intro/ || echo "Directory has already been removed."

clean-obj/level/:
	test -d obj/level/ && find obj/level/ -type f -exec rm {} \; || echo "No files to remove in obj/"
	test -d obj/level/ && rmdir obj/level/ || echo "Directory has already been removed."

clean-obj/outro/:
	test -d obj/outro/ && find obj/outro/ -type f -exec rm {} \; || echo "No files to remove in obj/"
	test -d obj/outro/ && rmdir obj/outro/ || echo "Directory has already been removed."

bin/limit: obj/intro/ obj/level/ obj/outro/ $(OBJS) bin/
	gcc -o $@ $(OBJS) -L/usr/local/lib -Wl,-rpath=/usr/local/lib -lSDL2

obj/%.o: src/%.c
	gcc -c $< -o $@ -Isrc/include

bin/:
	test -d bin || mkdir bin

obj/:
	test -d obj || mkdir obj

obj/intro/: obj/
	test -d obj/intro/ || mkdir obj/intro/

obj/level/: obj/
	test -d obj/level/ || mkdir obj/level/

obj/outro/: obj/
	test -d obj/outro/ || mkdir obj/outro/
