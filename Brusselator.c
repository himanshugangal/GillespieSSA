// Solving the Brusselators reactions. 
// X1 bar -> Y1
// X2 bar + Y1 -> Y2 + Z1 
// 2Y1 + Y2 -> 3Y1 
// Y1 -> Z2 

// any component in bar represents that it is present in the system in abundance.
// will deal with 2 components here, y1 and y2 

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
float a[4],a0,r1,r2,tau,t,m ; 
int i,rxn,p,j,n,y1,y2;
FILE *fp ; 
fp = fopen("curve4.txt","w");
t = 0 ; 
m = 4 ; 
n = 0 ; 
y1 = 1000;
y2 = 2000;
for(i=0;i<=1000000;i++)
{
a[0] = 5000;
a[1] = 50*y1;
a[2] = 0.00005*y1*y2*(y1-1)/2 ;
a[3] = 5*y1;
a0 = a[0] + a[1] + a[2] + a[3];

p = rand()%100 ;
if(p==0){ p = rand()%100 ; }
r1 = (p+0.5)/100.0; 
tau = (1/a0)*log(1/r1);

p = rand()%100 ;
if(p==0){ p = rand()%100 ; }
r2 = (p+0.5)/100.0; 
if((r2>0)&&(r2<a[0]/a0)){ rxn = 1; } 
else if((r2>a[0]/a0)&&(r2<(a[0]+a[1])/a0)) { rxn = 2; } 
else if((r2>(a[0]+a[1])/a0)&&(r2<(a[0]+a[1]+a[2])/a0)) { rxn = 3; }
else if((r2>(a[0]+a[1]+a[2])/a0)&&(r2<1)) { rxn = 4; }
if(rxn == 1){
y1 = y1 + 1; 
t = t + tau; 
n = n + 1;
fprintf(fp,"%d \t %d \t %f \t %f \t %d \t %d \t %d \t %f \t %f \n ",y1,y2,t,tau,i,n,1,r1,r2);
}

else if(rxn ==2){ 
y1 = y1 - 1;
y2 = y2 + 1;
t = t + tau;
n = n + 1;
fprintf(fp,"%d \t %d \t %f \t %f \t %d \t %d \t %d \t %f \t %f \n ",y1,y2,t,tau,i,n,2,r1,r2);
}

else if(rxn == 3 ){ 
y1 = y1 + 1; 
y2 = y2 - 1;
t = t + tau;
n = n + 1;
fprintf(fp,"%d \t %d \t %f \t %f \t %d \t %d \t %d \t %f \t %f \n ",y1,y2,t,tau,i,n,3,r1,r2);
}

else if(rxn == 4 ){ 
y1 = y1 - 1;
t = t + tau;
n = n + 1;
fprintf(fp,"%d \t %d \t %f \t %f \t %d \t %d \t %d \t %f \t %f \n ",y1,y2,t,tau,i,n,4,r1,r2);
}

}



}

