	#include <iostream>
	#define inf -1
	using namespace std;

	void printUsedCoins(int* coin_parent , int amount);
	bool isGreaterThan(int a , int b);
	int* create_n_array(int value);
	int change(int *coins, int s , int value);



    int main()
    {
       int *coinArr, no_of_coins , value, n=0;
       cout<< "Input number of denominations "<<endl;
       cin>> no_of_coins ;
       coinArr = new int[no_of_coins];
       while(n!=no_of_coins)
       {
            cout<< "Input coins "<<endl;
            cin>> coinArr[n] ;
            n++;
       }
       cout<< "Input the amount "<<endl;
       cin>> value ;
       cout<<endl << "Number of coins required " << change(coinArr,no_of_coins,value);


       return 0;
    }


	bool isGreaterThan(int a , int b)
		{
		    bool result = false ;

			if(a!=-1 && b!=-1)
			{
				result = a>b ;
			}
			else if( a==-1  )
			{
				if(b!=-1) result=true;
			}
	     	return result;
		}


	int* create_n_array(int value)
	    {
	       int *a = new int[value+1];
	       a[0] =0;
	       for(int i=1; i<=value ; i++ )
	       {
	        a[i]=inf;
	       }
	       return a;
	    }

	int change(int *coins, int s , int value)
	    {
	     int *Current_value = create_n_array(value);
	     int *Parent_Coins_Used = create_n_array(value);
	     int coinUsed ;

	     for(int v =1 ; v<=value ; v++)
	     {
	        coinUsed = inf;
	        for(int i =0 ; i <s ; i++)
	        {
	        	if( coins[i]<=v )
	            {
	            /* Current_value[v] > Current_value[ v - coins[i] ] + 1) */
            	if(isGreaterThan( Current_value[v] , Current_value[ v - coins[i] ] + 1))
                {
                     Current_value[ v ] = Current_value[ v - coins[i] ]  + 1 ;
                     coinUsed=i ;
				}
	            }
	        }

	        Parent_Coins_Used[ v ] = coins[coinUsed]; // storing index of the used coin
		 }
	     cout<< endl << "The coins used are " <<endl;
		 printUsedCoins(Parent_Coins_Used , value);
	     return Current_value[value];

	    }


    void printUsedCoins(int* coin_parent , int amount)
        {
            if(amount==0) return ;
            printUsedCoins(coin_parent, amount-coin_parent[amount]);
            cout<< " " <<coin_parent[amount] << " ";
        }










