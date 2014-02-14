#include "def.h"

void combineTop()
{

}

void combineGeneral()
{

}

_Bool autofillLast(MSTYPE square[Ceilings])
{
	int i, j;
	int sum1, sum2;


	/* demand the sum of the left vertical line */
	for(i=0, sum1=0; i<Ceilings-X; i+=X)
		sum1+=square[i];

	/* demand the sum of the right-top to left-down diagonal line */
	for(i=0, sum2=0; i<X-1; i++)
		sum2+=square[i*X+(X-1-i)];

	/* check whether the sums are the same or not because they should be the same in a magic square */
	if(sum1!=sum2)
		return FALSE;
	else{
		/* check whether the left-down mass is larger than the top-right mass or not */
		if(!(OneLine-sum1>square[X-1]))
			return FALSE;

		/* now everything is OK for this mass; let's substitute the number */
		square[X*(X-1)]=OneLine-sum1;
	}


	/* demand the sum of the right vertical line */
	for(i=X-1, sum1=0; i<Ceilings; i+=X)
		sum1+=square[i];

	/* demand the sum of the left-top to right-down diagonal line */
	for(i=0, sum2=0; i<X-1; i++)
		sum2+=square[i*X+i];

	/* check whether the sums are the same because they should be the same in a magic square */
	if(sum1!=sum2)
		return FALSE;
	else{
		/* check whether the right-down mass is larger than the top-left mass or not */
		if(!(OneLine-sum1>square[0]))
			return FALSE;

		/* now everything is OK for this mass; let's substitute the number */
		square[X*X-1]=OneLine-sum1;
	}


	/* fill the empty masses below */
	/* note that the left-down one and the roght-down one are not filled in here because they are filled in above processes */
	for(i=1; i<X-1-1; i++){
		for(j=i, sum1=0; j<Ceilings-X; j+=X)
			sum1+=square[j];
		square[X*(X-1)+1+i]=OneLine-sum1;
	}

	return TRUE;
}
