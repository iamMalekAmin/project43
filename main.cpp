// malek mohammed amin
//ID : 20180209
#include <iostream>
#include<chrono>
#include<random>
using namespace std;
double get_c1(double r1)
{
    if (0<= r1 < 0.1)
            return 43;
        else if(0.1<=r1<0.3)
            return 44;
        else if (0.3<= r1< 0.7)
            return 45;
        else if (0.7<= r1< 0.9)
            return 46;
        else if (0.9<= r1< 1)
            return 47;
}
double get_x(int N)
{
     unsigned seed = chrono::steady_clock::now().time_since_epoch().count();
    default_random_engine e (seed);

     normal_distribution<double> distN(15000,4500);
    for (int i=1; i<=N; i++)
    {
     return distN(e);
    }
}
int main()
{

    int PricePerUnit = 249 ;
    int TotalCost = 1000000;
    double c1,c2;
    int a=80 , b=100 ;
    float counter =0, o=0 ;
    double x;
    double sum=0 ;
    int N, k=0 ;
    cerr<<"enter number of tiers \n ";
    cin>>N;
    double profit[N], posProfit[N], arrc1[N], arrc2[N],arrx[N];
    srand((unsigned)time(NULL));
    for(int i=1;i<=N;i++)
    {
        double r1 = ((double) rand()/ (RAND_MAX));
        double r2 = ((double) rand()/ (RAND_MAX));
        //<< r1<< "   "<< r2 <<endl ;
        c1 = get_c1(r1);
        arrc1[k]= c1 ;
        c2 = a + r2*(b-a);
        arrc2[k]=c2;
        x=get_x(N);
        arrx[k]=x;
        k++;
        profit[i] = (PricePerUnit-c1-c2)*x - TotalCost;
    }
  for (int i=0; i<N; i++ )
    {
        if (profit[i]<0)
            {
                counter++;
            }
            //cout<< profit[i]<< endl;
    }
    for (int j=0; j<N; j++ )
    {
        if (profit[j]>=0)
            {
                posProfit[j]= profit[j];
                sum = sum + profit[j];
                o++;
            }
           // cout<< posProfit[j]<< endl;
    }
    double average = sum / o ;
    double maximump = profit[0];
    for (int i=1; i < N; i++ )
    {
        if (profit[i]> maximump)
            maximump = profit[i];
    }

    double maximumLoss = profit[0];
    for (int i=1; i < N; i++ )
    {
        if (profit[i]< maximumLoss)
            maximumLoss = profit[i];
    }

    cout << " probability of Loss is "<< counter / N << endl ;
    cout << " maximum profit is "<< maximump<< endl ;
    cout << " maximum Loss is "<< maximumLoss<< endl ;
    cout << " average profit is "<< average<< endl ;

    /*double flag[N]={0};
    for (int i=0 ; i<N ;i++)
    {
        if(flag[i]!=1)
        {
            for(int j=0;j<N;j++)
            {
                if(posProfit[i]==posProfit[j])
                {
                    c++;
                    flag[i]=1;
                }
            }
            if(c>1||c==1)
            {
                cout<<"\n"<<posProfit[i]<< "occers "<<c ;
            }
        }
    }
    int arr[5]={1,2,3,4,5};
    for (int i =0; i<=N-1;i++)
    {
        //cout<<i<<"\t\t"<<posProfit[i]<<"\t\t";
        for(int j =1 ; j<=posProfit[i]; j++)
        {
            cout<<"*";
        }
        cout<< endl;
    }*/
    return 0;
}

