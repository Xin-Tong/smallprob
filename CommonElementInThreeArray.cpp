#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    //vector<int> arr1 = {2, 4, 7, 9};
    int arr1[] = {2, 4, 7, 9};
    int arr2[] = {2, 5, 6, 9};
    int arr3[] = {1, 2, 3, 4};
    //vector <int> arr1(a, a+sizeof(a)/sizeof(int));
    vector<int> res;
    int cnt1 = 0;
    int cnt2 = 0; 
    int cnt3 = 0;
    int size = sizeof(arr1)/sizeof(int);
    while(cnt1 < size && cnt2 < size && cnt3 < size){
        if(arr1[cnt1] == arr2[cnt2] && arr1[cnt1] == arr3[cnt3]){
            res.push_back(arr1[cnt1]);
            cnt1++;
            cnt2++;
            cnt3++;
        }
        else{
            int min_num = min(arr1[cnt1], arr2[cnt2]);
            min_num = min(min_num, arr3[cnt3]);
            if(min_num == arr1[cnt1])
                cnt1++;
            else if(min_num == arr2[cnt2])
                cnt2++;
            else
                cnt3++;
        }
    }
    for(int i=0; i<res.size(); i++){
        cout<<res[i]<<endl;
    }
    return 0;
}
