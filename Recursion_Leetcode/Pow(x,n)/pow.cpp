class Solution {
private:
    double fastpow(double x,long long n){
        //base case 
        if(n==0){
            return 1.0;
        }
        double half=fastpow(x,(n/2));
        if(n%2==0){
            return half*half;
        }
        else{
            return half*half*x;
        }
    };
public:
    double myPow(double x, int n) {
        long long power=n;
        //negative powers handling 
        if(power<0){
            power=-power;
            x=1.0/x;
        }
        return fastpow(x,power);
    }
};