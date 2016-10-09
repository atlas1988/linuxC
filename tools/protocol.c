#include<stdio.h>
#include<netdb.h>
#include<sys/utsname.h>

int main(){
	struct protoent *ent;
	struct utname name;
	if(argc==2){
		printf("查询的网络协议为%s\n",argv[1]);
		ent=getprotobyname(argv[1]);
	}else{
		printf("没有设置查询名，默认为“tcp”\n");
		printf("正确的格式：./getprotocolNo tcp !\n");
		ent=getprotobyname("tcp");
	}
	if(ent==0){
		printf("请输入正确的格式：./getprotocolNo tcp !\n");
		exit (-1);
	}
	printf("Protocol No: %d\n",ent->p_proto);
	
	uname(&name);
	printf("%s\n",name.machine);
	printf("%s\n",name.nodename);
	printf("%s\n",name.sysname);
	printf("%s\n",name.domainname);
	return 0;
}
