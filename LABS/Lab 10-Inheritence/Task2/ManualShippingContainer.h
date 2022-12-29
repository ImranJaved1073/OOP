#ifndef MANUALSHIPPINGCONTAINER_H
#define MANUALSHIPPINGCONTAINER_H

#include "ShippingContainer.h"
#include <string>
using namespace std;

class ManualShippingContainer : public ShippingContainer

{
private:
	string manifest;
public:
	ManualShippingContainer()
	{
		manifest = "";
	}
	ManualShippingContainer(int id, string m)
	{
		containerID = id;
		manifest = m;
	}
	string getManifest() const
	{
		return manifest;
	}
	void setManifest(string m)
	{
		manifest = m;
	}
};

#endif // !MANUALSHIPPINGCONTAINER_H

