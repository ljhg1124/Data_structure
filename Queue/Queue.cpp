#include "Queue.h"

// Q데이터 오버플로우 확인 여부
bool FullCheckQ(Queue *q)
{
	if( q->GetSize() >= QUEUE_MAXSIZE ) return true;
	return false;
}

Queue::Queue(void)
{
	this->InitQ();
}
 
Queue::~Queue(void)
{
}

bool Queue::Available(void)
{
	if(this->size >= 21)
	{
		return true;
	}

	return false;
}

bool Queue::FindQueue(int index)
{
	int loopMax = this->tail + this->size;

	for(int i = this->tail; i < loopMax; i++)
	{
		if( this->data[i] == index ) return 1;
	}
	return 0;
}


bool Queue::isQueue()
{
	if(this->size > 0) return true;
	return false;
}

void Queue::AddQueue(unsigned char data)
{
	if( !FullCheckQ(this) )
	{
		this->data[this->head] = data;		// 데이터 저장
		this->size++;						// 데이터 증가로 인한 사이즈 증가.
		
		
		// 배열 끝부분 예외처리
		this->head = ++this->head % QUEUE_MAXSIZE; // 배열 마지막에 도달하면 head를 다시 맨앞으로 이동.
	}
}

unsigned char Queue::GetQueue()
{
	unsigned char data;
	
	if( this->isQueue() )
	{
		data = this->data[this->tail];		// 데이터 해제 후 Tail 증가.
		this->data[this->tail] = 0;			// 데이터 넘긴 후 0처리
		this->size--;						// 데이터 해제로 인한 사이즈 감소.	

		// 배열 끝부분 예외 처리
		this->tail = ++this->tail % QUEUE_MAXSIZE;		// 배열 마지막에 도달시 tail을 다시 맨앞으로 이동.

		return data;					// 데이터 리턴
	}

	return -1;
}
void Queue::DelQueue()
{
	if( this->isQueue() )
	{
		this->data[this->tail] = 0;		// 데이터 해제 후 Tail 증가.
		this->size--;						// 데이터 해제로 인한 사이즈 감소.	

		// 배열 끝부분 예외 처리
		this->tail = ++this->tail % QUEUE_MAXSIZE;		// 배열 마지막에 도달시 tail을 다시 맨앞으로 이동.
	}
}