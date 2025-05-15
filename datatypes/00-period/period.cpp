#include <iostream>
#include <chrono>

enum PeriodType {TIME, NUMBER};
enum PeriodTimeStd {MINUTE, HOUR, DAY, WEEK, MONTH, QUARTER, YEAR, TEN_YEARS, ONE_HUNDERD_YERARS, OWN};
enum Edge {START, END};

/*class PeriodTime{
private:
	Edge m_edgeType;
	std::chrono::time_point m_edge;
	std::chrono::seconds m_duration;
	std::chrono::time_point m_start_next_period;
public:
	PeriodTime(Edge edgeType=START,	std::chrono::time_point edge, std::chrono::seconds duration=0)
		: m_edgeType=edgeType, m_edge=edge, m_duration=duration
	{
	}

	PeriodTime(Edge edgeType=START,	PeriodStd periodStd=YEAR)
		: m_edgeType=edgeType
	{
		switch (periodTimeStd){
		case MINUTE:
			// Ф-я для визначення початку мінути auto now=std::chrono::system_clock::now();
			break;
		case HOUR:
			// Ф-я для визначення початку часу auto now=std::chrono::system_clock::now();
			break;
		case DAY:
			// Ф-я для визначення початку дня auto now=std::chrono::system_clock::now();
			break;
		case WEEK:
			//auto now=std::chrono::system_clock::now();
			break;
		case MONTH:
			//auto now=std::chrono::system_clock::now();
			break;
		case YEAR:
			//auto now=std::chrono::system_clock::now();
			break;
		case TEN_YEARS:
			//auto now=std::chrono::system_clock::now();
			break;
		case ONE_HUNDERD_YERARS:
			//auto now=std::chrono::system_clock::now();
			break;
		}
	
	}
	
	std::chrono::time_point next_period_start()
	{
		auto now=std::chrono::system_clock::now();
		return now+duration_cast<seconds>1000;
	}

	bool isNext(){
	auto now=std::chrono::system_clock::now();
	
	}
};

*/

union uPeriod{
	std::chrono:time_point time;
	int number;
}

class Period{
private: 
	PeriodType m_periodType;
	int m_numPeriod; // номер періода
	union uPeriod m_per;
public:
	Period(PeriodType pT=NUMBER, int nP=1, union uPeriod p.number=1) : m_periodType{pT}, m_numPeriod{nP}, m_per{p.number}
	{
	}

	void print(){
		std::cout << m_periodType << '\t' << m_numPeriod << '\t' << m_per << '\n';
	}
};

//system_clock::now() — повертає поточний момент часу.
//floor<days>(...) — округлює час до початку дня.
//time_point + duration — базові типи для представлення моменту часу та тривалості 
//.
//year_month_day та sys_days — нові типи з C++20 для календарних обчислень 





int main() {

/*    using namespace std::chrono;


    auto now = system_clock::now();
    auto now_time = floor<seconds>(now);
    auto since_epoch = now_time.time_since_epoch();

    // Обчислюємо, скільки секунд минуло з початку останньої хвилини
    auto secs = duration_cast<seconds>(since_epoch) % 60;
    auto start_of_minute = now_time - secs;

    std::cout << "Початок поточної хвилини: " 
              << start_of_minute.time_since_epoch().count() << " секунд від епохи\n"; 
*/

Period testP;

testP.print();

}
