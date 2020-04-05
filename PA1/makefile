OBJS = driver.o functions.o
CFLAGS = -Wall -g

driver: ${OBJS}
	gcc -o $@ -g ${OBJS} -save-temps

${OBJS}: functions.h makefile

run:
	./driver $@ $@

clean:
	rm -f *.o driver
