#include <iostream>
#include <chrono>


enum TypeTimeInterval{STD, CUSTOM};
enum StdTimeIntervals{MINUTE, HOAR, DAY, WEEK, MONTH, QUARTER, YEAR, TEN_YEARS, ONE_HUNDRED_YEARS};
enum TimeEdge{START,END};
enum TimeOfStartStdInterval{NOW,CUR_STD_PERIOD,CUR_NEXT_PERIOD,CUSTOM};

class NumPeriod{
private:
	int m_period;
	int m_start;
	int m_curPeriod;
public:
	NumPeriod(int start=1) : m_start{start}
	{
	m_period=m_start;
	m_curPeriod=m_period;
	}

	void printCurP(){std::cout << "Current period: " << m_curPeriod << '\n';}
};


class TimePeriod{
private:
	TypeTimeInterval m_typeTimeInterval; // Тип часового інтервалу: стандартний (STD) чи користувацький (CUSTOM)
	StdTimeIntervals m_stdTimeInterval; // Для зберігання стандартного часового інтервалу: мінута, година, доба і т.д.
	TimeOfStartStdInterval m_timeOfStartStdInterval; // Коли починається інтервал: зараз (NOW), чи з початку поточного стандартного інтервалу (CUR_STD_PERIOD), 
							// чи з початку наступного стандартного інтервалу (CUR_NEXT_PERIOD) чи з моменту, який ми вкажемо (CUSTOM)
	std::chrono::time_point m_start; // час початку (обчислюється конструктором при створенні об'єкту на основі поточного часу і налаштувань періода)
	std::chrono::time_point m_cur_end; // час закінчення потчного періоду (перший раз обчислюється конструктором при створенні об'єкту на основі поточного часу і налаштувань періода. Далі обчислюється при виконанні методів)
	Edge m_edge {START}; // якій край часового відрізка вікористовуємо для створення часового періоду : початок (START) чи кінець (END) при використанні 
	int m_periodNum {1};
	int m_curPeriod {m_periodNum};

public:
	TimePeriod(
			TypeTimeInterval typeTimeInterval=STD,
			StdTimeIntervals stdTimeInterval=YEAR, 
			TimeOfStartStdInterval timeOfStartStdInterval=CUR_STD_PERIOD,
			auto customStartStdPeriod =std::chrono::system_clock::now()
		)
		: m_typeTimeInterval {typeTimeInterval}, 
		m_stdTimeInterval {stdTimeInterval}, 
		m_timeOfStartStdInterval {m_timeOfStartStdInterval},
		m_start {customStartStdPeriod}
	{
		m_start=startCurPeriod();
	}

	std::chrono::time_point startCurPeriod()
	{
		if(m_typeTimeInterval==STD && TimeOfStartStdInterval==NOW) 
			return std::chrono::system_clock::now();;

		if(m_typeTimeInterval==STD && TimeOfStartStdInterval==CUR_STD_PERIOD)
		{
			switch (m_stdTimeInterval)
			{
				case MINUTE:
					return start_cur_minute();
					break;
				case HOAR:
					return start_cur_hoar();
					break;
				case DAY:
					return start_cur_day();
					break;
				case WEEK:
					return start_cur_week();
					break;
				case MONTH:
					return start_cur_month();
					break;
				case QUARTER:
					return start_cur_quarter();
					break;
				case YEAR:
					return start_cur_year();
					break;
				case TEN_YEARS:
					return start_cur_ten_years();
					break;
				case ONE_HUNDRED_YEARS:
					return start_cur_one_hundred_years();
					break;
			}
		}

		if(m_typeTimeInterval==STD && TimeOfStartStdInterval==CUR_NEXT_PERIOD)
		{
			switch (m_stdTimeInterval)
			{
				case MINUTE:
					return start_next_minute();
					break;
				case HOAR:
					return start_next_hoar();
					break;
				case DAY:
					return start_next_day();
					break;
				case WEEK:
					return start_next_week();
					break;
				case MONTH:
					return start_next_month();
					break;
				case QUARTER:
					return start_next_quarter();
					break;
				case YEAR:
					return start_next_year();
					break;
				case TEN_YEARS:
					return start_next_ten_years();
					break;
				case ONE_HUNDRED_YEARS:
					return start_next_one_hundred_years();
					break;
			}
		}
	if(m_typeTimeInterval==STD && TimeOfStartStdInterval==CUSTOM) 
			return m_start;


	return end_cur_year();
	}

	void printCurP(){std::cout << "Current period: " << m_curPeriod << '\n';}
	int getCurP(){ return m_curPeriod; }
	bool isNewPriod(){ 
		if( m_curPeriod > m_Period ) 
		{
			m_Period=m_curPeriod;
			return true;
		}
		else 
			return false;
	}

};



int main(){
	union U u;
	u.c='S';

	std::cout << "u.c = " << u.c << '\n';
//	periodDoc.printCurP();
	return 0;
}