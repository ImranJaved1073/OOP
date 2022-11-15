#ifndef ANDROIDPHONE_H
#define ANDROIDPHONE_H
#include<string>
#include "MobilePhone.h"
using namespace std;
class AndroidPhone :protected MobilePhone
{
private:
	string kernalVersion;
	string androidVersion;
public:
	AndroidPhone();
	AndroidPhone(int, string, string, string, string);
	void  setAndroidPhone(int, string, string);
	void launchSubwaySurfers();
	void launchFlynx();
	string getKernalVersion();
	void setKernalVersion(string);
	string getiOSVersion();
	void setiOSVersion(string);
	~AndroidPhone();

	int getMfgID() const;
	string getMfgName() const;
	string getMfgDate() const;

	bool turnOn();
	bool turnOff();
	void makeVoiceCall(int);
	void recordAudio();
	void sendSMS(string, int);

};




#endif // !NOVEL_H
