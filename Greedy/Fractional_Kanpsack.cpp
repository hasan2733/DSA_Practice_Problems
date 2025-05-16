#include <iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

int main()
{
    int n,w; cin>>n>>w;
    vector<double>val(n),wt(n);
    for(int i=0;i<n;i++){
      cin>>val[i]>>wt[i];
    }
    vector<pair<double,double>>profit(n);
    for(int i=0;i<n;i++){
      double x = val[i]/wt[i];
      profit[i].first = x;
      profit[i].second = wt[i];
    }
    sort(profit.rbegin(),profit.rend());
    int remaining_capacity = w;
    double sum=0;
    for(int i=0;i<n;i++){
      int item_weights = profit[i].second;
      if(item_weights<=remaining_capacity){
        sum+=item_weights*profit[i].first;
        remaining_capacity-=item_weights;
      }
      else{
        sum+=remaining_capacity*profit[i].first;
        break;
      }
    }
    cout<<sum<<endl;
}
// input      output 240
// 3 50
// 60 10
// 100 20
// 120 30
