#include "Student.h"
#include "Queue.h"
 

int main()
{
	srand((unsigned int)time(NULL));
	Simulator s;
	s.start();
	s.run();
	s.print();
	return 0;
	//���� ���� ����
}