#include <stdio.h>
#include <ctype.h>
int main(void)
{
	FILE *fp1, *fp2;
	char str[1000]; 
	int i;

	fp1 = fopen("input.txt", "rt");
	if (fp1 == NULL) {
		printf("file1 open error\n");
		return 1;
	}
	fp2 = fopen("output.txt", "wt");
	if (fp2 == NULL) {
		printf("file2 open error\n");
		return 1;
	}

	i = 0;
	fscanf(fp1, "%c", &str[i]);
	while (!feof(fp1)) {
		if (islower(str[i]))
			fprintf(fp2, "%c", toupper(str[i]));
		else
			fprintf(fp2, "%c", str[i]);
		i++;
		fscanf(fp1, "%c", &str[i]);		
	} fprintf(fp2, "\n\n");

	fclose(fp1);
	fclose(fp2);

	fp1 = fopen("input.txt", "rt");
	if (fp1 == NULL) {
		printf("file1 open error\n");
		return 1;
	}
	fp2 = fopen("output.txt", "at");
	if (fp2 == NULL) {
		printf("file2 open error\n");
		return 1;
	}

	i = 0;
	fscanf(fp1, "%c", &str[i]);
	while (!feof(fp1)) {
		if (isupper(str[i]))
			fprintf(fp2, "%c", tolower(str[i]));
		else
			fprintf(fp2, "%c", str[i]);
		i++;
		fscanf(fp1, "%c", &str[i]);		
	}

	fclose(fp1);
	fclose(fp2);
	
}