#include "header.h"

//Disusun Oleh :
//		Michael Brian Supranoto        - 230712483
//		Dionisius Christinus Jan Alvin - 230712393
//		I Made Damar Sadhu Wicaksana   - 230712395
//		Verrent Natha Aurelia	       - 230712401

int main(int argc, char *argv[]) {
	Multilist L;
	AddressParent tempParent = L.firstParent;
	menu M[maxMenu];
	createEmpty(&L);
	cred users[maxUser] = {{"admin", "admin"}, {"1", "1"}, {"brian", "1"}, {"damar", "2"}, {"verent", "3"}, {"alvin", "4"}};
	cred temp;
	int index_user = -1, nomorNota;
	string filename = "daftarMenu.txt";
	string saveMultiList = "savedata.txt";//untuk multi list
	
	readFromFile(filename, M);
	
	

	if (isFileEmpty(saveMultiList) == 0) { 
    	readFromFileMultiList(&L, saveMultiList);
	}
	
	tempParent = L.firstParent;
	
	if (tempParent != NULL) {
	    while (tempParent->next != NULL) {
	        tempParent = tempParent->next;
	    }
	    
	    nomorNota = tempParent->dataParent.nomorNota;
	} else {

	    nomorNota = 0;
	}
	
	while(1){
		while(1){
			system("cls");
			printStartUp();
			printf("\n\e[50G %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 201, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205,205, 187); // Top border using extended ASCII
		    printf("\e[45G -----%c   Login     %c----\n", 186, 186); // Left and right borders using extended ASCII
		    printf("\e[50G %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 200, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205, 205,205, 188); // Bottom border using extended ASCII

			printf("\e[45G username: "); fflush(stdin); gets(temp.user);
			printf("\e[45G password: "); fflush(stdin); gets(temp.pass);
			index_user = cekCred(users, temp);
			if(index_user == -1){
				printf("\n\e[42G[ !   Gagal Login   ! ]");
				getch();
			}else{
				loginScenario();
				
				printf("\n\e[42G[>     Halo, %s !\e[65G<]", temp.user);
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
