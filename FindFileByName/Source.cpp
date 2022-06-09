#define _CAT_SECURE_NO_WARNINGS
#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#include<iostream>
#include<string>
#include<fstream>
#include<direct.h>
#include<experimental/filesystem>
#include<io.h>
using namespace std;
int main() {
	setlocale(0, "");
	string filename;
	cout << "Enter file name" << endl;
	getline(cin, filename);
	_finddata_t data;
	const char* way = "C://*";
	intptr_t handle = _findfirst(way, &data);
	string ways = "C:/";
	while (_findnext(handle, &data) == 0) {
		cout << _findnext(handle, &data) << "   ";
		cout << experimental::filesystem::path(ways+data.name) << endl;
		if (_findnext(handle, &data) != 0) {
			intptr_t hand =_findfirst(way, &data);
			ways += data.name;
			ways.c_str();
			cout << ways.c_str() << endl;
			handle = _findfirst(ways.c_str(), &data);
			cout << experimental::filesystem::path(data.name).extension() << endl;
		}
	}
	
	system("pause");
 }

