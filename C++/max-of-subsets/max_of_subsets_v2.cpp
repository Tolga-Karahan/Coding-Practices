#include <iostream>
#include <deque>
using namespace std;

//3 4 6 3 4
void printKMax(int arr[], int n, int k){
    deque<pair<int, int>> d;

    for(int i = 0; i < n; i++){
        while(!d.empty() && (i - d.front().first >= k))
            d.pop_front();
        
        while(!d.empty() && d.back().second <= arr[i])
            d.pop_back();

        d.push_back({i, arr[i]});

        if(i >= k-1)
            cout << d.front().second << " ";
        
    }
    cout << endl;
}
int main(){
  
   int t;
   cin >> t;
   while(t>0) {
      int n,k;
       cin >> n >> k;
       int i;
       int arr[n];
       for(i=0;i<n;i++)
            cin >> arr[i];
       printKMax(arr, n, k);
       t--;
     }
     return 0;
}