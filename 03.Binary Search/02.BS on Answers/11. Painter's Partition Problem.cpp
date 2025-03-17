
int solve(vector<int> &boards, int k , int mid){
    int stud = 1;
    int pages = 0;

    for(int i : boards){
        if(pages + i <= mid){
            pages+=i;
        } else{
            stud++;
            pages= i;
        }
    }

    return stud;
}

int findLargestMinDistance(vector<int> &boards, int k)
{
    //    Write your code here.

    int left = *max_element(boards.begin() , boards.end());
    int right = accumulate(boards.begin() , boards.end() , 0);
    int ans;

    while (left <= right) {
                int mid = left + (right - left) / 2;
    
                int stud = solve(boards, k, mid);
    
                if (stud <= k) {
                    ans = mid;
                    right = mid - 1;
                } else if (stud > k) {
                    left = mid + 1;
                }
            }
            return ans;
}