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
	cout << endl;
	HCRYPTPROV a;
	CryptAcquireContext(&a, NULL, NULL, PROV_RSA_FULL, CRYPT_VERIFYCONTEXT);
	CryptGenRandom(a, QuanBytes, value);
	HCRYPTPROV b;
	//CryptAcquireContext(&b, NULL, NULL, PROV_RSA_FULL, CRYPT_VERIFYCONTEXT);
	HCRYPTHASH hashdeskr;													//насколько безлопасно использовать один дескриптор на 2 функции?
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
	cout << duplhasharray1 << endl;
	CryptGetHashParam(duplhashptr1,HP_HASHSIZE , duplhasharray2, &bytevalue, NULL);
	cout << duplhasharray2 << endl;
	CryptGetHashParam(duplhashptr1,HP_HASHVAL , duplhasharray3, &bytevalue, NULL);
	cout << duplhasharray3 << endl;
	return 0;
}