#include <iostream>

using namespace std;

int main(){
    int a[3] = {1,2,3};
    int *b = a;
    cout<<"aLen"    <<sizeof(a)<<endl;
    cout<<"bLen"    <<sizeof(b)<<endl;
    return 0;
}
