////
////  main.cpp
////  Test
////
////  Created by Gorakh Chavan on 20/12/20.
////
//
//#include <iostream>
//using namespace std;
//
//void mergeSort(int *a, int startIndex, int endIndex)
//{
//    if (startIndex >= endIndex)
//    {
//        return;
//    }
//    int mid = (startIndex + endIndex) / 2;
//    mergeSort(a, startIndex, mid);
//    mergeSort(a, mid + 1, endIndex);
//    int b[endIndex+1];
//    int k = 0;
//    for (int i = startIndex, j = mid + 1; j <= endIndex; i++, j++)
//    {
//        if (a[i] > a[j])
//        {
//            b[k++] = a[j];
//        }
//        else
//        {
//            b[k++] = a[i];
//        }
//    }
//    for(int i=0;i<=endIndex;i++){
//        a[i]=b[i];
//    }
//}
//
//int main()
//{
//    int n;
//    cin >> n;
//    int a[n];
//    for (int i = 0; i < n; i++)
//    {
//        cin >> a[i];
//    }
//    mergeSort(a,0,n-1);
//    return 0;
//}

//
//#include <bits/stdc++.h>
//using namespace std;
//int main()
//{
//    int t;
//    cin >> t;
//    while (t--)
//    {
//        int n;
//        cin>>n;
//        string encodedString;
//        cin>>encodedString;
//        string c;
//        c="abcdefghijklmnop";
//
//        int count=n/4;
//        int i=0;
//        int k=4;
//        while(count){
//            int start=0;
//            int end=16;
//            int mid=8;
//            for(;i<k;i++){
//            if(encodedString[i]=='1'){
//              start=mid;
//              mid=start+(end-start)/2;
//            }else
//            {
//                end=mid;
//                mid=start+(end-start)/2;
//            }
//
//        }
//        cout<<c[start];
//        count--;
//
//        k+=4;
//        }
//        cout<<"\n";
//
//    }
//    return 0;
//}
//#include <bits/stdc++.h>
//using namespace std;
//int main()
//{
//    string variable = "quinstreet";
//    int n = 2;
//
//    for(char& i : variable)
//    {
//        int count=0;
//
//        for(char& j : variable)
//        {
//           if(i==j){
//               count++;
//           }
//
//
//        }
//        if(count==n){
//            cout<<i<<"->"<<n<<endl;
//        }
//    }
//    return 0;
//}
//#include <bits/stdc++.h>
//using namespace std;
//int main()
//{
//    int t;
//    cin >> t;
//    for(int i=10;i>1;i--){
//        if(t%i==0){
//            cout<<i;
//            break;
//        }
//    }
//    return 0;
//}
//#include <bits/stdc++.h>
//using namespace std;
//bool checkSame(vector<int> &v){
//    int temp=v[0];
//    for(auto x: v){
//        if(x!=temp){
//            return false;
//        }
//    }
//    return true;
//}
//int main()
//{
//    int t;
//    cin >> t;
//    while (t--)
//    {   int n;
//        cin>>n;
//        vector<int> v(n);
//        for(auto x: v){
//            cin>>x;
//        }
//        sort(v.begin(),v.end());
//        if(!checkSame(v)){
//            cout<<abs(v[0]-v[n-1])+ abs(v[n-1]-v[1])+ abs(v[1]-v[0]);
//        }else{
//            cout<<"0"<<endl;
//        }
//
//
//    }
//    return 0;
//}

#include <bits/stdc++.h>
using namespace std;

void Union(vector<int>a,vector<int>b){
    vector<int>result;
    a.size()>b.size()?result=b:result=a;
    for(int i=0;i<result.size();i++){
        if(binary_search(result.begin(),result.end(),result[i])){
            cout<<result[i]<<" ";
        }
    }
}


int main()
{
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    vector<int> b(m);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    Union(a,b);


    return 0;
}
