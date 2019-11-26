#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{
	FILE *fp1, *fp2;
	int randNum[10];
	int i, sum = 0;
	
	srand(time(NULL));

	fp1 = fopen("random.txt", "wt");
	if (fp1 == NULL) {
		printf("file1 open error\n");
		return 1;
	}

	for (i = 0; i < 10; i++) {
		randNum[i] = rand() % 100;
		fprintf(fp1, "%d\n", randNum[i]);
	}

	fclose(fp1);

	fp1 = fopen("random.txt", "rt");
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
	fscanf(fp1, "%d", &randNum[i]);
	while(!feof(fp1)) {
		fprintf(fp2, "%d\n", randNum[i]);
		printf("%d  ", randNum[i]);
		sum += randNum[i];
		fscanf(fp1, "%d", &randNum[i]);
		i++;
	}
	printf("\n합은 %d\n", sum);
	fprintf(fp2, "합은 %d\n", sum);

	fclose(fp1);
	fclose(fp2);

}