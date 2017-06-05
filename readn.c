#include "header.h"

int readn(int fd,void *vptr,size_t n){

	size_t nLeft;
	size_t nRead;

	char *ptr = vptr;

	nLeft = n;

	while(nLeft >0){
	
		if((nRead = read(fd,ptr,nLeft)) <0){
		
			if(errno == EINTR)
				nRead = 0;
			else
				return -1;
		}else if(nRead == 0){
		
			break;
		}

		nLeft -= nRead;
		ptr += nRead;
	}

	return (n-nLeft);
}
