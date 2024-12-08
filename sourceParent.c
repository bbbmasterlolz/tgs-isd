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
	parent->dataParent.Total = countTotalHarga(parent);
	
    printf("\n==============================\n");
    printf("          NOTA PEMBELIAN\n");
    printf("==============================\n");
    printf("Nomor Nota  : %d\n", parent->dataParent.nomorNota);
    printf("Tanggal     : %s\n", parent->dataParent.tanggalNota);
    printf("Nomor Meja  : %d\n", parent->dataParent.nomorMeja);
    printf("------------------------------\n");
    printf("| No | Nama Menu       | Harga Satuan (Rp) | Jumlah | Subtotal (Rp) |\n");
    printf("---------------------------------------------------------------\n");
    printAllChild(parent);
    printf("---------------------------------------------------------------\n");
    printf("Total Harga : Rp %.2f\n", parent->dataParent.Total);
    printf("==============================\n");
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


