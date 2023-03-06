


#include "Queue.h"
#include <ctime>

// 랜덤으로 % 2를 해서 짝수면 m, 홀수면 f에 보내서 만약 front가 같을경우
// 커플 성사
// 랜덤은 시간 그걸로 짜보자

class Simulator
{
private:
	int maxStudent; //최대인원 참가인원
	double participate; // 단위시간당 등록하는 학생수 (0.5)

	int count;//학생 번호
	int couple; //출력파트
	int student; // 참가한 인원
	int random;//성병 판단

	double probArrival; //단위 시간당 미팅에 나오는 수
	int sex; //성별
	int m, f;

	double Random() {
		return rand() / (double)RAND_MAX;
		//무작위로 발생
	}
	bool isNewStudent() {
		return (Random() > probArrival);
			// 무작위로 발생하는 수가 단위 시간당 오는 놈보다 클 경우
	}
public:
	Simulator() {
		count = couple = student = m = f = 0;
	}
	void start() {
		cout << "시뮬레이션할 최대 인원 (100) " << endl;
		cin >> maxStudent;
		cout << "단위시간에 등록하는 학생 수(0.5) " << endl;
		cin >> probArrival;
	}
	void run() {
		Circular male, female;
		while (count <maxStudent) {
			cout << count + 1 << " 번째 시도 " << endl;
			if (isNewStudent())
				// 새 학생이 들오온 경우
			{
				student++;
				random = rand() % 2;
				if (random == 1) {
					cout << "남학생 들어옴" << endl;
					male.enqueue(count);
					m++;
				}
				else {
					cout << "여학생이 들어옴 " << endl;
					female.enqueue(count);
				}
			}
			else {
				cout << "오지 않음" << endl;
			}
			if (!male.isEmpty() && !female.isEmpty()) {
				//남자와 여자 큐가 비어있지 않다>> 둘다 차있다;
				int boy, girl;
				boy = male.dequeue();
				girl = female.dequeue();
				// 번호를 부여
				couple++;
				cout << "미팅 성공 !  " << boy << " " << girl << " 이 커플이 됨" << endl;
			}
			else {
				cout << "아직 대샂ㅇ가가 없음" << endl << endl;
			}
			count++;
		}
	}
	void print()
	{
		cout << "________________________________" << endl;
		cout << "미팅에 지원 " << maxStudent << endl;
		cout << "미팅에 참여한 학생 수 " << student << endl;
		cout << "성 비 (남:여) " << m << ":" << f << endl;
		cout << "성상된 커플 수 " << couple << endl;

	}

};