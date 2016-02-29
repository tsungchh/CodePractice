
#define DEFAULTSIZE 20

class queue {
public:

	queue();
	~queue();
	
	void push(int);

	int front();

	int pop();

	size_t size();


private:
	
	void resize();

	vector<int> ary;
	size_t head;
	size_t tail;

};


queue::queue()
{
	ary.resize(DEFAULTSIZE, 0);
	head = 0;
	tail = -1;
}

queue::~queue()
{
	ary.resize(0);
}

void queue::push(int val)
{
	size_t newIdx = (tail+1) % ary.size();

    if( (newIdx+1) % ary.size() == head )
    {
    	resize();
    	newIdx = (tail+1) % ary.size();
    }

	ary[newIdx] = val;
	tail = newIdx;
    
}

int queue::front()
{
	return size() <= 0 ? -1 : ary[head];
}

int queue::pop()
{
    if(size() <= 0)
    {
    	return -1;
    }
    else
    {
    	int ret = ary[head];
    	head = (head+1) % ary.size();
    	return ret;
    }
}

size_t queue::size()
{
	return tail < head ? tail + ary.size() - head + 1 : tail - head + 1;
}


void queue::resize()
{
	size_t newSize = ary.size() * 2;

	vector<int> newAry(newSize, 0);
	int _size = size();
	for(int i = 0; i < _size; i++)
	{
		int idx = (head + i ) % _size;
		newAry[i] = ary[idx];
	}

	ary = newAry;
	head = 0;
	tail = _size-1;
}





