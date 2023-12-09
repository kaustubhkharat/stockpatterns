#include <stdio.h>

int isPivot(int prices[], int size, int index, int leftRange, int rightRange){
	int i=index-leftRange,h=index,l=index;
	if (i<0) i=0;
	while (i<size&&i<index+rightRange){
		if (prices[h]<prices[i]) h=i;
		if (prices[l]>prices[i]) l=i;
		i++;
	}
	if (h==index) return 1;
	if (l==index) return -1;
	return 0;			
}

