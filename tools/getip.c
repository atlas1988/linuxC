#include <stdio.h>
#include <netdb.h>
#include<stdlib.h>

int main(int argc,char **argv){
	struct hostent *ent;
	int i=0;// 循环读取所有网址
	if(argc==2){
		printf("输入的需要查询的网站是：%s\n",argv[1]);
		ent=gethostbyname(argv[1]);
		if(ent==0){
       			 printf("请输入正确的格式:./getipbyname www.baidu.com!\n");	
			exit (-1);
		 }
	}else{
		printf("请输入正确的格式:./getipbyname www.baidu.com!\n");
		printf("默认没有配置，默认是百度网\n");
		ent=gethostbyname("www.baidu.com");
	}
	//printf("%s\n",ent->h_aliases[0]);
	while(ent->h_addr_list[i]){
		printf("%hhu.%hhu.%hhu.%hhu\n",
			ent->h_addr_list[i][0],
			ent->h_addr_list[i][1],
			ent->h_addr_list[i][2],
			ent->h_addr_list[i][3]);
		i++;
	}

	return 0;
}
