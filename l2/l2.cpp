#include <iostream>
#include <Windows.h>
#include <wincrypt.h>

using namespace std;

struct RetObj{
	HCRYPTPROV RetDeskr;
	BYTE* retptr;
};

RetObj ByteGener() {
	BYTE value[100];
	HCRYPTPROV Deskrip;
	int QuanBytes;
	cout << " Enter quantity  of bytes" << endl;
	cin >> QuanBytes;
	cout << endl;
	CryptAcquireContext(&Deskrip, NULL, NULL, PROV_RSA_FULL, CRYPT_VERIFYCONTEXT);
	CryptGenRandom(Deskrip, QuanBytes, value);
	for (int i = 0; i < QuanBytes; i++) {
		cout << i << '.' << value[i] << endl;
	}
	cout << endl;
	RetObj returnable;
	returnable.RetDeskr = Deskrip;
	returnable.retptr = value;
	return returnable;
}

void Hash(BYTE* DataPackParam, HCRYPTPROV Deskrip) {
	HCRYPTHASH q; 
	//HCRYPTPROV Deskrip = 0;
	HCRYPTHASH hashptr;
	CryptCreateHash(Deskrip,CALG_MD5, 0, 0,&hashptr);
	CryptHashData(hashptr,DataPackParam,45,0);
}

void starter() {
	RetObj A = ByteGener();
	Hash(A.retptr, A.RetDeskr);
}

int main()
{
	starter();
	  //сделать так на один вызов два возвращаемых значения. десркиптор и адрес нулевого элемента маассива.
						//постараться сделать так, что бы напрямую дескриптор не появлялся в main
					//сделать передачу в Hash из main либо по ссылке либо через указатель
										//узнать какой объем памяти занимает дескриптор криптопровайдера
	return 0;
}