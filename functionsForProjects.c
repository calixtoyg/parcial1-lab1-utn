
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "functionsForProjects.h"
int getI(int *pBuffer) {

    return scanf("%d", pBuffer);

}

char getC(char *pBuffer) {
    fflush(stdin);

    return scanf("%c", pBuffer);


}

float getF(float *pBuffer) {

    return scanf("%f", pBuffer);

}

/**
 * String getter taking into account possible overflow
 * @param sector int sector of juegos
 * @return int returns 0 if juegos was successfully added, returns -1 otherwise
 */
void getStringOverbuffCheck(char input[], char msg[], int len)
{
    fflush(stdin);
    printf("%s", msg);
    fgets(input, len, stdin);
    input[strcspn(input, "\n")] = 0;
}

/**
 * Turns to upper every single letter of name and last name.
 * @param employee eEmployee* Pointer to array of employees
 * @param len int size of array
 */
void toUpperLastNameAndName(eEmployee employee[], int len) {
    int i;
    int j;
    for (i = 0; i < len; i++) {
        for (j = 0; j < strlen(employee[i].lastName); ++j) {
            employee[i].lastName[j] = toupper(employee[i].lastName[j]);
        }
    }
    for (i = 0; i < len; i++) {
        for (j = 0; j < strlen(employee[i].name); ++j) {
            employee[i].name[j] = toupper(employee[i].name[j]);
        }
    }
}

/**
 * Gets int
 * @param pInt *pInt pointer to int variable.
 * @param msg msg* Pointer to array of chars
 * @param msgError msgError* Pointer to array of chars
 * @param min int minimum of number to enter
 * @param max int maximum of number to enter
 * @param retries int amount of retries user has
 * @return int returns (-1) if Error [Not between min and max or not number] - (0) if OK
 *
 */
int getEntero(int *pInt, char msg[], char msgError[], int min, int max, int retries) {
    int returnNum = -1;
    int bufferInt = 0;
    if (pInt != NULL && msg != NULL && msgError != NULL && min <= max && retries >= 0) {
        do {
            retries--;
            printf("%s", msg);
            fflush(stdin);
            if (getI(&bufferInt) && bufferInt >= min && bufferInt <= max) {
                *pInt = bufferInt;
                returnNum = 0;
                break;

            } else {
                printf("%s", msgError);

            }


        } while (retries > 0);

    }
    return returnNum;


}

/**
 * Gets float
 * @param pFloat *pFloat pointer to float variable
 * @param msg *msg pointer to array of chars
 * @param msgError *msgError pointer to array of chars
 * @param min int minimum of number to enter
 * @param max int maximum of number to enter
 * @param retries int amount of retries user has
 * @return float returns (-1) if Error [Not between min and max or not number] - (0) if OK
 */
int getFloat(float *pFloat, char msg[], char msgError[], float min, float max, int retries) {
    int returnNum = -1;
    float bufferFloat = 0;
    if (pFloat != NULL && msg != NULL && msgError != NULL && min <= max && retries >= 0) {
        do {
            retries--;
            printf("%s", msg);
            fflush(stdin);
            if (getF(&bufferFloat) && bufferFloat >= min && bufferFloat <= max) {

                *pFloat = bufferFloat;
                returnNum = 0;
                break;

            } else {
                printf("%s", msgError);

            }


        } while (retries > 0);

    }
    return returnNum;


}

/**
 * Checks if it is a letter(includes space)
 * @param c c* Pointer to array of chars
 * @return int return 1 if its a letter or 0 if it is there a space or enter in the first element or if it is not a letter
 */
int isLetter(char c[]) {
    int i = 0;
    if (c[0] == ' ' || c[0] == '\r')
        return 0;
    while (c[i] != '\0') {
        if (!(c[i] >= 'a' && c[i] <= 'z' || c[i] >= 'A' && c[i] <= 'Z') && c[i] != ' ')
            return 0;
        i++;
    }
    return 1;
}

/**
 * String getter
 * @param mensaje *msg pointer to array of chars
 * @param input *input pointer to array of chars
 */
void getString(char input[], char msg[]) {
    fflush(stdin);
    printf("%s", msg);
    fgets(input, 200, stdin);
    input[strcspn(input, "\n")] = 0;
}

/**
 * String getter for letters(includes space) only
 * @param input *input pointer to array of chars
 * @param msg *msg pointer to array of chars
 * @param len int size of array
 * @param retries int amount of times user can retry entry
 * @return int returns 1 if it is all letters(includes space) or 0 if not
 */
int getStringLettersOnly(char *input, char *msg, int len, int retries) {
    char aux[len];
    do {
        getString(aux, msg);
        if (isLetter(aux)) {
            strcpy(input, aux);
            return 1;
        } else {
            retries--;
            printf("Error nombre deben ser solo letras y no puede estar vacio!.\n");
        }

    } while (retries >= 0);
    return 0;
}
/*
/**
 * Gets free space within the array
 * @param employee *eEmployee pointer to an array of structs of type eEmployee
 * @param len int size of array
 * @return int index of first free space in array, 0 if there is no freespace
 */
 /*
int getFreeSpace(eEmployee employee[], int len) {

    int i;
    for (i = 0; i < len; i++) {
        if (employee[i].isEmpty == 1) {
            return i;
        }
    }
    printf("No hay espacio en el array para agregar mas empleados.\n");
    return -1;

}
*/
/**
 * Initializes the array of structs of employees, settings isEmpty variable to 1
 * @param employee *eEmployee pointer to array of structs of type eEmployee
 * @param len int size of array
 * @return int returns -1 if array was successfully initialize
 */
int initEmployees(eEmployee *employee, int len) {
    int i;
    for (i = 0; i < len; i++) {
        employee[i].isEmpty = 1;
    }
    return -1;

}

/**
 * Adds an employee to the first free space of the array
 * @param employee *eEmployee pointer to array of structs of type eEmployee
 * @param len int size of array
 * @param id int id of employee
 * @param name *name pointer to array of chars
 * @param lastName *lastName pointer to array of chars
 * @param salary int salary of employee
 * @param sector int sector of employee
 * @return int returns 0 if employee was successfully added, returns -1 otherwise
 */
int addEmployee(eEmployee *employee, int len, int id, char name[], char lastName[], float salary, int sector) {
    int i;
    i = getFreeSpace(employee, len);
    if (i != -1) {
        employee[i].isEmpty = 0;
        employee[i].id = id;
        strcpy(employee[i].name, name);
        strcpy(employee[i].lastName, lastName);
        employee[i].salary = salary;
        employee[i].sector = sector;
        return 0;
    }
    return -1;
}

/**
 * Finds employee by it's id
 * @param employee *eEmployee pointer to array of structs of type eEmployee
 * @param len int size of array
 * @param id int id of employee
 * @return returns index to position of the array where id is, returns -1 if there was no employee with that id
 */
int findEmployeeById(eEmployee employee[], int len, int id) {
    int i;
    for (i = 0; i < len; i++) {
        if (id == employee[i].id) {
            return i;

        }
    }
    printf("No hay empleados con el ID:%d en el array.\n", id);
    return -1;
}
/**
 * Checks if the menu was valid
 * @param menu int menu number
 * @param min int minimum number included
 * @param max int maximum number included
 * @return int returns 1 if the menu is valid 0 otherwise
 */
int isValidMenu(int menu, int min, int max) {
    if (menu >= min && menu <= max) {
        return 1;
    } else
        return 0;
}

/**
 * Prints employees
 * @param employee *eEmployee pointer to array of structs of type eEmployee
 * @param len int size of array
 */
void printEmployees(eEmployee employee[], int len) {
    int i;
    system("cls");
    for (i = 0; i < len; i++) {
        if (employee[i].isEmpty == 0) {
            printf("------------------------------------------------------------\n");
            printf("| ID        |    %d\n", employee[i].id);
            printf("| Nombre    |    %s\n", employee[i].name);
            printf("| Apellido  |    %s\n", employee[i].lastName);
            printf("| Salario   |    %f\n", employee[i].salary);
            printf("| Sector    |    %d\n", employee[i].sector);
            printf("------------------------------------------------------------\n");
        }
    }


}

/**
 * Sorts employees first by sector then by last name and finally by name
 * @param employee *eEmployee pointer to array of structs of type eEmployee
 * @param len int size of array
 * @param order int 1 for ascending order 0 for descending order
 */
void sortBySectorLastNameAndName(eEmployee *employee, int len, int order) {
    int i;
    int j;
    eEmployee auxEmployee;

    if (order == 1) {
        for (i = 0; i < len - 1; i++) {
            for (j = i; j < len; ++j) {
                if (employee[i].sector > employee[j].sector) {
                    auxEmployee = employee[i];
                    employee[i] = employee[j];
                    employee[j] = auxEmployee;
                }

            }

        }
        for (i = 0; i < len - 1; i++) {
            for (j = i; j < len; ++j) {
                if (strcmp(employee[i].lastName, employee[j].lastName) > 0 &&
                    employee[i].sector == employee[j].sector) {
                    auxEmployee = employee[i];
                    employee[i] = employee[j];
                    employee[j] = auxEmployee;
                } else if (strcmp(employee[i].lastName, employee[j].lastName) == 0 &&
                           employee[i].sector == employee[j].sector) {
                    if (strcmp(employee[i].name, employee[j].name) > 0) {
                        auxEmployee = employee[i];
                        employee[i] = employee[j];
                        employee[j] = auxEmployee;
                    }

                }

            }

        }
    }
    if (order == 0) {
        for (i = 0; i < len - 1; i++) {
            for (j = i; j < len; ++j) {
                if (employee[i].sector < employee[j].sector) {
                    auxEmployee = employee[i];
                    employee[i] = employee[j];
                    employee[j] = auxEmployee;
                }

            }

        }
        for (i = 0; i < len - 1; i++) {
            for (j = i; j < len; ++j) {
                if (strcmp(employee[i].lastName, employee[j].lastName) < 0 &&
                    employee[i].sector == employee[j].sector) {
                    auxEmployee = employee[i];
                    employee[i] = employee[j];
                    employee[j] = auxEmployee;
                } else if (strcmp(employee[i].lastName, employee[j].lastName) == 0 &&
                           employee[i].sector == employee[j].sector) {
                    if (strcmp(employee[i].name, employee[j].name) < 0) {
                        auxEmployee = employee[i];
                        employee[i] = employee[j];
                        employee[j] = auxEmployee;
                    }

                }

            }

        }
    }


}
/**
 * Removes employee by id ask for char input Y or y for deletion otherwise operation is cancelled
 * @param employee *eEmployee pointer to array of structs of type eEmployee
 * @param len int size of array
 * @param id int id of employee to delete
 * @return int returns 0 if registry was deleted -1 if Error[registry not found or operation cancelled]
 */
int removeEmployee(eEmployee *employee, int len, int id) {
    char tempChar;
    int i, returnNum = -1;
    printf("Esta seguro que desea eliminar el registro (Y/N): \n");
    getC(&tempChar);
    tempChar = toupper(tempChar);
    if (tempChar == 'Y') {
        for (i = 0; i < len; i++) {
            if (id == employee[i].id) {
                employee[i].isEmpty = 1;
                returnNum = 0;
                return returnNum;
            }
            returnNum = -1;
        }
        if (returnNum != 0) {
            printf("Registro no encontrado");
            returnNum = 0;
            return returnNum;
        }
    } else {
        system("cls");
        printf("Operacion cancelada-\n");
        return returnNum;
    }

}
/**
 * Gets average salaries of employees
 * @param employee *eEmployee pointer to array of structs of type eEmployee
 * @param len int size of array
 * @return int average of all salaries in array of employees
 */
int getAverageSalaries(eEmployee *employee, int len) {
    int i, averageSalaries = 0, rangeOfNotEmptyEmployees = 0;
    for (i = 0; i < len; i++) {
        if (employee[i].isEmpty == 0) {
            averageSalaries += employee[i].salary;
            rangeOfNotEmptyEmployees++;
        }
    }
    return averageSalaries / rangeOfNotEmptyEmployees;
}
/**
 * Gets the employees that are above average salary
 * @param employee *eEmployee pointer to array of structs of type eEmployee
 * @param len int size of array
 * @return int returns employees that are above average salary
 */
int employeesAboveAverage(eEmployee *employee, int len) {
    int getAverageSalary = getAverageSalaries(employee, len);
    int i, employessAboveAverage = 0;
    for (i = 0; i < len; i++) {
        if (employee[i].isEmpty == 0 && employee[i].salary > getAverageSalary) {
            employessAboveAverage++;

        }
    }
    return employessAboveAverage;


}
/**
 * Modifies employee selected by the id
 * @param employee *eEmployee pointer to array of structs of type eEmployee
 * @param len int size of array
 * @param id int id of employee
 * @param name *name pointer to array of chars
 * @param lastName *lastName pointer to array of chars
 * @param salary int salary of employee
 * @param sector int sector of employee
 * @return returns 0 if employee was deleted -1 if operation was cancelled
 */
int modifyEmployee(eEmployee *employee, int len, int id, char name[], char lastName[], float salary, int sector) {
    int i;
    for (i = 0; i < len; ++i) {
        if (employee[i].id == id && employee[i].isEmpty == 0) {
            employee[i].isEmpty = 0;
            employee[i].id = id;
            strcpy(employee[i].name, name);
            strcpy(employee[i].lastName, lastName);
            employee[i].salary = salary;
            employee[i].sector = sector;
            printf("Operacion realizada con exito ID %d fue modificado.\n", employee[i].id);
            return 0;
        }
    }
    printf("Operacion cancelada, no se pudo modificar al empleado.\n");
    return -1;
}
/**
 * Gets total of all salaries
 * @param employee *eEmployee pointer to array of structs of type eEmployee
 * @param len int size of array
 * @return int total of salaries
 */
float getAllSalaries(eEmployee *employee, int len) {
    float salaries = 0;
    int i;
    for (i = 0; i < len; ++i) {
        if (employee[i].isEmpty == 0)
            salaries += employee[i].salary;

    }
    return salaries;
}
