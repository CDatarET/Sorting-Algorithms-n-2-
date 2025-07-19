#include <stdio.h>
#include <string.h>

/*
    write a program to create a student database using structure and apply sorting techniques
    read name, roll, marks, and division

    bubble sort on roll no ascending
    bubble sort on name descending
    selection sort on marks descending
    insertion sort on name descending order
*/
struct student{
    char name[30];
    int idNum;
    float percent;
    char division;
};

void readData(struct student db[], int n){
    for(int i = 0; i < n; i++){
        printf("Please enter name- \n");
        scanf("%s", db[i].name);

        printf("Please enter roll no.- \n");
        scanf("%d", &db[i].idNum);

        printf("Please enter marks- \n");
        scanf("%f", &db[i].percent);

        printf("Please enter division- \n");
        scanf(" %c", &db[i].division);

        printf("\n");
    }
}

void disp(struct student db[], int n){
    printf("Index\tName\tRoll No\tMarks\tDivision\n");
    for(int i = 0; i < n; i++){
        printf("%d\t%s\t%d\t%.2f\t%c", i, db[i].name, db[i].idNum, db[i].percent, db[i].division);
        printf("\n");
    }
}

void bubbleSort(struct student db[], int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - 1; j++){
            if(db[j].idNum > db[j + 1].idNum){
                struct student t = db[j];
                db[j] = db[j + 1];
                db[j + 1] = t;
            }
        }
    }
}

void bubbleSortName(struct student db[], int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - 1; j++){
            if(strcmp(db[j].name, db[j + 1].name) < 0){
                struct student t = db[j];
                db[j] = db[j + 1];
                db[j + 1] = t;
            }
        }
    }
}

void selectionSort(struct student db[], int n){
    for(int i = 0; i < n; i++){
        float min = db[i].percent;
        int index = i;

        for(int j = i; j < n; j++){
            if(db[j].percent > min){
                min = db[j].percent;
                index = j;
            }
        }

        struct student t = db[i];
        db[i] = db[index];
        db[index] = t;
    }
}

void insertionSort(struct student db[], int n){
    for(int i = 1; i < n; i++){
        struct student key = db[i];
        int j = i - 1;

        while(j >= 0 && db[j].division < key.division){
            db[j+1] = db[j];
            j--;
        }
        db[j+1] = key;
    }
}


int main(){
    printf("Hello World\n");

    int n;
    printf("Enter how many students will be joining-\n");
    scanf("%d", &n);
    printf("\n");
    struct student db[n];

    readData(db, n);
    disp(db, n);

    int loop = 1;

    while(loop){
        printf("\nEnter operation\n1 for bubble sort by roll number\n2 for bubble sort on name descending\n3 for selection sort on marks descending\n4 for insertion sort on name descending order\n");
        int choice;
        scanf("%d", &choice);
        printf("\n");
        switch(choice){
            case 1:
                bubbleSort(db, n);
                disp(db, n);
                break;
    
            case 2:
                bubbleSortName(db, n);
                disp(db, n);
                break;
    
            case 3:
                selectionSort(db, n);
                disp(db, n);
                break;
    
            case 4:
                insertionSort(db, n);
                disp(db, n);
                break;
        }
        printf("again? 1 for yes 0 for no\n");
        scanf("%d", &loop);
    }
    

    return(0);
}
