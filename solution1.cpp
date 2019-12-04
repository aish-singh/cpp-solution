#include <bits/stdc++.h>
using namespace std;
#define ll int64_t

int dp[1 << 20][2]; 
int solve1(int leftmask, bool turn, ll arr[], int& n) 
{ 
    if (!leftmask) 
        return 0; 
  
    int& res = dp[leftmask][turn];  
    if (~res) 
        return res; 
    int rightmask = ((1 << n) - 1) ^ leftmask; 
    if (turn == 1) { 
        int minRow = INT_MAX, person; 
        for (int i = 0; i < n; ++i) { 
            if (rightmask & (1 << i)) { 
                if (minRow > arr[i]) { 
                    person = i; 
                    minRow = arr[i]; 
                } 
            } 
        } 
        res = arr[person] + solve1(leftmask | (1 << person), 
                                        turn ^ 1, arr, n); 
    } 
    else { 
        if (__builtin_popcount(leftmask) == 1) { 
            for (int i = 0; i < n; ++i) { 
                if (leftmask & (1 << i)) { 
                    res = arr[i]; 
                    break; 
                } 
            } 
        } 
        else { 
  
             
            res = INT_MAX; 
            for (int i = 0; i < n; ++i) { 
                if (!(leftmask & (1 << i))) 
                    continue; 
  
                for (int j = i + 1; j < n; ++j) { 
                    if (leftmask & (1 << j)) { 
                        int val = max(arr[i], arr[j]); 
                        val += solve1(leftmask ^ (1 << i) ^ (1 << j), 
                                                       turn ^ 1, arr, n); 
                        res = min(res, val); 
                    } 
                } 
            } 
        } 
    } 
    return res; 
} 
int solve(ll arr[], int n) 
{  
    int mask = (1 << n) - 1; 
    memset(dp, -1, sizeof(dp)); 
  
    return solve1(mask, 0, arr, n); 
}
int main()
{
        ll t;
        cin >> t;
        while(t--)
        {
                ll n;
                cin >> n;
                ll arr[n];
                for(ll i = 0; i < n ; i++)
                {
                        cin >> arr[i];
                }
                cout << solve(arr,n) << "\n";
        }
    return 0;
}
