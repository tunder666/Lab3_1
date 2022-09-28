#include <iostream>
#include <string.h>
using namespace std;


void int_array_print(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << i << ". " << arr[i] << endl;
    }
    cout << "===========================\n";
}

int* IntBubbleSort(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    }
    return arr;
}

void task1()
{
    cout << "BUBBLE SORT\n\n";

    int size;
    cout << "Enter size of array: ";
    cin >> size;

    int arr[1000];
    cout << "Enter array: " << endl;
    for (int i = 0; i < size; i++) {
        cout << i <<". ";
        cin >> arr[i];
    }
    cout << "\n-Sorted array-\n";
    int_array_print(IntBubbleSort(arr, size), size);
    system("pause");
}

void char_array_print(char arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << i << ". " << arr[i] << endl;
    }
    cout << "===========================\n";
}

char* CountingSort(char arr[], int size) {
    char output[1000];

    int count[256];
    memset(count, 0, sizeof(count));

    for (int i = 0; i < size; i++) {
        count[arr[i]]++;
    }   

    for (int i = 1; i <= 255; i++) {
        count[i] += count[i - 1];
    }  

    for (int i = 0; i < size; i++) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]=count[arr[i]] - 1;
    }

    return output;
}

void task2()
{
    cout << "COUNTING SORT\n\n";

    int size;
    cout << "Enter size of array: ";
    cin >> size;

    char arr[1000];

    cout << "Enter a-z symbol: " << endl;
    for (int i = 0; i < size; i++) {
        cout << i <<". ";
        cin >> arr[i];
    }

    cout << "\n-Sorted array-\n";
    char_array_print(CountingSort(arr,size), size);


    system("pause");
}


void task3()
{
    int arr[] = { 5, 2, 5, 8, 1, 9, 6 };
    system("pause");
}


int main()
{
    int choice = 0;
    while (true)
    {
        system("CLS");//clear console
        cout << "===========================\n";
        cout << "1. Task 1\n" << "2. Task 2\n" << "3. Task 3\n" << "4. Exit\n";
        cout << "What do you want to choose? ";
        cin >> choice;
        cout << "===========================\n\n";
        switch (choice)
        {
        case 1:
        {
            task1();
            break;
        }
        case 2:
        {
            task2();
            break;
        }
        case 3:
        {
            task3();
            break;
        }
        default:
        {
            return 0;
        }
        }
    }
}