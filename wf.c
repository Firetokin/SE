#include<stdio.h>
#include<string.h>
#define N 26
char str[N];
double num[N];
int total = 0;

void countTotal(FILE*fp){
	char ret;
	while(!feof(fp)){ //fefo():文件结束：返回非0值，文件未结束:返回0值
		ret = fgetc(fp);
		if(ret >= 'A' && ret <= 'Z'){
			num[ret - 'A'] ++;
			total ++;
		}
		else if(ret >= 'a' && ret <= 'z'){
			num[ret - 'a'] ++;
			total ++;
		}
		else if(ret == EOF){
			break;
		}
	}
}

void insertionSort(){
	int i, j;
	double temp;
	char tempstr;
	for(i = 0; i < N;i ++){
		num[i] = num[i] / (1.0 * total);
	}
	for(i = 1; i < N; i ++){
		j = i;
		temp = num[i];
		tempstr = str[i];
		while(j > 0 && temp < num[j-1]){
			num[j] = num[j-1];
			str[j] = str[j-1];  
			j --;
		}
		num[j] = temp;
		str[j] = tempstr;
	}
	
	for(i = 0; i < N; i ++){
		printf("%c : %.2lf\n",str[i], num[i]);
	}
} 

int main(int argc, char *argv[]){  //argv[1]保存指令，argv[2]保存文件路径 
	FILE*fp;
	int i;
	
	if(strcmp(argv[1],"-c") == 0){
		fp = fopen(argv[2],"r");	
	}
	else{
		printf("该指令与本程序功能不匹配！\n");
	}
	
	for(i = 0; i < N; i ++){
		str[i] = 'a' + i;
	}
	
	if(fp != NULL){
		countTotal(fp);
		insertionSort();
	}
	else{
		printf("文件打开失败！\n");
	}
	//printf("total = %d\n",total); 
	fclose(fp);
	return 0;
}
