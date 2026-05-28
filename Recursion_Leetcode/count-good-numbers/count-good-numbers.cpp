class Solution {
private:
    int MOD=1e9+7;
    long long fastpow(long long base, long long power){
        if(power==0){
            return 1;
        }
        long long half=fastpow(base,power/2);
        long long half_squared = (half * half) % MOD;

        if (power % 2 == 0) {
            return half_squared;
        } else {
            return (half_squared * base) % MOD;
        }
    }
public:
    int countGoodNumbers(long long n) {
        long long event_ind=(n+1)/2;
        long long odd_ind=n/2;

        long long even_choise=fastpow(5,event_ind);
        long long odd_choise=fastpow(4,odd_ind);

        int ans =(even_choise*odd_choise)% MOD;
        return ans;
    }
};