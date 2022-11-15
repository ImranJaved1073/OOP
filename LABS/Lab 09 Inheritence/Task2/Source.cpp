#include "WindowsPhone.h"
#include "MobilePhone.h"
#include "AndroidPhone.h"
#include "ApplePhone.h"
#include <iostream>
#include<string>
using namespace std;

int main()
{
	ApplePhone iphone;
	iphone.setMfgID(1);
	iphone.setMfgDate("15/11/2022");
	iphone.setMfgName("Apple");
	iphone.setiOSVersion("iOS 14");
	iphone.turnOn();
	iphone.makeVoiceCall(03224243115);
	iphone.launchSiri();
	iphone.launchPaper();
	iphone.recordAudio();
	iphone.turnOff();
	iphone.sendSMS("Hello, how are you?", 03004567);
	iphone.recordAudio();
	iphone.turnOn();
	iphone.makeVoiceCall(0324534554);

	cout << endl << endl;

	AndroidPhone oppo;
	oppo.setAndroidPhone(2, "11/11/2022", "OPPO");
	oppo.setiOSVersion("Android lollipop 11");
	oppo.setKernalVersion("44");
	oppo.turnOn();
	oppo.launchSubwaySurfers();
	oppo.turnOff();
	oppo.launchSubwaySurfers();
	oppo.launchFlynx();
	oppo.turnOn();
	oppo.makeVoiceCall(384);
	oppo.recordAudio();

	cout << endl << endl;

	WindowsPhone lumia;
	lumia.setWindowsPhone(3, "15/10/2022", "Microsoft");
	lumia.setProductVersion("Windows Phone 10");
	lumia.setBuildNumber("734234");
	lumia.turnOn();
	lumia.launchXboxGame();
	lumia.sendSMS("Message not allowed in lab", 02323);
	lumia.turnOff();
	lumia.launchFoundBite();
	lumia.turnOn();
	lumia.turnOff();

}
