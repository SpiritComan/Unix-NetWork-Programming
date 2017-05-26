#include "../header.h"

int main(int argc,char *argv[]){

    int sockfd;

    struct sockaddr_in cliaddr;

    sockfd = socket(AF_INET,SOCK_STREAM,0);

    assert(sockfd >= 0);

    bzero(&cliaddr,sizeof(cliaddr));

    cliaddr.sin_family = AF_INET;
    cliaddr.sin_port = htons(LISTEN_PORT);
    inet_pton(AF_INET,"127.0.0.1",&cliaddr.sin_addr);

    int n = connect(sockfd,(struct sockaddr*)&cliaddr,sizeof(cliaddr));

    assert(n != -1);

    char buf[MAX_SIZE];
    bzero(buf,MAX_SIZE);

    while( (n = read(sockfd,buf,MAX_SIZE-1)) >0){
    

        buf[n] = '\0';

        if(fputs(buf,stdout)  == EOF)
            printf("out put error\n");

        break;
    }

    close(sockfd);

    return 0;
}
