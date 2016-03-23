#include<stdio.h>
#include"vector.h"
int main(){
	VECTOR v={NULL,0,0,sizeof(int)};
	int i;
	for(i=0;i<10;i++){
		push_back(&v,&i);
	}
	for(i=0;i<v.size;i++){
		printf("%d\n",*(int*)at(&v,i));
	}
	return 0;
}
