#ifndef HEADER_H
#define HEADER_H

#define _GNU_SOURCE 1

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>
#include <assert.h>
#include <sys/socket.h> 
#include <sys/types.h>
#include <poll.h>
#include <sys/select.h>
#include <sys/epoll.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define MAX_SIZE 1024 //buf size 
#define LISTEN_PORT 11000 //listen port
#define LISTENQ 5 //max listen client number
#define MAX_EVENT 1024 //max event number


#ifndef HAVE_BZERO
#define bzero(buf,s) memset(buf,0,s)
#endif

#endif
