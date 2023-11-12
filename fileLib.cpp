#include "fileLib.h"
#include "debug.h"

size_t GetFileSize(FILE* file)
{
    ASSERT(file != nullptr);

    fseek(file, 0, SEEK_END);

    size_t size = ftell(file);

    fseek(file, 0, SEEK_SET);

    return size;
}

void ReadBufToText(FileData* fileData)
{
    ASSERT(fileData != nullptr);

    for (size_t i = 0; i < fileData->bufSize; i++)
    {
        if (fileData->buf[i] == '\0')
            fileData->text[i] = fileData->buf + i;
    }
}

size_t CountLines(FileData* fileData)
{
    ASSERT (fileData != nullptr);

    size_t counter = 0;
    for (size_t i = 0; i < fileData->bufSize; i++)
    {
        if (fileData->buf[i] == '\n')
        {
            counter++;
        }
    }
    return counter;
}

void SwapChars(FileData* fileData)
{
    ASSERT(fileData != nullptr);
    for (size_t i = 0; i < fileData->bufSize; i++)
    {
        if (fileData->buf[i] == '\n') 
        {
            fileData->buf[i] = '\0';
        }
    }
}


void FileRead(FILE* file, FileData* fileData)
{
    ASSERT(file != nullptr);
    ASSERT(fileData != nullptr);

    fread(fileData->buf, sizeof(char), fileData->bufSize, file);
    *(fileData->buf + fileData->bufSize - 1)  = '\0';
}

void Freedom(FileData* fileData)
{
    ASSERT(fileData != nullptr);

    free(fileData->buf);
    free(fileData->text);
}

void PrintfBuf(FileData* fileData)
{
    ASSERT(fileData != nullptr);
    printf("#  bufSize: %lu\n", fileData->bufSize);
    printf("#  textSize: %lu\n", fileData->textSize);
    for (size_t i = 0; i < fileData->textSize; i++)
        printf("%s", fileData->text[i]);
}

void ParseFile(FILE* file, FileData* fileData) 
{
    ASSERT (file != nullptr);
    ASSERT (fileData != nullptr);

    fileData->bufSize = GetFileSize(file) + 1;
    fileData->buf = (char*)calloc(fileData->bufSize, sizeof(char)); 

    FileRead (file, fileData); 

    fileData->textSize = CountLines(fileData);
    fileData->text = (char**)calloc(fileData->textSize, sizeof(char*));
    SwapChars(fileData);

    PrintfBuf(fileData);  
}

