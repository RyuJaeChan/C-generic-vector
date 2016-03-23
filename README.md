## C-generic-vector

이 라이브러리는 C언어로 구현한 **제네릭 vector** 입니다.

아래는 간단한 예시입니다.

```cpp
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

```