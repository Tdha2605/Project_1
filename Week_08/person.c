#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Citizen
{
    char Code[8];
    char Date_of_Birth[11];
    char Father_Code[8];
    char Mother_Code[8];
    char Is_Alive[2];
    char Region_Code[6];
};

struct Citizen *citizen = NULL;
int num_citizen = 0;

void processCitizen(char *code, char *date_of_birth, char *father_code, char *mother_code, char *is_alive, char *region_code)
{
    strcpy(citizen[num_citizen].Code, code);
    strcpy(citizen[num_citizen].Date_of_Birth, date_of_birth);
    strcpy(citizen[num_citizen].Father_Code, father_code);
    strcpy(citizen[num_citizen].Mother_Code, mother_code);
    strcpy(citizen[num_citizen].Is_Alive, is_alive);
    strcpy(citizen[num_citizen].Region_Code, region_code);
    num_citizen++;
}

int number_people()
{
    return num_citizen;
}

int number_people_born_at(char *date_of_birth)
{
    int number_people_born_at = 0;

    for (int i = 0; i < num_citizen; i++)
    {
        if (strcmp(citizen[i].Date_of_Birth, date_of_birth) == 0)
        {
            number_people_born_at++;
        }
    }
    return number_people_born_at;
}

int compare_dates(char *date1, char *date2)
{
    int year1, month1, day1;
    int year2, month2, day2;

    sscanf(date1, "%d-%d-%d", &year1, &month1, &day1);
    sscanf(date2, "%d-%d-%d", &year2, &month2, &day2);

    if (year1 < year2)
        return -1;
    if (year1 > year2)
        return 1;
    if (month1 < month2)
        return -1;
    if (month1 > month2)
        return 1;
    if (day1 < day2)
        return -1;
    if (day1 > day2)
        return 1;

    return 0;
}

int number_people_born_between(char *from_date, char *to_date)
{
    int number_people_born_between = 0;

    for (int i = 0; i < num_citizen; i++)
    {
        if (compare_dates(citizen[i].Date_of_Birth, from_date) >= 0 &&
            compare_dates(citizen[i].Date_of_Birth, to_date) <= 0)
        {
            number_people_born_between++;
        }
    }
    return number_people_born_between;
}

struct Citizen *find_citizen(char *code)
{
    for (int i = 0; i < num_citizen; i++)
    {
        if (strcmp(citizen[i].Code, code) == 0 && strcmp(citizen[i].Is_Alive, "Y") == 0)
        {
            return &citizen[i];
        }
    }
    return NULL;
}

int most_alive_ancestor(char *code)
{
    int most_alive_ancestor = 0;
    struct Citizen *provided_citizen = find_citizen(code);

    while (strcmp(provided_citizen->Father_Code, "0000000") != 0 &&
           strcmp(provided_citizen->Mother_Code, "0000000") != 0)
    {
        most_alive_ancestor++;
        if (strcmp(provided_citizen->Father_Code, "0000000") != 0)
        {
            provided_citizen = find_citizen(provided_citizen->Father_Code);
        }
        else
        {
            provided_citizen = find_citizen(provided_citizen->Mother_Code);
        }
    }

    return most_alive_ancestor;
}

int is_unrelated(struct Citizen *person)
{
    if (strcmp(person->Father_Code, "0000000") == 0 && strcmp(person->Mother_Code, "0000000") == 0)
        return 1;

    struct Citizen *father = find_citizen(person->Father_Code);
    struct Citizen *mother = find_citizen(person->Mother_Code);

    if (father && mother)
    {
        if ((strcmp(father->Father_Code, "0000000") != 0 || strcmp(father->Mother_Code, "0000000") != 0) ||
            (strcmp(mother->Father_Code, "0000000") != 0 || strcmp(mother->Mother_Code, "0000000") != 0))
        {
            return 1;
        }
    }

    return 0;
}

int dfs(struct Citizen *person, int visited[100000])
{
    if (person == NULL || visited[atoi(person->Code)] == 1)
    {
        return 0;
    }

    visited[atoi(person->Code)] = 1;
    int subset_size = 1;

    for (int i = 0; i < num_citizen; i++)
    {
        if (visited[atoi(citizen[i].Code)] == 0 && is_unrelated(&citizen[i]))
        {
            subset_size += dfs(&citizen[i], visited);
        }
    }

    return subset_size;
}

int max_unrelated_people()
{
    int *visited = (int *)calloc(num_citizen, sizeof(int));
    int max_subset_size = 0;

    for (int i = 0; i < num_citizen; i++)
    {
        if (visited[atoi(citizen[i].Code)] == 0 && is_unrelated(&citizen[i]))
        {
            int subset_size = dfs(&citizen[i], visited);
            max_subset_size = (subset_size > max_subset_size) ? subset_size : max_subset_size;
        }
    }

    free(visited);
    return max_subset_size;
}

int main()
{
    char input[100];

    while (1)
    {
        fgets(input, sizeof(input), stdin);
        if (input[0] == '*')
        {
            break;
        }

        char *code = strtok(input, " ");
        char *date_of_birth = strtok(NULL, " ");
        char *father_code = strtok(NULL, " ");
        char *mother_code = strtok(NULL, " ");
        char *is_alive = strtok(NULL, " ");
        char *region_code = strtok(NULL, "\n");

        processCitizen(code, date_of_birth, father_code, mother_code, is_alive, region_code);
    }

    while (1)
    {
        fgets(input, sizeof(input), stdin);
        if (input[0] == '*')
        {
            break;
        }
        char *do_what = strtok(input, " \n");

        if (strcmp(do_what, "NUMBER_PEOPLE") == 0)
        {
            printf("%d\n", number_people());
        }
        else if (strncmp(do_what, "NUMBER_PEOPLE_BORN_AT", 22) == 0)
        {
            char *date_of_birth = strtok(NULL, " \n");
            printf("%d\n", number_people_born_at(date_of_birth));
        }
        else if (strncmp(do_what, "MOST_ALIVE_ANCESTOR", 21) == 0)
        {
            char *code = strtok(NULL, " \n");
            printf("%d\n", most_alive_ancestor(code));
        }
        else if (strncmp(do_what, "MAX_UNRELATED_PEOPLE", 22) == 0)
        {
            printf("%d\n", max_unrelated_people());
        }
        else if (strncmp(do_what, "NUMBER_PEOPLE_BORN_BETWEEN", 28) == 0)
        {
            char *from_date = strtok(NULL, " ");
            char *to_date = strtok(NULL, " \n");
            printf("%d\n", number_people_born_between(from_date, to_date));
        }
    }

    free(citizen); 
    return 0;
}
