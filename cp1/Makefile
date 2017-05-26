CC = gcc 
CFLAG = -o
COMPLIE = -g -Wall -c

.SUFFIXES:.o .c

.o.c:
	${CC} ${CFLAGES} ${COMPLIE} $<

all:daytimetcpsrv daytimetcpcli

daytimetcpsrv:daytimetcpsrv.o
	${CC} ${CFLAG} daytimetcpsrv daytimetcpsrv.o

daytimetcpcli:daytimetcpcli.o
	${CC} ${CFLAG} daytimetcpcli daytimetcpcli.o

daytimetcpsrv.o:daytimetcpsrv.c

daytimetcpcli.o:daytimetcpcli.c

.PHONY:all

clean:
	rm -rf *.o daytimetcpsrv daytimetcpcli
