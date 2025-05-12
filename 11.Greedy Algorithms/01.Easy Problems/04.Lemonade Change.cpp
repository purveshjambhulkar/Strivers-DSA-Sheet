class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int count5 = 0;
        int count10 = 0;

        for (int i : bills) {
            if (i == 5) {
                count5++;
            } else if (i == 10) {
                count10++;
                if (count5 >= 1) {
                    count5--;
                } else {
                    return false;
                }
            } else {
                if (count10 >= 1 && count5 >= 1) {
                    count10--;
                    count5--;
                } else if (count5 >= 3) {
                    count5 = count5 - 3;
                } else {
                    return false;
                }
            }
        }

        return true;
    }
};