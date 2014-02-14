#include "def.h"

_Bool checkSum(MSTYPE square[Ceilings])
{
	int i, j;
	int sum;

	for(i=0; i<Ceilings; i+=X){
		for(j=i, sum=0; j<i+X; j++)
			sum+=square[j];
		if(sum!=OneLine)
			return FALSE;
	}

	for(i=0, sum=0; i<X; i++)
		sum+=square[i*X+i];
	if(sum!=OneLine)
		return FALSE;

	for(i=0, sum=0; i<X; i++)
		sum+=square[i*X+(X-1-i)];
	if(sum!=OneLine)
		return FALSE;

	return TRUE;
}
