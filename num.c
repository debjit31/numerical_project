#include<stdio.h>
#include<stdlib.h>
#include<math.h>
float fn1(float x, int m,int n, float c)
{
	float func;
	func = pow(x,m) +n*x + c;
	return func;
}
float fn3(float x, int m,int n, float c)
{
    float func;
	func = pow(x,m) +n*x + c;
	return func;
}
float fx(float x, int m,int n, float c)
{
	float func;
	func = pow(x,m) +n*x + c;
	return func;
}
float dfx(float x, int m,int n)
{
	return m*pow(x,m-1) +n;
}
void bisection()
{
	float a, b,c,x;
	int i = 1,m,n;
	printf("\nEquation to be solved => x^m + n*x + c = 0\n");
	printf("Enter the values of m,n,c :\n");
	printf("m : ");
	scanf("%d",&m);
	printf("n : ");
	scanf("%d",&n);
	printf("c : ");
	scanf("%f",&c);
	//printf("Enter the precision level (e) : ");
	//scanf("%f",&e);
	
	printf("Enter a number = ");
	scanf("%f",&a);
	printf("Enter a number = ");
	scanf("%f",&b);
	if(fn1(a,m,n,c)*fn1(b,m,n,c)>=0)
	{
		printf("Wrong Range Selected!!!!\n");
		bisection();
	}
	else
	{
		printf("\nBisection Method\n");
		printf("\nN\t");       
		printf("A\t\t");
		printf("B\t\t");
		printf("Xn+1\t\t");
		printf("f(Xn+1)\n\n");
		do{
			printf("%d\t",i);
			printf("%f\t",a);
			printf("%f\t",b);
			x=(a+b)/2;
			printf("%f\t",x);
			printf("%f\n",fn1(x,m,n,c));
			if(fn1(x,m,n,c) == 0)
			{
				printf("The root is = %.4f",x);
			}
			else if(fn1(a,m,n,c)*fn1(x,m,n,c)<0)
				b=x;
			else
				a=x;
		  }while(fabs(a-b)>0.0001);
		printf("The root is = %.4f",x);
	}
}
void regula_falsi()
{
	int itr = 1,m,n;
    float a,b,c,x;
    
    printf("\nEquation to be solved => x^m + n*x + c = 0\n");
	printf("Enter the values of m,n,c :\n");
	printf("m : ");
	scanf("%d",&m);
	printf("n : ");
	scanf("%d",&n);
	printf("c : ");
	scanf("%f",&c);
    printf("\nEnter the values of a, b :\n");
    scanf("%f %f",&a, &b);
    if (fn3(a,m,n,c)*fn3(b,m,n,c) > 0)
    {
    	printf("\nWrong range selected.\n");
    	regula_falsi();
	}
    else
	{
		printf("\nRegula Falsi Method\n");
		printf("\nN\t");       
		printf("Xn-1\t\t");
		printf("Xn\t\t");
		printf("f(Xn-1)\t\t");
		printf("f(Xn)\t\t");
		printf("Xn+1\t\t");
		printf("f(Xn+1)\n\n");
		do{
		printf("%d\t",itr);
		printf("%f\t",a);
		printf("%f\t",b);
		printf("%f\t",fn3(a,m,n,c));
		printf("%f\t",fn3(b,m,n,c));
		x = a - (((b - a)*fn3(a,m,n,c)) / (fn3(b,m,n,c) - fn3(a,m,n,c)));
        printf("%f\t",x);
        printf("%f\n",fn3(x,m,n,c));
		itr++;
        if (fn3(a,m,n,c) * fn3(x,m,n,c) < 0 )
        	b = x;
        else
        	a = x;
	    //printf("\n%d\t\t%f %f %f %f\n",itr,a,b,x,fn3(x)) ;   
       	}while (fabs(fn3(x,m,n,c))>=0.0001);
       	printf("\nThe root is = %f\n", x);
  	}     
	
}

void newton_raphson()
{
	float a,b,c,k;
	int m,n;
	printf("\nEquation to be solved => x^m + n*x + c = 0\n");
	printf("Enter the values of m,n,c :\n");
	printf("m : ");
	scanf("%d",&m);
	printf("n : ");
	scanf("%d",&n);
	printf("c : ");
	scanf("%f",&c);
	printf("Enter a number :- ");
	scanf("%f",&a);
	printf("Enter a number :- ");
	scanf("%f",&b);
	int i =0 ;
	if(fx(a,m,n,c)*fx(b,m,n,c)>0)
	{
		printf("Wrong Range selected!!!!\n");
		newton_raphson();
	}	
	else
	{
		printf("\nNewton Raphson method\n");
		printf("\nN\t\t");       
		printf("Xn\t\t\t");
		printf("Xn+1\t\t\t");
		printf("f(Xn+1)\n");
		k = (a+b) / 2;		
		do{
			    printf("%d\t\t",i);
			    i++;
			    printf("%f\t\t",k);           			 
			    k= k - (fx(k,m,n,c)/dfx(k,m,n));
			    printf("%f\t\t",c);
          		    printf("%f\n",fx(k,m,n,c));
		  }while(fabs(fx(k,m,n,c))>0.0001);
		  printf("The root is = %f",k);
	}
}
int main()
{
	int ch;
	printf("Welcome to numerical project!!!\n");
	while(1)
	{
		printf("\n\nFind the roots of a transdental equation by anyone of the following methods.\n1.Bisection Method\n2.Regula Falsi Method\n3.Newton Raphson Method\n4.Exit\nEnter your choice :- ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				bisection();
			break;
			case 2:
				regula_falsi();
			break;
			case 3:
				newton_raphson();
			break;
			case 4:
				exit(0);
			break;
			default:
				printf("Wrong Choice!!!");
		}	
	}
}




