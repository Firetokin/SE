#include<stdio.h>

char str[26];
int num[26] = {0}, totalnum = 0 , k = 0;

void hello(char one, FILE*fp ){
    char letter; 
    int  ret;
    while(!feof(fp)){    //fefo():�ļ����������ط�0ֵ���ļ�δ����:����0ֵ,fscanf�����Դ�һ���ļ����и�ʽ���������ݣ������ո��س���ֹͣ��
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

int main(){
    FILE *fp;
 
    int i=0 ;
    float pl = 0.0;
    str[0]='a';
    for (i=0; i<26; i++){
        str[i] = 'a' + i;
        hello(str[i], fp);
        rewind(fp);
    }
    for(i = 0; i < 26; i ++){
    	pl = 1.0 * num[i]/totalnum;
    	printf("%c:%lf\n",str[i],pl);
	}
    printf("totalnum = %d\n",totalnum);
    fclose(fp);

    return 0;
}

