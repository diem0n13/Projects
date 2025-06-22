
namespace CreateFolder.TimeCalc
{
    internal class TimeCalc
    {
        const int Mins_per_hr = 60;
        public TimeCalc()
        {
            Timer day1 = new Timer(){mins= 45,hours= 5 }; 
            Timer day2 = new Timer() { mins = 55, hours = 4 }; 
            Timer trip = sum(day1, day2);
        }

        Timer sum(Timer t1, Timer t2)
        {
            Timer total;
            total.mins = (t1.mins + t2.mins) % Mins_per_hr;
            total.hours = t1.hours + t2.hours + (t1.mins + t2.mins) / Mins_per_hr;
            //100 ÷ 60 = 1 (целая часть), остаток = 100 - (60 * 1) = 40
            return total;
        }
    }
}
