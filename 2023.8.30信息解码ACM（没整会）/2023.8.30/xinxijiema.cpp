#include<stdio.h>
#include<string.h>

int readcodes();//�����һ��Ҫ���ܵ��ַ������Ļ�����Ӧ����ͷ������� 
int readint(int);//��ָ������01��ת�������� 
int readchar();//���� 

int codes[8][1<<8];

int readint(int s){
	int number=0;
	while(s--)	number=number*2+readchar()-'0';//����ת��
	return number;
}

int readcodes(){
	memset(codes,0,sizeof(codes));	//ÿ�ζ���Ҫ��ʼ�������ַ�����
	codes[1][0]=readchar();//�ȴ洢��һ����֮��������ַ���ɰ��չ���ѭ���洢
	
	int i,j;
	for(i=2;i<=7;i++){
		for(j=0;j<(1<<i)-1;j++){
			int ch=getchar();
			if(ch==EOF)	return 0;//�ļ�������
			if(ch=='\n'||ch=='\r')	return 1;//�����˿ո����ת�У���ֹ���������ô�������ַ�������
			codes[i][j]=ch;
		}
	}
	return 1;
}

int readchar(){
	int ch=getchar();
	while(ch!='\n'&&ch!='\r')	return ch;//������������ı����е���������ʱ���м������¶��ٷ����ַ�
}

int main(){
	
	while( readcodes() ){
		for( ; ; ){
			int len=readint(3); 
			if(len==0)	break;
			for( ; ; ){
				int value=readint(len);
				if(value==(1<<len)-1)	break;
				putchar(codes[len][value]); //�Ѵ��ȥ����ӦASCII�����ת�����ַ�
			}
		} 
		printf("\n");	
	} 
	
	return 0;
} 
