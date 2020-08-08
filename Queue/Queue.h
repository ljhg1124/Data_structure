#pragma once
#include <string.h>
///-------------------------------------------------------------------------------------------------
///	define
///-------------------------------------------------------------------------------------------------
#define QUEUE_MAXSIZE 30

class Queue
{
private:
	unsigned char data[QUEUE_MAXSIZE];
	int		head;
	int		tail;
	int		size;

public:
	Queue(void);
	~Queue(void);

	int				GetSize(){ return this->size;}
	int				GetFrontIndex() { return this->tail; }
	unsigned char	*GetCurrentData(){	return this->data + this->tail; }
	unsigned char	GetLastData() { return this->data[this->head-1]; }
	unsigned char	GetQueue(int index) { return this->data[this->tail+index]; }
	void			InitQ() { memset(this, 0, sizeof(this)); }
	void			QueueClear() { this->InitQ(); }
	
	bool			Available();
	bool			FindQueue(int index);
	bool			isQueue();
	void			AddQueue(unsigned char data);
	unsigned char	GetQueue();
	void			DelQueue();
};