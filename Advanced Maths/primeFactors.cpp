// TC : O(N), SC : O(N)
class Solution {
	public:
	vector<int> AllPrimeFactors(int N) {
	    vector<int> fctrs;
	    for(int i = 2; i <= N; i++) {
	        if(N % i == 0) {
	            fctrs.push_back(i);
	            while(N % i == 0)
	                N = N / i;
	        }
	    }
	    return fctrs;
	}
};
