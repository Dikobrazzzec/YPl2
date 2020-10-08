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
	CryptCreateHash(a,CALG_MD5,0,0, &hashdeskr);
	CryptHashData(hashdeskr, value, QuanBytes, NULL);
	return 0;
}