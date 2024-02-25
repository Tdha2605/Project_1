#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Submission
{
    char UserID[11];
    char ProblemID[4];
    char Time_point[9];
    char Status[4];
    int Point;
};

struct Submission submission[100000];

int num_submission = 0;

void processSubmission(char *userID, char *problemID, char *time_point, char *status, int point)
{
    strcpy(submission[num_submission].UserID, userID);
    strcpy(submission[num_submission].ProblemID, problemID);
    strcpy(submission[num_submission].Time_point, time_point);
    strcpy(submission[num_submission].Status, status);
    submission[num_submission].Point = point;
    num_submission++;
}

int compareSubmissions(const void *a, const void *b)
{
    int problemComparison = strcmp(((struct Submission *)a)->ProblemID, ((struct Submission *)b)->ProblemID);

    if (problemComparison == 0)
    {
        return ((struct Submission *)a)->Point - ((struct Submission *)b)->Point;
    }

    return problemComparison;
}

int total_number_submissions()
{
    return num_submission;
}

int number_error_submision()
{
    int number_error_submision = 0;
    for (int i = 0; i < num_submission; i++)
    {
        if (strcmp(submission[i].Status, "ERR") == 0)
        {
            number_error_submision++;
        }
    }
    return number_error_submision;
}

int number_error_submision_of_user(char *userID)
{
    int number_error_submision_of_user = 0;
    for (int i = 0; i < num_submission; i++)
    {
        if (strcmp(submission[i].UserID, userID) == 0 && strcmp(submission[i].Status, "ERR") == 0)
        {
            number_error_submision_of_user++;
        }
    }
    return number_error_submision_of_user;
}

int total_point_of_user(char *userID)
{
    int total_point = 0;

    int maxPoints[100];
    for (int i = 0; i < 100; i++)
    {
        maxPoints[i] = 0;
    }

    for (int i = 0; i < num_submission; i++)
    {
        if (strcmp(submission[i].UserID, userID) == 0)
        {
            int problemIndex = atoi(submission[i].ProblemID + 1);
            if (submission[i].Point > maxPoints[problemIndex])
            {
                maxPoints[problemIndex] = submission[i].Point;
            }
        }
    }

    for (int i = 0; i < 100; i++)
    {
        total_point += maxPoints[i];
    }

    return total_point;
}

int is_Period(char *time, char *from_time, char *to_time)
{
    return (strcmp(time, from_time) >= 0 && strcmp(time, to_time) <= 0);
}

int number_submission_period(char *from_time, char *to_time)
{
    int number_submission_period = 0;

    for (int i = 0; i < num_submission; i++)
    {
        if (is_Period(submission[i].Time_point, from_time, to_time))
        {
            number_submission_period++;
        }
    }
    return number_submission_period;
}

int main()
{
    char input[100];

    while (1)
    {
        fgets(input, sizeof(input), stdin);
        if (input[0] == '#')
        {
            break;
        }

        char *userID = strtok(input, " ");
        char *problemID = strtok(NULL, " ");
        char *time_point = strtok(NULL, " ");
        char *status = strtok(NULL, " ");
        int point = atoi(strtok(NULL, "\n"));

        processSubmission(userID, problemID, time_point, status, point);
    }

    qsort(submission, num_submission, sizeof(struct Submission), compareSubmissions);

    while (1)
    {
        fgets(input, sizeof(input), stdin);
        if (input[0] == '#')
        {
            break;
        }
        char *do_what = strtok(input, " \n");

        if (strcmp(do_what, "?total_number_submissions") == 0)
        {
            printf("%d\n", total_number_submissions());
        }
        else if (strcmp(do_what, "?number_error_submision") == 0)
        {
            printf("%d\n", number_error_submision());
        }
        else if (strncmp(do_what, "?number_error_submision_of_user", 31) == 0)
        {
            char *userID = strtok(NULL, " \n");
            printf("%d\n", number_error_submision_of_user(userID));
        }
        else if (strncmp(do_what, "?total_point_of_user", 21) == 0)
        {
            char *userID = strtok(NULL, " \n");
            printf("%d\n", total_point_of_user(userID));
        }
        else if (strncmp(do_what, "?number_submission_period", 26) == 0)
        {
            char *from_time = strtok(NULL, " ");
            char *to_time = strtok(NULL, " \n");
            printf("%d\n", number_submission_period(from_time, to_time));
        }
    }
    return 0;
}