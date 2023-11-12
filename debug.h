#include <stdio.h>
#include <math.h>

#include "colors.h"

#ifndef NDEBUG
#define ASSERT(a)                                                   \
    do                                                              \
    {                                                               \
        if (!(a))                                                   \
            {                                                       \
                printf (RED "Ошибка! \n" RED);                      \
                printf (RED "В файле: %s \n" RED , __FILE__);       \
                printf (RED "В функции: %s \n" RED, __func__);      \
                printf (RED "В строке: %d \n" BLACK , __LINE__);    \
                abort ();                                           \
            }                                                       \
    }                                                               \
    while (0);
#else
#define ASSERT(a)
#endif

#define $ fprintf(stderr, ">>> %s (%d) %s\n", __FILE__, __LINE__, __PRETTY_FUNCTION__);
