#include <stdio.h>
#include "pivotPoints.c"

int isHandS(int prices[],int size){
	int h=0,i=0,highs[5],lows[5],l=0;
	float suppSlope,m,y,x;
	
	while (l<5&&h<5&&i<size){
		if (isPivot(prices,size,i,3,3) == 1) highs[h++]=i;
		if (isPivot(prices,size,i,3,3) == -1) lows[l++]=i;
		i++;
	}

	for (i=1;i<l;i++){
		m=(float)(prices[lows[i]]-prices[lows[i-1]])/(lows[i]-lows[i-1]);
		suppSlope+=m;
	}
	if (suppSlope<0) return -1;
	if (suppSlope>0) return 1;
	return 0;
}
