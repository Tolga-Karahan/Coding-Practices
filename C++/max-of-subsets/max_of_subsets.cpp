#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void print_max_of_subarrays(int*, int, int);

int main(){
    int arr_count;
    cin >> arr_count;

    for(int i = 0; i < arr_count; i++){
        int  arr_size;
        int subarray_size;

        cin >> arr_size;
        cin >> subarray_size;

        int array[arr_size];

        for(int j = 0; j < arr_size; j++)
            cin >> array[j];

        print_max_of_subarrays(array, arr_size, subarray_size);
    }
    return 0;
}

void print_max_of_subarrays(int* array, int arr_size, int subarray_size){
    multiset<int> mset;

    for(int i = 0; i < subarray_size; i++)
        mset.insert(array[i]);

    cout << *(--mset.end()) << " ";

    int index = 0;
    for(int i = subarray_size; i < arr_size; i++){
        mset.insert(array[i]);
        mset.erase(mset.find(array[index]));
        cout << *(--mset.end()) << " ";
        index++;
    }
    cout << endl;
}