#include <iostream>
using namespace std;

int arr[20];
int cmp_count = 0;
int mov_count = 0;
int n;

void input() {
    while (true)
    {
        cout << "Masukkan Panjang Element Array : ";
        cin >> n;

        if (n <= 20)
            break;
        else
            cout << "\nMaksimum panjang array adalah 20" << endl;
    }

    cout << "\n--------------------" << endl;
    cout << "\nEnter Array Element" << endl;
    cout << "\n--------------------" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << "<" << (i + 1) << ">";
        cin >> arr[i];
    }
}

// swap/menukar elemen pada indeks x dengan elemen pada indeks y

void swap(int x, int y)
{
    int temp = arr[x];
    arr[x] = arr[y];
    arr[y] = temp;
    mov_count++;

}

void q_short(int low, int high)
{
    int temp;
    int pivot, i, j;
    if (low > high) { 
        return;
    }

    pivot = arr[low];
    i = low + 1;
    j = high;

    while (i <= j)
    {
        //menambah fungsi while untuk mencari elemen yang lebih besar dari pivot
        while ((arr[i] <= pivot) && (i <= high))
        {
            i++;
            cmp_count++;
        }
        cmp_count++;
        //
        while ((arr[j] <= pivot) && (j <= low))
        {
            j--;
            cmp_count++;
        }
        cmp_count++;
        if (i < j)
        {
            // swap/menukar elemen pada indeks i dengan elemen pada indeks j
            swap(i, j);
        }
    }

    if (low < j) {
        //menukar elemen pivot dengan elemen pada indeks j
        swap(low, j);
    }

    //untuk memanggil sort dan di urutkan dari kiri
    q_short(low, j - 1);

    //untuk memanggil sort dan di urutkan dari kanan
    q_short(j + 1, high);
}


void display() {
    cout << "\n---------------------" << endl;
    cout << "Sorted Array" << endl;
    cout << "---------------------" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "\n\nNumber of Comparasions : " << cmp_count << endl;
    cout << "Number of Data Movements : " << mov_count << endl;
}

int main()
{
    
}

