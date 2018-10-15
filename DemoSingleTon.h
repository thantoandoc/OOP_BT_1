#pragma once
class DemoSingleTon
{
private:
	static DemoSingleTon * instance;
	int data;
	DemoSingleTon(void);


public:
	static DemoSingleTon* getInstance();
	~DemoSingleTon(void);
	void setData(int = 0);
	int getData();
};

