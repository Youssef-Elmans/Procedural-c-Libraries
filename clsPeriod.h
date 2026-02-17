#pragma once
#include<iostream>
#include"clsDate.h";
using namespace std;
class clsPeriod
{
private:
	clsDate _StartDate;
	clsDate _EndDate;
public:
	clsPeriod(clsDate StartDate, clsDate EndDate) {
		this->_StartDate = StartDate;
		this->_EndDate = EndDate;
	}
	void SetStartDate(clsDate StartDate) {
		_StartDate = StartDate;
	}
	clsDate GetStartDate() {
		return _StartDate;
	}
	__declspec(property(get = GetStartDate, put = SetStartDate)) clsDate StartDate;
	void SetEndDate(clsDate EndDate) {
		_EndDate = EndDate;
	}
	clsDate GetEndDate() {
		return _EndDate;
	}
	__declspec(property(get = GetEndDate, put = SetEndDate)) clsDate EndDate;
	void Print() {
		cout << "Period Start: ";
		_StartDate.Print();
		cout << endl;
		cout << "Period End  : ";
		_EndDate.Print();
		cout << endl;
	}
	static short PeriodLengthInDays(clsPeriod Period, bool IncludeEndDay = false) {
		return clsDate::GetDifferenceInDates(Period._StartDate, Period._EndDate, IncludeEndDay);
	}
	short PeriodLengthInDays(bool IncludeEndDay = false) {
		return PeriodLengthInDays(*this, IncludeEndDay);
	}

	static bool AreOverlapPeriods(clsPeriod Period1, clsPeriod Period2) {
		if (
			clsDate::CompareDates(Period2._EndDate, Period1._StartDate) == clsDate::enCompare2Dates::Before
			||
			clsDate::CompareDates(Period2._StartDate, Period1._EndDate) == clsDate::enCompare2Dates::After
			)
			return false;

		return true;
	}

	bool IsOverlapWith(clsPeriod Period2) {
		return AreOverlapPeriods(*this, Period2);
	}

	static bool IsDateInPeriod(clsPeriod Period, clsDate Date) {

		return !(clsDate::CompareDates(Date, Period._EndDate) == clsDate::enCompare2Dates::After
			||
			clsDate::CompareDates(Date, Period._StartDate) == clsDate::enCompare2Dates::Before);

	}
	bool IsDateInPeriod(clsDate Date) {
		return IsDateInPeriod(*this, Date);
	}
	static short CountOverlapPeriodsDays(clsPeriod Period1, clsPeriod Period2) {

		short Period1Length = PeriodLengthInDays(Period1, true);
		short Period2Length = PeriodLengthInDays(Period2, true);

		short OverlapDays = 0;

		if (!AreOverlapPeriods(Period1, Period2))
			return 0;

		if (Period1Length < Period2Length) {

			while (clsDate::IsDate1BeforeDate2(Period1._StartDate, Period1._EndDate)) {

				if (IsDateInPeriod(Period2, Period1._StartDate))
					OverlapDays++;

				Period1._StartDate = clsDate::IncreaseDateByOneDay(Period1._StartDate);
			}
		}

		else {

			while (clsDate::IsDate1BeforeDate2(Period2._StartDate, Period2._EndDate)) {

				if (IsDateInPeriod(Period1, Period2._StartDate))
					OverlapDays++;

				Period2._StartDate = clsDate::IncreaseDateByOneDay(Period2._StartDate);
			}
		}

		return OverlapDays;
	}

	short CountOverlapDaysWithAnotherPeriod(clsPeriod Period2) {
		return CountOverlapPeriodsDays(*this, Period2);
	}


};

