#include <iostream>
using namespace std;
int main(){

    int N, cnt = 2, i = 1;
    cin>>N;
    if(N == 1)
        cout<<1;

    else{
        while(N>=cnt){
            cnt +=  i*6;
            i++;
        }
            cout<<i;
    }
    return 0;
}