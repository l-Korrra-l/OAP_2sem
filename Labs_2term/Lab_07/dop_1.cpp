//#include <iostream>
//using namespace std;
//
//struct Node 
//{
//    int data; 
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
//    return (Q->first->next == NULL);
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
//void add(Queue* Q, int value) 
//{
//    
//    Node* temp = new Node;      
//    temp->data = value;
//    temp->next = NULL;
//    Node* ptrval = new Node;      
//    Node* temp1 = new Node;
//    Node* temp2 = new Node;
//    if (isempty(Q))
//        Q->first->next = Q->last = temp;
//    else
//    {
//        temp2 = Q->first->next; temp1 = Q->first->next;
//        if (value <= temp1->data)
//        {
//            ptrval->data = value;
//            ptrval->next = temp1;
//            Q->first->next = ptrval;
//            return;
//        }
//        while (temp1 != NULL)  
//        {
//            if (value <= temp1->data)  
//            {
//                {
//                    ptrval->data = value;
//                    ptrval->next = temp1;
//                    temp2->next = ptrval;
//                    return;
//                }
//                temp2 = temp2->next;
//            }      
//            if (value == temp1->data)  //LIFO
//            {
//                {
//                    ptrval->data = value;
//                    ptrval->next = temp1;
//                    temp2->next = ptrval;
//                    return;
//                }
//                temp2 = temp2->next;
//            }
//            temp1 = temp1->next;
//        }
//        if (temp1 == NULL)
//        {
//            Q->last->next = temp;
//            Q->last = temp;
//        }
//    }
//}
//
//
//
//
//
//void first(Queue* Q)
//{
//    if (isempty(Q))
//        cout << "Очередь пуста" << endl;
//    else
//        cout << "Первый элемент в очереди: " << Q->first->next->data << endl;
//}
//
//
//void first_crash(Queue* Q)
//{
//
//    Node* temp = Q->first->next;
//    Q->first->next = Q->first->next->next;
//    delete temp;
//}
//
//void clear(Queue* Q)
//{
//    while (!isempty(Q)) first_crash(Q);
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
//        cout << "3. Получить элемент с начала" << endl;
//        cout << "4. Извлечь элемент с начала" << endl;
//        cout << "5. Очистить очередь" << endl;
//        cout << "0. Выйти\n\n";
//        cout << "Номер команды > "; 
//        cin >> choice;
//        switch (choice)
//        {
//        case 1: 
//            int len;
//            cout << "Введите количество добавляемых элементов в очередь: ";
//            cin >> len;
//            for (int i = 0; i < len; i++)
//            {
//                int value;
//                cout << "Значение > ";
//                cin >> value;
//                add(&Q, value);
//                Q.size++;
//            }
//            cout << "\n\n";
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
//        case 3:
//            first(&Q);
//            cout << "\n\n";
//            break;
//        case 4:
//            if (isempty(&Q))
//                cout << "Очередь пуста" << "\n\n";
//            else
//            {
//                first_crash(&Q);
//                cout << "Первый элемент удален" << "\n\n";
//                Q.size--;
//            }
//            break;
//        case 5:
//            if (isempty(&Q))
//                cout << "Очередь пуста" << "\n\n";
//            else
//            {
//                clear(&Q);
//                cout << "Очередь очищена" << "\n\n";
//                Q.size = 0;
//            }
//            break;
//        case 0:
//            break;
//        default: 
//            cout << endl << "Команда не определена\n\n";
//            break;
//        }
//    } while (choice != 0);
//}
