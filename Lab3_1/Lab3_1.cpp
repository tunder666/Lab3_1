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
    memset(count, 0, sizeof(count)); // 0 to all elem of array

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

void merge(int arr[], int start, int end, int mid)
{
    int merged_arr[1000];
    int i, j, k;
    i = start;
    k = start;
    j = mid + 1;

    while (i <= mid && j <= end) {
        if (arr[i] < arr[j]) {
            merged_arr[k] = arr[i];
            k++;
            i++;
        }
        else {
            merged_arr[k] = arr[j];
            k++;
            j++;
        }
    }

    while (i <= mid) {
        merged_arr[k] = arr[i];
        k++;
        i++;
    }

    while (j <= end) {
        merged_arr[k] = arr[j];
        k++;
        j++;
    }

    for (i = start; i < k; i++) {
        arr[i] = merged_arr[i];
    }
}
void mergeSort(int arr[], int start, int end)
{
    int mid;
    if (start < end) {
        mid = (start + end) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, end, mid);
    }
   
}

void task3()
{
    cout << "MERGE SORT\n\n";

    int arr_size;
    cout << "Enter size of array: ";
    cin >> arr_size;

    int arr[1000];
    cout << "Enter array: " << endl;
    for (int i = 0; i < arr_size; i++) {
        cout << i << ". ";
        cin >> arr[i];
    }

    mergeSort(arr, 0, arr_size - 1);

    cout << "\n-Sorted array-\n";
    int_array_print(arr, arr_size);

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