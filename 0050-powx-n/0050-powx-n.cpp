class Solution {
public:

    double pow(double x, long long n){
        if(n == 0) return 1;

        double half = pow(x, n/2);
        if(n % 2 == 0) return half * half;
        else return x * half * half;
    }

    double myPow(double x, int n){
        long long i = n;

        if(i < 0) return 1/pow(x, -i);
        else return pow(x, i);
    }
};