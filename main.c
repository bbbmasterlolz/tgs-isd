#include "header.h"

//aaaa

int main(int argc, char *argv[]) {
	Multilist L;
	menu M[maxMenu];
	createEmpty(&L);
	cred users[maxUser] = {{"admin", "admin"}, {"1", "1"}, {"brian", "1"}, {"damar", "2"}, {"verent", "3"}, {"alvin", "4"}};
	cred temp;
	int index_user = -1, nomorNota=0;
	string filename = "daftarMenu.txt";
	string saveMultiList = "savedata.txt";//untuk multi list
	
	readFromFile(filename, M);
	
	while(1){
		while(1){
			system("cls");
			printStartUp();
			printf("\n\t\t\t\t\t     %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 187); // Top border using extended ASCII
		    printf("\t\t\t\t\t-----%c   Login    %c----\n", 186, 186); // Left and right borders using extended ASCII
		    printf("\t\t\t\t\t     %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 188); // Bottom border using extended ASCII

			printf("\t\t\t\t\tusername: "); fflush(stdin); gets(temp.user);
			printf("\t\t\t\t\tpassword: "); fflush(stdin); gets(temp.pass);
			index_user = cekCred(users, temp);
			if(index_user == -1){
				printf("\n [Gagal Login]");
				getch();
			}else{
				printf("\n\t\t\t\t\t [Halo %s]", temp.user);
				getch();
				break;
			}
		}
		
		if(index_user == 0){
			menuAdmin(M);
			saveToFile(filename, M);
		}else{
			menuKasir(M, &L, &nomorNota, saveMultiList, filename);
		}
	}
	return 0;
}
