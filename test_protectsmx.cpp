#include "protectsmx.h"

#include <cstdlib>


int main(int argc, char const *argv[])
{
	FILE *fp = protect_read_smx(argv[1], "rb");

	fseek(fp, 0, SEEK_END);
	long fsize = ftell(fp);
	fseek(fp, 0, SEEK_SET);

	char *content = (char*)malloc(fsize);
	fread(content, fsize, sizeof(char), fp);
	fclose(fp);

	fp = fopen("decrypted", "wb");
	fwrite(content, sizeof(char), fsize, fp);
	fclose(fp);

	free(content);
	return 0;
}
