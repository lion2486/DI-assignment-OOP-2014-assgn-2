#include <iostream>
#include "briefing.hpp"

briefing::briefing(int n, int k)
:N(n), K(k), Inserted(0)
{
	this->teachers = new teacher * [n];

	for(int i=0; i<n; i++)
		this->teachers[i] = new teacher(i);

	this->parents = new List();
}

briefing::~briefing(){

	for(int i=0; i<this->N; i++)
		delete this->teachers[i];

	delete[] this->teachers;

	delete this->parents;
}

parent * briefing::firstFromQueue(int teacherID){
	parent * p;

	p = this->parents->Get_List_First();

	while(p != NULL){
		if(p->wantsToSpeakWith(teacherID)){
			this->parents->Remove_Cur_Item();
			return p;
		}

		p = this->parents->Get_List_Next();
	}

	return NULL;
}

void briefing::start(){
	List * parentsPool;
	parent * p;

	parentsPool = new List();

	//Create all K parents in a list
	for(int i = 0; i<this->K; i++)
		parentsPool->Add_List_Item_at_End( new parent(i, this->N) );

	//Insert some parents into the queue
	while(this->Inserted < this->K || this->parents->Get_List_Size() != 0){
		int L = rand()%( ((this->K - this->Inserted)>0)?(this->K - this->Inserted): 1 ) + 1;

		this->Inserted += L;

		//Add the L(rand) parents into the queue
		while(L-- && parentsPool->Get_List_Size() > 0){
			p = parentsPool->Get_List_First();

			this->parents->Add_List_Item_at_End(p);

			parentsPool->Remove_Cur_Item();
		}

		//for all the teachers
		for(int i=0; i<this->N; i++){
			//find the first parent for teacher i
			p = this->firstFromQueue(i);
			this->teachers[i]->assignParent(p);
		}

		//add new parents to the end of the queue
		L = (int)(rand()%10/13.0*((this->K - this->Inserted))>0)?(this->K - this->Inserted): 0 + 1;

		this->Inserted += L;

		//Add the L(rand) parents into the queue
		while(L-- && parentsPool->Get_List_Size() > 0){
			p = parentsPool->Get_List_First();

			this->parents->Add_List_Item_at_End(p);

			parentsPool->Remove_Cur_Item();
		}

		//for all the teachers
		for(int i=0; i<this->N; i++){
			//returns parents to queue or leave
			if(this->teachers[i]->is_buzy()){
				p = this->teachers[i]->parentLeave();
				p->endsWith(i);

				if(p->anotherTeacher()){
					//lets chech if he will go back to queue
					if(rand()%10 < 3)
						std::cout << "Hey, What are you doing? Go Back!!!" << std::endl;
					else
						std::cout << "Again at the end... Hurry up!" << std::endl;

					this->parents->Add_List_Item_at_End(p);
				}else{
					std::cout << "Wow, I have done with that!" << std::endl;
					delete p;
				}
			}
		}


	}


	delete parentsPool;
}
