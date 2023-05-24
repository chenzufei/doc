INC=-I/usr/local/include/CUnit
LIB=-L/usr/local/lib/
all：stub.c main.c
gcc -o test $(INC) $(LIB) -lcunit $^
clean：
-rm -rf *.o test