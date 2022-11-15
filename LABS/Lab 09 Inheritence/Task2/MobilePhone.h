#ifndef MOBILEPHONE_H
#define MOBILEPHONE_H
#include<string>
using namespace std;
class MobilePhone
{
private:
	int mfgID;
	string mfgDate;
	string mfgName;
	bool state;
public:
	MobilePhone();
	MobilePhone(int, string, string);

	void setMfgID(int);
	void setMfgDate(string);
	void setMfgName(string);
	void setState(bool state);

	bool getState();
	int getMfgID() const;
	string getMfgDate() const;
	string getMfgName() const;

	bool turnOn();
	void makeVoiceCall(int);
	void recordAudio();
	void sendSMS(string, int);
	bool turnOff();

	~MobilePhone();
};



#endif // !MOBILEPHONE_H
