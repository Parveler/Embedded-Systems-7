#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
uint32_t* createSortedIntArray(uint32_t len);
bool binarySearch(uint32_t* pIntValues, uint32_t len, uint32_t search_element);


int main(void) {
  uint32_t* pIntValues = createSortedIntArray(1000);
  for (int i = 0; i < 1000; i += 1){
  binarySearch(pIntValues, 1000, i);
    usleep(1000*100);
  }
  return 0;
}

static int64_t recursiveSearch(uint32_t lowArrayBorder, uint32_t highArrayBorder, uint32_t* pIntValues, uint32_t search_element) {
  
  if (lowArrayBorder > highArrayBorder){
    return -1;
  }
  
  uint32_t midValue = lowArrayBorder + (highArrayBorder - lowArrayBorder) / 2;
  
  if (pIntValues[midValue] == search_element){
    return midValue;
  }
  else if (pIntValues[midValue] > search_element){
    return recursiveSearch(lowArrayBorder, midValue - 1, pIntValues, search_element);
  }
  else{
    return recursiveSearch(midValue + 1, highArrayBorder, pIntValues, search_element);
  }
}




uint32_t* createSortedIntArray(uint32_t len){
  uint32_t* pIntValues = malloc(sizeof(uint32_t) * len);
  if(pIntValues == NULL){
    printf("Error Occurred, not enough free memory to allocate IntValues\n");
    return NULL;
  }
  for(int i = 0; i < len; i += 1){
    pIntValues[i] = i;
  }
  return pIntValues;
}

bool binarySearch(uint32_t* pIntValues, uint32_t len, uint32_t search_element){
  uint32_t lowArrayBorder = 0;
  uint32_t highArrayBorder = len - 1;
  int64_t result = recursiveSearch(lowArrayBorder, highArrayBorder, pIntValues, search_element);
  if( result < 0){
    printf("The element is not part of the list\n");
    return false;
  }
  else{
  printf("The searched number is element of the given Integer-Array. Its position in the array is: %ld \n", result);
  return true;
  }
}
