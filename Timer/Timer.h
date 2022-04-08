#pragma once
class Timer
{
private:
	int start_point_sec;
	int start_point_min;
	int start_point_hr ;
	void display_time();
	void count_down();
	void check_and_start(int start_point_hr, int start_point_min, int start_point_sec);
	void startTimer();
	void stop_watch();
public:
	Timer();
	void set_up();
};

