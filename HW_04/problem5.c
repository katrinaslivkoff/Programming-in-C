#include <stdio.h>
#include <stdlib.h>

int main() {
	int masterFile, transactionFile;
	double masterBalance, transactionBalance;
	char masterName[30];

	FILE *oldMastPtr, *transactionFilePtr, *newMastPtr;

	// The next 3 if statements checks to see if the files are empty
	if ((oldMastPtr = fopen("oldmast.dat", "r")) == NULL) {
		printf("Unable to open oldmast.dat\n");
		exit(1);
	}


	if ((transactionFilePtr = fopen("trans.dat", "r")) == NULL) {
		printf("Unable to open trans.dat\n");
		exit(1);
	}

	if ((newMastPtr = fopen("newmast.dat", "w")) == NULL) {
		printf("Unable to open newmast.dat\n");
		exit(1);
	}

	printf("Processing this file: \n");
	fscanf(transactionFilePtr, "%d%lf", &transactionFile, &transactionBalance);

	// while we are not at the end of the file...
	while (!feof(transactionFilePtr)) {

		fscanf(oldMastPtr, "%d%[^0-9-]%lf", &masterFile, masterName, &masterBalance);

		// while the master file is less than the transaction file number AND we are not at the end of the old master file
		// print the file name next
		while (masterFile < transactionFile && !feof(oldMastPtr)) {
			fprintf(newMastPtr, "%d %s %.2f\n", masterFile, masterName, masterBalance);
			printf("%d %s %.2f\n", masterFile, masterName, masterBalance);
			fscanf(oldMastPtr, "%d%[^0-9-]%lf", &masterFile, masterName, &masterBalance);
		}

		// if the master file and transaction file are the same, 
		// update the master file
		if (masterFile == transactionFile) {
			masterBalance += transactionBalance;
			fprintf(newMastPtr, "%d %s %.2f\n", masterFile, masterName, masterBalance);
			printf("%d %s %.2f\n", masterFile, masterName, masterBalance);
		}

		// if the master file is bigger than the transaction file
		// there is no matching files after the previous one
		else if (masterFile > transactionFile) {
			printf("Unmatched transaction record for the account number: %d\n", transactionFile);
			fprintf(newMastPtr, "%d %s %.2f\n", masterFile, masterName, masterBalance);
			printf("%d %s %.2f\n", masterFile, masterName, masterBalance);
		}
		else {
			printf("Unmatched record for the account number: %d\n", transactionFile);
		}

		fscanf(transactionFilePtr, "%d%lf", &transactionFile, &transactionBalance);
	}

	// while we are not at the end of the old master file
	// print the account num, name, and balance
	while (!feof(oldMastPtr)) {
		fscanf(oldMastPtr, "%d%[^0-9-]%lf", &masterFile, masterName, &masterBalance);
		fprintf(newMastPtr, "%d %s %.2f", masterFile, masterName, masterBalance);
		printf("%d %s %.2f", masterFile, masterName, masterBalance);
	}
	fclose(oldMastPtr);
	fclose(transactionFilePtr);
	fclose(newMastPtr);
}