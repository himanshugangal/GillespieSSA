// Solving a 2 reaction coupled reaction system. 
// X + Y -> 2Y , 2Y -> Z . The concentration of X is assumed to be a constant, hinting the abundance of X in the reaction mixture.

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
float c1,c2,a0,a[2],r1,r2,tau,t,m ; 
int rxn,p,i,j,n,x1,x2,x10,x20,s;
FILE *fp;
fp = fopen("Curve1.txt","w");
t=0;
m = 2; 
n = 0;
x2 = 10000;

for(i=0;i<=10000;i++)
{
a[0] = 5*x2;
a[1] = 0.005*x2*(x2-1)/2.0 ; 
a0 = a[0] + a[1];

p = rand()%100 ;
if(p==0){ p = rand()%100 ; }
r1 = p/100.0; 
tau = (1/a0)*log(1/r1);

p = rand()%100 ;
if(p==0){ p = rand()%100 ; }
r2 = p/100.0; 
if((r2>0)&&(r2<a[0]/a0)){ rxn = 1; } 
else if((r2>a[0]/a0)&&(r2<(a[0]+a[1])/a0)) { rxn = 2; } 

if(rxn == 1){
x2 = x2 + 1; 
t = t + tau; 
n = n + 1;
fprintf(fp,"%d \t %f \t %f \t %d \t %d \t %d %f \t %f \t %f \t %f \n ",x2,t,tau,i,n,1,r1,r2,a[0]/a0,((a[0]+a[1])/a0));

}

else{ 
x2 = x2 - 2;
t = t + tau;
n = n + 1;
fprintf(fp,"%d \t %f \t %f \t %d \t %d \t %d %f \t %f \t %f \t %f \n ",x2,t,tau,i,n,2,r1,r2,a[0]/a0,((a[0]+a[1])/a0));

  }

}
} 
