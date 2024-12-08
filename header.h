#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <windows.h>

#define maxMenu 15
#define maxUser 6

typedef char string[200];
typedef char sBuff[20000];

typedef struct Child* AddressChild;
typedef struct Parent* AddressParent;

typedef struct cred{
	string user;
	string pass;
}cred;

typedef struct menu{
	int idMenu;
	string nama;
	float harga;
	int dibeli;
}menu;

typedef struct DataChild{
	int idMenu;
	string nama;
	int jumlah;
	float harga;
}DataChild;

typedef struct DataParent{
	int nomorNota;
	string tanggalNota;
	int nomorMeja;
	float Total;
}DataParent;

typedef struct Child{
	DataChild dataChild;
	AddressChild next;
}NodeChild;

typedef struct Parent{
	DataParent dataParent;
	AddressParent next;
	
	AddressChild firstChild;
}NodeParent;

typedef struct{
	AddressParent firstParent;
}Multilist;

//source etc
void printStartUp();
void menuAdmin(menu M[]);

void menuPrint(menu M[]);
void saveToFile(string filename, menu M[]);

void editMenu(menu M[]);
void omzetPrint(menu M[]);

void readFromFile(string filename, menu M[]);
void menuKasir(menu M[], Multilist *l, int *nomorNota, string filename, string filenameMenu);

void insertAllChild(Multilist l, AddressParent temp1, AddressParent temp2);
void mergeNota(Multilist *l);

void tambahPesanan(menu M[], Multilist *l);
void inputPesanan(menu M[], Multilist *l, int *nomorNota);

float countTotalHarga(AddressParent parent);
DataChild makeDataChild(int idMenu, string nama, int jumlah, float harga);

DataParent makeDataParent(int nomorNota, string tanggalNota, int nomorMeja, float total);
void makeTanggal(string *tanggalNota);

int countNota(AddressParent temp);
int findIdMenu(menu M[],int input);

int findNamaMenu(menu M[], string input);
int findMejaKosong(Multilist l);

void splitBill(Multilist *l, int *nomorNota);

void catat(menu M[], DataChild D);
void bayar(menu M[], Multilist *l, string filename);
//source Parent
void createEmpty(Multilist *L);

AddressParent alokasiParent(DataParent data);
AddressParent findParent(Multilist L, int idCari);

void insertFirstParent(Multilist *L, DataParent data);
void insertAfterParent(Multilist *L, int idParent, DataParent data);
void insertLastParent(Multilist *L, DataParent data);

void deleteFirstParent(Multilist *L);
void deleteAtParent(Multilist *L, int idParent);
void deleteLastParent(Multilist *L);

void printParent(AddressParent parent);
void printAll(Multilist L);
void printAllParent(Multilist L);

bool isEmpty(Multilist L);
bool isOneElement(Multilist L);
bool haveChild(AddressParent ap);

void deleteAllChild(AddressParent parent);


AddressChild alokasiChild(DataChild data);
AddressChild findChild(AddressParent parent, int idMenu);

void insertFirstChild(Multilist L, int idParent, DataChild data);
void insertLastChild(Multilist L, int idParent, DataChild data);

void deleteFirstChild(Multilist L, int idParent);
void deleteLastChild(Multilist L, int idParent);

void printChild(AddressChild child);
void printAllChild(AddressParent parent);


//save and load data from a file using multi list
void writeToFileMultiList(Multilist list, string filename);
void readFromFileMultiList(Multilist* list, const char* filename);


//warna
void setColor(int color);//set colour sesuai parameter
void resetColor();
void loadingBar();

