#ifndef SHIPPINGCONTAINER_H
#define SHIPPINGCONTAINER_H

class ShippingContainer
{
protected:
	int containerID;
public:
	ShippingContainer()
	{
		containerID = 0;
	}
	ShippingContainer(int id)
	{
		containerID = id;
	}
	void setContainerID(int id)
	{
		containerID = id;
	}
	int getContainerID() const
	{
		return containerID;
	}
};

#endif // !SHIPPING_CONTAINER
