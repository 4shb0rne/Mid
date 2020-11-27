#include <stdio.h>
#include <stdlib.h>
#include "Models.h"
#include <string.h>
patient *createNode(char *name, char *month, int day, int year, int age) {
  patient *temp = (patient*)malloc(sizeof(patient));
  strcpy(temp->name, name);
  strcpy(temp->month, month);
  temp->day = day;
  temp->year = year;
  temp->age = age;
  return temp;
};

void pushMid(char *name, char *month, int day, int year, int age)
{
    patient *newNode = createNode(name, month, day , year, age);
    if(!head)
    {
        head = tail = newNode;
    }
    else if(age > head->age)
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }    
    else if(age < tail->age)
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    else{
        patient *curr = head;
        while(curr && curr->next->age > age)
        {
            curr = curr->next;
        }
        newNode->next = curr->next;
        newNode->prev = curr;
        curr->next->prev = newNode;
        curr->next = newNode;
    }
}
void showCured(int left, int temp)
{
    patient *curr = tail;
    printf("Need %d more cure\n", left);
    for(int i = 0; curr; curr=curr->prev,i++)
    {
        printf("%d %s %d - %s\n", curr->day, curr->month, curr->year, curr->name);
    }
}
bool isNum(char c)
{
    if(c >= 48 && c <= 57)
    {
        return true;
    }
    else false;
}
void popHead() {
  if(head && head == tail) { 
    head = tail = NULL;
    free(head);
  } else { 
    patient *newHead = head->next; 
    head->next = newHead->prev = NULL; 
    free(head); 
    head = newHead; 
  }
}
int convertstr(char* str)
{
    int res = 0;
    for (int i = 0; str[i] != '\0'; ++i)
    {
        res = res * 10 + str[i] - '0';
    }
    return res;
}
int countage(int birth_date, int birth_month, int birth_year, int present_date, int present_month, int present_year) {
   int month[15] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
   if (birth_date > present_date) 
   {
      present_date = present_date + month[birth_month - 1];
      present_month = present_month - 1;
   }
   if (birth_month > present_month) 
   {
      present_year = present_year - 1;
      present_month = present_month + 12;
   }
    int final_date = present_date - birth_date;
    int final_month = present_month - birth_month;
    int final_year = present_year - birth_year;
    int age = (final_year*365) + (final_month*30) + final_date;
    return age;
}
int checkmonth(char *str)
{
    if(strcmp(str, "january") == 0)
    {
        return 1;
    } else if(strcmp(str, "february") == 0)
    {
        return 2;
    } else if(strcmp(str, "march") == 0)
    {
        return 3;
    } else if(strcmp(str, "april") == 0)
    {
        return 4;
    } else if(strcmp(str, "may") == 0)
    {
        return 5;
    } else if(strcmp(str, "juny") == 0)
    {
        return 6;
    }else if(strcmp(str, "july") == 0)
    {
        return 7;
    }else if(strcmp(str, "august") == 0)
    {
        return 8;
    }else if(strcmp(str, "september") == 0)
    {
        return 9;
    }else if(strcmp(str, "october") == 0)
    {
        return 10;
    }else if(strcmp(str, "november") == 0)
    {
        return 11;
    }else if(strcmp(str, "december") == 0)
    {
        return 12;
    }
}
