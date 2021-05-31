#include <iostream>
#include <ctime>
using namespace std;
const int size = 20;
int Hash_funtion(int key)
{
    return key / 10;
}

struct Table
{
    int number = 0;

    Table* next_list = nullptr;
} Hash_table[100];

Table* buffer = new Table;
Table* prev = new Table;

void show_table()
{
    for (int i = 0; i < ::size; i++)
    {
        if (Hash_table[i].number != 0)
        {
            buffer = &Hash_table[i];
            cout << "\nЯчейка " << int(i) << endl;
            do
            {
                cout << "\t" << buffer->number << " ";
                buffer = buffer->next_list;

            } while (buffer != nullptr);
        }
    }
}

void find()
{
    setlocale(LC_CTYPE, "Rus");
    int Number;
    cout << "\nВведите число: "; cin >> Number;
    int key = Hash_funtion(Number);

    clock_t t1, t2;

  
    buffer = &Hash_table[key];
    for (;;)
    {
        if (buffer->number == Number)
        {
           
            cout << "\nЯчейка: " << key << "  ---  " << "Число - " << buffer->number;

            break;
        }
        buffer = buffer->next_list;
        if (buffer == NULL) break;
    }

}

void delete_el()
{
    int Number;
    cout << "\nВведите число: "; cin >> Number;
    int key = Hash_funtion(Number);
    buffer = &Hash_table[key];
    Table* prev = new Table;

    for (;;)
    {
        if (buffer->number == Number)
        {

            if (buffer == &Hash_table[key])
            {

                Hash_table[key].number = Hash_table[key].next_list->number;
                buffer = buffer->next_list;
                Hash_table[key].next_list = buffer->next_list;
                delete buffer;
                break;
            }

            if (buffer->next_list == NULL)
            {
                prev->next_list = NULL;
                delete buffer;
                break;
            }

            if (buffer->next_list != NULL)
            {
                prev->next_list = buffer->next_list;
                delete buffer;
                break;
            }
        }
        prev = buffer;
        buffer = buffer->next_list;
        if (buffer == NULL) break;
    }
}

int main()
{
    setlocale(LC_CTYPE, "Rus");
    FILE* file;
    fopen_s(&file, "a.txt", "r+");
    int Arr[50], key;


    for (int i = 0; i < ::size; i++)
    {
        fscanf_s(file, "%d ", &Arr[i]);


        key = Hash_funtion(Arr[i]);

        if (Hash_table[key].number == 0)
            Hash_table[key].number = Arr[i];
        else
        {
            buffer = &Hash_table[key];
            while (buffer->next_list != nullptr) buffer = buffer->next_list;
            Table* element = new Table;
            element->number = Arr[i];
            buffer->next_list = element;
        }
    }


    int choise;

    for (;;)
    {
        cout << "\n1-Вывод таблицы" << endl;
        cout << "2-Поиск элемента" << endl;
        cout << "3-Удаление элемента" << endl;
        cout << "0-Выход" << endl;
        cout << "Ваш выбор: "; cin >> choise;

        switch (choise)
        {
        case 1:show_table(); break;
        case 2: find(); break;
        case 3: delete_el(); break;
        case 0: exit(0);
        }
    }







}
