#pragma once
#include <vector>
#include <string>
using namespace std;
void MusicInit();
bool MusicPlay(string alias, string arguments);
bool MusicStop(string alias);
struct mLoad
{
	string file = "";
	string type = "";
	string alias = "";
	int status;
};
bool MusicLoad(string file, string type, string alias, string initalvolume, mLoad* Returnfile);


