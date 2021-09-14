#include<stdio.h>
#include<stdlib.h>

struct students{
    int number;
    float grade;
    char name[40];
}typedef student;

void main(){
    FILE* gFile;
    FILE* lFile;
    FILE* cFile;
    cFile = fopen("testcontent", "r");
    gFile = fopen("grades.dat", "w");
    lFile = fopen("labs.txt", "w");
    student* studs;
    float tempLab;
    studs = (student*)malloc(sizeof(student));
    int i =0;
    while(!feof(cFile)){
        if(i!=0)studs = realloc(studs, (i+1)*sizeof(student));
        fscanf(cFile, "%d %f %f %s", &(studs+i)->number, &(studs+i)->grade, &tempLab, (studs+i)->name);
        if((studs+i)->number !=0){
            fwrite((studs+i), sizeof(student),1,gFile);
            fprintf(lFile, "%d %f\n", (studs+i)->number, tempLab);
        }
        i++;    
    }
    fclose(cFile);
    fclose(lFile);
    fclose(gFile);
}
