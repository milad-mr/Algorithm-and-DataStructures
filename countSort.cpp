#include <iostream>
using namespace std;

void CountSort(int a[], int a_size){ // sort and change a
    int max = a[0], min = a[0];
    //find minimum and maximum of array
    for (int i = 0; i < a_size; ++i){
        if (a[i] > max)
            max = a[i];
        if (a[i] < min)
            min = a[i];
    }
    //initialing count array
    int count_size = max - min + 1;
    int *count = new int[count_size];
    for (int i = 0; i < count_size; ++ i){
        count[i] = 0;
    }
    for (int i = 0; i < a_size; ++ i){
        count[a[i] - min] ++;
    }
    int k = 0;
    for (int i = 0; i < count_size; ++ i){
        for (int j = 0; j < count[i] ; ++j){
            a[k++] = i + min;
        }
    }
}

int main(){
    int a[] = {1,2,1,5,6};
    CountSort(a, 5);
    for (int i = 0; i < 5; ++i)
        cout << a[i];
    return 0;
}
