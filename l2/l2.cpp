#include <iostream>
#include <Windows.h>
#include <wincrypt.h>

using namespace std;


int main()
{
	BYTE value[100];
	int QuanBytes;
	cout << " Enter quantity  of bytes" << endl;
	cin >> QuanBytes;
	//DWORD T = 100;
	//cout <<T<< endl;
	HCRYPTPROV a;
	CryptAcquireContext(&a, NULL, NULL, PROV_RSA_FULL, CRYPT_VERIFYCONTEXT);
	CryptGenRandom(a, QuanBytes, value);
	for (int i = 0; i < 100; i++) {
		cout << i << ". " << value[i] << endl;
	}
	HCRYPTPROV b;
	//CryptAcquireContext(&b, NULL, NULL, PROV_RSA_FULL, CRYPT_VERIFYCONTEXT);    //насколько безлопасно использовать один дескриптор на 2 функции?
	HCRYPTHASH hashdeskr;													
	HCRYPTHASH duplhashptr1;
	HCRYPTHASH duplhashptr2;
	HCRYPTHASH duplhashptr3;
	DWORD bytevalue;
	BYTE duplhasharray1[100];
	BYTE duplhasharray2[100];
	BYTE duplhasharray3[100];
	CryptCreateHash(a,CALG_MD5,0,0, &hashdeskr);
	CryptHashData(hashdeskr, value, QuanBytes, NULL);
	CryptDuplicateHash(hashdeskr, NULL, NULL, &duplhashptr1);
	CryptDuplicateHash(hashdeskr, NULL, NULL, &duplhashptr2);
	CryptDuplicateHash(hashdeskr, NULL, NULL, &duplhashptr3);
	CryptGetHashParam(hashdeskr, HP_ALGID, duplhasharray1, &bytevalue,NULL);
	cout << duplhasharray1 << "          "<< bytevalue << endl;
	CryptGetHashParam(duplhashptr1,HP_HASHSIZE , duplhasharray2, &bytevalue, NULL);
	cout << duplhasharray2 << "          " << bytevalue << endl;
	CryptGetHashParam(duplhashptr2,HP_HASHVAL , duplhasharray3, &bytevalue, NULL);
	cout << duplhasharray3 << "          " << bytevalue << endl;
	CryptDestroyHash(duplhashptr3);
	return 0;
}