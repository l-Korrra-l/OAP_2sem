﻿////Создать очередь с вещественными числами, и заполнить ее с клавиатуры.Выполнить циклический сдвиг элементов в очереди так,
////чтобы в ее начале был расположен наибольший элемент.
//
//#include <iostream>
//using namespace std;
//
//struct Node 
//{
//    double data; 
//    Node* next;
//};
//
//struct Queue 
//{
//    int size;
//    Node* first; 
//    Node* last; 
//};
//
//
//void creation(Queue* Q)     
//{
//    Q->first = new Node;
//    Q->first->next = NULL;
//    Q->last = Q->first;
//    Q->size = 0;
//}
//
//int size(Queue* Q) 
//{
//    return Q->size;
//}
//
//
//bool isempty(Queue* Q) 
//{
//    if (Q->first == Q->last) return true;
//    else return false;
//}
//
//void print(Queue* Q)
//{
//   if (isempty(Q) == true)
//   {
//        printf("Очередь пуста\n");
//        return;
//   }
//   else
//   {
//       Node* temp;
//       temp = Q->first->next;
//       for (int i = 0; i < size(Q); i++)
//       {
//           cout << temp->data << " ";
//           temp = temp->next;
//       }
//   }
//}
//
//
//void add(Queue* Q) 
//{
//    int len;
//    cout << "Введите количество добавляемых элементов в очередь: ";
//    cin >> len;
//    for (int i = 0; i < len; i++)
//    {
//        double value;
//        cout << "Значение > ";
//        cin >> value;
//        Q->last->next = new Node;
//        Q->last = Q->last->next;
//        Q->last->data = value; 
//        Q->last->next = NULL;
//        Q->size++;
//    }
//    cout << "\n\n";
//}
//
//
//void shift(Queue* Q)
//{
//   if (isempty(Q) == true)
//    {
//        printf("Очередь пуста\n");
//        return;
//    }
//    else
//    {
//        Node* temp;
//        Node* max;
//        max = temp = Q->first->next;
//        for (int i = 0; i < size(Q); i++)
//        {
//            if (temp->data > max->data)
//                max = temp;
//            temp = temp->next;
//        }
//        temp = Q->first->next;
//        if (max != Q->first->next)
//        {
//            for (int i = 0; i < size(Q); i++)
//            {
//                if (temp->next->data == max->data)
//                {
//                    Q->last->next = Q->first->next;
//                    Q->first->next = max;
//                    Q->last = temp; 
//                    temp->next = max->next;
//                    break;
//                }
//                temp = temp->next;
//            }
//        }
//    }
//}
//
//void main() 
//{
//    setlocale(0, "");
//    Queue Q;
//    creation(&Q);
//    int choice;
//    do
//    {
//        cout << "1. Добавить элементы" << endl;
//        cout << "2. Вывести очередь" << endl;
//        cout << "4. Циклический сдвиг" << endl;
//        cout << "0. Выйти\n\n";
//        cout << "Номер команды > "; 
//        cin >> choice;
//        switch (choice)
//        {
//        case 1: 
//            add(&Q);
//            break;
//        case 2:
//            if (isempty(&Q)) 
//                cout << endl << "Очередь пуста\n\n";
//            else { 
//                cout << "\nЭлементы очереди: ";
//                print(&Q);
//                cout << "\n\n";
//            }
//            break;
//        case 4:
//            shift(&Q);
//        case 0:
//            break;
//        default: 
//            cout << endl << "Команда не определена\n\n";
//            break;
//        }
//    } while (choice != 0);
//}
//
