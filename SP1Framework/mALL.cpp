#include <Windows.h>
#include "mALL.h"
#include <iostream>

using namespace std;

vector<mLoad> loadFiles;

void MusicInit()
{
	mLoad load;
	MusicLoad("BGM1(Game-Intro).mp3", "mpegvideo", "tacos", "100", &load);
	MusicLoad("BGM2(Maze-Level1-special).mp3", "mpegvideo", "mazelevel1", "100", &load);
	MusicLoad("BGM3(Maze-level2-special).mp3", "mpegvideo", "mazelevel3", "100", &load);
	MusicLoad("BGM4.1(Maze-Level3-special).mp3", "mpegvideo", "die", "100", &load);
	loadFiles.push_back(load);
}
bool MusicLoad(string file, string type, string alias, string initalvolume, mLoad* Returnfile)
{
	MCIERROR me;
	string buff;
	buff = "open \"" + file + "\" type " + type + " alias " + alias;
	me = mciSendString(buff.c_str(), NULL, 0, NULL);
	if (me == 0)
	{
		(*Returnfile).status = 0;
		(*Returnfile).file = file;
		(*Returnfile).type = type;
		(*Returnfile).alias = alias;
		buff = "setaudio " + alias + " volume to " + initalvolume;
		me = mciSendString(buff.c_str(), NULL, 0, NULL);
		return true;
	}
	else
	{
		(*Returnfile).status = me;
		return false;
	}

}
bool MusicPlay(string alias, string arguments)
{
	MCIERROR ME;
	string constructstring = "play ";
	constructstring += alias;
	constructstring += " " + arguments;
	ME = mciSendString(constructstring.c_str(), NULL, 0, NULL);
	if (ME != 0)
		return false;
	else
		return true;
}
bool MusicStop(string alias)
{
	MCIERROR ME;
	string constructstring = "stop ";
	constructstring += alias;
	ME = mciSendString(constructstring.c_str(), NULL, 0, NULL);
	if (ME != 0)
		return false;
	else
		return true;
}