#include "STD.H"
#ifndef SDB_H
#define SDB_H
typedef struct SimpleDb
{
 uint32 Student_ID;
 uint32 Student_year;
 uint32 Course1_ID;
 uint32 Course1_grade;
 uint32 Course2_ID;
 uint32 Course2_grade;
 uint32 Course3_ID;
 uint32 Course3_grade;
 
} student;
void SDB_APP();
void SDB_action(uint32 x);
bool SDB_IsFull ();
void SDB_GetList();
bool SDB_IsIdExist (uint32 id);
void initialize();
uint8 SDB_GetUsedSize();
bool SDB_ReadEntry (uint32 id);
bool SDB_AddEntry(int ID);
void SDB_DeletEntry (uint32 id);
#endif