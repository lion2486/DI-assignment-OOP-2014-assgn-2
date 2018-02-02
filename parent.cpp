#include <iostream>
#include "parent.hpp"

parent::parent(int ID, int n )
:id(ID), N(n){
	this->to_visit = new bool[n];

	for(int i=0; i<n; i++)
		this->to_visit[i] = (rand()%10 < 5) ? true : false;

	//add at least one teacher to visit
	if(!this->anotherTeacher())
		this->to_visit[rand()%this->N] = true;
}

parent::~parent(){
	delete[] this->to_visit;
}
