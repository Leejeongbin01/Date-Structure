


#include "Queue.h"
#include <ctime>

// �������� % 2�� �ؼ� ¦���� m, Ȧ���� f�� ������ ���� front�� �������
// Ŀ�� ����
// ������ �ð� �װɷ� ¥����

class Simulator
{
private:
	int maxStudent; //�ִ��ο� �����ο�
	double participate; // �����ð��� ����ϴ� �л��� (0.5)

	int count;//�л� ��ȣ
	int couple; //�����Ʈ
	int student; // ������ �ο�
	int random;//���� �Ǵ�

	double probArrival; //���� �ð��� ���ÿ� ������ ��
	int sex; //����
	int m, f;

	double Random() {
		return rand() / (double)RAND_MAX;
		//�������� �߻�
	}
	bool isNewStudent() {
		return (Random() > probArrival);
			// �������� �߻��ϴ� ���� ���� �ð��� ���� �𺸴� Ŭ ���
	}
public:
	Simulator() {
		count = couple = student = m = f = 0;
	}
	void start() {
		cout << "�ùķ��̼��� �ִ� �ο� (100) " << endl;
		cin >> maxStudent;
		cout << "�����ð��� ����ϴ� �л� ��(0.5) " << endl;
		cin >> probArrival;
	}
	void run() {
		Circular male, female;
		while (count <maxStudent) {
			cout << count + 1 << " ��° �õ� " << endl;
			if (isNewStudent())
				// �� �л��� ����� ���
			{
				student++;
				random = rand() % 2;
				if (random == 1) {
					cout << "���л� ����" << endl;
					male.enqueue(count);
					m++;
				}
				else {
					cout << "���л��� ���� " << endl;
					female.enqueue(count);
				}
			}
			else {
				cout << "���� ����" << endl;
			}
			if (!male.isEmpty() && !female.isEmpty()) {
				//���ڿ� ���� ť�� ������� �ʴ�>> �Ѵ� ���ִ�;
				int boy, girl;
				boy = male.dequeue();
				girl = female.dequeue();
				// ��ȣ�� �ο�
				couple++;
				cout << "���� ���� !  " << boy << " " << girl << " �� Ŀ���� ��" << endl;
			}
			else {
				cout << "���� �똴������ ����" << endl << endl;
			}
			count++;
		}
	}
	void print()
	{
		cout << "________________________________" << endl;
		cout << "���ÿ� ���� " << maxStudent << endl;
		cout << "���ÿ� ������ �л� �� " << student << endl;
		cout << "�� �� (��:��) " << m << ":" << f << endl;
		cout << "����� Ŀ�� �� " << couple << endl;

	}

};