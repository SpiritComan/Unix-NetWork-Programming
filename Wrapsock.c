#include "header.h"


int Accept(int fd,struct sockaddr* sa,socklen_t*salenptr){

	int n;

again:
	if((n = accept(fd,sa,salenptr)) <0){
	
#ifdef EPROTO
		if(errno == EPROTO || errno == ECONNABORTED)
#else
	    if(errno == ECONNABORTED)

#endif
		goto again;
	else
		fputs("accept error\n",stdout);
	}

	return n;
}

void Bind(int fd,struct sockaddr* sa,socklen_t salen){

	if(bind(fd,sa,salen) <0)
		fputs("bind error\n",stdout);
}

void Connect(int fd,struct sockaddr*sa,sockeln_t salen){

	if(connect(fd,sa,salen) <0)
		fputs("Connect error\n",stdout);
}


void Getpeername(int fd,struct sockaddr*sa,socklen_t *salenptr){

	if(getpeername(fd,sa,salenptr) <0)
		perror("getpeername error\n");
}

void Getsockname(int fd,struct sockaddr*sa,soclen_t *salenptr){

	if(getsockname(fd,sa,salenptr)< 0)

		perror("getsockanem error\n");
}


void Getsockopt(int fd,int level,int optname,void *optval,sockeln_t * optlenptr){

	if(getsockopt(fd,level,optname,optval,optlenptr)<0)
		perror("getsockopt error\n");
}

void Listen(int fd,int backlog){

	char *ptr;

	if((ptr = getenv("LISTENQ")) != NULL)
		backlog = atoi(ptr);

	if(listen(fd,backlog) <0)
		perror("Listen error\n");

}
