#include <stdio.h>
#include <stdlib.h>
typedef int Item;
#define MIN(a,b) ((a)<(b)?(a):(b))
void sort_merge(Item a[],size_t lo, size_t hi){

   if (hi <= lo) return;
   size_t mid = (lo+hi)/2;
   sort_merge(a,lo,mid);
   sort_merge(a,mid+1,hi);
   merge(a,lo,mid,hi);

}

void merge( Item a[], size_t lo, size_t mid, size_t hi){
   Item *tmp = malloc(sizeof(Item) * hi-lo +1);
   size_t i = lo, j = mid +1, k=0;
   // scan both segement, copy to 'tmp'
   while( i <= mid && j <= hi){
      if( a[i] < a[j]){
         tmp[k] = a[i];
         k++;
         i++;
      }else{
         tmp[k] = a[j];
         k++;
         j++;

      }


   }
   while( i <= mid) {

      tmp[k++] = a[i++];
   }
   while( j <= hi ){
       tmp[k++] = a[j++];
   }

   for(i =lo,k =0;i<=hi;a[i++] = tmp[k++])
   free(tmp);

}


/////////////////// NONE RECURSIVE WAY


void 

