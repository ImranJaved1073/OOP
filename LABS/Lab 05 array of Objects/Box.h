#pragma once
class Box
{
private:
	int length=0;
	int width=0;
	int height=0;

public:

	Box();

	void setLength(int);
	void setWidth(int);
	void setHeight(int);

	int getLength() const;
	int getWidth() const;
	int getHeight() const;

	~Box();
	int getVloume();

};

