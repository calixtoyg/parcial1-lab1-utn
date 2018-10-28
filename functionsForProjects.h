
typedef struct {
    int id;
    char name[25];
    char lastName[15];
    float salary;
    int sector;
    int isEmpty;

}eEmployee;
int getEntero(int *,char [], char [], int ,int, int);
int getFloat(float *pFloat, char msg[], char msgError[], float min, float max, int retries);
int getI(int* );
float getF(float *);
char getC(char *);
int getChar(char *, char msg[], char msgError[], char minChar, char maxChar, int reintentos);
int isLetter(char c[]);
void getString(char input[], char msg[]);
int getStringLettersOnly(char *input, char *msg, int len, int retries);
//int getFreeSpace(eEmployee[],int);
int initEmployees(eEmployee *, int);
int isValidMenu(int menu,int min, int max);
int addEmployee(eEmployee[], int len, int id, char name[],char lastName[],float salary,int sector);
void printEmployees(eEmployee *, int);
void sortBySectorLastNameAndName(eEmployee *employee, int len, int order);
int findEmployeeById(eEmployee employee[],int len, int id);
int removeEmployee(eEmployee* employee, int len,int id);
int getAverageSalaries(eEmployee *employee, int len);
int employeesAboveAverage(eEmployee* employee,int len);
void toUpperLastNameAndName(eEmployee employee[], int len);
int modifyEmployee(eEmployee[],int len, int id, char name[],char lastName[],float salary,int sector);
float getAllSalaries(eEmployee[],int len);
void getStringOverbuffCheck(char input[], char msg[],int len);
