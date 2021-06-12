#include "Hash.h"
#include <iostream>
int HashFunction(int key, int size, int p)    //--------Модульная --------- Хеш-функция 
{
	return (p + key) % size;
}
int HashFunctionmult(int key, int size, int p)    //--------Мультипликативная--------- Хеш-функция 
{
	double A = 0.6180339887499;
	double key2 = size*((key * A)- ((key * A)/1));
	return key2;
}
int HashFunctionUn(char* key, int size, int p)                   //--------Универсальная--------- Хеш-функция

{
	int h, a = 31415, b = 27183;
	int l = strlen(key);
	for (h = 0; *key != 0; key++, a = a * b % (size - l))

		h = (a * h + *key) % size;

	return (h < 0) ? (h + size) : h;

}
//-------------------------------
int Next_hash(int hash, int size, int p)
{
	return (hash + 5 * p + 3 * p * p) % size;
}
//-------------------------------
Object create(int size, int(*getkey)(void*))
{
	return *(new Object(size, getkey));
}
//-------------------------------
Object::Object(int size, int(*getkey)(void*))
{
	N = 0;
	this->size = size;
	this->getKey = getkey;
	this->data = new void* [size];
	for (int i = 0; i < size; ++i)
		data[i] = NULL;
}
//-------------------------------
//bool Object::insert(void* d)
//{
//	bool b = false;
//	if (N != size)
//		for (int i = 0,  t = getKey(d),  j = HashFunction(t, size, 0);       i != size && !b;      j = Next_hash(j, size, ++i))
//			if (data[j] == NULL || data[j] == DEL)
//			{
//				data[j] = d;
//				N++;
//				b = true;
//			}
//	return b;
//}
bool Object::insert(void* d)
{
	bool b = false;
	if (N != size)
		for (int i = 0, t = getKey(d), j = HashFunction(t, size, 0); i != size && !b; j = Next_hash(j, size, ++i))
			if (data[j] == NULL || data[j] == DEL)
			{
				data[j] = d;
				N++;
				b = true;
			}
	return b;
}

bool Object::insertmult(void* d)  //////--------Мультипликативная--------- Хеш-функция
{
	bool b = false;
	if (N != size)
		for (int i = 0, t = getKey(d), j = HashFunctionmult(t, size, 0); i != size && !b; j = Next_hash(t++, size, ++i))
			if (data[j] == NULL || data[j] == DEL)
			{
				data[j] = d;
				N++;
				b = true;
			}
	return b;
}

//bool Object::insertun(void* d)  ////--------Универсальная--------- Хеш-функция
//{
//	bool b = false;
//	if (N != size)
//		for (int i = 0, t = d[getKey(d)].mas, j = HashFunctionUn(t, size, 0); i != size && !b; j = Next_hash(j, size, ++i))
//			if (data[j] == NULL || data[j] == DEL)
//			{
//				data[j] = d;
//				N++;
//				b = true;
//			}
//	return b;
//}
//-------------------------------
int Object::searchInd(int key)
{
	int t = -1;
	bool b = false;
	if (N != 0)
		for (int i = 0, j = HashFunction(key, size, 0); data[j] != NULL && i != size && !b; j = HashFunction(key, size, ++i))
			if (data[j] != DEL)
				if (getKey(data[j]) == key)
				{
					t = j; b = true;
				}
	return t;
}
int Object::searchIndmult(int key)
{
	int t = -1;
	bool b = false;
	if (N != 0)
		for (int i = 0, j = HashFunctionmult(key, size, 0); data[j] != NULL && i != size && !b; j = HashFunctionmult(key, size, ++i))
			if (data[j] != DEL)
				if (getKey(data[j]) == key)
				{
					t = j; b = true;
				}
	return t;
}
//-------------------------------
void* Object::search(int key)
{
	int t = searchInd(key);
	return(t >= 0) ? (data[t]) : (NULL);
}
void* Object::searchmult(int key)
{
	int t = searchIndmult(key);
	return(t >= 0) ? (data[t]) : (NULL);
}
//-------------------------------
void* Object::deleteByKey(int key)
{
	int i = searchInd(key);
	void* t = data[i];
	if (t != NULL)
	{
		data[i] = DEL;
		N--;
	}
	return t;
}
void* Object::deleteByKeymult(int key)
{
	int i = searchIndmult(key);
	void* t = data[i];
	if (t != NULL)
	{
		data[i] = DEL;
		N--;
	}
	return t;
}
//-------------------------------
bool Object::deleteByValue(void* d)
{
	return(deleteByKey(getKey(d)) != NULL);
}
bool Object::deleteByValuemult(void* d)
{
	return(deleteByKeymult(getKey(d)) != NULL);
}
//-------------------------------
void Object::scan(void(*f)(void*))
{
	for (int i = 0; i < this->size; i++)
	{
		std::cout << " Элемент" << i;
		if ((this->data)[i] == NULL)
			std::cout << "  пусто" << std::endl;
		else
			if ((this->data)[i] == DEL)
				std::cout << "  удален" << std::endl;
			else
				f((this->data)[i]);
	}
}
