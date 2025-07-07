#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
struct Student
{
char name[100], id[100];
double cgpa;
int sem;
};
struct Student a[100];
int nos;

int main()
{
FILE *f = fopen("db.txt", "r");
if(f == 0)
{
FILE *wf = fopen("db.txt", "w");
fclose(wf);
}
fclose(f);
int type;
while(1)
{
    printf("1. View All Students\n");
    printf("2. Add a student\n");
    printf("3. Delete a student\n");
    printf("4. Update semester\n");
    printf("5. Exit\n");
    printf("Enter Your Choice: ");
    scanf("%d", &type);

    if(type < 1 || type > 5) continue;
    if(type == 5) break;
    if(type == 1)
    {
        system("cls");
        /// Show All Students

        /// 1. Read stduent info from file to Student Array
        FILE* db = fopen("db.txt", "r");
        if(db == 0)
        {
            printf("Error opening the file...\n");
        }
        else
        {
            int i = 0;
            while(fscanf(db, "%s\n", a[i].id) == 1)
            {
                fscanf(db, "%[^\n]", a[i].name);
                fscanf(db, "%d", &a[i].sem);
                fscanf(db, "%lf", &a[i].cgpa);
                i++;
            }
            nos = i;
        }
        fclose(db);

        /// Show All students' Info
        printf("\n\n---------------------------------\n");
        if(nos == 0)
        {
            printf("No Student Info found\n");
            printf("---------------------------------\n");
            continue;
        }
        for(int i = 0; i < nos; i++)
        {
            printf("Name: %s\n", a[i].name);
            printf("ID: %s\n", a[i].id);
            printf("CG: %.3lf\n", a[i].cgpa);
            printf("Sem: %d\n\n", a[i].sem);
        }
        printf("---------------------------------\n");
    }
    if(type == 2)
    {
        system("cls");
        /// 1. Read std info from the file to Student Array
        FILE* db = fopen("db.txt", "r");
        if(db == 0)
        {
            printf("Error opening the file...\n");
        }
        else
        {
            int i = 0;
            while(fscanf(db, "%s\n", a[i].id) == 1)
            {
                fscanf(db, "%[^\n]", a[i].name);
                fscanf(db, "%d", &a[i].sem);
                fscanf(db, "%lf", &a[i].cgpa);
                i++;
            }
            nos = i;
        }
        fclose(db);

        /// 2. Add new student to the array
        struct Student temp;
        printf("Enter Name, ID, cgpa and Sem: \n");
        scanf("\n%[^\n]", temp.name);
        scanf("%s", temp.id);
        scanf("%lf", &temp.cgpa);
        scanf("%d", &temp.sem);

        a[nos] = temp;
        nos++;

        /// 3. write array content to the file
        db = fopen("db.txt", "w");
        if(db == 0)
        {
            printf("Error opening the file...\n");
        }
        else
        {
            for(int i = 0; i < nos; i++)
            {
                fprintf(db, "%s\n", a[i].id);
                fprintf(db, "%s\n", a[i].name);
                fprintf(db, "%d\n", a[i].sem);
                fprintf(db, "%.2lf\n", a[i].cgpa);
            }
        }
        fclose(db);
    }
    else if(type == 3)
    {
        system("cls");
        /// 1. Read all content from the file to Student Array
        FILE* db = fopen("db.txt", "r");
        if(db == 0)
        {
            printf("Error opening the file...\n");
        }
        else
        {
            int i = 0;
            while(fscanf(db, "%s\n", a[i].id) == 1)
            {
                fscanf(db, "%[^\n]", a[i].name);
                fscanf(db, "%d", &a[i].sem);
                fscanf(db, "%lf", &a[i].cgpa);
                i++;
            }
            nos = i;
        }
        fclose(db);


        /// 2. take id and delete it from the array


        printf("\nEnter ID to remove: ");
        char id[100];
        scanf("%s", id);

        int loc = -1;
        for(int i = 0; i < nos; i++)
        {
            if(strcmp(a[i].id, id) == 0)
            {
                loc = i;
                break;
            }
        }
        if(loc == -1)
        {
            printf("ID not found\n");
            continue;
        }
        for(int i = loc; i < nos - 1; i++)
        {
            a[i] = a[i + 1];
        }
        nos--;


        /// 3. Write Student array content to the file
        db = fopen("db.txt", "w");
        if(db == 0)
        {
            printf("Error opening the file...\n");
        }
        else
        {
            for(int i = 0; i < nos; i++)
            {
                fprintf(db, "%s\n", a[i].id);
                fprintf(db, "%s\n", a[i].name);
                fprintf(db, "%d\n", a[i].sem);
                fprintf(db, "%.2lf\n", a[i].cgpa);
            }
        }
        fclose(db);
    }
    else if(type == 4)
    {
        system("cls");
        /// 1. Read all content from the file to Student Array
        FILE* db = fopen("db.txt", "r");
        if(db == 0)
        {
            printf("Error opening the file...\n");
        }
        else
        {
            int i = 0;
            while(fscanf(db, "%s\n", a[i].id) == 1)
            {
                fscanf(db, "%[^\n]", a[i].name);
                fscanf(db, "%d", &a[i].sem);
                fscanf(db, "%lf", &a[i].cgpa);
                i++;
            }
            nos = i;
        }
        fclose(db);


        /// 2.update info in the array


        char id[100];
        int sem;
        printf("Enter ID: ");
        scanf("%s", id);
        printf("Enter Semester: ");
        scanf("%d", &sem);

        int loc = -1;
        for(int i = 0; i < nos; i++)
        {
            if(strcmp(a[i].id, id) == 0)
            {
                loc = i;
                break;
            }
        }
        if(loc == -1)
        {
            printf("ID not found\n");
            continue;
        }
        a[loc].sem = sem;


        /// 3. Write Student array content to the file
        db = fopen("db.txt", "w");
        if(db == 0)
        {
            printf("Error opening the file...\n");
        }
        else
        {
            for(int i = 0; i < nos; i++)
            {
                fprintf(db, "%s\n", a[i].id);
                fprintf(db, "%s\n", a[i].name);
                fprintf(db, "%d\n", a[i].sem);
                fprintf(db, "%.2lf\n", a[i].cgpa);
            }
        }
        fclose(db);
    }
}



return 0;
}
