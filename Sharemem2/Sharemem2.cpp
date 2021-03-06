// Sharemem2.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include <boost/interprocess/shared_memory_object.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <iostream> 

using namespace boost::interprocess; 
using namespace std;


int _tmain(int argc, _TCHAR* argv[])
{
	try 
	{ 
		// creating our first shared memory object.
		shared_memory_object sharedmem1 (open_only, "Hello", read_only);

		// map the shared memory to current process 
		mapped_region mmap (sharedmem1, read_only, 0, 256); 

		// access the mapped region using get_address
		//std::strcpy(static_cast<char* >(mmap.get_address()), "Hello World!\n");
		printf( "sharedmem : %s\n", static_cast<char* >(mmap.get_address()) );

 		shared_memory_object::remove("Hello");

	} 
	catch (interprocess_exception&e) 
	{
		// .. .  clean up 
		cout << e.what() << endl;
		printf( "client2 error\n" );
	} 

	return 0;
}

