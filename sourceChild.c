#include "header.h"

//DataChild makeDataChild(string namaPasien, int sisaHari){
//	DataChild data;
//	
//	data.sisaHari = sisaHari;
//	strcpy(data.namaPasien, namaPasien);
//	
//	return data;
//}

AddressChild alokasiChild(DataChild data){
	AddressChild ac;
	ac = (AddressChild)malloc(sizeof(NodeChild));
	
	ac->next = NULL;
	ac->dataChild = data;
	
	return ac;
}

AddressChild findChild(AddressParent parent, int idMenu){
	AddressChild temp = parent->firstChild;
	
	while(temp != NULL){
		if(temp->dataChild.idMenu == idMenu){
			return temp;
		}
		temp = temp->next;
	}
    
    return NULL;
}

void insertFirstChild(Multilist L, int idParent, DataChild data){
	AddressParent parent = findParent(L, idParent);
	
	if(parent != NULL){
		AddressChild dataBaru = alokasiChild(data);
		dataBaru->next = parent->firstChild;
		
		parent->firstChild = dataBaru;
	}
}

void insertLastChild(Multilist L, int idParent, DataChild data){
	AddressParent parent = findParent(L, idParent);
	
	if(parent != NULL){
		if(!haveChild(parent)){
			insertFirstChild(L, idParent, data);
		}else{
			AddressChild temp = parent->firstChild;
			AddressChild dataBaru = alokasiChild(data);
			
			while(temp->next != NULL){
				temp = temp->next;
			}
			temp->next = dataBaru;
		}
	}
}

void deleteFirstChild(Multilist L, int idParent){
	AddressParent parent = findParent(L, idParent);
	
	if(parent != NULL){
		if(haveChild(parent)){
			AddressChild(temp) = parent->firstChild;
			parent->firstChild = parent->firstChild->next;
			free(temp);
		}
	}
}

void deleteLastChild(Multilist L, int idParent){
	AddressParent parent = findParent(L, idParent);
	
	if(parent != NULL){
		if(haveChild(parent)){
			if(parent->firstChild->next == NULL){
				deleteFirstChild(L, idParent);
			}else{
				AddressChild temp = parent->firstChild;
				
				while(temp->next->next != NULL){
					temp = temp->next;
				}
				free(temp->next);
				temp->next = NULL;
			}
		}
	}
}

void deleteAtChild(Multilist L, int idParent, int idMenu){
	AddressParent parent = findParent(L, idParent);
	AddressChild hapus, temp = parent->firstChild;
	
	if(parent != NULL){
		if(haveChild(parent)){
			if(temp->dataChild.idMenu == idMenu){
				deleteFirstChild(L, idParent);
			}else{
				while(temp->next != NULL){
					if(temp->next->dataChild.idMenu == idMenu){
						hapus = temp->next;
						temp->next = temp->next->next;
						
						free(hapus);
						hapus = NULL;
						break;
					}
					temp = temp->next;
				}
			}
		}
	}
}

void printChild(AddressChild child){
	
	char vertical = 186; 
	printf("%c %-2d %c %-15s %c %-17.2f %c %-6d %c %-13.2f \e[72G%c\n", vertical, child->dataChild.idMenu, vertical,  child->dataChild.nama, vertical, child->dataChild.harga, vertical, child->dataChild.jumlah, vertical, child->dataChild.harga*child->dataChild.jumlah, vertical);
}

void printAllChild(AddressParent parent){
	AddressChild temp = parent->firstChild;
	
	while(temp != NULL){
		printChild(temp);
		temp = temp->next;
	}
}
