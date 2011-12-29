CC=gcc
CFLAGS=-Wall

server: rudp.o mainserver.o linkedlist.o connection.o crc.o clients.o
	$(CC) -o s.out rudp.o mainserver.o linkedlist.o connection.o crc.o clients.o
	rm -f *.o
client: rudp.o mainclient.o linkedlist.o connection.o crc.o clients.o
	$(CC) -o c.out rudp.o mainclient.o linkedlist.o connection.o crc.o clients.o
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
linkedlist.0:
	$(CC) $(CFLAGS) -o linkedlist.o -c linkedlist.c
connection.o:
	$(CC) $(CFLAGS) -o connection.o -c connection.c
crc.o:
	$(CC) $(CFLAGS) -o crc.o -c crc.c
clients.o:
	$(CC) $(CFLAGS) -o clients.o -c clients.c

