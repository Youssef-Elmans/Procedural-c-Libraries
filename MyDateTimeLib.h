
#pragma once
#pragma warning(disable:4996)
#include<iostream>
#include"MyInputLib.h";
#include"MyMathLib.h";
#include"MyStringManipulationLib.h";
using namespace std;
namespace mydatetimelib {
	enum enCompare2Dates { Before = -1, Equal = 0, After = 1 };
	struct stDate {
		short Year;
		short Month;
		short Day;
	};
	struct stPeriod {
		mydatetimelib::stDate DateFrom;
		mydatetimelib::stDate DateTo;
	};
	bool LeapNotLeapYear(short Year) {
		return ((Year % 400 == 0) || ((Year % 4 == 0) && (Year % 100 != 0)));
	}
	short NumberOfDaysInYear(short Year) {
		return (LeapNotLeapYear(Year)) ? 366 : 365;
	}
	short NumberOfHoursInYear(short Year) {
		return NumberOfDaysInYear(Year) * 24;
	}
	int NumberOfMinutesInYear(short Year) {
		return NumberOfHoursInYear(Year) * 60;
	}
	int NumberOfSecondsOfYear(short Year) {
		return NumberOfMinutesInYear(Year) * 60;
	}
	short NumberOfDaysInMonth(short Year, short Month) {
		if (Month < 1 || Month>12)
			return 0;

		short arrNumberOfDaysInMonths[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };


		return (Month == 2) ? (LeapNotLeapYear(Year) ? 29 : 28) : arrNumberOfDaysInMonths[Month - 1];
	}

	short NumberOfHoursInMonth(short Year, short Month) {
		return NumberOfDaysInMonth(Year, Month) * 24;
	}

	short NumberOfMinutesInMonth(short Year, short Month) {
		return NumberOfHoursInMonth(Year, Month) * 60;
	}

	short NumberOfSecondsInMonth(short Year, short Month) {
		return NumberOfMinutesInMonth(Year, Month) * 60;
	}
	short DayIndexInWeek(short Year, short Month, short Day) {
		short a = (14 - Month) / 12;

		short y = Year - a;

		short m = Month + 12 * a - 2;

		short d = (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;

		return d;
	}
	short DayIndexInWeek(mydatetimelib::stDate Date) {
		return DayIndexInWeek(Date.Year, Date.Month, Date.Day);
	}
	short NumberOfDaysInAMonth(short Year, short Month)
	{
		if (Month < 1 || Month > 12)
			return 0;

		short arrNumberOfDays[12] = {
			31, 28, 31, 30, 31, 30,
			31, 31, 30, 31, 30, 31
		};

		return (Month == 2) ?
			(LeapNotLeapYear(Year) ? 29 : 28) :
			arrNumberOfDays[Month - 1];
	}
	string MonthShortName(short Month) {
		string arrNameOfMonths[12] = {
			"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul",
			"Aug", "Sep", "Oct", "Nov", "Dec"
		};
		return arrNameOfMonths[Month - 1];
	}

	void PrintMonthCalender(short Year, short Month) {

		short NumberOfDays = NumberOfDaysInAMonth(Year, Month);

		short OrderOfFirstDayInMonthOfTheWeek = DayIndexInWeek(Year, Month, 1);

		printf("   __________________%s___________________\n\n", MonthShortName(Month).c_str());

		printf("   Sun   Mon   Tue   Wed   Thu   Fri   Sat\n");

		short i = 0;

		for (i = 0; i < OrderOfFirstDayInMonthOfTheWeek; i++)
			printf("      ");

		for (short j = 1; j <= NumberOfDays; j++) {
			printf("%6d", j);

			if (++i == 7) {
				i = 0;
				printf("\n");
			}
		}

		printf("\n   ________________________________________\n\n");
	}
	void PrintYearCalender(short Year) {
		printf("   ________________________________________\n\n");
		printf("                 Calender - %d\n", Year);
		printf("   ________________________________________\n\n");
		for (short i = 1; i <= 12; i++) {
			mydatetimelib::PrintMonthCalender(Year, i);
		}

	}
	short TotalDaysFromYearBeginning(short Year, short Month, short Day) {
		short CounterNumberOfDays = 0;
		for (short i = 1; i < Month; i++) {
			CounterNumberOfDays += mydatetimelib::NumberOfDaysInAMonth(Year, i);
		}
		CounterNumberOfDays += Day;
		return CounterNumberOfDays;
	}
	stDate GetDateFromDayOrderInYear(short Year, short DayOrderInYear) {
		stDate Date;
		Date.Year = Year;
		Date.Month = 1;
		short MonthDays = 0;
		short RemainingDays = DayOrderInYear;
		while (true) {
			MonthDays = mydatetimelib::NumberOfDaysInMonth(Year, Date.Month);
			if (RemainingDays > MonthDays) {
				RemainingDays -= MonthDays;
				Date.Month++;
			}
			else {
				Date.Day = RemainingDays;
				break;
			}
		}
		return Date;
	}
	stDate ReadFullDate() {
		stDate Date;
		Date.Day = myinputlib::ReadShortNumber("Please Enter a Day? ");
		cout << "\n\n";
		Date.Month = myinputlib::ReadShortNumber("Please Enter a Month? ");
		cout << "\n\n";
		Date.Year = myinputlib::ReadShortNumber("Please Enter a Year? ");
		cout << "\n\n";
		return Date;
	}
	stDate GetDateAfterAddingDays(stDate DateAfterAddingDays, int DaysToAdd) {
		int RemainingDays = DaysToAdd + mydatetimelib::TotalDaysFromYearBeginning(DateAfterAddingDays.Year,
			DateAfterAddingDays.Month, DateAfterAddingDays.Day);
		int MonthDays = 0;
		DateAfterAddingDays.Month = 1;
		while (true) {
			MonthDays = mydatetimelib::NumberOfDaysInAMonth(DateAfterAddingDays.Year, DateAfterAddingDays.Month);
			if (RemainingDays > MonthDays) {
				RemainingDays -= MonthDays;
				DateAfterAddingDays.Month++;
				if (DateAfterAddingDays.Month > 12) {
					DateAfterAddingDays.Month = 1;
					DateAfterAddingDays.Year++;
				}
			}
			else {
				DateAfterAddingDays.Day = RemainingDays;
				break;
			}

		}
		return DateAfterAddingDays;
	}

	bool IsDate1EqualToDate2(mydatetimelib::stDate Date1, mydatetimelib::stDate Date2) {

		return (Date1.Year == Date2.Year) ? ((Date1.Month == Date2.Month) ? ((Date1.Day == Date2.Day) ? true : false) : false) : false;
	}
	bool IsDate1BeforeDate2(mydatetimelib::stDate Date1, mydatetimelib::stDate Date2) {

		return (Date1.Year < Date2.Year) ? true : ((Date1.Year == Date2.Year) ? ((Date1.Month < Date2.Month) ? true : ((Date1.Month == Date2.Month) ? (Date1.Day < Date2.Day) : false)) : false);

	}
	bool IsLastDayInMonth(mydatetimelib::stDate Date) {
		return (Date.Day == mydatetimelib::NumberOfDaysInAMonth(Date.Year, Date.Month)) ? true : false;
	}
	bool IsLastMonthInYear(short Month) {
		return (Month == 12) ? true : false;
	}
	mydatetimelib::stDate IncreaseDateByOneDay(mydatetimelib::stDate DateAfterAddingOneDay) {

		if (mydatetimelib::IsLastDayInMonth(DateAfterAddingOneDay)) {

			if (mydatetimelib::IsLastMonthInYear(DateAfterAddingOneDay.Month)) {
				DateAfterAddingOneDay.Day = 1;
				DateAfterAddingOneDay.Month = 1;
				DateAfterAddingOneDay.Year++;
			}
			else {
				DateAfterAddingOneDay.Day = 1;
				DateAfterAddingOneDay.Month++;
			}

		}

		else
			DateAfterAddingOneDay.Day++;

		return DateAfterAddingOneDay;
	}
	void SwapDates(mydatetimelib::stDate& Date1, mydatetimelib::stDate& Date2) {
		mydatetimelib::stDate TempDate;
		TempDate = Date1;
		Date1 = Date2;
		Date2 = TempDate;
	}
	short GetDifferenceInDate(mydatetimelib::stDate Date1, mydatetimelib::stDate Date2, bool IncludeEndDay = false) {
		short DifferenceInDays = 0;
		short SwapValueFlag = 1;
		if (!(mydatetimelib::IsDate1BeforeDate2(Date1, Date2) || mydatetimelib::IsDate1EqualToDate2(Date1, Date2))) {
			SwapValueFlag = -1;
			SwapDates(Date1, Date2);
		}
		while (mydatetimelib::IsDate1BeforeDate2(Date1, Date2)) {
			DifferenceInDays++;
			Date1 = mydatetimelib::IncreaseDateByOneDay(Date1);
		}

		return (IncludeEndDay) ? ++DifferenceInDays * SwapValueFlag : DifferenceInDays * SwapValueFlag;
	}
	short PeriodLengthInDays(mydatetimelib::stPeriod& Period,bool IncludeEndDay = false) {
		return GetDifferenceInDate(Period.DateFrom,Period.DateTo,IncludeEndDay);
	}

	mydatetimelib::stDate GetSystemDate() {
		mydatetimelib::stDate Date;
		time_t t = time(0);
		tm* Timenow = localtime(&t);
		Date.Year = Timenow->tm_year + 1900;
		Date.Month = Timenow->tm_mon + 1;
		Date.Day = Timenow->tm_mday;
		return Date;
	}
	short ValidateLastDayInMonth(mydatetimelib::stDate Date) {
		short NumberOfDaysInCurrentMonth = mydatetimelib::NumberOfDaysInAMonth(Date.Year, Date.Month);

		return 	(Date.Day > NumberOfDaysInCurrentMonth) ? NumberOfDaysInCurrentMonth : Date.Day;
	}
	mydatetimelib::stDate IncreaseDateByXdays(short XdaysToAdd, mydatetimelib::stDate Date) {
		for (short i = 1; i <= XdaysToAdd; i++)
			Date = mydatetimelib::IncreaseDateByOneDay(Date);
		return Date;
	}
	mydatetimelib::stDate IncreaseDateByoneWeek(mydatetimelib::stDate Date) {

		for (short i = 1; i <= 7; i++)
			Date = mydatetimelib::IncreaseDateByOneDay(Date);

		return Date;
	}

	mydatetimelib::stDate IncreaseDateByXweeks(mydatetimelib::stDate Date, short XweeksToAdd) {
		for (short i = 1; i <= XweeksToAdd; i++)
			Date = IncreaseDateByoneWeek(Date);

		return Date;
	}

	mydatetimelib::stDate IncreaseDateByoneMonth(mydatetimelib::stDate Date) {
		if (Date.Month == 12) {
			Date.Month == 1;
			Date.Year++;
		}
		else
			Date.Month++;


		Date.Day = ValidateLastDayInMonth(Date);

		return Date;
	}

	mydatetimelib::stDate IncreaseDateByXmonths(mydatetimelib::stDate Date, short XmonthsToAdd) {

		for (short i = 1; i <= XmonthsToAdd; i++)
			Date = IncreaseDateByoneMonth(Date);

		return Date;
	}

	mydatetimelib::stDate IncreaseDateByOneYear(mydatetimelib::stDate Date) {

		Date.Year++;
		Date.Day = ValidateLastDayInMonth(Date);
		return Date;
	}

	mydatetimelib::stDate IncreaseDateByXyears(mydatetimelib::stDate Date, short XyearsToAdd) {
		for (short i = 1; i <= XyearsToAdd; i++)
			Date = IncreaseDateByOneYear(Date);

		return Date;
	}

	mydatetimelib::stDate IncreaseDateByXyearsFaster(mydatetimelib::stDate Date, short XyearsToAdd) {

		Date.Year += XyearsToAdd;
		Date.Day = ValidateLastDayInMonth(Date);
		return Date;
	}

	mydatetimelib::stDate IncreaseDateByOneDecade(mydatetimelib::stDate Date) {

		Date.Year += 10;
		Date.Day = ValidateLastDayInMonth(Date);
		return Date;
	}

	mydatetimelib::stDate IncreaseDateByXdecades(mydatetimelib::stDate Date, short XdecadesToAdd) {
		for (short i = 1; i <= XdecadesToAdd * 10; i++)
			Date = IncreaseDateByOneYear(Date);

		return Date;
	}

	mydatetimelib::stDate IncreaseDateByXdecadesFaster(mydatetimelib::stDate Date, short XdecadesToAdd) {

		Date.Year += XdecadesToAdd * 10;
		Date.Day = ValidateLastDayInMonth(Date);

		return Date;
	}

	mydatetimelib::stDate IncreaseDateByOneCentury(mydatetimelib::stDate Date) {
		Date.Year += 100;
		Date.Day = ValidateLastDayInMonth(Date);

		return Date;
	}

	mydatetimelib::stDate IncreaseDateByOneMillennium(mydatetimelib::stDate Date) {
		Date.Year += 1000;
		Date.Day = ValidateLastDayInMonth(Date);
		return Date;
	}
	bool IsFirstDayInMonth(short Day) {
		return (Day == 1) ? true : false;
	}
	bool IsFirstMonthInYear(short Month) {
		return (Month == 1) ? true : false;
	}
	mydatetimelib::stDate DecreaseDateByOneDay(mydatetimelib::stDate DateAfterAddingOneDay) {
		if (IsFirstDayInMonth(DateAfterAddingOneDay.Day)) {

			if (IsFirstMonthInYear(DateAfterAddingOneDay.Month)) {
				DateAfterAddingOneDay.Day = 31;
				DateAfterAddingOneDay.Month = 12;
				DateAfterAddingOneDay.Year--;
			}
			else {
				DateAfterAddingOneDay.Month--;
				DateAfterAddingOneDay.Day = mydatetimelib::NumberOfDaysInMonth(DateAfterAddingOneDay.Year, DateAfterAddingOneDay.Month);
			}

		}

		else
			DateAfterAddingOneDay.Day--;

		return DateAfterAddingOneDay;
	}
	mydatetimelib::stDate DecreaseDateByXdays(mydatetimelib::stDate Date, short XdaysToSubstract) {
		for (short i = 1; i <= XdaysToSubstract; i++)
			Date = DecreaseDateByOneDay(Date);

		return Date;
	}
	mydatetimelib::stDate DecreaseDateByoneWeek(mydatetimelib::stDate Date) {

		for (short i = 1; i <= 7; i++)
			Date = DecreaseDateByOneDay(Date);

		return Date;
	}

	mydatetimelib::stDate DecreaseDateByXweeks(mydatetimelib::stDate Date, short XweeksToSubstract) {
		for (short i = 1; i <= XweeksToSubstract; i++)
			Date = DecreaseDateByoneWeek(Date);

		return Date;
	}

	mydatetimelib::stDate DecreaseDateByoneMonth(mydatetimelib::stDate Date) {
		if (Date.Month == 1) {
			Date.Month == 12;
			Date.Year--;
		}
		else
			Date.Month--;


		Date.Day = mydatetimelib::ValidateLastDayInMonth(Date);

		return Date;
	}

	mydatetimelib::stDate DecreaseDateByXmonths(mydatetimelib::stDate Date, short XmonthsToSubstract) {

		for (short i = 1; i <= XmonthsToSubstract; i++)
			Date = DecreaseDateByoneMonth(Date);

		return Date;
	}

	mydatetimelib::stDate DecreaseDateByOneYear(mydatetimelib::stDate Date) {

		Date.Year--;
		Date.Day = mydatetimelib::ValidateLastDayInMonth(Date);
		return Date;
	}

	mydatetimelib::stDate DecreaseDateByXyears(mydatetimelib::stDate Date, short XyearsToSubstract) {
		for (short i = 1; i <= XyearsToSubstract; i++)
			Date = DecreaseDateByOneYear(Date);

		return Date;
	}

	mydatetimelib::stDate DecreaseDateByXyearsFaster(mydatetimelib::stDate Date, short XyearsToSubstract) {

		Date.Year -= XyearsToSubstract;
		Date.Day = mydatetimelib::ValidateLastDayInMonth(Date);
		return Date;
	}

	mydatetimelib::stDate DecreaseDateByOneDecade(mydatetimelib::stDate Date) {

		Date.Year -= 10;
		Date.Day = mydatetimelib::ValidateLastDayInMonth(Date);
		return Date;
	}

	mydatetimelib::stDate DecreaseDateByXdecades(mydatetimelib::stDate Date, short XdecadesToSubstract) {
		for (short i = 1; i <= XdecadesToSubstract * 10; i++)
			Date = DecreaseDateByOneYear(Date);

		return Date;
	}

	mydatetimelib::stDate DecreaseDateByXdecadesFaster(mydatetimelib::stDate Date, short XdecadesToSubstract) {

		Date.Year -= XdecadesToSubstract * 10;
		Date.Day = mydatetimelib::ValidateLastDayInMonth(Date);

		return Date;
	}

	mydatetimelib::stDate DecreaseDateByOneCentury(mydatetimelib::stDate Date) {
		Date.Year -= 100;
		Date.Day = mydatetimelib::ValidateLastDayInMonth(Date);

		return Date;
	}

	mydatetimelib::stDate DecreaseDateByOneMillennium(mydatetimelib::stDate Date) {
		Date.Year -= 1000;
		Date.Day = mydatetimelib::ValidateLastDayInMonth(Date);
		return Date;
	}
	bool IsEndOfWeek(mydatetimelib::stDate& Date) {

		short DayOrderInWeek = mydatetimelib::DayIndexInWeek(Date);
		return DayOrderInWeek == 6;

	}

	bool IsWeekEnd(mydatetimelib::stDate& Date) {

		short DayOrderInWeek = mydatetimelib::DayIndexInWeek(Date);
		return DayOrderInWeek == 5 || DayOrderInWeek == 6;

	}
	bool IsBusinessDay(mydatetimelib::stDate& Date) {

		return !IsWeekEnd(Date);

	}
	short DaysUntilTheEndOfWeek(mydatetimelib::stDate& Date) {
		return 6 - mydatetimelib::DayIndexInWeek(Date);
	}
	short DaysUntilTheEndOfMonth(mydatetimelib::stDate& Date) {
		mydatetimelib::stDate EndOfMonthDate;
		EndOfMonthDate.Day = mydatetimelib::NumberOfDaysInAMonth(Date.Year, Date.Month);
		EndOfMonthDate.Month = Date.Month;
		EndOfMonthDate.Year = Date.Year;
		return mydatetimelib::GetDifferenceInDate(Date, EndOfMonthDate, true);

	}
	short DaysUntilTheEndOfYear(mydatetimelib::stDate& Date) {
		mydatetimelib::stDate EndOfYearDate;
		EndOfYearDate.Day = 31;
		EndOfYearDate.Month = 12;
		EndOfYearDate.Year = Date.Year;
		return mydatetimelib::GetDifferenceInDate(Date, EndOfYearDate, true);
	}
	string GetDayNameOfSomeDate(mydatetimelib::stDate Date) {

		string DayNames[7] = { "Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday" };
		return DayNames[mydatetimelib::DayIndexInWeek(Date)];

	}
	void PrintDate(mydatetimelib::stDate Date, string Message) {
		printf("%s %s , %d/%d/%d\n\n", Message.c_str(), GetDayNameOfSomeDate(Date).c_str(), Date.Day, Date.Month, Date.Year);
	}
	short CalculateTheActualVacationDays(mydatetimelib::stDate VacationStartDate, mydatetimelib::stDate VacationEndDate) {

		short DaysCounter = 0;

		while (mydatetimelib::IsDate1BeforeDate2(VacationStartDate, VacationEndDate)) {

			if (mydatetimelib::IsBusinessDay(VacationStartDate))
				DaysCounter++;

			VacationStartDate = mydatetimelib::IncreaseDateByOneDay(VacationStartDate);

		}

		return DaysCounter;
	}
	mydatetimelib::stDate GetVacationEndDate(mydatetimelib::stDate& VacationStartDate, short VacationDays) {
		short WeekEndCounter = 0;

		while (mydatetimelib::IsWeekEnd(VacationStartDate))
			VacationStartDate = mydatetimelib::IncreaseDateByOneDay(VacationStartDate);

		for (short i = 1; i <= VacationDays + WeekEndCounter; i++) {

			if (mydatetimelib::IsWeekEnd(VacationStartDate))
				WeekEndCounter++;

			VacationStartDate = mydatetimelib::IncreaseDateByOneDay(VacationStartDate);
		}

		while (mydatetimelib::IsWeekEnd(VacationStartDate))
			VacationStartDate = mydatetimelib::IncreaseDateByOneDay(VacationStartDate);

		return VacationStartDate;
	}
	bool IsDate1AfterDate2(mydatetimelib::stDate& Date1, mydatetimelib::stDate& Date2) {
		return (!mydatetimelib::IsDate1BeforeDate2(Date1, Date2) && !mydatetimelib::IsDate1EqualToDate2(Date1, Date2));
	}
	
	enCompare2Dates CompareDates(mydatetimelib::stDate& Date1, mydatetimelib::stDate& Date2) {
		if (mydatetimelib::IsDate1BeforeDate2(Date1, Date2))
			return enCompare2Dates::Before;

		if (mydatetimelib::IsDate1EqualToDate2(Date1, Date2))
			return enCompare2Dates::Equal;

		return enCompare2Dates::After;
	}
	
	stPeriod ReadPeriod() {
		stPeriod Period;

		cout << "Enter Start Date:\n\n";
		Period.DateFrom = mydatetimelib::ReadFullDate();

		cout << "Enter End Date:\n\n";
		Period.DateTo = mydatetimelib::ReadFullDate();

		return Period;
	}
	bool AreOverlapPeriods(stPeriod& Period1, stPeriod& Period2) {
		if (
			mydatetimelib::CompareDates(Period2.DateTo, Period1.DateFrom) == mydatetimelib::enCompare2Dates::Before
			||
			mydatetimelib::CompareDates(Period2.DateFrom, Period1.DateTo) == mydatetimelib::enCompare2Dates::After
			)
			return false;

		return true;
	}
	bool IsDateInPeriod(mydatetimelib::stPeriod& Period, mydatetimelib::stDate& Date) {

		return !(mydatetimelib::CompareDates(Date, Period.DateTo) == mydatetimelib::enCompare2Dates::After
			||
			mydatetimelib::CompareDates(Date, Period.DateFrom) == mydatetimelib::enCompare2Dates::Before);

	}
	short CountOverlapDays(mydatetimelib::stPeriod& Period1, mydatetimelib::stPeriod& Period2) {

		short Period1Length = mydatetimelib::PeriodLengthInDays(Period1, true);
		short Period2Length = mydatetimelib::PeriodLengthInDays(Period2, true);

		short OverlapDays = 0;

		if (!mydatetimelib::AreOverlapPeriods(Period1, Period2))
			return 0;

		if (Period1Length < Period2Length) {

			while (mydatetimelib::IsDate1BeforeDate2(Period1.DateFrom, Period1.DateTo)) {

				if (mydatetimelib::IsDateInPeriod(Period2, Period1.DateFrom))
					OverlapDays++;

				Period1.DateFrom = mydatetimelib::IncreaseDateByOneDay(Period1.DateFrom);
			}
		}

		else {

			while (mydatetimelib::IsDate1BeforeDate2(Period2.DateFrom, Period2.DateTo)) {

				if (mydatetimelib::IsDateInPeriod(Period1, Period2.DateFrom))
					OverlapDays++;

				Period2.DateFrom = mydatetimelib::IncreaseDateByOneDay(Period2.DateFrom);
			}
		}

		return OverlapDays;
	}
	bool IsValideDate(mydatetimelib::stDate& Date) {

		if (Date.Day < 1 || Date.Day>31)
			return false;

		if (Date.Month < 1 || Date.Month>12)
			return false;

		if (Date.Month == 2) {
			if (mydatetimelib::LeapNotLeapYear(Date.Year)) {
				if (Date.Day > 29)
					return false;
			}
			else {
				if (Date.Day > 28)
					return false;
			}
		}

		short NumberOfDaysInCurrentMonth = mydatetimelib::NumberOfDaysInAMonth(Date.Year, Date.Month);

		if (Date.Day > NumberOfDaysInCurrentMonth)
			return false;

		return true;
	}
	mydatetimelib::stDate ConvertStringDateToDateStructure(string DateStr) {

		mydatetimelib::stDate Date;

		vector<string> vDateParts;
		vDateParts = mystringmanipulationlib::SplitString(DateStr, "/");

		Date.Day = (short)stoi(vDateParts[0]);
		Date.Month = (short)stoi(vDateParts[1]);
		Date.Year = (short)stoi(vDateParts[2]);
		return Date;
	}
	string ConvertDateStructureToStringDate(mydatetimelib::stDate& Date) {
		string DateText = "";
		DateText += to_string(Date.Day) + "/";
		DateText += to_string(Date.Month) + "/";
		DateText += to_string(Date.Year);
		return DateText;
	}
	string FormatDate(string DateText, string Format = "dd/mm/yyyy") {
		string FormattedDate = "";
		mydatetimelib::stDate Date = mydatetimelib::ConvertStringDateToDateStructure(DateText);
		FormattedDate = mystringmanipulationlib::ReplaceWordInStringUsingBuiltInFunction(Format, "dd", to_string(Date.Day));
		FormattedDate = mystringmanipulationlib::ReplaceWordInStringUsingBuiltInFunction(FormattedDate, "mm", to_string(Date.Month));
		FormattedDate = mystringmanipulationlib::ReplaceWordInStringUsingBuiltInFunction(FormattedDate, "yyyy", to_string(Date.Year));


		return FormattedDate;
	}
}