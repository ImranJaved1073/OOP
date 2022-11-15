#include "MobilePhone.h"
#include <iostream>
#include<string>
using namespace std;


MobilePhone::MobilePhone()
{
	cout << "\"Phone is manufatured by the factory..\"" << endl;
	mfgID = 0;
	mfgDate = "";
	mfgName = "";
	state = false;
}

MobilePhone::MobilePhone(int id, string md, string mn)
{
	cout << "\"Phone is manufatured by the factory..\"" << endl;
	mfgID = id;
	mfgDate = md;
	mfgName = mn;
	state = false;
}

void MobilePhone::setMfgID(int id)
{
	mfgID = id;
}
void MobilePhone::setMfgDate(string md)
{
	mfgDate = md;
}
void MobilePhone::setMfgName(string mn)
{
	mfgName = mn;
}

void MobilePhone::setState(bool stat)
{
	state = stat;
}

bool MobilePhone::getState()
{
	return state;
}

int MobilePhone::getMfgID() const
{
	return mfgID;
}
string MobilePhone::getMfgDate()const
{
	return mfgDate;
}
string MobilePhone::getMfgName()const
{
	return mfgName;
}

bool MobilePhone::turnOn()
{
	state = true;
	cout << "\"Phone is turned on.\"\n";
	return state;
}

void MobilePhone::makeVoiceCall(int number)
{
	if (state == true)
	{
		cout << "Calling to " << number << endl;
	}
	else
	{
		cout << "\"Phone is turned off so cannot make call...\"" << endl;
	}
}

void MobilePhone::recordAudio()
{
	if (state == true)
	{
		cout << "\"Start Speaking into the Microphone to record audio...\"\n ";
	}
	else
	{
		cout << "\"Phone is turned off so cannot record audio...\"" << endl;
	}
}
void MobilePhone::sendSMS(string name, int n)
{
	if (state == true)
	{
		cout << "Message: \"" << name << "\" has been sent to " << n << endl;
	}
	else
	{
		cout << "\"Phone is off so cannot send messages...\"" << endl;
	}

}

bool MobilePhone::turnOff()
{
	cout << "\"Phone is turned off.\"\n";
	state = false;
	return state;
}

MobilePhone::~MobilePhone()
{
	cout << "\"Phone Destroyed.\"\n";
}