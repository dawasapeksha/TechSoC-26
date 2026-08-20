#include <iostream>
using namespace std;

int main (){
    int c,n;
    cout << "Enter capacity\n";
    cin >> c;
    cout << "Enter number of containers\n";
    cin >> n;

    double weight[n];
    for ( int i=0; i<n; i++){
        cout << "Enter weight of container" << i+1 << endl;
        cin >> weight[i];
    }

    int sum=0;
    for ( int k=0; k<n; k++){
        sum+=weight[k];
    }
    cout << "total shipment weight:" << sum << endl;

    double average;
    average=sum/n;
    cout << "average container weight:" << average << endl;

    double h=weight[0];
    for( int a=0; a<n; a++){
    if ( h < weight[a]){
        h=weight[a];
    }
    }

    double l=weight[0];
    for( int b=0; b<n; b++){
    if ( l > weight[b]){
        l=weight[b];
    }
}
    cout << "Heaviest container = " << h << endl;
    cout << "lightest container = " << l << endl;

    if (sum>=200){
        cout <<  "Heavy" << endl;
    }
    else {
        cout << "light" << endl;
    }

    cout << "Port capacity = " << c << endl;

    if(sum<= c){
        cout << "Shipment can be unloaded" << endl;
    }
    else{
        cout << "Shipment exceeds port capacity" << endl;
    }
    return 0;
}