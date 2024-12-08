#include "header.h"


void printStartUp(){
//	printf("\n"
//	"\t\t$$\\                       $$$$$$\\                                     $$\\            \n"
//	"\t\t$$ |                     $$  __$$\\                                    $$ |           \n"    
//	"\t\t$$ |      $$$$$$\\        $$ /  \\__| $$$$$$\\  $$$$$$\\  $$$$$$$\\   $$$$$$$ | $$$$$$\\   \n"        
//	"\t\t$$ |      \\____$$\\       $$ |$$$$\\ $$  __$$\\ \\____$$\\ $$  __$$\\ $$  __$$ |$$  __$$\\  \n"        
//	"\t\t$$ |      $$$$$$$ |      $$ |\\_$$ |$$ |  \\__|$$$$$$$ |$$ |  $$ |$$ /  $$ |$$$$$$$$ | \n"        
//	"\t\t$$ |     $$  __$$ |      $$ |  $$ |$$ |     $$  __$$ |$$ |  $$ |$$ |  $$ |$$   ____| \n"
//	"\t\t$$$$$$$$\\\\$$$$$$$ |      \\$$$$$$  |$$ |     \\$$$$$$$ |$$ |  $$ |\\$$$$$$$ |\\$$$$$$$\\  \n"       
//	"\t\t\\________|\\_______|       \\______/ \\__|      \\_______|\\__|  \\__| \\_______| \\_______| \n");

//	printf("\n");
//
//    
//    setColor(32);
//    printf("\t\t$$\\                       $$$$$$\\                                     $$\\            \n");
//    printf("\t\t$$ |                     $$  __$$\\                                    $$ |           \n");
//
//    // Warna Putih (tengah)
//    setColor(37);
//    printf("\t\t$$ |      $$$$$$\\        $$ /  \\__| $$$$$$\\  $$$$$$\\  $$$$$$$\\   $$$$$$$ | $$$$$$\\   \n");
//    printf("\t\t$$ |      \\____$$\\       $$ |$$$$\\ $$  __$$\\ \\____$$\\ $$  __$$\\ $$  __$$ |$$  __$$\\  \n");
//    printf("\t\t$$ |      $$$$$$$ |      $$ |\\_$$ |$$ |  \\__|$$$$$$$ |$$ |  $$ |$$ /  $$ |$$$$$$$$ | \n");
//
//    // Warna Merah (sebelah kanan)
//    setColor(31);
//    printf("\t\t$$ |     $$  __$$ |      $$ |  $$ |$$ |     $$  __$$ |$$ |  $$ |$$ |  $$ |$$   ____| \n");
//    printf("\t\t$$$$$$$$\\\\$$$$$$$ |      \\$$$$$$  |$$ |     \\$$$$$$$ |$$ |  $$ |\\$$$$$$$ |\\$$$$$$$\\  \n");
//
//    // Warna Putih (sebelah kanan, bagian bawah)
//    setColor(37);
//    printf("\t\t\\________|\\_______|       \\______/ \\__|      \\_______|\\__|  \\__| \\_______| \\_______| \n");
//
//    // Reset warna ke default
//    printf("\033[0m");

	char topLeft = 201, topRight = 187, bottomLeft = 200, bottomRight = 188;
    char horizontal = 205, vertical = 186;
    int i;
    // Menampilkan border atas
    printf("\n");
    printf("\t%c", topLeft);  // Corner kiri atas
    for ( i = 0; i < 100; i++) {
        printf("%c", horizontal);  // Baris horizontal atas
    }
    printf("%c\n", topRight);  // Corner kanan atas

    setColor(32);
    printf("\t\t$$\\                       $$$$$$\\                                     $$\\            \n");
    printf("\t\t$$ |                     $$  __$$\\                                    $$ |           \n");

    // Warna Putih (tengah)
    setColor(37);
    printf("\t\t$$ |      $$$$$$\\        $$ /  \\__| $$$$$$\\  $$$$$$\\  $$$$$$$\\   $$$$$$$ | $$$$$$\\   \n");
    printf("\t\t$$ |      \\____$$\\       $$ |$$$$\\ $$  __$$\\ \\____$$\\ $$  __$$\\ $$  __$$ |$$  __$$\\  \n");
    printf("\t\t$$ |      $$$$$$$ |      $$ |\\_$$ |$$ |  \\__|$$$$$$$ |$$ |  $$ |$$ /  $$ |$$$$$$$$ | \n");

    // Warna Merah (sebelah kanan)
    setColor(31);
    printf("\t\t$$ |     $$  __$$ |      $$ |  $$ |$$ |     $$  __$$ |$$ |  $$ |$$ |  $$ |$$   ____| \n");
    printf("\t\t$$$$$$$$\\\\$$$$$$$ |      \\$$$$$$  |$$ |     \\$$$$$$$ |$$ |  $$ |\\$$$$$$$ |\\$$$$$$$\\  \n");

    // Warna Putih (sebelah kanan, bagian bawah)
    setColor(37);
    printf("\t\t\\________|\\_______|       \\______/ \\__|      \\_______|\\__|  \\__| \\_______| \\_______| \n");


    // Menampilkan border bawah
    setColor(37);  // Mengatur warna putih
    printf("\t%c", bottomLeft);  // Corner kiri bawah
    for ( i = 0; i < 100; i++) {
        printf("%c", horizontal);  // Baris horizontal bawah
    }
    printf("%c\n", bottomRight);  // Corner kanan bawah


    resetColor();



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
		int currentMenu=0;
		int jumlahMenu=4;
		
		
		
		while(1){
			system("cls"); // Clear screen
	        showAdminMenu(currentMenu);
	
	        input = _getch(); // Get key press
	        if (input == 0 || input == 224) {
	            // Arrow keys
	            input = _getch();
	            if (input == UP_ARROW) {
	                currentMenu = (currentMenu - 1 + jumlahMenu) % jumlahMenu;
	            } else if (input == DOWN_ARROW) {
	                currentMenu = (currentMenu + 1) % jumlahMenu;
	            }
	        } else if (input == ENTER_KEY) {
	            // Enter key pressed
	            break;
	        }
	    }
    
		
		switch(currentMenu){
			case 0: 
				menuPrint(M);
				editMenu(M);
			break;
			
			case 1:
				omzetPrint(M);
			break;

			case 2:
				Popularitas(M);
			break;
							
			case 3:
				return;
		}
		getch();
	}
}

void Popularitas(menu M[]){//UI NYA BANGGG ini banggg
	int i, tempF = 0, tempD = 0;
	
	char topLeft = 201, topRight = 187, bottomLeft = 200, bottomRight = 188;
    char horizontal = 205, vertical = 186;
    char threeWayToTheRight = 204, threeWayToTheLeft = 185, threeWayUp = 202, threeWayDown = 203;
	char fourway = 206;
	
	for(i=0;i<maxMenu;i++){
		if(M[tempF].dibeli <= M[i].dibeli && M[i].jenis == 'F'){
			tempF = i;
		}
	}
	for(i=0;i<maxMenu;i++){
		if(M[tempD].dibeli <= M[i].dibeli && M[i].jenis == 'D'){
			tempD = i;
		}
	}
		
	//Workspace
	gotoxy(20, 10);
	printf("%c", topLeft);//Baris Pertama
    for(i=0; i<80; i++){
    	printf("%c", horizontal);
	}
	printf("%c\n", topRight);
	printf("\e[20G%c \e[50GMakanan Paling Populer \e[101G%c", vertical, vertical);
	
	gotoxy(20, 12);
	printf("%c", threeWayToTheRight);//Baris Kedua
    for(i=0; i<78; i++){
    	if( i == 4 || i == 38){
    		printf("%c", threeWayDown);
		}
    	printf("%c", horizontal);
	}
	printf("%c\n", threeWayToTheLeft);
	gotoxy(20, 13);
	printf("%c Id \e[25G%c Nama Menu \e[60G%c Total Dijual \e[101G%c ", vertical, vertical, vertical, vertical);
//	printf("%c Id \e[25G%c Nama Menu \e[60G%c Total Dijual %c ", vertical, M[tempF].idMenu, vertical, M[tempF].nama, vertical);
	
	gotoxy(20, 14);
	printf("%c", threeWayToTheRight);//Baris Kedua
    for(i=0; i<78; i++){
    	if( i == 4 || i == 38){
    		printf("%c", fourway);
		}
    	printf("%c", horizontal);
	}
	printf("%c\n", threeWayToTheLeft);
	
	gotoxy(20, 15);
	printf("%c %d \e[25G%c %s \e[60G%c %d \e[101G%c ", vertical, M[tempF].idMenu, vertical, M[tempF].nama, vertical, M[tempF].dibeli, vertical);
	
	gotoxy(20, 16);
	printf("%c", threeWayToTheRight);//Baris Kedua
    for(i=0; i<78; i++){
    	if( i == 4 || i == 38){
    		printf("%c", fourway);
		}
    	printf("%c", horizontal);
	}
	printf("%c\n", threeWayToTheLeft);
	
	gotoxy(20, 17);
	printf("%c %d \e[25G%c %s \e[60G%c %d \e[101G%c ", vertical, M[tempD].idMenu, vertical, M[tempD].nama, vertical, M[tempD].dibeli, vertical);
	
	gotoxy(20, 18);
	printf("%c", bottomLeft);//Baris Kedua
    for(i=0; i<78; i++){
    	if( i == 4 || i == 38){
    		printf("%c", threeWayUp);
		}
    	printf("%c", horizontal);
	}
	printf("%c\n", bottomRight);
	
	//Workspace
//	printf("\n Makanan paling populer : %s", M[tempF].nama);
//	printf("\n Total Dijual           : %d", M[tempF].dibeli);
//	printf("\n");
//	printf("\n Minuman paling populer : %s", M[tempD].nama);
//	printf("\n Total Dijual           : %d", M[tempD].dibeli);
}

void showAdminMenu(int currentMenu) {
    int i;
    
    const char *menuItems[] = {
        "Edit Menu",
        "Omzet",
        "Popularitas",
        "Exit"
    };

    // Draw top border
    printf("\e[45G%c", 201); // Top-left corner
    for (i = 0; i < 28; i++) printf("%c", 205); // Horizontal line
    printf("%c\n", 187); // Top-right corner

    // Title row
    printf("\e[45G%c       Admin Menu           %c\n", 186, 186);

    // Draw title separator
    printf("\e[45G%c", 204); // Left T-junction
    for (i = 0; i < 28; i++) printf("%c", 205); // Horizontal line
    printf("%c\n", 185); // Right T-junction

    // Menu items
    for (i = 0; i < 4; i++) {
        if (i == currentMenu) {
            // Highlight the selected item
            printf("\e[45G%c", 186);
            setColor(32);
            printf(" > %-24s ", menuItems[i]);
            resetColor();
            printf("%c\n", 186);
        } else {
            printf("\e[45G%c    %-23s %c\n", 186, menuItems[i], 186);
        }
    }

    // Draw bottom border
    printf("\e[45G%c", 200); // Bottom-left corner
    for (i = 0; i < 28; i++) printf("%c", 205); // Horizontal line
    printf("%c\n", 188); // Bottom-right corner
}

void editMenu(menu M[]){
	int input;
	menu temp;
	printf("\nId menu: ");
	fflush(stdin);scanf("%d", &input);
	if(input>maxMenu || input<1){
		setColor(31);
		printf("\n\t[!] invalid");
		setColor(37);
		return;
	}
	temp.idMenu = input;
	temp.dibeli = 0;
	printf("\nNama menu : ");
	fflush(stdin);gets(temp.nama);
	while(1){
		printf("\nHarga menu: ");
		fflush(stdin);
		if(scanf("%f", &temp.harga)==1){
			break;
		}
	}
	printf("\nMakanan = F | Minuman = D");
	while(1){
		printf("\nJenis menu: ");
		fflush(stdin);scanf("%c", &temp.jenis);
		if(temp.jenis == 'F' || temp.jenis == 'f'){
			temp.jenis = 'F';
			break;
		}else if(temp.jenis == 'd' || temp.jenis == 'D'){
			temp.jenis = 'D';
			break;
		}
	}
	M[input-1] = temp;
}

void omzetPrint(menu M[]){
	int i;
	char topLeft = 201, topRight = 187, bottomLeft = 200, bottomRight = 188;
    char horizontal = 205, vertical = 186;
    char threeWayToTheRight = 204, threeWayToTheLeft = 185, threeWayUp = 202, threeWayDown = 203;
	char fourway = 206;
	
	printf("%c", topLeft);
	for(i=0; i<75; i++){
//		printf("%c", horizontal);
		printf("%c", horizontal);
		if(i == 8 || i == 27 || i == 36 || i == 50){
			printf("%c", threeWayDown);
		}
	}
	printf("%c", topRight);
	
	
	printf("\n%c", vertical);
	printf("idMenu");
	printf("\e[11G%cNama", vertical);
	printf("\e[31G%cDibeli", vertical);
	printf("\e[41G%cHarga", vertical);
	printf("\e[56G%cTotal", vertical);
	printf("\e[81G%c\n", vertical);
	
	printf("%c", threeWayToTheRight);
	for(i=0; i<75; i++){
//		printf("%c", horizontal);
		printf("%c", horizontal);
		if(i == 8 || i == 27 || i == 36 || i == 50){
			printf("%c", fourway);
		}
	}
	printf("%c", threeWayToTheLeft);
	
	for(i=0;i<maxMenu;i++){
//		printf("\n%c", vertical);
		
		
		printf("\n%c", vertical);
		printf("%d", M[i].idMenu);
		printf("\e[10G %c %s", vertical,M[i].nama);
		printf("\e[30G %c %d", vertical, M[i].dibeli);
		printf("\e[40G %c %.2f", vertical,  M[i].harga);
		printf("\e[55G %c %.2f", vertical, (float) M[i].dibeli * M[i].harga);
		printf("\e[80G %c", vertical);
	}
	
	printf("\n%c", bottomLeft);
	for(i=0; i<75; i++){
		printf("%c", horizontal);
		if(i == 8 || i == 27 || i == 36 || i == 50){
			printf("%c", threeWayUp);
		}
	}
	printf("%c\n", bottomRight);
	
	printf("\n\e[55G Tekan '");
	setColor(33);
	printf("\e[63GApapun");
	setColor(37);
	printf("\e[69G' Untuk Kembali. . .");
	
}

void menuPrint(menu M[]){
	int i;
	char topLeft = 201, topRight = 187, bottomLeft = 200, bottomRight = 188;
    char horizontal = 205, vertical = 186;
    char threeWayToTheRight = 204, threeWayToTheLeft = 185, threeWayUp = 202, threeWayDown = 203;
	char fourway = 206;
	
	printf("%c", topLeft);
	for(i=0; i<56; i++){
		printf("%c", horizontal);
		if(i == 8 || i == 27){
			printf("%c", threeWayDown);
		}
	}
	printf("%c", topRight);
	
	printf("\n%c", vertical);
	printf("\e[3GidMenu");
	printf("\e[11G%c      Harga", vertical);
	printf("\e[31G%c            Nama", vertical);
	printf("\e[59G %c\n", vertical);
	
	printf("%c", threeWayToTheRight);
	for(i=0; i<56; i++){
		printf("%c", horizontal);
		if(i == 8 || i == 27){
			printf("%c", fourway);
		}
	}
	printf("%c", threeWayToTheLeft);
	
	for(i=0;i<maxMenu;i++){
		printf("\n%c", vertical);
		printf("%d", M[i].idMenu);
		printf("\e[10G %c %.2f", vertical, M[i].harga);
		printf("\e[30G %c %s", vertical, M[i].nama);
		printf("\e[59G %c", vertical);
	}
	
	printf("\n%c", bottomLeft);
	for(i=0; i<56; i++){
		printf("%c", horizontal);
		if(i == 8 || i == 27){
			printf("%c", threeWayUp);
		}
	}
	printf("%c\n", bottomRight);
}

void saveToFile(string filename, menu M[]) {
	int i;
	
    FILE *file = fopen(filename, "w");
    if (!file) {
        perror("Error opening file for writing");
        return;
    }
	
    for (i = 0; i < maxMenu; i++) {
        fprintf(file, "%d %s | %f %d %c \n", M[i].idMenu, M[i].nama, M[i].harga, M[i].dibeli, M[i].jenis);
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
    	fscanf(file, "%f %d %c \n", &M[i].harga, &M[i].dibeli, &M[i].jenis);
	}
	fclose(file);
}

void menuKasir(menu M[], Multilist *l, int *nomorNota, string filename, string filenameMenu){
	while(1){
	
		int input;
		int currentMenu = 0;
		int jumlahMenu = 8;
		
		while(1){
			system("cls"); // Clear screen
	        showKasirMenu(currentMenu);
	
	        input = _getch(); // Get key press
	        if (input == 0 || input == 224) {
	            // Arrow keys
	            input = _getch();
	            if (input == UP_ARROW) {
	                currentMenu = (currentMenu - 1 + jumlahMenu) % jumlahMenu;
	            } else if (input == DOWN_ARROW) {
	                currentMenu = (currentMenu + 1) % jumlahMenu;
	            }
	        } else if (input == ENTER_KEY) {
	            // Enter key pressed
	            break;
	        }
	    }
	    
		switch(currentMenu){
			
			case 0: 
				inputPesanan(M, &(*l), &(*nomorNota));
			break;
			
			case 1:
				tambahPesanan(M, &(*l));	
			break;
			 
			case 2:
				mergeNota(&(*l));
			break;

			case 3:
				splitBill(&(*l), &(*nomorNota));
			break;

			case 4:
				bayar(M, &(*l), filenameMenu);
			break;
			
			case 5:
				if(isEmpty(*l))
					printf("\n\t\t\t\t\t[!] Belum Ada Pesanan [!]");
				else
					writeToFileMultiList(*l,filename);
			break;
			
			case 6:
				if(!isFileEmpty(filename)){
					deleteAllParent(&(*l));
    				createEmpty(&(*l));
					readFromFileMultiList(&(*l),filename);
				}else{
					printf("\n\t\t\t\t\t[!] Tidak Bisa Memuat Berkas [!]");
				}
			break;
			
			case 7:
				return;
			break;
			
		}
		getch();
	}
}

void showKasirMenu(int currentMenu){
	int i;
	const char *menuItems[] = {
        "Input Pesanan",
        "Tambahan Pesanan",
        "Gabung Nota",
        "Split Bill",
        "Bayar",
        "Save Data",
        "Load Data",
        "Exit"
    };



	
    // Draw top border
    printf("\t\t\t\t\t  %c", 201); // Top-left corner
    for ( i = 0; i < 28; i++) printf("%c", 205); // Horizontal line
    printf("%c\n", 187); // Top-right corner

    // Title row
    printf("\t\t\t\t\t  %c       Menu Kasir           %c\n", 186, 186);

    // Draw title separator
    printf("\t\t\t\t\t  %c", 204); // Left T-junction
    for ( i = 0; i < 28; i++) printf("%c", 205); // Horizontal line
    printf("%c\n", 185); // Right T-junction

    // Menu items
    for ( i = 0; i < 8; i++) {
        if (i == currentMenu) {
            // Highlight the selected item
            printf("\t\t\t\t\t  %c", 186);
            setColor(32);
            printf(" > %-24s ", menuItems[i]);
            resetColor();
            printf("%c\n", 186);
        } else {
            printf("\t\t\t\t\t  %c    %-23s %c\n", 186, menuItems[i], 186);
        }
    }

    // Draw bottom border
    printf("\t\t\t\t\t  %c", 200); // Bottom-left corner
    for ( i = 0; i < 28; i++) printf("%c", 205); // Horizontal line
    printf("%c\n", 188); // Bottom-right corner
}


void bayar(menu M[], Multilist *l, string filename){
	if(!isEmpty(*l)){
		printAll(*l);
		int nomorNota;
		float Dibayar;
		printf("\nMasukkan Nomor Nota : ");
		fflush(stdin); scanf("%d", &nomorNota);
		
		AddressParent temp = findParent(*l, nomorNota);
		if(temp == NULL){
			printf("\n\tNota dengan nomor %d tidak ditemukan", nomorNota);
			return;
		}
		
		while(1){
			printf("\nDibayar : ");
			fflush(stdin); scanf("%f", &Dibayar);
			if(Dibayar >= temp->dataParent.Total){
				printParent(temp);
				printf("Dibayar     : Rp %.2f\n", Dibayar);
				printf("Kembali     : Rp %.2f\n", Dibayar - temp->dataParent.Total);
				break;
			}else if(Dibayar == 0){
				printf("\n\t Cancel");
				return;
			}else{
				printf("\n\t Uang tidak cukup");
			}
		}
		
		while(temp->firstChild != NULL){
			catat(M, temp->firstChild->dataChild);
			deleteFirstChild((*l), nomorNota);
		}
		
		deleteAtParent(&(*l), nomorNota);
		saveToFile(filename, M);
	}else{
		setColor(31);
		printf("\n\t\t\t\t\t[!] Mohon Maaf Belum Ada Pesanan [!]");
		resetColor();
	}
}

void catat(menu M[], DataChild D){
	int i;
	if(strcmp(M[D.idMenu-1].nama, D.nama)==0){
		i = D.idMenu-1;
	}else{
		for(i=0;i<maxMenu;i++){
			if(strcmp(M[i].nama, D.nama)==0){
				break;
			}
		}
	}
	M[i].dibeli += D.jumlah;
}

void insertAllChild(Multilist l, AddressParent temp1, AddressParent temp2){
    AddressChild temp = temp2->firstChild;
    int nota = temp2->dataParent.nomorNota;

    while(temp !=NULL){
        AddressChild tempChild1 = temp1->firstChild;
        bool idSama = 0; 
        
        while(tempChild1 !=NULL){
            if (tempChild1->dataChild.idMenu == temp->dataChild.idMenu){
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

void splitBill(Multilist *l, int *nomorNota){
	if(!isEmpty(*l)){
		int nota, input, banyak;
		bool exit = false;
		(*nomorNota) = (*nomorNota) + 1;
		string tanggalNota, cek;
		makeTanggal(&tanggalNota);
		system("cls");
		printf("\n\t==[ Split Bill ]==");
		printf("\nMasukkan Nomor Nota Yang Ingin Di Split : ");fflush(stdin);scanf("%d", &nota);
		if(findParent(*l, nota)!=NULL){
			AddressParent temp = findParent(*l, nota), notaBaru;
			insertLastParent(&(*l), makeDataParent(*nomorNota, tanggalNota, temp->dataParent.nomorMeja, 0));
			notaBaru = findParent(*l, *nomorNota);
			do{
				system("cls");
				printParent(temp);
				printf("\nMasukkan Nomor Menu Yang Ingin Pindah: ");fflush(stdin);scanf("%d", &input);
				AddressChild tempC = findChild(temp, input);
				if(tempC!=NULL){
		        	printf("\nMasukkan Banyak yang ingin di pindah: ");fflush(stdin);scanf("%d", &banyak);
		        	while(banyak<1 || banyak>tempC->dataChild.jumlah){
		        		if(banyak<1){
		        			printf("\n\t[!] Tidak Boleh Lebih Kecil Dari 1 [!]\n");
						}else{
							printf("\n\t[!] Tidak Boleh Lebih Banyak dari %d [!]\n", tempC->dataChild.jumlah);
						}
		        		printf("\nMasukkan Banyak yang ingin di pindah: ");fflush(stdin);scanf("%d", &banyak);
					}
					
					if(findChild(notaBaru, input)==NULL){
						insertLastChild((*l), notaBaru->dataParent.nomorNota, makeDataChild(tempC->dataChild.idMenu, tempC->dataChild.nama, banyak, tempC->dataChild.harga));
					}else{
						AddressChild tempC2 = findChild(notaBaru, input);
						tempC2->dataChild.jumlah = tempC2->dataChild.jumlah + banyak;
					}
					if(banyak==tempC->dataChild.jumlah){
						deleteAtChild(*l, nota, input);
					}else{
						tempC->dataChild.jumlah = tempC->dataChild.jumlah - banyak;
					}
					if(haveChild(temp)){
						printf("\n\tApakah ada lagi yang ingin di Pindah [N/Y] ");fflush(stdin);gets(cek);
						if(strcmpi(cek,"n")==0 ){
							notaBaru->dataParent.Total = countTotalHarga(notaBaru);
							printParent(notaBaru);
							printParent(temp);
							exit = true;
						}
					}else{
						printf("\n\tSemua Pesanan Telah Dipindahkan");
						notaBaru->dataParent.Total = countTotalHarga(notaBaru);
						deleteAtParent(&(*l), temp->dataParent.nomorNota);
						printParent(notaBaru);
						exit = true;
					}
				}else{
					setColor(31);
					printf("\n\t\t\t\t\t[!] Id tidak ditemukan [!]");
					resetColor();
				}if(exit!=true) getch();
			}while(exit != true);
		}else{
			setColor(31);
			printf("\n\t\t\t\t\t[!] Mohon Maaf Nota Tidak Ditemukan[!]");
			resetColor();
		}
	}else{
		setColor(31);
		printf("\n\t\t\t\t\t[!] Mohon Maaf Belum Ada Pesanan [!]");
		resetColor();
	}
}

void mergeNota(Multilist *l){
	if(!isEmpty(*l)){
		if(!isOneElement(*l)){
			int nota1, nota2;
			printf("\n\t\t\t\t\tMasukkan Nomor Nota 1 Yang Ingin Di Gabung : ");fflush(stdin);scanf("%d", &nota1);
			if(findParent(*l, nota1)!=NULL){
				AddressParent temp1 = findParent(*l, nota1);
				printf("\n\t\t\t\t\tMasukkan Nomor Nota 2 Yang Ingin Di Gabung : ");fflush(stdin);scanf("%d", &nota2);
				if(findParent(*l, nota2)!=NULL){
					AddressParent temp2 = findParent(*l, nota2);
					if(nota1<nota2){
						insertAllChild(*l, temp1, temp2);
						deleteAtParent(&(*l),temp2->dataParent.nomorNota);
					}else{
						insertAllChild(*l, temp2, temp1);
						deleteAtParent(&(*l), temp1->dataParent.nomorNota);
					}
					setColor(32);
					printf("\n\t\t\t\t\t[!] Berhasil Merge Nota [!]");
					resetColor();
				}else{
					setColor(31);
					printf("\n\t\t\t\t\t[!] Mohon Maaf Nota Tidak Ditemukan[!]");
					resetColor();
				}
			}else{
				setColor(31);
				printf("\n\t\t\t\t\t[!] Mohon Maaf Nota Tidak Ditemukan[!]");
				resetColor();
			}
		}else{
			setColor(31);
			printf("\n\t\t\t\t\t[!] Mohon Maaf Hanya Ada 1 Nota [!]");
			resetColor();
		}
	}else{
		setColor(31);
		printf("\n\t\t\t\t\t[!] Mohon Maaf Belum Ada Pesanan [!]");
		resetColor();
	}
}


void tambahPesanan(menu M[], Multilist *l){
	if(!isEmpty(*l)){
		string input, tanggalNota;
		int index, banyak, cariNota;
		bool exit = false;
		printAll(*l);
		printf("\n\t\t\t\t\tMasukkan Nomor Nota Yang Ingin Ditambah : ");fflush(stdin);scanf("%d", &cariNota);
		if(findParent(*l, cariNota)!=NULL){
			AddressParent temp = findParent(*l, cariNota);
			do{
				system("cls");
				menuPrint(M);
				printf("\n\t\t\t\t\tMasukkan Nomor atau Nama Menu Yang Ingin Di Pesan: ");fflush(stdin);gets(input);
				if(sscanf(input, "%d", &index) == 1){
		            index = findIdMenu(M, index);
		        }else{
		            index = findNamaMenu(M, input);
		        }	
		        if(index!=-1){
		        	printf("\n\t\t\t\t\tMasukkan Banyak Pesanan : ");fflush(stdin);scanf("%d", &banyak);
		        	while(banyak<1){
		        		setColor(31);
		        		printf("\n\t\t\t\t\t[!] Tidak Boleh Lebih Kecil Dari 1 [!]\n");
		        		resetColor();
		        		printf("\n\t\t\t\t\tMasukkan Banyak Pesanan : ");fflush(stdin);scanf("%d", &banyak);
					}
					if(findChild(temp, M[index].idMenu)==NULL){
						insertLastChild((*l), temp->dataParent.nomorNota, makeDataChild(M[index].idMenu, M[index].nama, banyak, M[index].harga));
					}else{
						AddressChild tempC = findChild(temp, M[index].idMenu);
						tempC->dataChild.jumlah = tempC->dataChild.jumlah  + banyak;
					}
					printf("\n\t\t\t\t\tApakah ada lagi yang ingin di pesan [N/Y] ");fflush(stdin); gets(input);
					if(strcmpi(input,"n")==0){
						findParent(*l, temp->dataParent.nomorNota)->dataParent.Total = countTotalHarga(findParent(*l, temp->dataParent.nomorNota));
						printParent(findParent(*l, temp->dataParent.nomorNota));
						exit = true;
					}
				}else{
					setColor(31);
					printf("\n\t\t\t\t\t[!] Nama Atau Id tidak ditemukan [!]");
					resetColor();
				}if(exit!=true) getch();
			}while(exit!=true);
		}else{
			setColor(31);
			printf("\n\t\t\t\t\t[!] Mohon Maaf Nota Tidak Ditemukan[!]");
			resetColor();
		}
	}else{
		setColor(31);
		printf("\n\t\t\t\t\t[!] Mohon Maaf Belum Ada Pesanan [!]");
		resetColor();
	}
	
}


void inputPesanan(menu M[], Multilist *l, int *nomorNota){
	if(findMejaKosong(*l)!=-1){
		string input, tanggalNota;
		bool exit=false;
		int index, banyak;
		(*nomorNota) = (*nomorNota) + 1;
		makeTanggal(&tanggalNota);
		insertLastParent(&(*l), makeDataParent(*nomorNota, tanggalNota, findMejaKosong(*l), 0));
		do{
			system("cls");
			menuPrint(M);
			fflush(stdin);
			printf("\n\t\t\t\t\tMasukkan Nomor atau Nama Menu Yang Ingin Di Pesan: ");fflush(stdin); gets(input);
			if(sscanf(input, "%d", &index) == 1){
	            index = findIdMenu(M,index);
	        }else{
	            index = findNamaMenu(M,  input);
	        }	
	        if(index!=-1){
	        	printf("\n\t\t\t\t\tMasukkan Banyak Pesanan : ");fflush(stdin);scanf("%d", &banyak);
	        	while(banyak<1){
	        		printf("\n\t\t\t\t\t[!] Tidak Boleh Lebih Kecil Dari 1 [!]\n");
	        		printf("\nMasukkan Banyak Pesanan : ");fflush(stdin);scanf("%d", &banyak);
				}
				if(findChild(findParent(*l, *nomorNota), M[index].idMenu)==NULL){
					insertLastChild((*l), *nomorNota, makeDataChild(M[index].idMenu, M[index].nama, banyak, M[index].harga));
				}else{
					findChild(findParent(*l, *nomorNota), M[index].idMenu)->dataChild.jumlah += banyak;
				}
				printf("\n\t\t\t\t\tApakah ada lagi yang ingin di pesan [N/Y] ");fflush(stdin); gets(input);
				if(strcmpi(input,"n")==0){
					findParent(*l, *nomorNota)->dataParent.Total = countTotalHarga(findParent(*l, *nomorNota));
					printParent(findParent(*l, *nomorNota));
					exit=true;
				}
			}else{
				setColor(31);
				printf("\n\t\t\t\t\t[!] Nama Atau Id tidak ditemukan [!]");
				resetColor();
			}if(exit!=true) getch();
		}while(exit != true);
	}else{
		setColor(31);
		printf("\n\t\t\t\t\t[!] Mohon Maaf Tidak Ada Meja Yang Tersedia [!]");
		resetColor();
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
int findIdMenu(menu M[], int input) {
	int i;
    for(i = 0; i < maxMenu; i++) {
        if (M[i].idMenu == input) {
            return i;
        }
    }
    return -1;
}

int findNamaMenu(menu M[], string input) {
	int i;
    for( i = 0; i < maxMenu; i++) {
        if (strcmpi(M[i].nama, input) == 0) {
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

void writeToFileMultiList(Multilist list, string filename) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
    	setColor(31);
        perror("\n\t\t\t\t\tError opening file for writing.\n");
        resetColor();
        return;
    }

    AddressParent parent = list.firstParent;
    while (parent != NULL) {
        // nyimpen data parent
        fprintf(file, "%d|%s|%d|%.2f\n",
                parent->dataParent.nomorNota,
                parent->dataParent.tanggalNota,
                parent->dataParent.nomorMeja,
                parent->dataParent.Total);

        // nyimpen data child
        AddressChild child = parent->firstChild;
        while (child != NULL) {
            fprintf(file, "C|%d|%s|%d|%.2f\n",
                    child->dataChild.idMenu,
                    child->dataChild.nama,
                    child->dataChild.jumlah,
                    child->dataChild.harga);
            child = child->next;
        }
        parent = parent->next;
    }

    fclose(file);
    system("cls");
    loadingBar();
    setColor(32);
    printf("\n\t\t\t\t\t[+] Berhasil Menyimpan Data [+]");
    resetColor();
}

void readFromFileMultiList(Multilist* list, const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
    	setColor(31);//merah
        perror("\n\t\t\t\t\tError opening file for reading.\n");
        resetColor();
        return;
    }
    string buffer;
    AddressParent currentParent = NULL;

    while (fgets(buffer, sizeof(buffer), file)) {
        if (buffer[0] != 'C') { // Parent data
            AddressParent newParent = (AddressParent)malloc(sizeof(NodeParent));
            sscanf(buffer, "%d|%[^|]|%d|%f",
                   &newParent->dataParent.nomorNota,
                   newParent->dataParent.tanggalNota,
                   &newParent->dataParent.nomorMeja,
                   &newParent->dataParent.Total);

            newParent->next = NULL;
            newParent->firstChild = NULL;

            if (list->firstParent == NULL) {
                list->firstParent = newParent;
            } else {
                currentParent->next = newParent;
            }
            currentParent = newParent;
        } else { // data child
            AddressChild newChild = (AddressChild)malloc(sizeof(NodeChild));
            sscanf(buffer + 2, "%d|%[^|]|%d|%f",
                   &newChild->dataChild.idMenu,
                   newChild->dataChild.nama,
                   &newChild->dataChild.jumlah,
                   &newChild->dataChild.harga);

            newChild->next = NULL;

            if (currentParent->firstChild == NULL) {
                currentParent->firstChild = newChild;
            } else {
                AddressChild lastChild = currentParent->firstChild;
                while (lastChild->next != NULL) {
                    lastChild = lastChild->next;
                }
                lastChild->next = newChild;
            }
        }
    }

    fclose(file);
    system("cls");
    loadingBar();
    setColor(32);
    printf("\n\t\t\t\t\t[~] Berhasil Memasukan Data [~]");
    resetColor();
}


void setColor(int color) {
    printf("\033[0;%dm", color); // ANSI escape code untuk warna
}

void resetColor() {
    printf("\033[0m"); // Reset ke warna default
}

void loadingBar() {
	int i;
    // Karakter untuk loading bar menggunakan extended ascii
    char a = 177, b = 219;

    // Cetak bar awal
    gotoxy(40, 15);
    
    for (i = 1; i < 30; i++)
        printf("%c", a);

    // Cetak progres dengan perubahan warna
    gotoxy(40, 15);
	for (i = 1; i < 30; i++) {
        // Pilih warna berdasarkan progres
        if (i <= 10)
            setColor(31); // Merah
        else if (i <= 20)
            setColor(33); // Kuning
        else
            setColor(32); // Hijau
		
        printf("%c", b);
        Sleep(25); 
    }

    resetColor();
    printf("\n");
}

void loginScenario(){
	
	int i;
	char topLeft = 201, topRight = 187, bottomLeft = 200, bottomRight = 188;
    char horizontal = 205, vertical = 186;
    char threeWayToTheRight = 204, threeWayToTheLeft = 185, threeWayUp = 202, threeWayDown = 203;
	char fourway = 206;
	
	system("cls");
	printf("\n");
    printf("\t%c", topLeft);  // Corner kiri atas
    for ( i = 0; i < 100; i++) {
        printf("%c", horizontal);  // Baris horizontal atas
    }
    printf("%c\n", topRight);  // Corner kanan atas

    setColor(32);
    printf("\t\t$$\\                       $$$$$$\\                                     $$\\            \n");
    printf("\t\t$$ |                     $$  __$$\\                                    $$ |           \n");

    // Warna Putih (tengah)
    setColor(37);
    printf("\t\t$$ |      $$$$$$\\        $$ /  \\__| $$$$$$\\  $$$$$$\\  $$$$$$$\\   $$$$$$$ | $$$$$$\\   \n");
    printf("\t\t$$ |      \\____$$\\       $$ |$$$$\\ $$  __$$\\ \\____$$\\ $$  __$$\\ $$  __$$ |$$  __$$\\  \n");
    printf("\t\t$$ |      $$$$$$$ |      $$ |\\_$$ |$$ |  \\__|$$$$$$$ |$$ |  $$ |$$ /  $$ |$$$$$$$$ | \n");

    // Warna Merah (sebelah kanan)
    setColor(31);
    printf("\t\t$$ |     $$  __$$ |      $$ |  $$ |$$ |     $$  __$$ |$$ |  $$ |$$ |  $$ |$$   ____| \n");
    printf("\t\t$$$$$$$$\\\\$$$$$$$ |      \\$$$$$$  |$$ |     \\$$$$$$$ |$$ |  $$ |\\$$$$$$$ |\\$$$$$$$\\  \n");

    // Warna Putih (sebelah kanan, bagian bawah)
    setColor(37);
    printf("\t\t\\________|\\_______|       \\______/ \\__|      \\_______|\\__|  \\__| \\_______| \\_______| \n");

    // Menampilkan border bawah
    setColor(37);  // Mengatur warna putih
    printf("\t%c", bottomLeft);  // Corner kiri bawah
    for ( i = 0; i < 100; i++) {
        printf("%c", horizontal);  // Baris horizontal bawah
    }
    printf("%c\n", bottomRight);  // Corner kanan bawah

    resetColor();
	printf("\n\e[42G   | >>> Loading <<< |");    
	loadingBar();
	
	
//cek level
//	printf("\n\t1");
//    printf("\n\t\t2");
//    printf("\n\t\t\t3");
//    printf("\n\t\t\t\t4");
//    printf("\n\t\t\t\t\t5");
//    printf("\n\t\t\t\t\t\t6");
}
	
void gotoxy(int x, int y){
	printf("\e[%d;%dH", y, x);
}

int isFileEmpty(string filename) {
    FILE *file = fopen(filename, "r"); // Buka file dalam mode read
    if (file == NULL) {
        // Jika file tidak dapat dibuka, mungkin file tidak ada
        return -1; // Indikasi file tidak ditemukan
    }

    fseek(file, 0, SEEK_END); // Pindahkan pointer ke akhir file
    long size = ftell(file); // Dapatkan posisi pointer (ukuran file)
    //long dapat menampung lebih besar dari int
    fclose(file); // Tutup file

    return size == 0; // Jika ukuran 0, file kosong
}
