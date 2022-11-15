#include "WindowsPhone.h"
#include "MobilePhone.h"
#include <iostream>
#include<string>
using namespace std;



WindowsPhone::WindowsPhone()
{
	cout << "\"Hello, Windows!\"\n";
}
void WindowsPhone::launchFoundBite()
{
	if (getState() == true)
	{
		cout << "\"Checking Foundbite newsfeed\"\n";
	}
	else
	{
		cout << "\"Phone is off so cannot launch Foundbite...\"" << endl;
	}
}
void WindowsPhone::launchXboxGame()
{
	if (getState() == true)
	{
		cout << "\"Playing Xbox Game.\"\n";
	}
	else
	{
		cout << "\"Phone is off so cannot launch Xbox Game...\"" << endl;
	}
}

void WindowsPhone::setProductVersion(string n)
{
	productName = n;
}

void WindowsPhone::setBuildNumber(string b)
{
	buildNumber = b;
}

string WindowsPhone::getProductName() const
{
	return productName;
}

string WindowsPhone::getBuildNumber() const
{
	return buildNumber;
}

WindowsPhone::~WindowsPhone()
{
	cout << "\"Windows Phone Destroyed.\"\n";
}



WindowsPhone::WindowsPhone(int id, string date, string name, string product, string build) :MobilePhone(id, date, name)
{
	productName = product;
	buildNumber = build;
}

void  WindowsPhone::setWindowsPhone(int id, string date, string name)
{
	setMfgID(id);
	setMfgDate(date);
	setMfgName(name);
}
int WindowsPhone::getMfgID() const
{
	return getMfgID();
}
string WindowsPhone::getMfgDate() const
{
	return  getMfgDate();
}
string WindowsPhone::getMfgName() const
{
	return  getMfgName();
}

bool WindowsPhone::turnOn()
{
	cout << "\"Phone is turned on...\"" << endl;
	setState(true);
	return getState();
}
bool WindowsPhone::turnOff()
{
	setState(false);
	cout << "\"Phone is turned off...\"" << endl;
	return getState();
}

void WindowsPhone::makeVoiceCall(int number)
{
	if (getState() == true)
	{
		cout << "Calling to " << number << endl;
	}
	else
	{
		cout << "\"Phone is turned off so cannot make call...\"" << endl;
	}
}
void WindowsPhone::recordAudio()
{
	if (getState() == true)
	{
		cout << "\"Start Speaking into the Microphone to record audio...\"\n ";
	}
	else
	{
		cout << "\"Phone is turned off so cannot record audio...\"" << endl;
	}
}
void WindowsPhone::sendSMS(string msg, int num)
{
	if (getState() == true)
	{
		cout << "Message: \"" << msg << "\" has been sent to " << num << endl;
	}
	else
	{
		cout << "\"Phone is off so cannot send messages..\"" << endl;
	}

}
