#pragma once
#define HASHDEL (void*) -1
struct Object
{
	void** data;
	Object(int, int(*)(void*));
	int size;  int N=0;
	int(*getKey)(void*);
	bool insert(void*);
	bool insertmult(void*);
	//bool insertun(void*);
	int searchInd(int key);
	int searchIndmult(int key);
	void* search(int key);
	void* searchmult(int key);
	void* deleteByKey(int key);
	void* deleteByKeymult(int key);
	bool deleteByValue(void*);
	bool deleteByValuemult(void*);
	void scan(void(*f)(void*));
};
static void* DEL = (void*)HASHDEL;
Object create(int size, int(*getkey)(void*));
#undef HASHDEL
