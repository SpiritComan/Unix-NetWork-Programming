#include "../header.h"

int main(int argc,char *argv[]){

    int listenfd;

    struct sockaddr_in servaddr;

    listenfd = socket(AF_INET,SOCK_STREAM,0);

    assert(listenfd);

    bzero(&servaddr,sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(LISTEN_PORT);
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);

    int iRet = bind(listenfd,(struct sockaddr*)&servaddr,sizeof(servaddr));

    assert(iRet != -1);

    iRet = listen(listenfd,LISTENQ);

    assert(iRet != -1);

    struct sockaddr_in cliaddr;
    socklen_t nLen = sizeof(cliaddr);

    time_t tm;

    for(;;){

        int connfd = accept(listenfd,(struct sockaddr*)&cliaddr,&nLen);

        if(connfd <0 ){
        
            printf("Accept error\n");
            continue;
        }

        char addr[INET_ADDRSTRLEN];
        bzero(addr,INET_ADDRSTRLEN);

        printf("Connected by %s port %d\n",inet_ntop(AF_INET,&cliaddr.sin_addr,addr,INET_ADDRSTRLEN),
                ntohs(cliaddr.sin_port));


        tm = time(NULL);

        char buf[MAX_SIZE];
        bzero(buf,MAX_SIZE);

        sprintf(buf,"%.24s\n",ctime(&tm));

        write(connfd,buf,strlen(buf));

        close(connfd);

    
    }

    close(listenfd);
    return 0;
}
