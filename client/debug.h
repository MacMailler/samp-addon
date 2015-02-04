#pragma once



#include "client.h"





class addonDebug
{

public:

	std::list<std::string> funcTrace;

	addonDebug();
	virtual ~addonDebug();

	void Log(char *format, ...);
	void traceLastFunction(char *format, ...);
	void processFW();

	boost::thread *getThreadInstance() const
	{
		return threadInstance.get();
	}

	static void Thread();
	static LONG WINAPI UnhandledExceptionFilter(struct _EXCEPTION_POINTERS *ExceptionInfo);

private:

	std::queue<std::string> logQueue;
	boost::mutex lwrMutex;
	boost::mutex ftrMutex;
	boost::shared_ptr<boost::thread> threadInstance;
};