#include<stdio.h>

char str[52];
double num[52] = {0.0};
int totalnum = 0 , k = 0;

void hello(char one, FILE*fp ){
    char letter; 
    int  ret;
    while(!feof(fp)){    //fefo():文件结束：返回非0值，文件未结束:返回0值,fscanf（可以从一个文件流中格式化读出数据，遇到空格或回车就停止）
     	ret = fscanf(fp, "%c", &letter);
        if(letter==one){
        	num[k] ++;
        	totalnum ++;
		}        
        if (ret == EOF)
            break;
    }
	k++;
    return ;
}


void insertionSort(){
	int i , j ;
	double temp = 0;
	char c ;
	
	for(i = 0; i < 52; i ++){
    	num[i] = num[i]/(1.0 * totalnum);
	}
	
	for(i = 1; i < 52; i ++){
		j = i;
		temp = num[i];
		c = str[i];
		while(j > 0.0 && temp < num[j-1]){
			num[j] = num[j-1];
			str[j] = str[j-1];
			j --;
		}
		num[j] = temp;
		str[j] = c;
	}
	
	for(i= 0; i < 52; i ++){
		printf("%c : %.2lf\n",str[i],num[i]);
	}
} 


int main(){
    FILE *fp;
	if((fp=fopen("englishtest.txt", "r"))==NULL){
        printf("Cannot open the file!\n");
        return -1;
    }
    int i=0 ,j = 0, k = 0;
    float pl = 0.0;
   
    for (i=0; i<52; i++){
        str[i] = 'a' + i;
        
        if(j < 26){
        	str[i] = 'A' + j;
        	hello(str[i], fp);
        	j ++;
		}
		else{
			str[i] = 'G' + j;
			hello(str[i], fp);
			j ++;
		}
        rewind(fp);
    }
    insertionSort();
    fclose(fp);
    return 0;
}

