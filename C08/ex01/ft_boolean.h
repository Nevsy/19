#ifndef EVEN_MSG
	#define EVEN_MSG "I have an even number of arguments."
#endif
#ifndef ODD_MSG
	#define ODD_MSG "I have an odd number of arguments."
#endif
#ifndef EVEN
	#define EVEN(x) (x % 2 == 0 ? 1 : 0)
#endif

#include <unistd.h>

typedef enum t_bool
{
	FALSE,
	TRUE
} t_bool;

#ifndef SUCCESS
	#define SUCCESS 0
#endif
