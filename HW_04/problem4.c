#include <stdio.h>

typedef struct HardwareData HardwareData;

void textFile(FILE* file);
void updateRecord(FILE* file);
void newRecord(FILE* file);
void deleteRecord(FILE* file);

int enterYourChoice(void);

struct HardwareData {
    int idNum;
    char nameOfTool[30];
    int quantity;
    double cost;
};

int main(void) {
    FILE* file;
    int choice;
    
    if ((file = fopen("hardware.dat", "rb+")) == NULL){
        printf("File could not be opened.\n");
    } 
    else {
        while ((choice = enterYourChoice()) != 5){
            switch (choice) {
                case 1:
                    textFile(file);
                    break;
                case 2:
                    updateRecord(file);
                    break;
                case 3:
                    newRecord(file);
                    break;
                case 4:
                    deleteRecord(file);
                    break;
                default:
                    printf("Incorrect choice\n");
                    break;
            }
        }
        fclose(file);
    }
}

// enter the choice of what you want to do
int enterYourChoice(void){
    int choice;
    
    printf("\nEnter your choice:\n"
            "1 - store a formatted text file of hardware called \"hardware.txt\" for printing\n"
            "2 - update a record\n"
            "3 - add new record\n"
            "4 - delete a record\n"
            "5 - end program\n");
    
    scanf("%d", &choice);
    return choice;
}

// the text file
void textFile(FILE* file) {
    FILE* write;
    HardwareData data = {0, "", 0, 0.0};

    if ((write = fopen("hardware.txt", "w")) == NULL) {
        printf("File could not be opened");
    } else {
        rewind(file);
        fprintf(write, "%s %s %s %s\n", "id", "Tool name", "Quantity", "Cost");

        while (!feof(file)) {
            fread(&data, sizeof (HardwareData), 1, file);
            if (data.idNum != 0) {
                fprintf(write, "%d %s %d %f\n", data.idNum, data.nameOfTool, data.quantity, data.cost);
            }
        }
        fclose(write);
    }
}

// method to update the record
void updateRecord(FILE* file) {
    int id;
    int quantity;
    double cost;

    HardwareData data = {0, "", 0, 0.0};
    printf("Enter id to update (1-100): ");
    scanf("%d", &id);

    fseek(file, (id - 1) * sizeof (HardwareData), SEEK_SET);
    fread(&data, sizeof (HardwareData), 1, file);

    if (data.idNum == 0) {
        printf("No data found\n");
    } else {
        printf("%d %s %d %f\n", data.idNum, data.nameOfTool, data.quantity, data.cost);
        printf("Enter new quantity: ");
        scanf("%d", &quantity);
        data.quantity = quantity;
        printf("\nEnter new price: ");
        scanf("%lf", &cost);
        data.cost = cost;
        printf("%d %s %d %f\n", data.idNum, data.nameOfTool, data.quantity, data.cost);
        fseek(file, (id - 1) * sizeof (HardwareData), SEEK_SET);
        fwrite(&data, sizeof (HardwareData), 1, file);
    }

}

// method for new record
void newRecord(FILE* file) {
    HardwareData data = {0, "", 0, 0.0};
    int id;
    
    printf("Enter new id (1-100): ");
    scanf("%d", &id);
    
    fseek(file, (id - 1) * sizeof (HardwareData), SEEK_SET);
    fread(&data, sizeof (HardwareData), 1, file);
    
    if (data.idNum != 0) {
        printf("Id already contains information.\n");
    } 
    else {
        printf("Enter new name, quantity, and price: ");
        scanf("%s%d%lf", (char*)&data.nameOfTool, &data.quantity, &data.cost);
        data.idNum = id;
        fseek(file, (id - 1) * sizeof (HardwareData), SEEK_SET);
        fwrite(&data, sizeof (HardwareData), 1, file);
    }

}

// method to delete record
void deleteRecord(FILE* file) {
    HardwareData data;
    HardwareData blankData = {0, "", 0, 0.0};
    int id;
    
    printf("Enter id to delete (1-100): ");
    scanf("%d", &id);
    
    fseek(file, (id - 1) * sizeof (HardwareData), SEEK_SET);
    fread(&data, sizeof (HardwareData), 1, file);
    
    if (data.idNum == 0) {
        printf("No data found\n");
    } else {
        fseek(file, (id - 1) * sizeof (HardwareData), SEEK_SET);
        fwrite(&blankData, sizeof (HardwareData), 1, file);
    }
}