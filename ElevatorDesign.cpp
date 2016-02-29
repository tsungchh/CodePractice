class ElevatorManager
{
	Elevator elevatorArray[ELEVATOR_COUNT];
	// List of pending hallcalls
	HallCallList hallcallList_;

public:
	// User API to intiate a hall call
	void ProcessHallCall(const HallCall& rHallCall);

private:
	// Starts the Hall Call Process Thread
	void StartHallCallProcessThread();
	// Create thread for each elevator to make it operational
	void StartCarMovementThread();
};
	
void ElevatorManager::ProcessHallCall(const HallCall& rHallCall)
{
	hallcallList_->AddHallCall(rHallCall);
}

ElevatorManager::StartHallCallProcessThread()
{
	HallCallProcessThread thread(elevator, hallcallList_);
	thread.run();
	thread.detach();
}

ElevatorManager::StartCarMovementThread()
{
	for (int i = 0; i < ELEVATOR_COUNT; i++)
	{
		ElevatorThread thread(elevatorArray[i]);
		thread.run();
		thread.execute();
	}
}


//////////////////////////////////////////////////////////////////////////////////

// class encapsulating the hallcall list treatment
class HallCallList
{
	list<HallCall> lHallCallList_;
	Mutex mHallCallListMutex;
public:
	void AddHallCall(HallCall hallCall);
	HallCall PopHallCall();
};

HallCallList::AddHallCall(HallCall hallCall)
{
	MutexLock(mHallCallListMutex);
	lHallCallList_->push_back(hallCall);
	hallCallListSemaphore->signal();
}

HallCall HallCallList::PopHallCall()
{
	MutexLock(mHallCallListMutex);
	Hallcall hallcall = lHallCallList_->front();
	lHallCallList_->erase(lHallCallList_.begin(), lHallCallList_.begin());
	return hallcall;
}

//////////////////////////////////////////////////////////////////////////////////
// Creates one thread per hallcall so that non-interfering hall calls can work parallely
HallCallProcessThread::Execute()
{
	hallCallListSemaphore->signal();
	MutexLock(mHallCallListMutex);
	Hallcall hallcall = hallcallList_->pop();
	OneHallcallThread thread(hallcall, hallcallList_);
	thread.run()
	thread.detach();
}

OneHallcallThread::Execute()
{
	bool bCallProcessed = false;
        // Sorted Elevator Array sorts the provided elevator array based on the current requested hallcall floor.
       // We want to try out the elevator which is nearest
	SortedElevator elevatorArray(elevatorArray, hallcall);
	FOR_EACH elevator in elevatorArray
	{
		if (true == elevator->ProcessCall(hallcall))
		{
			bCallProcessed = true;
			break;
		}
	}

	// If currently no elevator can process the hallcall
	// it is added back to the hallcalllist
	if (false == bCallProcessed)
	{
		hallcallList_->AddHallCall(hallcall);
	}
}


/////////////////////////////////////////////////////////////////////////////////////////////

class Elevator
{
	typedef int FLOOR;
	typedef list<FLOOR> DestFloorList;
	Mutex elevLock;
	Semaphore destFloorEmptySem; // To put elevator thread into wait state when no hallcall
	DestFloorList lDestFloorList_;
public:
	Elevator() : elevLock(1), destFloorEmptySem(0);
	void ProcessCall(Hallcall hallcall);
	void Move();
	
protected:
	void Reset();
	void UpdateCurrentFloor();
};

Elevator::ProcessCall(HallCall hallcall)
{
	Mutexlock lock(elevLock);

	// Logic to find if the elevator can process the request
	if ((this->state == STATIONARY) || 
		((this->state == UP) && (hallcall.direction == UP) && (this->currFloor < hallcall.floor)) ||
		((this->state == DOWN) && (hallcall.direction == DOWN) && (this->currFloor > hallcall.floor)))
	{
		this->lDestFloorList_->push_back(hallcall.floor);
		this->destFloorEmptySem_->signal();
		return true;
	}

	return false;
}

Elevator::Reset()
{
	this->state = STATIONARY;
	this->currFloor = 0;
	this->lDestFloorList_ = empty List;
}

Elevator::UpdateCurrentFloor()
{
	Mutexlock lock(this->elevLock);
	Floor targetFloor = this->lDestFloorList_->front();
	if (this->currFloor > targetFloor)
	{
		this->state = DOWN;
		this->currFloor--;
	}
	else if (this->currFloor < nextFloor)
	{
		this->state = UP;
		this->currFloor++;
	}
}

ElevatorThread::Execute()
{
	elevator->Move();
}

Elevator::Move()
{
	this->Reset();
	while(true) 
	{
		if ((this->state == UP) ||  (this->state == DOWN))
		{
			floor = this->lDestFloorList_->top();
			if (floor == this->currFloor)
			{
				{
					Mutexlock lock(elevLock);
					this->lDestFloorList_->pop_front();
					this->state == STATIONARY;
				}
				this->destFloorEmptySem_->wait();
				this->UpdateCurrentFloor();
			}
			else
			{
				this->UpdateCurrentFloor();
			}
		}
		else
		{
			this->destFloorEmptySem_->wait();
			this->UpdateCurrentFloor();
		}
		sleep(5);
	}
}