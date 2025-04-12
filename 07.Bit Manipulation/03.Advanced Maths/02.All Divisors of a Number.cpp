int* printDivisors(int n, int &size) {

    //Approach 2 - Optimised - O(sqrt(n))
    vector<int> temp;

    //instead of using sqrt function STL we can use below method for looping condition

    for (int i = 1; i * i <= n; i++) {
        if (n%i == 0 ) {
            temp.push_back(i);
            if(i != n/i){
                temp.push_back(n/i);
            }
        }
    }
    // for (int i = 1; i <= sqrt(n); i++) {
    //     if (n%i == 0 ) {
    //         temp.push_back(i);
    //         if(i != n/i){
    //             temp.push_back(n/i);
    //         }
    //     }
    // }
    // temp.push_back(n);
    sort(temp.begin() , temp.end());
    size = temp.size();
    int* result = new int[size];
    for (int i = 0; i < size; i++) {
        result[i] = temp[i];
    }

    return result;


    //Approach 1- Brute force O(n/2)
    // vector<int> temp;

    // for (int i = 1; i <= n/2; i++) {
    //     if (n%i == 0 ) {
    //         temp.push_back(i);
    //     }
    // }
    // temp.push_back(n);
    // sort(temp.begin() , temp.end());
    // size = temp.size();
    // int* result = new int[size];
    // for (int i = 0; i < size; i++) {
    //     result[i] = temp[i];
    // }

    // return result;
}
