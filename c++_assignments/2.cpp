/* my algo works on the intuition that finding the element with the maximum range of jump will lead to minimum jumps*/

#include <iostream>
using namespace std;

#define min(x,y) (x>y)?y:x //macros for minimum of 2 nos

int best_step( int a[], int i, int k, int n); //function for finding best step from i+1 to i+k

int min_step( int a[], int n); //function that returns minimum number of steps

int main() {

    int n;
    cout<<" Kindly enter the length of array ";
    cin >> n;

    int* a = new int[n]; //dynamic array of n
    cout << "Now enter the array of steps I should climb ";
    for ( size_t i = 0; i < n; i++) {
        cin >> a[i];
    }

    int s = min_step(a,n);


    cout << endl << "Minimum number of steps I took was " << s << endl;
    delete[] a;
    return 0;
}

int best_step( int a[], int i, int t, int n) {

    int m = 0, l;

    l = min( t+i , n-1 );
//this finds the element that will give the maximum range to make jumps
    for ( size_t j = i+1; j <= l; j++ ) {
        if( m <= a[j] ) {
            m = a[j];
            i = j;
        }
    }
    return i;
}

int min_step( int a[], int n) {

    int i = 0, t = a[i] , s = 0;
    while ( i < n-1 ) {

        if ( i < n-1 && (t+i) < n) { //if we are less than last number we run the following

            i = best_step(a,i,t,n);
            t = a[i]; 
            s++;

        }
        else {
            s++;
            break;
        }

        if( t == 0 ) {
            cout << "I am stuck at 0 help me :(";
            return 0;
        }
    }

    return s;
}
