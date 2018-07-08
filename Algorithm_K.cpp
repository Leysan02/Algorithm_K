// Algorithm_K.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <math.h>
#include <ctime>
#include <iostream>
using namespace std;

int mypow(int a, int n){
	if(n==0)
		return 1;
	long int res=a;
	for(int i=0; i<n-1; i++)
		res*=a;
	return res;
}
int binpow(int a,int n){
	if(n==0)
		return 1;
	if(n%2==1)
		return binpow(a,n-1)*a;
	else{
		int b= binpow(a,n/2);
		return b*b;
	}

}

int _tmain(int argc, _TCHAR* argv[])
{
	char exit='0';
	long double X;
	long long iX, temp;
	__int64 tX;//тжс что long long
	int Y, Z, Nd;
	int *dig = new int [10];//массив цифр чиcла Х;
	bool Xchanged = true;
	scanf_s("%lf", &X);
	printf_s("\nX = %lf", X);
	Y=X/1000000000.0;		
	printf_s("\nY = %i\n", Y);
	while(exit == '0'){
		if(Xchanged == false)
			Z=Z+1;
		else {
		Z=X/100000000.0;
		Z=Z%10+3;
		}
		printf_s("step K%i\n", Z);
		Xchanged = false;
			switch(Z){
			case 3: 
				if(X<5000000000){
					X=X+5000000000;
					Xchanged = true;
				}
				printf_s("K%d: X = %lf\n", Z, X);
			case 4:
				{/*iX=floor(X*X/100000);// этот код не обрезает Х^2/100000, а округляет число, из-за чего алгК искажается уже на шаге К4. 
				X=iX%10000000000;*///обойдем это так:
				X=X*X/1000.0;
				//printf_s("\nxx=%lf\n", X);
				//вычислим число цифр в X
				Nd = 0;
				tX=X;
				//printf_s("\ntx=%I64d\n", tX);
				for(int i=0; tX>0; i++){
					tX/=10;
					Nd++;
				}
				tX=X;
				//printf_s("\ntx=%I64d\n", tX);
				//printf_s("\nNd=%d\n", Nd);
				const int N =Nd;
				int *dig1=new int[N];
				for(int i=N-1; i>=0; i--){
					dig1[i] = tX%10;
					tX/=10;
				}
				printf("\n");
				for(int i=0; i<Nd; i++)
					printf("%d ", dig1[i]);
				X=0;
				for(int i=Nd-3; i>Nd-13; i--)//собираем из цифр середину квадрата
					X+=dig1[i]*pow(10.0, 14-i);
				Xchanged = true;
				printf_s("\nK%d: X = %lf\n", Z, X);}
			case 5:
				iX = 1001001001.0*X;
				X = iX%10000000000;
				Xchanged = true;
				printf_s("K%d: X = %lf\n", Z, X);
			case 6:
				if(X<100000000)
					X=X+9814055677;
				else X = 10000000000-X;
				Xchanged = true;
				printf_s("K%d: X = %lf\n", Z, X);
			case 7:
				iX=X;
				X = (iX%100000)*100000 + floor((double)X/100000);
				printf_s("K%d: X = %lf\n", Z, X);
				Xchanged = true;
			case 8:
				iX = 1001001001.0*X;
				X = iX%10000000000;
				printf_s("K%d: X = %lf\n", Z, X);
				Xchanged = true;
			case 9://полагаем, что в Х 10 цифр
				temp = X;
				for(int i=9; i>=0; i--){
					dig[i] = temp%10;
					if(dig[i]!=0)
						dig[i]-=1;			
					temp/=10;
					printf_s("\n%d\n", dig[i]);
				}
				X=0;//преобразованные цифры числа Х соберем обратно из массива
				for(int i=0; i<10; i++){
					X+=dig[i]*pow(10, 9-i);
				}
				Xchanged = true;
				printf_s("K%d: X = %lf\n", Z, X);
			case 10:
				if(X<10000)
					X = X*X + 99999;
				else X = X - 99999;
				Xchanged = true;
				printf_s("K%d: X = %lf\n", Z, X);
			case 11:
				if(X<1000000000){
					X*=10;
					Xchanged = true;
				}
				if(X<1000000000){
					X*=10;
					Xchanged = true;
				}
				printf_s("K%d: X = %lf\n", Z, X);
			case 12:
				iX = X*(X-1)/10000;
				X = iX%10000000000;
				Xchanged = true;
				printf_s("K%d: X = %lf\n", Z, X);
			case 13:
				if(Y>0)	Y-=1;
				printf_s("K%d: X = %lf\n", Z, X);
				if(Y==0){
					printf_s("Y=%d, res X = %lf\n", Y, X);
					printf_s("Enter 0 if you want to continue, else enter any other sign\n");		
					scanf_s("%c", &exit);
					printf_s("%c", exit);
				}
			}
	}
	int time = clock();
	printf_s("total time=%d ms", time);
	getchar();
	return 0;
}

