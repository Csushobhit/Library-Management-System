#include <stdio.h>
#include <stdlib.h>

// Function declarations
void add_course();
void view_courses();
void search_course();
void delete_course();
void exit_program();

// Global variables
struct course {
  char name[100];
  int credits;
};

struct course courses[100];
int num_courses = 0;

// Main function
int main() {
  int choice;

  while (1) {
    printf("Welcome to the Learning Management System!\n");
    printf("What would you like to do?\n");
    printf("1. Add a course\n");
    printf("2. View courses\n");
    printf("3. Search for a course\n");
    printf("4. Delete a course\n");
    printf("5. Exit\n");

    scanf("%d", &choice);

    switch (choice) {
      case 1:
        add_course();
        break;
      case 2:
        view_courses();
        break;
      case 3:
        search_course();
        break;
      case 4:
        delete_course();
        break;
      case 5:
        exit_program();
        break;
      default:
        printf("Invalid choice.\n");
    }
  }

  return 0;
}

// Function to add a course
void add_course() {
  char name[100];
  int credits;

  printf("Enter the name of the course: ");
  scanf("%s", name);

  printf("Enter the number of credits: ");
  scanf("%d", &credits);

  struct course new_course;
  strcpy(new_course.name, name);
  new_course.credits = credits;

  courses[num_courses++] = new_course;

  printf("Course added successfully!\n");
}

// Function to view all courses
void view_courses() {
  for (int i = 0; i < num_courses; i++) {
    printf("Course name: %s\n", courses[i].name);
    printf("Number of credits: %d\n\n", courses[i].credits);
  }
}

// Function to search for a course
void search_course() {
  char name[100];

  printf("Enter the name of the course to search for: ");
  scanf("%s", name);

  for (int i = 0; i < num_courses; i++) {
    if (strcmp(courses[i].name, name) == 0) {
      printf("Course found!\n");
      printf("Course name: %s\n", courses[i].name);
      printf("Number of credits: %d\n\n", courses[i].credits);
      return;
    }
  }

  printf("Course not found.\n");
}

// Function to delete a course
void delete_course() {
  char name[100];

  printf("Enter the name of the course to delete: ");
  scanf("%s", name);

  for (int i = 0; i < num_courses; i++) {
    if (strcmp(courses[i].name, name) == 0) {
      for (int j = i; j < num_courses - 1; j++) {
        struct course temp = courses[j];
        courses[j] = courses[j + 1];
        courses[j + 1] = temp;
      }
      num_courses--;
      printf("Course deleted successfully!\n");
      return;
    }
  }

  printf("Course not found.\n");
}

// Function to exit the program
void exit_program() {
  printf("Thank you for using the Learning Management System!\n");
  exit(0);
