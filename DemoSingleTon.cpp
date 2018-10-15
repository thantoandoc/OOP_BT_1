#include "DemoSingleTon.h"

DemoSingleTon* DemoSingleTon::instance = 0;

DemoSingleTon::DemoSingleTon(void)
{
	this->data = 0;
}


DemoSingleTon::~DemoSingleTon(void)
{
}

DemoSingleTon * DemoSingleTon ::getInstance(){
	if(!instance) {
		instance = new DemoSingleTon();
	}
	return instance;
}
void DemoSingleTon::setData(int data){
	this->data = data;
}

int DemoSingleTon::getData(){
	return this->data;
}

