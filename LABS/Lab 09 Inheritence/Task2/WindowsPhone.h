
#ifndef WINDOWSPHONE_H
#define WINDOWSPHONE_H
#include<string>
#include "MobilePhone.h"
using namespace std;
class WindowsPhone :private MobilePhone
{
private:
	string buildNumber;
	string productName;
public:
	WindowsPhone();
	WindowsPhone(int, string, string, string, string);
	void  setWindowsPhone(int, string, string);
	void launchFoundBite();
	void launchXboxGame();
	string getProductName() const;
	void setProductVersion(string);
	string getBuildNumber() const;

	void setBuildNumber(string);
	int getMfgID() const;
	string getMfgName() const;
	string getMfgDate() const;

	bool turnOn();
	bool turnOff();
	void makeVoiceCall(int);
	void recordAudio();
	void sendSMS(string, int);

	~WindowsPhone();

};



#endif // !NOVEL_H




