#pragma GCC optimize("O3, unroll-loops")
int countOdds(int low, int high){
    return (high+(high&1)-low+(low&1))>>1;
}