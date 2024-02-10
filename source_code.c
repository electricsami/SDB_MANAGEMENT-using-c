#include<stdio.h>
#include "STD.H"
#include"SDB.h"
student arr[10]; //globa student array
void SDB_APP(){
    int x,y=1,num;
initialize();//initialize the DB with 3 students
  
  do{
    printf("\n\n\t***Student Management System Using C***\n\n"); /*do-while condition to make a super loop for the program and terminates when when pressed 0*/
    printf("\t\t\tMAIN MENU\n");
    printf("\t\t=======================\n");
    printf("\t\t[1] Add A New student.\n");
    printf("\t\t[2] Show used size.\n");
    printf("\t\t[3] Search A student.\n");
    printf("\t\t[4] show all studentst.\n");
    printf("\t\t[5] check of student id exists\n");
    printf("\t\t[6] Delete A student.\n");
    printf("\t\t[7] check if DB is full\n");

   
   num=scanf("%d",&x);//store the scanf operation status (if succes=0,if fail=1) in num varibale
 while(num !=1 || x<=0)//condition to make sure user input is a positive int
 {
   printf("invalid format,input shoud not be a character or 0<,=0, try again");
   scanf("%*[^\n]");//this expression avoids infinte loops when user input charater,this process is repeated evry time user input is asked
   printf("\nchose from 1 to 7\n");
     num=scanf("%d",&x);

 }
 
 SDB_action(x);//passes user choise to the action function which has swtich cases
printf("[press any number for another operation] / [0] to exit \n");
      scanf("%d",&y);}while(y!=0);



}


void SDB_action(uint32 x){
 switch (x){
 case 1:
 int num3,s=1,id;
 
printf("enter student id that consists of any number from 0 to 9 :");
  num3=scanf("%d",&id);
while(num3 !=1 ||id<=0 )
 {
   printf("invalid format,id shoud not be a character or 0<,=0, try again");
   scanf("%*[^\n]");
   printf("\n enter student id that consists of any number from 0 to 9\n");
   num3=scanf("%d",&id);
 }
 if(SDB_IsIdExist(id)==0){  //condition to check if the student id exists or not before passing it to the addentry func,this is also repeated in other cases with other funcs to check
 if(SDB_AddEntry(id))
    printf("SDB is full, delete entry to add more\n");}
    else{printf("id already exists\n");}
 break;
 case 2:
 printf("%d students are in DB\n", SDB_GetUsedSize());
 break;
 case 3:
int x,num;
printf("enter the student id you wish to find ");
num=scanf("%d",&x);
 while(num !=1||x<=0)
 {
   printf("invalid format, try again");
   scanf("%*[^\n]");
   printf("\nchose id from numbers of 1 to 9\n");
     num=scanf("%d",&x);

 }
 printf("the id you entered is %d\n",x);
SDB_ReadEntry (x);
 break;
 case 4:
 SDB_GetList();
 break;
 case 5:
 int b,num2;
printf("enter the student id you wish to find ");
num2=scanf("%d",&b);
 while(num2 !=1||b<=0)
 {
   printf("invalid format, try again");
   scanf("%*[^\n]");
   printf("\nchose id from numbers of 1 to 9\n");
     num2=scanf("%d",&b);

 }
 
 if(SDB_IsIdExist (b))

printf("the id %d you entered exists\n",b);
else
printf("the id %d you entered doesn't exist\n",b);
break;
case 6:
printf("enter the student id you wish to delete ");
num=scanf("%d",&x);
 while(num !=1||x<=0)
 {
   printf("invalid format, try again");
   scanf("%*[^\n]");
   printf("\nchose id from numbers of 1 to 9\n");
     num=scanf("%d",&x);

 }
 printf("the id %d you entered now ",x);
 
 if(SDB_IsIdExist(x))
 {printf("deleted\n");SDB_DeletEntry(x);}
 else{printf("already doesnt exist\n");}
break;
case 7:
if(SDB_IsFull())
{printf("DB IS NOT FULL \n");}
else {printf("DB IS FULL\n");}
break;
 }}


bool SDB_AddEntry(int ID)
{
  int count=0,empty_slot=0,isvalid=0; //check before anything if the DB is full or not(empty_slot) and where an id=0(count)in the aray, since an id=0 is an empty index in the array where we can store the new added entry

for( int i=0;i<10;i++){
   

    if(arr[i].Student_ID==0){
        empty_slot=1;
        break;
    } count++;
}
if(empty_slot==1)  //checks if the DB has empty slots ie.empty or full
{
  /*printf("enter student id that consists of any number from 0 to 9 :");
  isvalid=scanf("%d",&arr[count].Student_ID);
while(isvalid !=1 ||arr[count].Student_ID==0 )
 {
   printf("invalid format,id shoud not be a character or 0, try again");
   scanf("%*[^\n]");
   printf("\n enter student id that consists of any number from 0 to 9\n");  //failed attempt :(
     isvalid=scanf("%d",&arr[count].Student_ID);
 }
 
/** exist=SDB_IsIdExist (arr[count].Student_ID);
 
  while(exist ){
    printf("that id already exists,try another id\n");
    printf("enter student id that consists of any number from 0 to 9 :");
  isvalid=scanf("%d",&arr[count].Student_ID);
while(isvalid !=1 ||arr[count].Student_ID==0 )
 {
   printf("invalid format,id shoud not be a character or 0, try again");
   scanf("%*[^\n]");
   printf("\n enter student id that consists of any number from 0 to 9\n");
     isvalid=scanf("%d",&arr[count].Student_ID);
 }
  exist=SDB_IsIdExist (arr[count].Student_ID);

  }*/
  
arr[count].Student_ID=ID;
printf("enter student year that consists of  number from 0 to 9:");
isvalid=scanf("%d",&arr[count].Student_year);
while(isvalid !=1)
 {
   printf("invalid format,years should not be a character, try again");
   scanf("%*[^\n]");
   printf("\nenter student year that consists of  number from 0 to 9:\n");
isvalid=scanf("%d",&arr[count].Student_year);

 }
  


  printf("enter course 1 id that consists of  number from 0 to 9:");
     isvalid=scanf("%d",&arr[count].Course1_ID);

while(isvalid !=1)
 {
   printf("invalid format,course id/grade should not be a character try again");
   scanf("%*[^\n]");
   printf("\nenter course 1 id that consists of  number from 0 to 9:\n");
   isvalid=scanf("%d",&arr[count].Course1_ID);

 }
 


printf("enter course 1 grade that consist of  number from 0 to 9:");
      isvalid=scanf("%d",&arr[count].Course1_grade);

while(isvalid !=1)
 {
   printf("invalid format,course id/grade should not be a character try again");
   scanf("%*[^\n]");
   printf("\nenter course 1 grade that consist of  number from 0 to 9:\n");
      isvalid=scanf("%d",&arr[count].Course1_grade);

 }
 


  printf("enter course 2 id that consist of  number from 0 to 9:");
     isvalid=scanf("%d",&arr[count].Course2_ID);

while(isvalid !=1)
 {
   printf("invalid format,course id/grade should not be a character try again");
   scanf("%*[^\n]");
   printf("\nenter course 2 id that consist of  number from 0 to 9:\n");
     isvalid=scanf("%d",&arr[count].Course2_ID);


 }
  


  printf("enter course 2 grade that consist of  number from 0 to 9:");
     isvalid=scanf("%d",&arr[count].Course2_grade);

while(isvalid !=1)
 {
   printf("invalid format,course id/grade should not be a character try again");
   scanf("%*[^\n]");
   printf("\nenter course 2 grade that consist of  number from 0 to 9:\n");
     isvalid=scanf("%d",&arr[count].Course2_grade);

 }
  


  printf("enter course 3 id that consist of  number from 0 to 9:");
     isvalid=scanf("%d",&arr[count].Course3_ID);

while(isvalid !=1)
 {
   printf("invalid format,course id/grade should not be a character try again");
   scanf("%*[^\n]");
   printf("\nenter course 3 id that consist of  number from 0 to 9:\n");
     isvalid=scanf("%d",&arr[count].Course3_ID);

 }
  


  printf("enter course 3 grade that consist of  number from 0 to 9:");
       isvalid=scanf("%d",&arr[count].Course3_grade);

while(isvalid !=1)
 {
   printf("invalid format, try again");
   scanf("%*[^\n]");
   printf("\nchose from 1 to 8\n");
     isvalid=scanf("%d",&arr[count].Course3_grade);

 }

  
return 0;

  }
else
return 1;

}
 void SDB_GetList(){
    printf("|===|====|===========|==============|============|==============|===========|==============|\n");
    printf("|ID |year|course 1 ID|course 1 grade|course 2 ID |course 2 grade|course 3 ID|course 3 grade|\n");
    printf("|===|====|===========|==============|============|==============|===========|==============|\n");

for(int i=0;i<10;i++){
    if(arr[i].Student_ID==0){
        continue;//skips printing any empty indexes where student id=0
    }
    /*printf("student id:%d  ",arr[i].Student_ID);
    printf("student year:%d  ",arr[i].Student_year);
    printf("student course 1 id:%d  ",arr[i].Course1_ID);
    printf("student course 1 grade:%d  ",arr[i].Course1_grade);
    printf("student course 2 id:%d  ",arr[i].Course2_ID);
    printf("student course 2 grade:%d  ",arr[i].Course2_grade);
    printf("student course 3 id:%d  ",arr[i].Course3_ID);
    printf("student course 3 grade: \n%d  ",arr[i].Course3_grade);*/
    printf("  %d  ",arr[i].Student_ID);
    printf("  %d  ",arr[i].Student_year);
    printf("      %d  ",arr[i].Course1_ID);
    printf("          %d  ",arr[i].Course1_grade);
    printf("           %d  ",arr[i].Course2_ID);
    printf("           %d  ",arr[i].Course2_grade);
    printf("           %d  ",arr[i].Course3_ID);
    printf("           %d\n",arr[i].Course3_grade);

}}
 
bool SDB_IsIdExist (uint32 id){
int i,count=0;
    for(i = 0; i < 10; i++){
       
        if(arr[i].Student_ID == id)//checks if a student ID exists or not in the array with a giving id as a func argument
        {
          return true;
           // count++;
        } 
    }
   // if(count>2) {return true;}
    //else 
    return false;
}


void initialize(){
    arr[0].Student_ID=1;
    arr[1].Student_ID=2;
    arr[2].Student_ID=3;
    arr[3].Student_ID=0;
    arr[4].Student_ID=0;
    arr[5].Student_ID=0;
    arr[6].Student_ID=0;
    arr[7].Student_ID=0;
    arr[8].Student_ID=0;
    arr[9].Student_ID=0;
    


}
uint8 SDB_GetUsedSize(){
    int i,count=0;
    for(i=0;i<10;i++){
        if (arr[i].Student_ID!=0)//counts all the student id entries in the array that are not 0
        {
            count++;
        }
    }
    return count;//return amount of existing student IDs
}


 bool SDB_ReadEntry (uint32 id){
    
 if(SDB_IsIdExist(id)){

int i,G_count=0;  //searches for the given id in the array and storing the index in which the id was found in (g_count), then print student valuse at that index
  
 for(i = 0; i < 10; i++){ if(arr[i].Student_ID == id){break;} G_count++; }     
        
    printf("|===|====|===========|==============|============|==============|===========|==============|\n");
    printf("|ID |year|course 1 ID|course 1 grade|course 2 ID |course 2 grade|course 3 ID|course 3 grade|\n");
    printf("|===|====|===========|==============|============|==============|===========|==============|\n");
    printf("  %d  ",arr[G_count].Student_ID);
    printf("  %d  ",arr[G_count].Student_year);
    printf("      %d  ",arr[G_count].Course1_ID);
    printf("          %d  ",arr[G_count].Course1_grade);
    printf("           %d  ",arr[G_count].Course2_ID);
    printf("           %d  ",arr[G_count].Course2_grade);
    printf("           %d  ",arr[G_count].Course3_ID);
    printf("           %d\n",arr[G_count].Course3_grade);}
else printf("student is not found \n");}

void SDB_DeletEntry (uint32 id){

  if(SDB_IsIdExist(id)==1)//searches for the given student id and and changes its value to student id=0,making it an empty slot for a new entry to replace all the rest of the values in the student struct
  {
    for(int i=0;i<10;i++)
    {
      if(arr[i].Student_ID==id)
      {
        arr[i].Student_ID=0;
        break;
      }
    }
  }
}

bool SDB_IsFull (){
for( int i=0;i<10;i++)
{
   

    if(arr[i].Student_ID==0)//checks if there are any empty slosts as in student ID=0,returns true if found, returns false if no id=0 found in the array
    {
        return true;
        break;
    } 
}
return false;
}