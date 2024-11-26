#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_TASKS 100

// task structure
typedef struct {
    char title[100];
    char description[255];
    char expary_date[11];  // Format: "YYYY-MM-DD"
    char priority[10];        // "High" ou "Low"
    char statut[20];          // "Complete" ou "Incomplete"
} Task;

void displayMenu() {
    printf("\n");

    printf("===== *task management application* =====\n");
    printf("===================================\n");
    printf("created by : MARYAM EL OUADAA\n");
    printf("=== ENAA BENI MELLAL ===\n");
    printf("1. add a Task\n");
    printf("2. display the Task\n");
    printf("3. update the Task\n");
    printf("4. delete the Task\n");
    printf("5. Filter by Priority\n");
    printf("6. Filter by Statut\n");
    printf("7. Tri the Task\n");
    printf("8. Quitt\n");
    printf("=============================\n");
    printf("enter your choice: ");
}

// add a new task
void addtask(Task tasks[MAX_TASKS], int nbTaches) {
    Task newtask;
    printf("Title of the task: ");
    getchar();
    fgets(newtask.title, 100, stdin);
    newtask.title[strcspn(newtask.title, "\n")] = '\0'; 

    printf("Description of the task: ");
    fgets(newtask.description, 255, stdin);
    newtask.description[strcspn(newtask.description, "\n")] = '\0';

    printf("expary_date (YYYY-MM-DD): ");
    fgets(newtask.expary_date, 11, stdin);
    newtask.expary_date[strcspn(newtask.expary_date, "\n")] = '\0';
getchar();
    printf("Priority (High/Low): ");
    fgets(newtask.priority, 10, stdin);
    newtask.priority[strcspn(newtask.priority, "\n")] = '\0';

    printf("Statut (Complete/Incomplete): ");
    fgets(newtask.statut, 20, stdin);
    newtask.statut[strcspn(newtask.statut, "\n")] = '\0';

    // Add task to the list
    tasks[nbTaches] = newtask;
}

// display the task list
void displaytask(Task tasks[MAX_TASKS], int nbTaches) {
    if (nbTaches == 0) {
        printf("no tasks yet.\n");
        return;
    }
    for (int i = 0; i < nbTaches; i++) {
        printf("\ntask %d:\n", i + 1);
        printf("Title: %s\n", tasks[i].title);
        printf("Description: %s\n", tasks[i].description);
        printf("expary_date: %s\n", tasks[i].expary_date);
        printf("Priority: %s\n", tasks[i].priority);
        printf("Statut: %s\n", tasks[i].statut);
    }
}

// update the task
void updatetask(Task tasks[MAX_TASKS], int nbTaches) {
    int id;
    printf("Enter the ID of the task  (1-%d): ", nbTaches);
    scanf("%d", &id);
    id--; // the index started from  0

    if (id < 0 || id >= nbTaches) {
        printf("Task invalide.\n");
        return;
    }

    // updating
    printf("New title: ");
    getchar();
    fgets(tasks[id].title, 100, stdin);
    tasks[id].title[strcspn(tasks[id].title, "\n")] = '\0';

    printf("New description: ");
    fgets(tasks[id].description, 255, stdin);
    tasks[id].description[strcspn(tasks[id].description, "\n")] = '\0';

    printf("New expary_date (YYYY-MM-DD): ");
    fgets(tasks[id].expary_date, 11, stdin);
    tasks[id].expary_date[strcspn(tasks[id].expary_date, "\n")] = '\0';

    printf("New priority (High/Low): ");
    fgets(tasks[id].priority, 10, stdin);
    tasks[id].priority[strcspn(tasks[id].priority, "\n")] = '\0';
getchar();
    printf("New statut (Complete/Incomplete): ");
    fgets(tasks[id].statut, 20, stdin);
    tasks[id].statut[strcspn(tasks[id].statut, "\n")] = '\0';
    getchar();
}

    
   int deletetask(Task tasks[MAX_TASKS], int nbtaches) {
    int id;
    printf("Enter the ID of the task to delete (1-%d): ", nbtaches);
    scanf("%d", &id);
    id--; 

    if (id < 0 || id >= nbtaches) {
        printf("Invalid task ID.\n");
        return nbtaches;  
    }

    
    for (int i = id; i < nbtaches - 1; i++) {
        tasks[i] = tasks[i + 1];
    }

    nbtaches--;  
    printf("Task deleted successfully.\n");
    return nbtaches;  
}
 /*void filterTasks() {
    int choice;
    printf("1. Filtrer par priorité\n2. Filtrer par statut\n3. Filtrer par date\nEntrez votre choix : ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: {
            int prio;
            printf("1. URGENT\n2. PAS URGENT\nEntrez votre choix : ");
            scanf("%d", &prio);
            if (prio == 1) UR();
            else if (prio == 2) URP();
            else printf("Choice invalide.\n");
            break;
        }
        case 2: {
            int stat;
            printf("1. COMPLETE\n2. INCOMPLETE\nEntrez votre choix : ");
            scanf("%d", &stat);
            if (stat == 1) CMP();
            else if (stat == 2) inCMP();
            else printf("Choice invalide.\n");
            break;
        }
        case 3: {
            int Mois, Jour;
            printf("Entrez le mois : ");
            scanf("%d", &Mois);
            printf("Entrez le jour : ");
            scanf("%d", &Jour);
            for (int i = 0; i < Taille; i++) {
                if (tasks[i].date.Mois == Mois && tasks[i].date.Jour == Jour) {
                    printf("Tâche %d : %s\n", i + 1, tasks[i].title);
                }
            }
            break;
        }
        default:
            printf("Choice invalide.\n");
    }
}*/

/*void deletetask(Task tasks[MAX_TASKS], int nbtaches) {
    int id;
    printf("enter the id of the task (1-%d): ", nbtaches);
    scanf("%d, &id");
    id--;
    if (id < 0 || id >= nbtaches) {
        printf("Task invalide.\n");
        return;
    }
    for (int i = id; i < nbtaches - 1; i++) {
        tasks[i] = tasks[i + 1];
    }
    (nbtaches)--;
    printf("task deleted succefully.\n");
}*/

void filterbyPriority(Task tasks[MAX_TASKS], int nbtaches, char priority[10]) {
for (int i = 0; i < nbtaches; i++){
    if (strcmp(tasks[i].priority, priority) == 0) {
        printf("\ntask %d:\n", i + 1);
        printf("title: %s\n",tasks[i].title);
        printf("description: %s\n", tasks[i].description);
        printf("expay_date: %s\n", tasks[i].expary_date);
        printf("priority: %s\n", tasks[i].priority);
        printf("statut: %s\n", tasks[i].statut);
    }
  }
}

void filterbyStatut(Task tasks[MAX_TASKS], int nbtaches, char statut[20]) {
    for (int i = 0; i < nbtaches; i++) {
        if (strcmp(tasks[i].statut, statut) == 0) {
            printf("\nTask %d:\n", i + 1);
            printf("title: %s\n",tasks[i].title);
            printf("description: %s\n", tasks[i].description);
            printf("dexpary_date: %s\n", tasks[i].expary_date);
            printf("priority;%s\n", tasks[i].priority);
            printf("statut:%s\n", tasks[i].statut);
            
        }
    }
}                         

int compareDates(Task taskA, Task taskB) {
     return strcmp(taskA.expary_date, taskB.expary_date);
}

void triTasks(Task tasks[MAX_TASKS], int nbtaches) {
    Task temp;
    for (int i = 0 ;i < nbtaches - 1; i++) {
        for (int j = 0; j < nbtaches - i - 1; i++) {
            if (compareDates(tasks[j], tasks[j + i]) > 0) {
                temp = tasks[j];
                tasks[j] = tasks[j + i];
                tasks[j + 1] = temp;
            }
        }
    }
}

void sauvegardeTasks(Task tasks[MAX_TASKS], int nbtaches) {
    FILE *folder = fopen("tasks.txt", "w");
    if (folder == NULL) {
        printf("Error.\n");
        return;
    }

    for (int i = 0; i < nbtaches; i++) {
        fprintf(folder, "%s\n%s\n%s\n%s\n%s\n",
        tasks[i].title,
        tasks[i].description,
        tasks[i].expary_date,
        tasks[i].priority,
        tasks[i].statut);
    }
    fclose(folder);
}

int main() {
    Task tasks[MAX_TASKS];
    int nbtaches = 0;
    int choice;

      do {
       displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
              addtask(tasks, nbtaches);
              nbtaches++;
              break;
            case 2:
              displaytask(tasks, nbtaches);
               break;
            case 3:
                updatetask(tasks, nbtaches);
                break;
            case 4:
                 deletetask(tasks, nbtaches);
                 nbtaches = deletetask(tasks, nbtaches);
                 break;
            case 5:
                 {
                    char priority[20];
                    printf("priority to filter (high/low):");
                    scanf("%s", priority);
                    filterbyPriority(tasks, nbtaches, priority);
                 }   
                  break;
            case 6:
            {
                char statut[20];
                    printf("statut to filter (complete/incomplete):");
                    scanf("%s", statut);
                    filterbyPriority(tasks, nbtaches, statut);
            }
                   break;
            case 7:
                 triTasks(tasks, nbtaches);
                 printf("Tri tasks by date.\n");
                 break;
            case 8:
                 sauvegardeTasks(tasks, nbtaches);
                 printf("by by!!\n");
                 break;
            default:
                printf("choice invalide.\n");     
        }
      } while (choice != 8);
      
        return 0;
        
      }
      