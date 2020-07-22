#include <stdio.h> 
#include <stddef.h>
#include <stdint.h> 
#include <netinet/in.h>

uint32_t ConvertNetByteOrder(uint32_t data)
{
	return ntohl(data);
}

int main(int argc, char* argv[])
{
	FILE *fp1, *fp2;
	uint32_t File1, File2,Result;
    if(argc != 3)
        return printf("Usage: %s <File1> <File2>\n", argv[0]);

    fp1 = fopen(argv[1],"rb");
    fp2 = fopen(argv[2],"rb");
	
    fread(&File1, sizeof(uint32_t), 1, fp1);
    fread(&File2, sizeof(uint32_t), 1, fp2);
	
    File1 = ConvertNetByteOrder(File1);
    File2 = ConvertNetByteOrder(File2);
    Result = File1+File2;
	
    printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", File1, File1, File2, File2, Result, Result);

    fclose(fp1);
    fclose(fp2);
    return 0;
}
