#include "header.h"

void createEmpty(Multilist *L){
	(&(*L))->firstParent = NULL;
}

bool isEmpty(Multilist L){
	return L.firstParent == NULL;
}

bool isOneElement(Multilist L){
	return L.firstParent->next == NULL;
}

bool haveChild(AddressParent ap){
	return ap->firstChild != NULL;
}

AddressParent alokasiParent(DataParent data){
	AddressParent ap;
	
	ap = (AddressParent) malloc(sizeof(NodeParent));
	
	ap->next = NULL;
	ap->firstChild = NULL;
	ap->dataParent = data;
	
	return ap;
}

AddressParent findParent(Multilist L, int cariNota){
	AddressParent temp = NULL;
	
	temp = L.firstParent;
	
	while(temp!=NULL){
		if(temp->dataParent.nomorNota == cariNota){
			return temp;
		}
		temp = temp->next;
	}
	return NULL;
}

void insertFirstParent(Multilist *L, DataParent data){
	AddressParent temp = alokasiParent(data);
	
	temp->next = L->firstParent;
	L->firstParent = temp;
}

void insertAfterParent(Multilist *L, int idParent, DataParent data){
	AddressParent dataBaru = alokasiParent(data);
	
	if(!isEmpty(*L)){
		AddressParent temp = findParent(*L, idParent);
		
		if(temp!=NULL){
			dataBaru->next = temp->next;
			temp->next = dataBaru;
		}
	}
}

void insertLastParent(Multilist *L, DataParent data){
	AddressParent dataBaru = alokasiParent(data);
	
	if(isEmpty(*L)){
		insertFirstParent(L, data);
	}else{
		AddressParent temp = L->firstParent;
		
		while(temp->next != NULL){
			temp = temp->next;
		}
		temp->next = dataBaru;
	}
}

void deleteFirstParent(Multilist *L){
	AddressParent temp = L->firstParent;
	
	if(!isEmpty(*L)){
		deleteAllChild(temp);
		
		L->firstParent = L->firstParent->next;
		free(temp);
	}
}

void deleteAtParent(Multilist *L, int nomorNota){
	AddressParent temp = L->firstParent;
	AddressParent hapus;
	
	if(!isEmpty(*L)){
		if(temp->dataParent.nomorNota == nomorNota){
			deleteFirstParent(&(*L));
		}else{
			while(temp->next != NULL){
				if(temp->next->dataParent.nomorNota == nomorNota){
					hapus = temp->next;
					temp->next = temp->next->next;
					
					deleteAllChild(hapus);
					free(hapus);
					hapus = NULL;
					break;
				}
				temp = temp->next;
			}
		}
	}
}

void deleteLastParent(Multilist *L){
	AddressParent temp = L->firstParent;
	
	if(!isEmpty(*L)){
		if(temp->next == NULL){
			deleteFirstParent(L);
		}else{
			while(temp->next->next != NULL){
				temp = temp->next;
			}
			
			deleteAllChild(temp->next);
			free(temp->next);
			
			temp->next = NULL;
		}
	}
}

void deleteAllParent(Multilist *L) {
    AddressParent temp;

    while (L->firstParent != NULL) {
        temp = L->firstParent;    
        deleteAllChild(temp); 
        deleteFirstParent(L); 
    }
}

void deleteAllChild(AddressParent parent){
	AddressChild temp;
	
	while(haveChild(parent)){
		temp = parent->firstChild;
		parent->firstChild = parent->firstChild->next;
		
		free(temp);
	}
}

void printParent(AddressParent parent){
	int i;
	char topLeft = 201, topRight = 187, bottomLeft = 200, bottomRight = 188;
    char horizontal = 205, vertical = 186;
    char threeWayToTheRight = 204, threeWayToTheLeft = 185, threeWayUp = 202, threeWayDown = 203;
	char fourway = 206;
	parent->dataParent.Total = countTotalHarga(parent);
	
    printf("\n");
    printf("%c", topLeft);
    for(i=0; i<70; i++){
    	printf("%c", horizontal);
	}
	
	printf("%c\n", topRight);
    printf("%c\e[30GNOTA PEMBELIAN \e[72G%c\n", vertical, vertical, vertical);
    
    printf("%c", threeWayToTheRight);
    for(i=0; i<70; i++){
    	printf("%c", horizontal);
	}
    printf("%c\n", threeWayToTheLeft);

    printf("%c Nomor Nota  : %d \e[72G%c \n", vertical, parent->dataParent.nomorNota);
    printf("%c Tanggal     : %s \e[72G%c \n", vertical, parent->dataParent.tanggalNota);
    printf("%c Nomor Meja  : %d \e[72G%c \n", vertical, parent->dataParent.nomorMeja);
    
    printf("%c", threeWayToTheRight);
    for(i=0; i<65; i++){
    	if(i == 4 || i == 21 ||  i == 40 || i == 48 ){
    		printf("%c", threeWayDown);
		}
    	printf("%c", horizontal);
	}
	printf("%c\n", threeWayToTheLeft);
	
    printf("%c No %c Nama Menu       %c Harga Satuan (Rp) %c Jumlah %c Subtotal (Rp) \e[72G%c\n", vertical, vertical, vertical, vertical, vertical, vertical);    
    printf("%c", threeWayToTheRight);
    for(i=0; i<70; i++){
    	printf("%c", horizontal);
	}
	printf("%c\n", threeWayToTheLeft);
	
	
    printAllChild(parent);
    for(i=0; i<70; i++){
    	printf("%c", horizontal);
	}
    printf("%c \e[36GTotal Harga : Rp %.2f\n", vertical,  parent->dataParent.Total);
    printf("%c", threeWayToTheRight);
    for(i=0; i<70; i++){
    	printf("%c", horizontal);
	}
	printf("%c\n", threeWayToTheLeft);
    
    printf("==============================\n");
    
	printf("\n\t1");
    printf("\n\t\t2");
    printf("\n\t\t\t3");
    printf("\n\t\t\t\t4");
    printf("\n\t\t\t\t\t5");
    printf("\n\t\t\t\t\t\t6");
}

void printAllParent(Multilist L){
	AddressParent temp = L.firstParent;
	
	while(temp != NULL){
		printParent(temp);
		
		printf("\n");
		temp = temp->next;
	}
}

void printAll(Multilist L){
	AddressParent temp = L.firstParent;
	
	while(temp != NULL){
		printParent(temp);
		
		printf("\n");
		
		temp = temp->next;
	}
}

