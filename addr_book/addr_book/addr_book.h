#pragma once
#include<stdlib.h>
#include<stdio.h>
#include<stddef.h>
enum{
	DISPLAY = 1,
	ADD = 2,
	ERASE = 3,
	FIND = 4,
	MODIFY=5,
    EXIT=6
};
#define NAME_SIZE 200
#define PHONY_SIZE 200
#define ADDR_SIZE  200
typedef struct PersonInfo{
	char name[NAME_SIZE]; 
	char phone[PHONY_SIZE];
	char addr[ADDR_SIZE];

}PersonInfo;
typedef struct AddrBook{
	PersonInfo* data;
	size_t size;
	size_t capacity;
}AddrBook;
void AddrBookInit(AddrBook* addr_book);
void AddrBookAdd(AddrBook* addr_book);
void AddrBookErase(AddrBook* addr_book);
void AddrBookFind(AddrBook* addr_book);
void AddrBookDisplay(AddrBook* addr_book);