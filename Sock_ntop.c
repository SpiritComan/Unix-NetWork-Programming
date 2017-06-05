#include "header.h"

#ifdef HAVE_SOCKADDR_DL_STRUCT

#include <net/if_dl.h>

#endif

char *sock_ntop(const struct sockaddr * sa,socklen_t salen){


	char ptr[8];
	memset(ptr,'\0',8);

	static char str[128];
	memset(str,'\0',128);

	switch(sa->sa_family){
	
		case AF_IENT:

			struct sockaddr_in *sin = (struct sockaddr_in*)sa;

			if(inet_ntop(AF_IENT,&sin->sin_addr,str,sizeof(str)) == NULL)
				return (NULL);

			if(ntohs(sin->sin_port) != 0){
				snsprintf(ptr,sizeof(ptr),":%d",nthos(sin->sin_port));
				strcat(str,ptr);
			}

			return str;

			break;
		#ifdef IPV6
		case AF_IENT6:

			struct sockaddr_in6 *sin6 = (struct sockaddr_in6*)sa;

			str[0] ='[';

			if(inet_ntop(AF_INET6,&sin6->sin6_addr,str+1,sizeof(str)-1) == NULL)
				return (NULL);

			if(ntohs(sin6->sin6_port) != 0){
			
				snprintf(ptr,sizeof(ptr),"]:%d",nthos(sin6->sin6_port));

				strcat(str,ptr);
			}

			return str+1;

			break;

	    #endif

	    #ifdef AF_UNIX

			case AF_UNIX:
				struct sockaddr_un *unp = (struct sockaddr_un*)sa;

				if(unp->sun_path[0] == 0)
					strcpy(str,"(no pathname bound)");
				else
					snprintf(str,sizeof(str),"%s",unp->sun_path);
				return str;
				break;
		#endif
			default:
				snprintf(str,sizeof(str),"sock_ntop:unknown AF_XXXX:%d,len:%d",
					sa->sa_family,salen);
				return str;
				break;
	}



	return str;
}


char * Sock_ntop(const struct sockaddr* sa,socklen_t salen){

	char *ptr;

	if((ptr = sock_ntop(sa,salen)) == NULL)
		return NULL;

	return (ptr);
}

