#include "header.h"

int writen(int fd,char *vptr,size_t n){


	size_t nLeft;
	size_t nWritn;

	char *ptr = vptr;

	while(nLeft >0){
	
		if((nWritn = write(fd,ptr,nLeft)) <= 0){
		
			if(nWritn < 0 && errno == EINTR)
				nWritn = 0;
			else
				return (-1);
		}

		nLeft -= nWritn;
		ptr += nWritn;

	}


	return n;
}
