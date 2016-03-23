#ifndef VECTOR_H
#define VECTOR_H
#include<memory.h>
#include<malloc.h>
typedef struct{
	void* base;
	int size;
	int capacity;
	int typesize;
}VECTOR;
void push_back(VECTOR* v,void* value){
	if(v->size==v->capacity){
		v->capacity=v->capacity?v->capacity*2:1;
		void* temp=calloc(v->capacity,v->typesize);
		memcpy(temp,v->base,v->size*v->typesize);
		if(v->base)free(v->base);
		v->base=temp;
	}
	//v->base[v->size]=value;
	memcpy(((char*)v->base)+(v->size*v->typesize),
		value,v->typesize);
	v->size++;
}
void* at(VECTOR* v,int index){
	return ((char*)v->base)+(index*v->typesize);
}
#endif
