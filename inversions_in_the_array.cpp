
/*
Counting Inversions in the array 
*/

#include<bits/stdc++.h>
using namespace std;


// merge sort method 
int merge(vector<int> &a, vector<int> &temp, int st, int mid, int en) {
      int i = st, k = st;
      int j = mid+1;
      int invCnt = 0;

      while (i <= mid && j <= en) {
            if(a[i] <= a[j]) {
                  temp[k++] = a[i++];
            } else {
                  // these are number of elements 
                  // that are grater than a[j]
                  invCnt += mid-i+1;
                  temp[k++] = a[j++];
            }
      }
      while (i <= mid) {
            temp[k++] = a[i++];
      }
      while (j <= en) {
            temp[k++] = a[j++];
      }

      for(int i=st; i<=en; i++) {
            a[i] = temp[i];
      }
      return invCnt;
}

int mergeSort(vector<int> &a, vector<int> &temp, int st, int en) {
      int invCnt = 0;
      if(st < en) {
            int mid = (st + en)/2;
            invCnt += mergeSort(a, temp, st, mid);
            invCnt += mergeSort(a, temp, mid+1, en);

            invCnt += merge(a, temp, st, mid, en);
      }
      return invCnt;
}


// using STL set

// Note that the worst case time complexity of above implementation 
// is O(n2) as distance function in STL takes O(n) time worst case, 
// but this implementation is much simpler than other implementations 
// and would take much less time than Naive method on average.
int STLSet(vector<int> &a) {
      int n = (int)a.size();
      int invCnt = 0;
      multiset<int> mset;
      mset.insert(a[0]);

      for(int i=1; i<n; i++) {
            auto it = mset.upper_bound(a[i]);
            // this basically tells how many elements > a[i]
            // have already occured in the array 
            invCnt += distance(it, mset.end());
            mset.insert(a[i]);
      }
      return invCnt;
}


int main() {
      int n;
      cin >> n;
      vector<int> a(n);
      vector<int> temp(n);
      for(int i=0; i<n; i++) {
            cin >> a[i];
      }

      // merge sort method 
      cout << mergeSort(a, temp, 0, n-1) << endl;

      cout << STLSet(a) << endl;

}