#ifndef __DEF_INSIDE__
#define __DEF_INSIDE__

#include <stdint.h>
#include <stdio.h>

#ifndef X
#error X is not defined.
#endif /* X */

#define Ceilings ((X)*(X))
#define OneLine ((X)*((Ceilings)+1)/2)

	typedef int16_t MSTYPE;

	enum{
		FALSE, TRUE
	};

#endif /* __DEF_INSIDE__ */
