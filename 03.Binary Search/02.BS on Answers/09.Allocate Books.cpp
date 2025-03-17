int solve(vector<int>& arr, int n, int m,int mid ){
    int stud = 1;
    int pages = 0;

    for(int i : arr){
        if(pages + i <= mid){
            pages+=i;
        } else{
            stud++;
            pages= i;
        }
    }

    return stud;
}

int findPages(vector<int>& arr, int n, int m) {
    // Write your code here.
    if(n < m)
    {
        return -1;
    }

    int left = *max_element(arr.begin() , arr.end());
    int right = accumulate(arr.begin() , arr.end() , 0);
    int ans;

    while(left <= right){
        int mid = left + (right - left) /2;

        int stud = solve(arr, n , m, mid);
        
        if(stud <= m){
            ans = mid;
            right = mid -1 ;
        }else if (stud > m){
            left = mid + 1;
        }


            }
            return ans;


}