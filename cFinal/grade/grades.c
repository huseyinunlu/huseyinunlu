#include<stdio.h>
#include<stdlib.h>
struct student{
    int number;
    float grade;
    char name[40];
}typedef student;
int main(){
    FILE* gFile, *lFile;
    if((gFile=fopen("grades.dat", "r+")) == NULL){
        printf("error file did not opened");
        return -1;
    }
    student* studs = (student*) malloc(sizeof(student));
    int i=0;
    while(!feof(gFile)){
        if(i!=0)studs = realloc(studs, (i+1)*sizeof(student));
        fread((studs+i), sizeof(student), 1, gFile);
        i++;
    }
    if((lFile = fopen("labs.txt", "r")) == NULL){
        printf("error file did not opened");
        return -1;
    }
    int tempNo;
    float tempPoint;
    while(!feof(lFile)){
        fscanf(lFile, "%d %f\n", &tempNo, &tempPoint);
        for(int j =0; j<i;j++){
            if((studs+j)->number == tempNo){
                (studs+j)->grade +=tempPoint;
            }
        }
    }
    fclose(lFile);
    rewind(gFile);
    for(int j=0;j<i;j++){
        if((studs+j)->number!=0) fwrite((studs+j), sizeof(student),1, gFile);
    }
    fclose(gFile);
    return 0;
}
