#include <iostream>
using namespace std;

int f(int *x){
  //  cout<<*x;
    cout<<sizeof(x);
}
int main(){
    int b[6] = {4};
    int *a = new int[5];

    //cout<<&a;
    cout<<sizeof(a.size());
    //f(&a);
    //cout<<sizeof(b) / sizeof(*b);
}
