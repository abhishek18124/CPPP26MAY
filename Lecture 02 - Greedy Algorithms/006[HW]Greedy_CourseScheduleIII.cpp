/*

https://leetcode.com/problems/course-schedule-iii/

*/

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {

        sort(courses.begin(), courses.end(),
        [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        int ans = 0;
        int clock = 0;
        priority_queue<int> maxHeap;

        for (auto course : courses) {
            int duration = course[0];
            int deadline = course[1];
            if (clock + duration <= deadline) {
                // do the current course
                clock += duration;
                maxHeap.push(duration);
                ans++;
            } else {
                if (!maxHeap.empty() and maxHeap.top() > duration) {
                    // replace previously done course with maximum duration with current course
                    clock -= maxHeap.top();
                    maxHeap.pop();
                    clock += duration;
                    maxHeap.push(duration);
                }
            }
        }
        return ans;
    }
};