 #include <iostream>
 using namespace std;

 //Access Specifiers (private,public,protected)

 class Point
 {
 private: // Default
 	int x;
 	int y;

 public:
 	//Setter/mutators  Functions(MODIFY)
 	//Getter/accessors Functions(READ)

 	//void setX(int val);  //Member Function
 	void setX(int val)
 	{
 		x = val;
 	}

 	//void setY(int val);  //Member Function
 	void setY(int val)
 	{
 		y = val;
 	}

 	//Constant member function
 	int getX() const
 	{
 		return x;
 	}

 	//Constant member function
 	int getY() const
 	{
 		return y;
 	}

 	//Constant member function
 	void displayPoint() const
 	{
 		cout << "(" << x << "," << y << ")\n";
 	}

 };

 int main()
 {
 	// don't create data public
 	// we are Creating an instance of class Point
 	// OR
 	// Instantiating an object of class Point
 	Point p1; //p1 is an object/instance of class Point
	
 	//p1.x = 5;   //ERROR: can't access private data members
 	//p1.y = 10;  //ERROR: can't access private data members

 	p1.setX(5);
 	p1.setY(10);

 	Point p2;
 	int tempX, tempY;
 	cout << "Enter Coordinates: ";
 	cin >> tempX >> tempY;

 	p2.setX(tempX);
 	p2.setY(tempY);

 	cout << "p1 contains: ";
 	//cout << p1.getX() << " " << p1.getY() << endl;
 	p1.displayPoint();

 	cout << "\np2 contains: ";
 	//cout << p2.getX() << " " << p2.getY() << endl;
 	p2.displayPoint();

 	//------------------------------------------------

 	//Dynamic Memory Allocation
 	Point* ptr = new Point;
 	ptr->setX(50);
 	ptr->setY(80);

 	//cout << ptr->getX() << " " << ptr->getY() << endl;
 	ptr->displayPoint();

 	delete ptr;
 	ptr = nullptr;
 }