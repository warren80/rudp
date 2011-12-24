CC=gcc
CFLAGS=-Wall

server: rudp.o mainserver.o 
	$(CC) -o s.out rudp.o mainserver.o
	rm -f *.o
client: rudp.o mainclient.o 
	$(CC) -o c.out rudp.o mainclient.o 
	rm -f *.o
clean:
	rm -f *.o
	rm -f *.out
stop:
	ps aux | grep "0[[:space:]]./s.out" | awk '{system("kill " $$2)}'
start:
	./s.out &
rudp.o:
	$(CC) $(CFLAGS) -o rudp.o -c rudp.c
mainserver.o:
	$(CC) $(CFLAGS) -o mainserver.o -c mainserver.c
mainclient.o:
	$(CC) $(CFLAGS) -o mainclient.o -c mainclient.c

