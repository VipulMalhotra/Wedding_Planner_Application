#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
int a[500][500];
FILE *ptr=fopen("Hamilton_Cycle_500_Input.txt","r");
int i,j;
for(i=0;i<500;i++){
for(j=0;j<500;j++){
fscanf(ptr,"%d",&a[i][j]);
}
}
for(i=0;i<500;i++){
cout<<"Person-"<<i<<" knows- ";
for(j=0;j<500;j++){
if(a[i][j]==1){
cout<<j<<", ";
}
}
cout<<endl;
}
fclose(ptr);
return 0;


}
