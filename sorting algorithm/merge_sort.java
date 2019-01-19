public class merge_sort_algrithm{
   public static void merge_sort(int[] array){
      mergesort(array,new int[array.length],0,array.length -1);
   }
   public static void mergesort(int[] array, int[] tmp,int lo, int hi){
      if(lo>= hi) return;
      int mid= (lo+hi)/2
      mergesort(array,tmp,lo,mid);
      mergesort(array,tmp,mid+1,hi);
      merge(array,lo,hi);

   }
   public static void merge(int[] array,int[] tmp, int leftstart,int rightend){
      int leftend = (leftstart+rightend) /2;
      int rightstart = leftend +1;
      int left_curr = 0;
      int right_curr = 0;
      int index =0; 
      for(; left_curr<= leftend&& right_curr<= rightend;){
         if (array[left_curr] < array[right_curr]){
            tmp[index]=array[left_curr];
            index++;
            left_curr++;

         }else{
            tmp[index]=array[right_curr];
            index++;
            right_curr++;

         }

      } 
      // copy the rest of array
      while( right_curr <= rightend){
         tmp[index]=array[right_curr];
         index++;
         right_curr++;

      }
      while( left_curr <= leftend){
         tmp[index]=array[left_curr];
         index++;
         left_curr++;

      }
      System.arraycopy(tmp,leftstart,array,leftstart,rightend-leftstart+1);

   }

}

