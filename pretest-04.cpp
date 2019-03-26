#include <iostream>
using namespace std;

struct Elemtlist{
    char npm[14];
    char nama[20];
    float ipk;
    Elemtlist* next;
};

typedef Elemtlist* pointer;
typedef pointer List;

void createList(List& first){
    first=NULL;
}

void createElement(pointer& pBaru){
    pBaru = new Elemtlist;
    cout<<"Masukan Data:\n";
    cout<<"NPM  : ";cin>>pBaru->npm;
    cout<<"Nama : ";cin>>pBaru->nama;
    cout<<"IPK  : ";cin>>pBaru->ipk;
    cout<<endl;
}

void insertSortNPM(List& first, pointer pBaru){
    if (first==NULL){
        first=pBaru;
    }
    else {
        pBaru->next=first;
        first=pBaru;
    }
}

void traversal(List first){
    pointer pBantu;
    cout<<"\t\t\tData Mahasiswa\n";
    if (first==NULL){
        cout<<"\t\t\t***LIST KOSONG***\n";
    }
    else {
        pBantu=first;
        int i=1;
        cout<<"No  NPM\tNama\t\tIPK\n";
        while(pBantu!=NULL){
            cout<<i<<"   "<<pBantu->npm<<"\t"<<pBantu->nama<<"\t\t"<<pBantu->ipk<<endl;
            pBantu=pBantu->next;
            i++;
        }
    }
    cout<<endl;
}

int main()
{
    List mhs;
    pointer p;
    int pil;
    createList(mhs);
    do{
        traversal(mhs);
        cout<<endl;
        cout<<"1. Tambah Data\n";
        cout<<"2. Keluar\n\n";
        cout<<"Pilih : ";cin>>pil;
        if (pil==1){
            createElement(p);
            insertSortNPM(mhs,p);
        }
    }while(pil==1);
    return 0;
}
