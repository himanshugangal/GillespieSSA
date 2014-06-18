// Solving the Oregonator reactions. 
// X1 bar + Y2 -> Y1
// Y1 + Y2  -> Z1 
// X2 bar + Y1 -> 2Y1 + Y3  
// 2Y1 -> Z2 
// X3 bar + Y3 -> Y2 
// any component in bar represents that it is present in the system in abundance.
// will deal with 2 components here, y1 and y2 

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main()
{
float a[5],a0,r1,r2,tau,t,m ; 
int i,rxn,p,j,n,y1,y2,y3,ro1,ro2;

FILE *fp ; 
fp = fopen("curve5.txt","w");
t = 0 ; 
m = 5 ; 
n = 0 ; 
y1 = 500;
y2 = 1000;
y3 = 2000;
ro1 = 2000;
ro2 = 50000;
for(i=0;i<=1000000;i++)
{
a[0] = 2*y2 ;
a[1] = (y1*y2)/10.0;
a[2] = 104*y1 ;
a[3] = (2.0/250.0)*y1*(y1-1);
a[4] = 26*y3;
a0 = a[0] + a[1] + a[2] + a[3] + a[4];

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
else if((r2>(a[0]+a[1]+a[2])/a0)&&(r2<(a[0]+a[1]+a[2]+a[3])/a0)) { rxn = 4; }
else if((r2>(a[0]+a[1]+a[2]+a[3])/a0)&&(r2<1)) { rxn = 5; }
if(rxn == 1){
y1 = y1 + 1; 
y2 = y2 - 1;
t = t + tau; 
n = n + 1;
fprintf(fp,"%d \t %d \t %d \t  %f \t %f \t %d \t %d \t %d \t %f \t %f \n ",y1,y2,y3,t,tau,i,n,1,r1,r2);
}

else if(rxn ==2){ 
y1 = y1 - 1;
y2 = y2 - 1;
t = t + tau;
n = n + 1;
fprintf(fp,"%d \t %d \t %d \t %f \t %f \t %d \t %d \t %d \t %f \t %f \n ",y1,y2,y3,t,tau,i,n,2,r1,r2);
}

else if(rxn == 3 ){ 
y1 = y1 + 1; 
y3 = y3 + 1;
t = t + tau;
n = n + 1;
fprintf(fp,"%d \t %d \t %d \t %f \t %f \t %d \t %d \t %d \t %f \t %f \n ",y1,y2,y3,t,tau,i,n,3,r1,r2);
}

else if(rxn == 4 ){ 
y1 = y1 - 2;
t = t + tau;
n = n + 1;
fprintf(fp,"%d \t %d \t %d \t %f \t %f \t %d \t %d \t %d \t %f \t %f \n ",y1,y2,y3,t,tau,i,n,4,r1,r2);
}

else if(rxn == 5 ){ 
y3 = y3 - 1;
y2 = y2 + 1;
t = t + tau;
n = n + 1;
fprintf(fp,"%d \t %d \t %d \t %f \t %f \t %d \t %d \t %d \t %f \t %f \n ",y1,y2,y3,t,tau,i,n,5,r1,r2);
}

}



}

