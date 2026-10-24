class Solution {
public:
    int findDayOfYr(string date, vector<int>& cumMonthDays){
        int month = stoi(date.substr(0,2));
        int days = stoi(date.substr(3));

        return cumMonthDays[month-1]+days;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> monthDays = {31,28,31,30,31,30,31,31,30,31,30,31};
        vector<int> cumMonthDays(13, 0);
        cumMonthDays[1] = 31; //jan
        for(int i = 2; i<=12; i++){
            cumMonthDays[i] = cumMonthDays[i-1] + monthDays[i-1];
        }

        int arriveAlice_day = findDayOfYr(arriveAlice, cumMonthDays);
        int leaveAlice_day = findDayOfYr(leaveAlice, cumMonthDays);
        int arriveBob_day = findDayOfYr(arriveBob, cumMonthDays);
        int leaveBob_day = findDayOfYr(leaveBob, cumMonthDays);

        int overLapDays = min(leaveAlice_day, leaveBob_day) - max(arriveAlice_day, arriveBob_day) + 1;

        return overLapDays < 0 ? 0 : overLapDays;
    }
};