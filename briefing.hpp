#ifndef BRIEFING_HPP_
#define BRIEFING_HPP_
#include "teacher.hpp"
#include "parent.hpp"
#include "List.h"

class briefing{
private:
	int N;
	int K;
	int Inserted;
	teacher ** teachers;
	List * parents;

public:
	briefing(int n, int k);
	~briefing();

	/**
	 * returns the parent that is next in the queue for the teacher
	 * and removed him from the queue
	 */
	parent * firstFromQueue(int teacherID);

	/**
	 * runs all the operations
	 */
	void start();

};

#endif /* BRIEFING_HPP_ */
