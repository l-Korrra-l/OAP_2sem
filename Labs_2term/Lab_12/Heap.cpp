#include "Heap.h"
#include <iostream>
#include <iomanip>
void AAA::print()
{
	std::cout << x;
}
int AAA::getPriority() const
{
	return x;
}
namespace heap
{
	Heap create(int maxsize, CMP(*f)(void*, void*))
	{
		return *(new Heap(maxsize, f));
	}
	int Heap::left(int ix)
	{
		return (2 * ix + 1 >= size) ? -1 : (2 * ix + 1);
	}
	int Heap::right(int ix)
	{
		return (2 * ix + 2 >= size) ? -1 : (2 * ix + 2);
	}
	int Heap::parent(int ix)
	{
		return (ix + 1) / 2 - 1;
	}
	void Heap::swap(int i, int j)
	{
		void* buf = storage[i];
		storage[i] = storage[j];
		storage[j] = buf;
	}
	void Heap::heapify(int ix)
	{
		int l = left(ix), r = right(ix), irl = ix;
		if (l > 0)
		{
			if (isGreat(storage[l], storage[ix])) irl = l;
			if (r > 0 && isGreat(storage[r], storage[irl])) 	irl = r;
			if (irl != ix)
			{
				swap(ix, irl);
				heapify(irl);
			}
		}
	}
	void Heap::insert(void* x)
	{
		int i;
		if (!isFull())
		{
			storage[i = ++size - 1] = x;
			while (i > 0 && isLess(storage[parent(i)], storage[i]))
			{
				swap(parent(i), i);
				i = parent(i);
			}
		}
	}
	void Heap::insertr(void* x)
	{
		int i;
		if (!isFull())
		{
			storage[i = ++size - 1] = x;
			while (i > 0 && isGreat(storage[parent(i)], storage[i]))
			{
				swap(parent(i), i);
				i = parent(i);
			}
		}
	}
	void* Heap::extractMax()
	{
		void* rc = nullptr;
		if (!isEmpty())
		{
			rc = storage[0];
			storage[0] = storage[size - 1];
			size--;
			heapify(0);
		} return rc;
	}
//----------------------------------------------------------------------------------------------------------------------------
	void* Heap::extractMin(int m)
	{
		void* rc = nullptr;
		if (!isEmpty())
		{
			for (int i = m; i < size; i++)
			{
				storage[i] = storage[i + 1];
			}
			size--;
		heapify(0);
		} return rc;
	}
//----------------------------------------------------------------------------------------------------------------------------
	
	void* Heap::extractI(int k)
	{
		void* rc = nullptr;
		if (!isEmpty())
		{
			for (int i = k; i < size; i++)
			{
				rc = storage[i];
				storage[i] = storage[i + 1];
			}
			size--;
			heapify(0);
		} return rc;
	}
//----------------------------------------------------------------------------------------------------------------------------
	void Heap::unionHeap(Heap* h2) 
	{
		if (size == 0)
			std::cout << "Куча 1 пуста";
		if (h2->size == 0)
			std::cout << "Куча 2 пуста";
		for (int u = 0; u < size; u++)
		{
			h2->insert(((AAA*)storage[u]));
		}
		//h2->scan(0);
	}
	void Heap::unionHeapr(Heap* h2)
	{
		if (size == 0)
			std::cout << "Куча 1 пуста";
		if (h2->size == 0)
			std::cout << "Куча 2 пуста";
		for (int u = 0; u < size; u++)
		{
			h2->insertr(((AAA*)storage[u]));
		}
		//h2->scan(0);
	}
//----------------------------------------------------------------------------------------------------------------------------

	int Heap::scan(int i) const     //Вывод значений элементов на экран
	{
		int probel = 20, min=0;
		std::cout << '\n';
		if (size == 0)
			std::cout << "Куча пуста";
		for (int u = 0, y = 0; u < size; u++)
		{
			std::cout << std::setw(probel + 10) << std::setfill(' ');
			((AAA*)storage[u])->print();
			if (!isGreat(storage[u], storage[min])) min = u;
			if (u == y)
			{
				std::cout << '\n';
				if (y == 0)
					y = 2;
				else
					y += y * 2;
			}
			probel /= 2;
		}
		std::cout << '\n';
		return min;
	}

	int Heap::sum()     
	{
		int sum = 0; 
	
		if (size == 0)
			std::cout << "Куча пуста";
		for (int u = 0, y = 0; u < size; u++)
		{
			
			sum+=((AAA*)storage[u])->x;
			
		}
		
		return sum;
	}
}
