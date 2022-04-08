#include "Timer.h"
#include <iostream>
#include <Windows.h>
#include<conio.h>
using namespace std;
Timer::Timer():start_point_hr{0},start_point_min{0},start_point_sec{0}
{
}

void Timer::display_time()
{
	system("CLS");
	cout << "=================================================\n" << endl;
	cout << "      hr     ||      min    ||      sec      " << endl;
	cout << "=================================================\n" << endl;
	printf("       %d      :       %d      :      %d        \n", start_point_hr, start_point_min, start_point_sec);

}

void Timer::count_down()
{
	while (true) {
		display_time();
		Sleep(1000);
		if (start_point_hr > 0) {
			if (start_point_min > 0) {
				if (start_point_sec > 0) {
					start_point_sec--;
				}
				else {
					start_point_sec = 59;
					start_point_min--;
				}
			}
			else {
				if (start_point_sec > 0) {
					start_point_sec--;
				}
				else {
					start_point_sec = 59;
					start_point_min = 59;
					start_point_hr--;
				}
			}
		}
		else {
			if (start_point_min > 0) {
				if (start_point_sec > 0) {
					start_point_sec--;
				}
				else {
					start_point_sec = 59;
					start_point_min--;
				}
			}
			else {
				if (start_point_sec > 0) {
					start_point_sec--;
				}
				else {
					//PlaySound(TEXT("Old Alarm Clock Royalty Free Sound Effects Track.mp3"), NULL, SND_SYNC);
					cout << "Time out" << endl;


					break;
				}
			}
		}

	}
	cout << "back to modes press space b" << endl;
	char c;
	cin >> c;
	if (c == 'b') {
		set_up();
	}
	else {
		cout << "Wrong!" << endl;
		exit(1);
	}
}

void Timer::check_and_start(int start_point_hr, int start_point_min, int start_point_sec)
{
	if (start_point_hr <= 23) {
		if (start_point_min <= 59) {
			if (start_point_sec <= 59) {
				count_down();
			}
			else {
				cout << "please Enter hours in range 59 sec only" << endl;
				startTimer();
			}
		}
		else {
			cout << "please Enter hours in range 59 min only" << endl;
			startTimer();
		}
	}
	else {
		cout << "please Enter hours in range 23 hr only" << endl;
		startTimer();
	}
}

void Timer::startTimer()
{

	cout << "Please Enter the start time\n(hr || min || sec) " << endl;
	try
	{
		cin >> start_point_hr >> start_point_min >> start_point_sec;
		if (start_point_hr < 0 || start_point_min < 0 || start_point_hr < 0)
		{
			throw - 1;
		}
		else
			check_and_start(start_point_hr, start_point_min, start_point_sec);

	}
	catch (int e)
	{
		cout << "Negative Time !!!" << endl;
		startTimer();
	}
}

void Timer::stop_watch()
{
	cout << "press any button to start" << endl;
	getchar();
	while (true) {

		display_time();

		Sleep(1000);
		start_point_sec++;
		if (start_point_sec == 60) {
			start_point_min++;
			start_point_sec = 0;
		}
		if (start_point_min == 60) {
			start_point_hr++;
			start_point_sec = 0;
			start_point_min = 0;
		}
		if (_kbhit())
			break;

	}
	display_time();
	cout << "Time stoppped!" << endl;
	cout << "back to modes press space b" << endl;
	char c;
	cin >> c;
	if (c == 'b') {
		set_up();
	}
	else {
		cout << "Wrong!" << endl;
		exit(1);
	}
}

void Timer::set_up()
{
	int mode = 0;
	cout << "Select mode  " << endl;
	cout << "#1 Timer     " << endl;
	cout << "#2 stop watch" << endl;
	cout << "#3 Exit" << endl;
	cin >> mode;
	switch (mode)
	{
	case 1:
		startTimer();
		break;
	case 2:
		stop_watch();
		break;
	case 3:
		exit(1);
		break;
	default:
		break;
	}
}
