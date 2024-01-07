#include <stdio.h>
#include "decideplayer.h"

int decideplayer(int stepcounter)
{
    if (stepcounter % 2 == 0)
    {
        return 1;
    }
    else 
    {
        return 2;
    }
}