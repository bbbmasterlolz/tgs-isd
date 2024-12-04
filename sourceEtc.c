#include "header.h"


void printStartUp(){
	printf("\n"
	"$$\\                       $$$$$$\\                                     $$\\            \n"
	"$$ |                     $$  __$$\\                                    $$ |           \n"    
	"$$ |      $$$$$$\\        $$ /  \\__| $$$$$$\\  $$$$$$\\  $$$$$$$\\   $$$$$$$ | $$$$$$\\   \n"        
	"$$ |      \\____$$\\       $$ |$$$$\\ $$  __$$\\ \\____$$\\ $$  __$$\\ $$  __$$ |$$  __$$\\  \n"        
	"$$ |      $$$$$$$ |      $$ |\\_$$ |$$ |  \\__|$$$$$$$ |$$ |  $$ |$$ /  $$ |$$$$$$$$ | \n"        
	"$$ |     $$  __$$ |      $$ |  $$ |$$ |     $$  __$$ |$$ |  $$ |$$ |  $$ |$$   ____| \n"
	"$$$$$$$$\\\\$$$$$$$ |      \\$$$$$$  |$$ |     \\$$$$$$$ |$$ |  $$ |\\$$$$$$$ |\\$$$$$$$\\  \n"       
	"\\________|\\_______|       \\______/ \\__|      \\_______|\\__|  \\__| \\_______| \\_______| \n");
}

int cekCred(cred users[], cred temp){
	int i;
	for(i=0;i<maxUser;i++){
		if(strcmp(users[i].pass, temp.pass)==0 && strcmp(users[i].user, temp.user)==0){
			return i;
		}
	}
	return -1;
}

void menuAdmin(menu M[]){
	while(1){
		int input;
		system("cls");
		printf("\n\t[admin]\n\n");
		printf("\n1. Edit Menu");
		printf("\n2. Omzet");
		printf("\n3. Popularitas");
		printf("\n0. Exit");
		printf("\n>>> ");
		fflush(stdin); scanf("%d", &input);
		
		switch(input){
			case 1: 
				menuPrint(M);
				editMenu(M);
				break;
			case 2:
				omzetPrint(M);
				break;
				
			case 0:
				return;
		}
		getch();
	}
}

void editMenu(menu M[]){
	int input;
	menu temp;
	printf("\nid menu: ");
	fflush(stdin);scanf("%d", &input);
	if(input>maxMenu || input<1){
		printf("\n\t[!] invalid");
		return;
	}
	temp.idMenu = input;
	temp.dibeli = 0;
	printf("\nnama menu: ");
	fflush(stdin);gets(temp.nama);
	printf("\nharga menu: ");
	fflush(stdin);scanf("%f", &temp.harga);
	M[input-1] = temp;
}

void omzetPrint(menu M[]){
	int i;
	printf("\n idMenu");
	printf("\e[10G nama");
	printf("\e[30G dibeli");
	printf("\e[40G harga");
	printf("\e[55G total");
	for(i=0;i<maxMenu;i++){
		printf("\n %d", M[i].idMenu);
		printf("\e[10G %s",M[i].nama);
		printf("\e[30G %d", M[i].dibeli);
		printf("\e[40G %.2f", M[i].harga);
		printf("\e[55G %.2f", (float) M[i].dibeli * M[i].harga);
	}
}

void menuPrint(menu M[]){
	int i;
	printf("\nidMenu \e[10G harga \e[25G nama\n");
	for(i=0;i<maxMenu;i++){
		printf("%d \e[10G %.2f", M[i].idMenu, M[i].harga);
		printf("\e[25G");
		printf(" %s \n",M[i].nama);
	}
}

void saveToFile(string filename, menu M[]) {
	int i;
	
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Error opening file for writing");
        return;
    }
	
    for (i = 0; i < maxMenu; i++) {
        fprintf(file, "%d %s | %f %d\n", M[i].idMenu, M[i].nama, M[i].harga, M[i].dibeli);
    }
	
    fclose(file);
}

void readFromFile(string filename, menu M[]){
	string sTemp;
	int i;
	
	FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }
    for(i=0;i<maxMenu;i++){
    	fscanf(file, "%d ", &M[i].idMenu);
    	strcpy(M[i].nama, "");
    	while(fscanf(file, "%s", sTemp)){
			if(strcmp(sTemp, "|")==0){
				M[i].nama[strlen(M[i].nama) - 1] = '\0';
				break;
			}else{
				strcat(M[i].nama, sTemp);
				strcat(M[i].nama, " ");
			}
		}
    	fscanf(file, "%f %d", &M[i].harga, &M[i].dibeli);
	}
	fclose(file);
}


void menuKasir(menu M[], Multilist *l, int *nomorNota){
	while(1){
		int input;
		system("cls");
		printf("\n\t[Kasir]\n\n");
		printf("\n1. Input Pesanan");
		printf("\n2. Tambahan Pesanan");
		printf("\n3. Gabung Nota");
		printf("\n4. Split Bill");
		printf("\n>>> ");
		fflush(stdin); scanf("%d", &input);
		
		switch(input){
			case 1: 
				inputPesanan(M, &(*l), &(*nomorNota));
			break;
			
			case 2:
				tambahPesanan(M, &(*l));	
			break;
			 
			case 3:
				mergeNota(&(*l));
			break;
		}
		getch();
	}
}

void insertAllChild(Multilist l, AddressParent temp1, AddressParent temp2){
    AddressChild temp = temp2->firstChild;
    int nota = temp2->dataParent.nomorNota;

    while(temp !=NULL){
        AddressChild tempChild1 = temp1->firstChild;
        bool idSama = 0; 
        
        while(tempChild1 !=NULL){
            if (tempChild1->dataChild.idMenu == temp->dataChild.idMenu) {
                tempChild1->dataChild.jumlah += temp->dataChild.jumlah;
                idSama = 1;
                break;
            }
            tempChild1 = tempChild1->next;
        }
        if(idSama ==0){
            insertLastChild(l, temp1->dataParent.nomorNota, makeDataChild(temp->dataChild.idMenu, temp->dataChild.nama, temp->dataChild.jumlah, temp->dataChild.harga));
        }
        temp = temp->next;
    }
}

void mergeNota(Multilist *l){
	if(!isEmpty(*l)){
		if(!isOneElement(*l)){
			int nota1, nota2;
			printf("\nMasukkan Nomor Nota 1 Yang Ingin Di Gabung : ");scanf("%d", &nota1);
			if(findParent(*l, nota1)!=NULL){
				AddressParent temp1 = findParent(*l, nota1);
				printf("\nMasukkan Nomor Nota 2 Yang Ingin Di Gabung : ");scanf("%d", &nota2);
				if(findParent(*l, nota2)!=NULL){
					AddressParent temp2 = findParent(*l, nota2);
					if(nota1<nota2){
						insertAllChild(*l, temp1, temp2);
						deleteAtParent(&(*l),temp2->dataParent.nomorNota);
					}else{
						insertAllChild(*l, temp2, temp1);
						deleteAtParent(&(*l), temp1->dataParent.nomorNota);
					}
				}else{
					printf("\n[!] Mohon Maaf Nota Tidak Ditemukan[!]");
				}
			}else{
				printf("\n[!] Mohon Maaf Nota Tidak Ditemukan[!]");
			}
		}else{
			printf("\n[!] Mohon Maaf Hanya Ada 1 Nota [!]");
		}
	}else{
		printf("\n[!] Mohon Maaf Belum Ada Pesanan [!]");
	}
}



void tambahPesanan(menu M[], Multilist *l){
	if(!isEmpty(*l)){
		string tanggalNota, cek;
		int input, index, banyak, cariNota;
		printAll(*l);
		printf("\nMasukkan Nomor Nota Yang Ingin Ditambah : ");scanf("%d", &cariNota);
		if(findParent(*l, cariNota)!=NULL){
			AddressParent temp = findParent(*l, cariNota);
			do{
				system("cls");
				menuPrint(M);
				printf("\nMasukkan Nomor atau Nama Menu Yang Ingin Di Pesan: ");scanf("%d", &input);
				index = findIdMenu(M, input);
		        if(index!=-1){
		        	printf("\nMasukkan Banyak %syang ingin di Tambah : ", M[index].nama);scanf("%d", &banyak);
		        	while(banyak<1){
		        		printf("\n\t[!] Tidak Boleh Lebih Kecil Dari 1 [!]\n");
		        		printf("\nMasukkan Banyak %syang ingin di Tambah : ", M[index].nama);scanf("%d", &banyak);
					}
					if(findChild(temp, M[index].idMenu)==NULL){
						insertLastChild((*l), temp->dataParent.nomorNota, makeDataChild(M[index].idMenu, M[index].nama, banyak, M[index].harga));
					}else{
						temp->firstChild->dataChild.jumlah += banyak;
					}
					printf("\n\tApakah ada lagi yang ingin di pesan [N/Y] ");scanf("%s", cek);
					if(strcmpi(cek,"n")==0){
						findParent(*l, temp->dataParent.nomorNota)->dataParent.Total = countTotalHarga(findParent(*l, temp->dataParent.nomorNota));
						printParent(findParent(*l, temp->dataParent.nomorNota));
						input = 0;
					}
				}else{
					printf("\n[!] Nama Atau Id tidak ditemukan [!]");
				}
			}while(input!=0);
		}else{
			printf("\n[!] Mohon Maaf Nota Tidak Ditemukan[!]");
		}
	}else{
		printf("\n[!] Mohon Maaf Belum Ada Pesanan [!]");
	}
	
}


void inputPesanan(menu M[], Multilist *l, int *nomorNota){
	if(findMejaKosong(*l)!=-1){
		string tanggalNota, cek;
		int index, banyak, input;
		(*nomorNota)++;
		makeTanggal(&tanggalNota);
		insertLastParent(&(*l), makeDataParent(*nomorNota, tanggalNota, findMejaKosong(*l), 0));
		do{
			system("cls");
			menuPrint(M);
			printf("\nMasukkan Nomor atau Nama Menu Yang Ingin Di Pesan: ");scanf("%d", &input);
			index = findIdMenu(M, input);
	        if(index!=-1){
	        	printf("\nMasukkan Banyak %syang ingin di Pesanan : ", M[index].nama);scanf("%d", &banyak);
	        	while(banyak<1){
	        		printf("\n\t[!] Tidak Boleh Lebih Kecil Dari 1 [!]\n");
	        		printf("\nMasukkan Banyak %syang ingin di Pesanan : ", M[index].nama);scanf("%d", &banyak);
				}
				if(findChild(findParent(*l, *nomorNota), M[index].idMenu)==NULL){
					insertLastChild((*l), *nomorNota, makeDataChild(M[index].idMenu, M[index].nama, banyak, M[index].harga));
				}else{
					findChild(findParent(*l, *nomorNota), M[index].idMenu)->dataChild.jumlah += banyak;
				}
				printf("\n\tApakah ada lagi yang ingin di pesan [N/Y] ");scanf("%s", cek);
				if(strcmpi(cek,"n")==0){
					findParent(*l, *nomorNota)->dataParent.Total = countTotalHarga(findParent(*l, *nomorNota));
					printParent(findParent(*l, *nomorNota));
					input = 0;
				}
			}else{
				printf("\n[!] Nama Atau Id tidak ditemukan [!]");
			}
		}while(input!=0);
	}else{
		printf("\n[!] Mohon Maaf Tidak Ada Meja Yang Tersedia [!]");
	}
	
}

float countTotalHarga(AddressParent parent){
	AddressChild temp = parent->firstChild;
	float total=0;
	while(temp != NULL){
		total += temp->dataChild.harga *temp->dataChild.jumlah;
		temp = temp->next;
	}
	return total;
}

DataChild makeDataChild(int idMenu, string nama, int jumlah, float harga){
	DataChild data;
	
	data.idMenu = idMenu;
	data.jumlah = jumlah;
	data.harga = harga;
	strcpy(data.nama, nama);
	
	return data;
}

DataParent makeDataParent(int nomorNota, string tanggalNota, int nomorMeja, float total){
	DataParent data;
	
	data.nomorNota = nomorNota;
	strcpy(data.tanggalNota, tanggalNota);
	data.nomorMeja = nomorMeja;
	data.Total = total;
	
	return data;
}

void makeTanggal(string *tanggalNota){
	time_t now;
    struct tm *timeinfo;

    time(&now);
    timeinfo = localtime(&now);
    
    strftime(*tanggalNota,sizeof(string), "%d-%m-%Y", timeinfo);
}


int countNota(AddressParent temp){
	if(temp==NULL){
		return 0;
	}
	return 1 + countNota(temp->next);

}

int findIdMenu(menu M[],int input) {
	int i;
    for(i = 0; i < maxMenu; i++) {
        if (M[i].idMenu == input) {
            return i;
        }
    }
    return -1;
}

int findMejaKosong(Multilist l){
    int mejaTerisi[20 + 1] = {0}; 
    AddressParent temp = l.firstParent;
    int i, meja;
    while(temp != NULL) {
        meja = temp->dataParent.nomorMeja;
        mejaTerisi[meja] = 1;
        temp = temp->next;
    }
    for(i = 1; i <= 20; i++) {
        if(mejaTerisi[i] == 0) {
            return i; 
        }
    }
    return -1;
}

