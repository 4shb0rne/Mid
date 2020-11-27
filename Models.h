struct patient {
  char name[255];
  char month[255];
  int day, year, age;
  patient *next, *prev;
} *head, *tail, *curr;

