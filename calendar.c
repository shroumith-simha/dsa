#include <stdio.h>
#include <stdlib.h>
// Structure to represent a day in the calendar
struct Day
{
char * dayName; // Dynamically allocated string for the day name
int date;
char * activity; // Dynamically allocated string for the activity description
};
// Function to create a day
void create(struct Day * day)
{
// Allocate memory for the day name and activity
day -> dayName = (char * ) malloc(sizeof(char) * 20);
// Assuming day names are less than 20 characters
day -> activity = (char * ) malloc(sizeof(char) * 100);
// Assuming activity descriptions are less than 100 characters
// Input the day details
printf("Enter the day name:");
scanf("%s", day -> dayName);printf("Enter the date:");
scanf("%d", & day -> date);printf("Enter the activity for the day:");
scanf(" %[^\n]s", day -> activity); // Read the entire line, including spaces
}
// Function to read data from the keyboard and create the calendar
void read(struct Day * calendar, int size)
{
for (int i = 0; i < size; i++)
{
printf("Enter details for Day %d:\n", i + 1);
create( & calendar[i]);
}
}
// Function to display the calendar
void display(struct Day * calendar, int size)
{
printf("\nWeek's Activity Details:\n");
for (int i = 0; i < size; i++)
{
printf("Day %d:\n", i + 1);
printf("Day Name: %s\n", calendar[i].dayName);
printf("Date: %d\n", calendar[i].date);
printf("Activity: %s\n", calendar[i].activity);
printf("\n");
}
}
// Function to free the dynamically allocated memory
void freeMemory(struct Day * calendar, int size)
{
for (int i = 0; i < size; i++)
{
free(calendar[i].dayName);
free(calendar[i].activity);
}
}
int main()
{
int size;
printf("Enter the number of days in the week:");
scanf("%d", & size);// Dynamically allocate memory for the calendar
struct Day * calendar = (struct Day * ) malloc(sizeof(struct Day) * size);
// Check if memory allocation is successful
if (calendar == NULL)
{
printf("Memory allocation failed. Exiting program.\n");
return 1;
}
// Read and display the calendar
read(calendar, size);
display(calendar, size); // Free the dynamically allocated memory
freeMemory(calendar, size); // Free the memory allocated for the calendar array
free(calendar);
return 0;
}
