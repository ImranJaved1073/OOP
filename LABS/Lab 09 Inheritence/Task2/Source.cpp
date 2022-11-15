#include "WindowsPhone.h"
#include "MobilePhone.h"
#include "AndroidPhone.h"
#include "ApplePhone.h"
#include <iostream>
#include<string>
using namespace std;

int main()
{
	{
		ApplePhone iphone;
		iphone.setMfgID(1);
		iphone.setMfgDate("11/3/2022");
		iphone.setMfgName("Apple");
		iphone.setiOSVersion("iOS 14");
		iphone.turnOn();
		iphone.launchSiri();
		iphone.launchPaper();
		iphone.makeVoiceCall(3057);
		iphone.recordAudio();
		iphone.turnOff();
		iphone.sendSMS("Hello, World?", 305);
		iphone.turnOn();
		iphone.makeVoiceCall(384);

	}
	cout << endl;
	cout << endl;

	{
		AndroidPhone samsung;
		samsung.setAndroidPhone(2, "11/3/2022", "Samsung");
		samsung.setiOSVersion("Android 10");
		samsung.setKernalVersion("44");
		samsung.turnOn();
		samsung.turnOff();
		samsung.launchSubwaySurfers();
		samsung.launchFlynx();
		samsung.turnOn();
		samsung.makeVoiceCall(384);
		samsung.recordAudio();
	}

	cout << endl;
	cout << endl;

	WindowsPhone wp;
	wp.setWindowsPhone(3, "11/3/2022", "Microsoft");
	wp.setProductVersion("Windows Phone");
	wp.setBuildNumber("105860");
	wp.turnOn();
	wp.launchXboxGame();
	wp.sendSMS("Message not allowed in lab", 02323);
	wp.turnOff();
	wp.launchFoundBite();
	wp.turnOn();


}