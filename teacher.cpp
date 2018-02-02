#include <iostream>
#include "teacher.hpp"

teacher::~teacher(){
	if(this->talking_with != NULL)
		delete this->talking_with;
}

parent * teacher::parentLeave(){
	parent * p = this->talking_with;
	this->talking_with = NULL;
	return p;
}

void teacher::assignParent(parent * p){
	this->talking_with = p;
}
