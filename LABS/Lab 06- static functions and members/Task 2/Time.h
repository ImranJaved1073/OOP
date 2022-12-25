
class Time
{
private:
	int hours;
	int minutes;
	int seconds;

public:

	Time();
	Time(int, int, int);
	~Time();

	void setHours(int);
	void setMinutes(int);
	void setSeconds(int);

	int getHours() const;
	int getMinutes() const;
	int getSeconds() const;

	void advance(int, int, int);
	void reset(int, int, int);

	void print();
	Time(const Time&);
};
