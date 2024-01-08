#include <stdio.h>
#define DAYS 7
#define MAX 50
struct Day {
    int date;
    char dayName[MAX];
    char activity[MAX];
};

void readInfo(struct Day Calendar[MAX]) {
    printf("Enter details for each day:\n");
    for(int i=0; i<DAYS; ++i) {
        printf("Day %d:\n",i+1);
        printf("Day Name:\n");
        scanf("%s", Calendar[i].dayName);
        printf("Enter date: \n");
        scanf("%d", &Calendar[i].date);
        printf("Enter Activity:\n");
        scanf("%s", Calendar[i].activity);
    }
}

void displayInfo(struct Day Calendar[MAX]) {
    printf("Weekly Details:\n");
    for(int i=0; i<DAYS; ++i) {
        printf("Day %d:\n", i+1);
        printf("Date: %d\n", Calendar[i].date);
        printf("Day: %s\n", Calendar[i].dayName);
        printf("Activity: %s\n", Calendar[i].activity);
    }
}

int main() {
    struct Day weeklyCalendar[DAYS];
    readInfo(weeklyCalendar);
    displayInfo(weeklyCalendar);
    return 0;
}