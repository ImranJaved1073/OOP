#include "ApplePhone.h"
#include <iostream>
#include<string>
using namespace std;


ApplePhone::ApplePhone()
{
	cout << "\"Hello, Apple!\"" << endl;
}
ApplePhone::ApplePhone(int id, string date, string name, string version) :MobilePhone(id, date, name)
{
	iOSVersion = version;
}
void ApplePhone::setiOSVersion(string version)
{
	iOSVersion = version;
}
void ApplePhone::launchSiri()
{
	cout << "\"Talking to Siri\"" << endl;
}
void ApplePhone::launchPaper()
{
	cout << "\"Using Paper App\"" << endl;
}
string ApplePhone::getiOSVersion() const
{
	return iOSVersion;
}
void  ApplePhone::setApplePhone(int id, string date, string name)
{
	setMfgID(id);
	setMfgDate(date);
	setMfgName(name);
}
int ApplePhone::getMfgID() const
{
	return getMfgID();
}
string ApplePhone::getMfgDate() const
{
	return  getMfgDate();
}
string ApplePhone::getMfgName() const
{
	return  getMfgName();
}

ApplePhone::~ApplePhone()
{
	cout << "\"Apple Phone destroyed\"" << endl;
}