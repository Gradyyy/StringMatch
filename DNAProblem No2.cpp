#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
  char dna[101];
  char dnacari[101];
  scanf("%s",&dna);
  scanf("%s",&dnacari);
  char extension[101];
  int temp=0;
  //string modifier
  for(int i=0;i<strlen(dnacari)-1;i++){
    if(i<strlen(dna)){
      extension[i]=dna[i];
    }
    else{
      temp = i % strlen(dna);
      extension[i]=dna[temp];
    }
  }
  strcat(dna,extension);
  //KMP
  int a = strlen(dnacari);
  int b = strlen(dna);
  int table[a];
  int len = 0;
  table[0] = 0;

  for(int i=1;i<a;i++){
    if(dnacari[i]==dnacari[len]){
      len = len+1;
      table[i] = len;
    }
    else{
      if(len!=0){
        len = table[len-1];
      }
      else{
        table[i] = 0;
      }
    }
  }

  int i = 0;
  int j = 0;
  while(i<b){
    if(dnacari[j]==dna[i]){
      i = i+1;
      j = j+1;
    }
    if(j==a){
      printf("Ya\n");
      break;
    }
    else if(i<b && dnacari[j] != dna[i]){
      if(j!=0){
        j = table[j-1];
      }
      else{
        i = i+1;
      }
    }
  }
  if(j!=a){
    printf("Tidak\n");
  }
}
