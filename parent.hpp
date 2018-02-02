#ifndef PARENT_HPP_
#define PARENT_HPP_
#include <cstdlib>

class parent{
private:
	int id;
	bool * to_visit;
	int N;
public:
	parent(int ID, int n );
	~parent();

	inline int getId(){ return this->id; }
	inline bool wantsToSpeakWith(int teacherID){ return this->to_visit[teacherID]; }
	inline void endsWith(int teacherID){ this->to_visit[teacherID] = false; }
	inline bool anotherTeacher(){ for(int i=0; i<this->N; i++) if(this->to_visit[i]) return true; return false; }
};

#endif /* PARENT_HPP_ */
