#ifndef TEACHER_HPP_
#define TEACHER_HPP_
#include "parent.hpp"

class teacher{
private:
	int id;
	parent * talking_with;
public:
	teacher(int ID)
	:id(ID), talking_with(NULL){ }

	~teacher();

	inline int getId()		{ return this->id; }
	inline bool is_buzy()	{ return this->talking_with != NULL; }

	/**
	 * returns the parent that currently is speaking with the teacher
	 */
	parent * parentLeave();

	/**
	 * assignes a parent to a teacher to speak with
	 */
	void assignParent(parent * p);
};

#endif /* TEACHER_HPP_ */
