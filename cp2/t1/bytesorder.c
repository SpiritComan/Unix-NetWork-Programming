#include "../header.h"

int main(int argc,char *argv[]){

	union{
	
		short u_value;
		char c_value[2];
	}un;

	//printf("%s\n",CPU_VENDOR_OS);


	un.u_value = 0x0102;

	if(sizeof(short) == 2){
	
		if(un.c_value[0] == 1 && un.c_value[1] == 2)
			printf("Big endian\n");
		else if(un.c_value[0] == 2 && un.c_value[1] == 1)
			printf("Small endian\n");
		else
			printf("unknown endian\n");
	}else{
	
		printf("unknown\n");
	}


	return 0;
}
