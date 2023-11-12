#include <stdio.h>

#include "fileLib.h"
#include "sort.h"

int main(int argc, char** argv)
{
    FILE* file = fopen (argv[1], "r");
    FileData onegin = {0};

    ParseFile (file, &onegin);
    fclose (file);

    BubbleSort(onegin.text, onegin.textSize);

    Freedom(&onegin);
    
    return 0;
}
