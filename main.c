#include "header.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	Multilist L;
	menu M[maxMenu];
	createEmpty(&L);
	cred users[maxUser] = {{"admin", "admin"}, {"1", "1"}, {"brian", "1"}, {"damar", "2"}, {"verent", "3"}, {"alvin", "4"}};
	cred temp;
	int index_user = -1, count, nomorNota=0;
	string filename = "daftarMenu.txt";
	
	readFromFile(filename, M);
	
	while(1){
		while(1){
			system("cls");
			printStartUp();
			printf("\n\t[LOGIN]\n\n");
			printf("username: "); fflush(stdin); gets(temp.user);
			printf("password: "); fflush(stdin); gets(temp.pass);
			index_user = cekCred(users, temp);
			if(index_user == -1){
				printf("\n [Gagal Login]");
				getch();
			}else{
				printf("\n [Halo %s]", temp.user);
				getch();
				break;
			}
		}
		
		if(index_user == 0){
			menuAdmin(M);
			saveToFile(filename, M);
		}else{
			menuKasir(M, &L, count, &nomorNota);
		}
	}
	return 0;
}
