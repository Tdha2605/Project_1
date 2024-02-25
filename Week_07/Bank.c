#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Transaction {
    char from_account[20];
    char to_account[20];
    int money;
    char time_point[8];
    char atm[10];
};

struct Transaction transactions[100000];
int num_transactions = 0;

int compareStrings(const void *a, const void *b) {
    return strcmp(*(const char **)a, *(const char **)b);
}

void listSortedAccounts() {
    char *accounts[200000];
    int num_accounts = 0;

    for (int i = 0; i < num_transactions; ++i) {
        accounts[num_accounts++] = transactions[i].from_account;
        accounts[num_accounts++] = transactions[i].to_account;
    }

    qsort(accounts, num_accounts, sizeof(accounts[0]), compareStrings);

    printf("%s", accounts[0]);
    for (int i = 1; i < num_accounts; ++i) {
        if (strcmp(accounts[i], accounts[i - 1]) != 0) {
            printf("\n%s", accounts[i]);
        }
    }
}

int hasCycleUtil(int current, int start, int k, int *visited, int *adjacency_matrix) {
    if (k == 0 && current == start) {
        return 1;
    }

    if (visited[current]) {
        return 0;
    }

    visited[current] = 1;

    for (int i = 0; i < num_transactions; ++i) {
        if (adjacency_matrix[i * 2] == current) {
            if (hasCycleUtil(adjacency_matrix[i * 2 + 1], start, k - 1, visited, adjacency_matrix)) {
                return 1;
            }
        }
    }

    visited[current] = 0;
    return 0;
}

int inspectCycle(char *account, int k) {
    int *visited = (int *)malloc(num_transactions * sizeof(int));
    memset(visited, 0, num_transactions * sizeof(int));

    // Create an adjacency matrix to represent the graph
    int *adjacency_matrix = (int *)malloc(2 * num_transactions * sizeof(int));
    for (int i = 0; i < num_transactions; ++i) {
        adjacency_matrix[i * 2] = i * 2;
        adjacency_matrix[i * 2 + 1] = i * 2 + 1;
    }

    for (int i = 0; i < num_transactions; ++i) {
        if (strcmp(transactions[i].from_account, account) == 0) {
            for (int j = 0; j < num_transactions; ++j) {
                if (strcmp(transactions[i].to_account, transactions[j].from_account) == 0) {
                    adjacency_matrix[i * 2 + 1] = j * 2;
                    break;
                }
            }
        }
    }

    int result = hasCycleUtil(0, 0, k, visited, adjacency_matrix);

    free(visited);
    free(adjacency_matrix);

    return result;
}

int main() {
    char line[100];
    while (1) {
        fgets(line, sizeof(line), stdin);
        if (line[0] == '#') {
            break;
        }

        sscanf(line, "%s %s %d %s %s",
               transactions[num_transactions].from_account,
               transactions[num_transactions].to_account,
               &transactions[num_transactions].money,
               transactions[num_transactions].time_point,
               transactions[num_transactions].atm);

        num_transactions++;
    }

    while (1) {
        fgets(line, sizeof(line), stdin);
        if (line[0] == '#') {
            break;
        }

        if (strcmp(line, "?number_transactions\n") == 0) {
            printf("%d\n", num_transactions);
        } else if (strcmp(line, "?total_money_transaction\n") == 0) {
            int total_money = 0;
            for (int i = 0; i < num_transactions; ++i) {
                total_money += transactions[i].money;
            }
            printf("%d\n", total_money);
        } else if (strcmp(line, "?list_sorted_accounts\n") == 0) {
            listSortedAccounts();
        } else if (sscanf(line, "?total_money_transaction_from %s", line) == 1) {
            int total_money = 0;
            for (int i = 0; i < num_transactions; ++i) {
                if (strcmp(transactions[i].from_account, line) == 0) {
                    total_money += transactions[i].money;
                }
            }
            printf("%d\n", total_money);
        } else if (sscanf(line, "?inspect_cycle %s", line) == 1) {
            int k;
            sscanf(line, "%*s %d", &k);
            printf("%d\n", inspectCycle(line, k));
        }
    }

    return 0;
}
