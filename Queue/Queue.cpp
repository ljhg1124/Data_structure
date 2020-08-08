#include "Queue.h"

// Q������ �����÷ο� Ȯ�� ����
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
		this->data[this->head] = data;		// ������ ����
		this->size++;						// ������ ������ ���� ������ ����.
		
		
		// �迭 ���κ� ����ó��
		this->head = ++this->head % QUEUE_MAXSIZE; // �迭 �������� �����ϸ� head�� �ٽ� �Ǿ����� �̵�.
	}
}

unsigned char Queue::GetQueue()
{
	unsigned char data;
	
	if( this->isQueue() )
	{
		data = this->data[this->tail];		// ������ ���� �� Tail ����.
		this->data[this->tail] = 0;			// ������ �ѱ� �� 0ó��
		this->size--;						// ������ ������ ���� ������ ����.	

		// �迭 ���κ� ���� ó��
		this->tail = ++this->tail % QUEUE_MAXSIZE;		// �迭 �������� ���޽� tail�� �ٽ� �Ǿ����� �̵�.

		return data;					// ������ ����
	}

	return -1;
}
void Queue::DelQueue()
{
	if( this->isQueue() )
	{
		this->data[this->tail] = 0;		// ������ ���� �� Tail ����.
		this->size--;						// ������ ������ ���� ������ ����.	

		// �迭 ���κ� ���� ó��
		this->tail = ++this->tail % QUEUE_MAXSIZE;		// �迭 �������� ���޽� tail�� �ٽ� �Ǿ����� �̵�.
	}
}