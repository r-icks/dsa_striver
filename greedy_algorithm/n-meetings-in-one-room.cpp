#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    class Meeting
    {
    public:
        int startTime;
        int endTime;

        Meeting(int startTime, int endTime)
        {
            this->startTime = startTime;
            this->endTime = endTime;
        }
    };

    bool static comparator(const Meeting &m1, const Meeting &m2)
    {
        if (m1.endTime < m2.endTime)
            return true;
        return false;
    }

    int maxMeetings(vector<int> &start, vector<int> &end)
    {
        vector<Meeting> meet;
        for (int i = 0; i < start.size(); i++)
        {
            meet.push_back(Meeting(start[i], end[i]));
        }
        sort(meet.begin(), meet.end(), comparator);
        int cur_time = -1;
        int count = 0;
        for (int i = 0; i < meet.size(); i++)
        {
            if (meet[i].startTime > cur_time)
            {
                count++;
                cur_time = meet[i].endTime;
            }
        }
        return count;
    }
};