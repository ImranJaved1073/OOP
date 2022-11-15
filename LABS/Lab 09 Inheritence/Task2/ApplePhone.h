
#ifndef APPLEPHONE_H
#define APPLEPHONE_H
#include<string>
#include "MobilePhone.h"
using namespace std;
class ApplePhone :public MobilePhone
{
private:
	string iOSVersion;
public:
	ApplePhone();
	ApplePhone(int, string, string, string);
	void  setApplePhone(int, string, string);
	void launchSiri();
	void launchPaper();
	void setiOSVersion(string);
	string getiOSVersion() const;
	int getMfgID() const;
	string getMfgName() const;
	string getMfgDate() const;
	~ApplePhone();

};




#endif // !NOVEL_H




