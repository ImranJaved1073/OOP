#include "AndroidPhone.h"
#include <iostream>
#include<string>
using namespace std;


AndroidPhone::AndroidPhone()
{
	cout << "\"Hello, Android!\"\n";
}

AndroidPhone::AndroidPhone(int id, string date, string name, string version, string kernal) :MobilePhone(id, date, name)
{
	androidVersion = version;
	kernalVersion = kernal;
}

void AndroidPhone::launchSubwaySurfers()
{
	if (getState() == true)
	{
		cout << "\"Playing Subway Surfers.\"\n";
	}
	else
	{
		cout << "\"Phone is turned off so you cannot play Subway Surfers\"\n";
	}
}
void AndroidPhone::launchFlynx()
{
	if (MobilePhone::getState() == true)
	{
		cout << "\"Using Flynx Browser.\"\n";
	}
	else
	{
		cout << "\"Phone is turned off so you cannot use Flynx Browser.\"\n";
	}
}
string AndroidPhone::getKernalVersion()
{
	return kernalVersion;
}
void AndroidPhone::setKernalVersion(string v)
{
	kernalVersion = v;
}
string AndroidPhone::getiOSVersion()
{
	return androidVersion;
}
void AndroidPhone::setiOSVersion(string version)
{
	androidVersion = version;
}
AndroidPhone::~AndroidPhone()
{
	cout << "\"Android Phone Destroyed.\"\n";
}


int AndroidPhone::getMfgID() const
{
	return getMfgID();
}
string AndroidPhone::getMfgDate() const
{
	return  getMfgDate();
}
string AndroidPhone::getMfgName() const
{
	return  getMfgName();
}

void  AndroidPhone::setAndroidPhone(int id, string date, string name)
{
	setMfgID(id);
	setMfgDate(date);
	setMfgName(name);
}

bool AndroidPhone::turnOn()
{
	cout << "\"Phone is turned on...\"" << endl;
	setState(true);
	return getState();
}
bool AndroidPhone::turnOff()
{
	cout << "\"Phone is turned off...\"\n";
	setState(false);
	return getState();
}

void AndroidPhone::makeVoiceCall(int number)
{
	if (getState() == true)
	{
		cout << "\"Calling to " << number << "\"\n";
	}
	else
	{
		cout << "\"Phone is turned off so cannot make call...\"\n";
	}
}
void AndroidPhone::recordAudio()
{
	if (getState() == true)
	{
		cout << "\"Start Speaking into the Microphone to record audio...\"\n ";
	}
	else
	{
		cout << "\"Phone is turned off so cannot record audio...\"\n";
	}
}
void AndroidPhone::sendSMS(string msg, int num)
{
	if (getState() == true)
	{
		cout << "Message: \"" << msg << "\" has been sent to " << num << endl;
	}
	else
	{
		cout << "\"Phone is off so cannot send messages\"" << endl;
	}

}

