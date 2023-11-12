#include "sort.h"

void BubbleSort(char** arr, size_t size)
{
    for (size_t pass = 0; pass < size - 1; pass++)
    {
        for (size_t i = 0; i < size - pass + 1; i++)
        {
            if (strcmp(*(arr + i), *(arr + i + 1)) > 0)
            {
                char* temp = *(arr + i);
                *(arr + i) = *(arr + i + 1);
                *(arr + i + 1) = temp;
            }
        }
    }
}
