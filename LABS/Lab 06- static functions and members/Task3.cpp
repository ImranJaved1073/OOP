#include <iostream> 
using namespace std;

//Implement a class ObjectTracker that can track how many objects of a class are present in memory.It
//should increment the object counter when a new instance of the object tracker is created.It should
//decrement the counter when any object is removed from the memory.
//Implement all constructors, destructors, and necessary accessorsand mutator functions.The user should
//be able to get the number of active objects of the class.

class ObjectTracker
{
private:
    static int activeObjects;
public:
    ObjectTracker();
    ObjectTracker(const ObjectTracker& obj);
    ~ObjectTracker();
    static int getActiveObjects();
};

ObjectTracker::ObjectTracker() {
    activeObjects++;
}

ObjectTracker::ObjectTracker(const ObjectTracker& obj) {
    activeObjects++;
}

ObjectTracker::~ObjectTracker() {
    activeObjects--;
}

int ObjectTracker::getActiveObjects() {
    return activeObjects;
}

int ObjectTracker::activeObjects = 0;

int main() {
    cout << "Active Objects: " << ObjectTracker::getActiveObjects() << endl;
	cout << "Creating Object 1" << endl;
    ObjectTracker obj1;
	cout << "Active Objects: " << ObjectTracker::getActiveObjects() << endl;
	cout << "Creating Object 2" << endl;
    ObjectTracker obj2;
    cout << "Active Objects: " << ObjectTracker::getActiveObjects() << endl;
	cout << "Creating Object 3" << endl;
    ObjectTracker obj3;
	cout << "Active Objects: " << ObjectTracker::getActiveObjects() << endl;
	cout << "Creating Object 4" << endl;
    ObjectTracker obj4;
    cout << "Active Objects: " << ObjectTracker::getActiveObjects() << endl;
	cout << "Creating Object 5" << endl;
    ObjectTracker obj5;
	cout << "Active Objects: " << ObjectTracker::getActiveObjects() << endl;
    cout << "Object created through copy constructor" << endl;
	ObjectTracker obj6(obj5);
    cout << "Active Objects: " << ObjectTracker::getActiveObjects() << endl;
    cout << "Deleting obj1" << endl;
    obj1.~ObjectTracker();
    cout << "Active Objects: " << ObjectTracker::getActiveObjects() << endl;
    cout << "Deleting obj2" << endl;
	obj2.~ObjectTracker();
    cout << "Active Objects: " << ObjectTracker::getActiveObjects() << endl;
    cout << "Deleting obj3" << endl;
	obj3.~ObjectTracker();
    cout << "Active Objects: " << ObjectTracker::getActiveObjects() << endl;
    cout << "Deleting obj4" << endl;
	obj4.~ObjectTracker();
    cout << "Active Objects: " << ObjectTracker::getActiveObjects() << endl;
    cout << "Deleting obj5" << endl;
	obj5.~ObjectTracker();
    cout << "Active Objects: " << ObjectTracker::getActiveObjects() << endl;
    return 0;
}