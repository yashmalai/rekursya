#include <iostream>
#include <ctime>
#include <cstdlib>


using namespace std;

void swap(int* a, int i, int j, int n);
void sort(int* a, int iteration) {
    if (iteration == 0)
        return;

    swap(a, 0, 1, iteration);
    sort(a, iteration - 1);
}


void swap(int* a, int i, int j, int n) {

    if (j >= n)
        return;

    if (a[i] < a[j]) {
        int buf = a[i];
        a[i] = a[j];
        a[j] = buf;
    }

    swap(a, i + 1, j + 1, n);
}


int main() {
    srand(time(0));
    int a[1000];
    int b;
    int n = 0;
    while ((n <= 0) || (n > 1000)) {
        cout << "Vvedite razmernost' massiva (max=1000): ";
        cin >> n;
    }
    cout << endl;

    cout << "Nash massiv vyglyadit vot tak:" << endl;
    for (int i = 0;i < n; i++) {
        a[i] = rand() % 100 + 1;
        cout << a[i] << " ";
    }
    sort(a, n);

    cout << endl << endl;
    cout << "Posle sortirovki massiv vyglyadit vot tak:" << endl;
    for (int i = 0;i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
