#include "spdlog/spdlog.h"
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <chrono>


class Timer
{
private:
	// Псевдонимы типов используются для удобного доступа к вложенным типам
	using clock_t = std::chrono::high_resolution_clock;
	using second_t = std::chrono::duration<double, std::ratio<1> >;
 
	std::chrono::time_point<clock_t> m_beg;
 
public:
	Timer() : m_beg(clock_t::now())
	{
	}
 
	void reset()
	{
		m_beg = clock_t::now();
	}
 
	double elapsed() const
	{
		return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
	}
};

class BinaryMLModelOutput{

public:

const static void print_header(const int& processed, const Timer& timer){
    const char separator    = ' | ';
    const int nameWidth     = 6;
    const int numWidth      = 8;

    std::cout << std::left << std::setw(nameWidth) << std::setfill(separator) << "Processed: ";
    std::cout << std::left << std::setw(numWidth) << std::setfill(separator) << processed;
    std::cout << std::endl;

    std::cout << std::left << std::setw(nameWidth) << std::setfill(separator) << "Time: ";
    std::cout << std::left << std::setw(numWidth) << std::setfill(separator) << timer.elapsed();
    std::cout << std::endl;

    float perfomance = processed / timer.elapsed();
    std::cout << std::left << std::setw(nameWidth) << std::setfill(separator) << "Perfomance: ";
    std::cout << std::left << std::setw(numWidth) << std::setfill(separator) << perfomance;
    std::cout << std::left << std::setw(numWidth) << std::setfill(separator) << " pkg/";
    std::cout << std::endl;
}

const static inline void print_binary_descion(bool result){
    result ? spdlog::info("Clean") : spdlog::critical("Atack");
}

};




int main() 
{
    spdlog::info("Welcome to spdlog!");
	Timer timer;

    int i=1;
    
    while (int(timer.elapsed())<10 )
    {
        BinaryMLModelOutput::print_header(i, timer);

        while (i%15!=0)
        {
            BinaryMLModelOutput::print_binary_descion(i%5);
            i++;
        }
        std::system("clear");
        i++;
    }

}
