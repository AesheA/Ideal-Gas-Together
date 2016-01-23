#ifndef _DEFINES_HPP_INCLUDED_
#define _DEFINES_HPP_INCLUDED_

//----------------------------------------------------------------------------
//{ Includes
//----------------------------------------------------------------------------

	#include <stdio.h>
	#include <assert.h>
	#include <Windows.h>
	#include <chrono>
	#include <thread>

//}
//----------------------------------------------------------------------------


//----------------------------------------------------------------------------
//{ Fun:
//----------------------------------------------------------------------------

	#define EVER (;,,;)

//}
//----------------------------------------------------------------------------


//----------------------------------------------------------------------------
//{ Console colors(TXLib only):
//----------------------------------------------------------------------------

	#ifdef __TXLIB_H_INCLUDED
		#define BLU txSetConsoleAttr(0xB);
		#define GRN txSetConsoleAttr(0xA);
		#define RED txSetConsoleAttr(0xC);
		#define YEL txSetConsoleAttr(0xE);
		#define WHT txSetConsoleAttr(0xF);
	#endif /*__TXLIB_H_INCLUDED*/

//}
//----------------------------------------------------------------------------


//----------------------------------------------------------------------------
//{ Different sleeps/waits:
//----------------------------------------------------------------------------

	#define WAIT waitUntilSpaceButtonIsPressed();
	#define DOTS waitUntilSpaceButtonIsPressedWhileMakingThreeDots();
	#define SLEEP(time) sleepForTimePassedInMillisconds(time);

//}
//----------------------------------------------------------------------------


//----------------------------------------------------------------------------
//{ Counter stuff:
//----------------------------------------------------------------------------

	#define COUNTER_STR(counter) ((counter) = GetTickCount());
	#define COUNTER_FIN(counter) ((counter) = (GetTickCount() - (counter)));

//}
//----------------------------------------------------------------------------


//----------------------------------------------------------------------------
//{ Assertion:
//----------------------------------------------------------------------------

	//#undef assert
	//#define assert(message) if (!(message) && printf("ERROR OCCURED: (##message) is false")) waitUntilSpaceButtonIsPressed()

//}
//----------------------------------------------------------------------------


//----------------------------------------------------------------------------
//{ Making variable unused(recently absorbed info):
//----------------------------------------------------------------------------

	#define UNUSED_VARIABLE(variable) static_cast<void>(variable);

//}
//----------------------------------------------------------------------------


//----------------------------------------------------------------------------
//{ Additional function, used in those defines:
//----------------------------------------------------------------------------

	void sleepForTimePassedInMillisconds(unsigned int toSleep)
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(toSleep));
	}

	void waitUntilSpaceButtonIsPressed()
	{
		bool spaceButtonPressed = (GetAsyncKeyState(VK_SPACE)) ? true : false;
		bool ready = !spaceButtonPressed;

		while (true)
		{
			if (!GetAsyncKeyState(VK_SPACE) && spaceButtonPressed) ready = true;

			if (ready && GetAsyncKeyState(VK_SPACE)) break;
		}
	}

	void waitUntilSpaceButtonIsPressedWhileMakingThreeDots()
	{
		bool spaceButtonPressed = (GetAsyncKeyState(VK_SPACE)) ? true : false;
		bool ready = !spaceButtonPressed;

		SLEEP(500);

		unsigned int currentDot = 0;
		for (; !(ready && GetAsyncKeyState(VK_SPACE)); currentDot++)
		{
			if (!GetAsyncKeyState(VK_SPACE) && spaceButtonPressed) ready = true;

			if (currentDot == 3)
			{
				printf("\b\b\b");
				printf("   ");
				printf("\b\b\b");

				currentDot = 0;
			}

			if (currentDot != 3) printf(".");

			SLEEP(600);
		}

		for (; currentDot > 0; currentDot--) printf("\b");
	}


//}
//----------------------------------------------------------------------------

#endif /*_DEFINES_HPP_INCLUDED_*/