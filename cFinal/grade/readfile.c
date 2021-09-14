#include<stdio.h>

struct student{
    int number;
    float grade;
    char name[40];
}typedef student;

void main(){
    FILE* gfile;
    student stud;
    gfile=fopen("grades.dat", "r");
    while(!feof(gfile)){
        if(fread(&stud, sizeof(student), 1, gfile)==1) printf("%d %f %s\n",stud.number, stud.grade, stud.name);
    }
}
