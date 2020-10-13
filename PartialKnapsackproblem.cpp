#include<bits/stdc++.h>
using namespace std;
class item
{
public:
    int value,weight;

};
bool cmp(item a, item b)
{
    double r1=(double)a.value/a.weight;
    double r2=(double)b.value/b.weight;
    return(r1>r2);
}
double fractionalKnapsack(int W,class item a[],int n)
{
    sort(a, a+n,cmp);
    int curWeight=0;
    double finalvalue=0.0;
    for(int i=0;i<n;i++)
    {
        if(curWeight+a[i].weight<=W)
        {
            curWeight+=a[i].weight;
            finalvalue+=a[i].value;
        }
        else
        {
            int remain=W-curWeight;
            finalvalue+=a[i].value*((double)remain/a[i].weight);
            break;
        }
    }
    return finalvalue;
}
int main()
{
    int W=50;
    item a[]={{60, 10}, {100, 20}, {120, 30}};
    int n = sizeof(a) / sizeof(a[0]);

    cout << "Maximum value we can obtain = "
         << fractionalKnapsack(W, a, n);
    return 0;
}
