#include<stdio.h>
#include<string.h>

int readcodes();//处理第一行要加密的字符串，改换成相应编码头存进数组 
int readint(int);//将指定长度01串转换成整型 
int readchar();//读串 

int codes[8][1<<8];

int readint(int s){
	int number=0;
	while(s--)	number=number*2+readchar()-'0';//进制转换
	return number;
}

int readcodes(){
	memset(codes,0,sizeof(codes));	//每次都需要初始化密码字符数组
	codes[1][0]=readchar();//先存储第一个，之后的密码字符便可按照规律循环存储
	
	int i,j;
	for(i=2;i<=7;i++){
		for(j=0;j<(1<<i)-1;j++){
			int ch=getchar();
			if(ch==EOF)	return 0;//文件结束符
			if(ch=='\n'||ch=='\r')	return 1;//读到了空格或者转行，终止函数，不用存进密码字符数组中
			codes[i][j]=ch;
		}
	}
	return 1;
}

int readchar(){
	int ch=getchar();
	while(ch!='\n'&&ch!='\r')	return ch;//用于针对密码文本多行的情况，如果时换行继续往下读再返回字符
}

int main(){
	
	while( readcodes() ){
		for( ; ; ){
			int len=readint(3); 
			if(len==0)	break;
			for( ; ; ){
				int value=readint(len);
				if(value==(1<<len)-1)	break;
				putchar(codes[len][value]); //把存进去的相应ASCII码输出转换成字符
			}
		} 
		printf("\n");	
	} 
	
	return 0;
} 
