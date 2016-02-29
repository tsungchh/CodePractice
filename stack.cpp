#define DEFAULTSIZE 20

class stack
{
public:
	stack();
	~stack();

	void push(int);
	int pop();
	size_t size();

private:

	vector<int> ary;
	int tail;

};

stack::stack()
{
	ary.resize(DEFAULTSIZE, 0);
	tail = -1;
}

stack::~stack()
{

}

void stack::push(int val)
{
	if(tail+1 == ary.size())
		resize();
	ary[++tail] = val;

}

int stack::pop()
{
	if(size() == 0)
		return -1;

	int val = ary[tail];
	tail--;
	return val;
}

size_t stack::size()
{
	return tail+1;
}

void stack::resize()
{
	vector<int> newAry(ary.size()*2, 0);

	for(int i = 0; i < ary.size(); i++)
	{
		newAry[i] = ary[i];
	}
	ary = newAry;
}


