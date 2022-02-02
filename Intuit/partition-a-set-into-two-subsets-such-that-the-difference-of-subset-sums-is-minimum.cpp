#include <bits/stdc++.h>

using namespace std;

int minDifference(int arr[], int n)
{
    int range = 0;
    for (int i = 0; i < n; i++)
    {
        range += arr[i];
    }
    bool dp[n + 1][range + 1];

    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < range + 1; j++)
        {
            if (i == 0)
                dp[i][j] = false;
            if (j == 0)
                dp[i][j] = true;
        }
    }
   
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= range; j++)
        {
            if (arr[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
   
    int ans = INT_MAX;
    for (int i = 0; i <= range / 2; i++)
    {
        if (dp[n][i] == true && ans > abs(i - (range - i)))
        {
            ans = abs(i - (range - i));
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int res = minDifference(arr, n);

    cout << res << endl;

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

bool dfs(vector<vector<char>> &board, string word, int i, int j, int pos)
{
    int m = board.size();
    int n = board[0].size();
    if (i < 0 || j < 0 || i >= m || j >= n)
        return false;
    if (pos == word.length())
        return true;
    if (word[pos] == board[i][j])
    {
        char temp = board[i][j];
        board[i][j] = '#';
        bool a = dfs(board, word, i + 1, j, pos + 1);
        bool b = dfs(board, word, i - 1, j, pos + 1);
        bool c = dfs(board, word, i, j + 1, pos + 1);
        bool d = dfs(board, word, i, j - 1, pos + 1);
        board[i][j] = temp;
        return a || b || c || d;
    }
    else
        return false;
}
bool isWordExist(vector<vector<char>> &board, string word)
{
    // Code here
    int m = board.size();
    int n = board[0].size();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == word[0])
            {
                if (dfs(board, word, i, j, 0))
                    return true;
            }
        }
    }
    return false;
}

int main()
{
    int n,m;
    cin >> n>>m;

    vector<vector<char>>board(n , vector<char>(m ,'*'));
    for (int i = 0; i < n; i++){
        for(int j =0 ; j<m ; j++){
            cin>>board[i][j];
        }
    }
    string word;
    cin>>word;  

    bool res = isWordExist(board , word);

    if(res)
    cout<<1<<endl;
    else
    cout<<0<<endl;
    

    return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int MAX_DIGITS = 6;
 
int getValue(const string& str, int i, int m)
{
    if (i + m > str.length())
        return -1;

    int value = 0;
    for (int j = 0; j < m; j++)
    {
        int c = str[i + j] - '0';
        if (c < 0 || c > 9)
            return -1;
        value = value * 10 + c;
    }
    return value;
}
 

int findMissingNumber(const string& str)
{
  
    for (int m=1; m<=MAX_DIGITS; ++m)
    {
        
        int n = getValue(str, 0, m);
        if (n == -1)
           break;
 
       
        int missingNo = -1;
 
       
        bool fail = false;
 
       
        for (int i=m; i!=str.length(); i += 1 + log10l(n))
        {
            if ((missingNo == -1) &&
                (getValue(str, i, 1+log10l(n+2)) == n+2))
            {
                missingNo = n + 1;
                n += 2;
            }
            else if (getValue(str, i, 1+log10l(n+1)) == n+1)
                n++;
 
            else
            {
                fail = true;
                break;
            }
        }
 
        if (!fail)
          return missingNo;
    }
    return -1; 
}
 
int main()
{
    int t;
    cin>>t;

    while(t--){
    string s;
    cin>>s;

    int res = findMissingNumber(s);

    cout<<res<<endl;
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

void helper(string s, string &res, int k, int ind)
{
    if (k == 0)
        return;
    if (ind == s.length())
        return;
    int chk = s[ind] - '0';
    int j = -1;
    for (int i = ind + 1; i < s.length(); i++)
    {
        if (chk < s[i] - '0')
        {
            chk = s[i] - '0';
        }
    }
    if (chk != s[ind] - '0')
    {
        k--;
    }
    for (int i = s.length() - 1; i >= ind; i--)
    {
        if (s[i] - '0' == chk)
        {
            swap(s[ind], s[i]);
            res = max(res, s);
            helper(s, res, k, ind + 1);
            swap(s[ind], s[i]);
        }
    }
}
string findMaximumNum(string str, int k)
{
    // code here.
    string res = str;
    helper(str, res, k, 0);
    return res;
}

int main()
{
    int t;
    cin >> t;

    string s;
    cin >> s;

    string res = findMaximumNum(s, t);

    cout << res << endl;

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int splitArray(vector<int> &a, int m)
{
    int n = a.size();
    int sum = 0;
    for (auto t : a)
        sum += t;

    int l = a[0];
    int r = sum;

    for (int i = 1; i < a.size(); i++)
        l = max(l, a[i]);
    int ans = INT_MAX;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        int t = 0;
        int c = 0;
        int s = 0;
        for (int i = 0; i < n; i++)
        {
            s += a[i];
            if (s > mid)
            {
                c++;
                s = a[i];
            }
        }
        if (s > 0)
            c++;
        if (c <= m)
        {

            ans = min(ans, mid);
            r = mid - 1;
        }
        else if (c > m)
            l = mid + 1;
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    int m;
    cin >> m;

    int res = splitArray(a, m);

    cout << res << endl;

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int findInMountainArray(int target, vector<int>&m) {
        int l=1;int r=m.size()-1;
int t=-1;

    while(l<=r)
    {
      int mid=(l+r)/2;
      int idx=m[mid];
      int idxl=m[mid-1];
      int idxr=m[mid+1];
      if(idx>idxl&&idx>idxr)
      {
        t=mid;
        break;
      }
      else if(idxr>idx&&idx>idxl)
        l=mid+1;
      else if(idxr<idx&&idx<idxl)
        r=mid-1;

    }

    l=0;r=t;

    while(l<=r)
    {
      int mid=(l+r)/2;
      int x=m[mid];
      if(x==target)
      {
        return mid;
      }
      else if(x<target)
        l=mid+1;
      else
        r=mid-1;
    }

    l=t;r=m.size()-1;

    while(l<=r)
    {
      int mid=(l+r)/2;
      int x=m[mid];
      if(x==target)
      {
        return mid;
      }
      else if(x<target)
        r=mid-1;
      else
        l=mid+1;
    }
    return -1;

    }

    int main()
{
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    int target;
    cin >> target;

    int res = findInMountainArray(target ,a);

    cout << res << endl;

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

  int shipWithinDays(vector<int>& weights, int days) {
          int sum = 0;
        int maxWeight = 0;
        for (auto& w : weights) {
            sum += w;
            maxWeight = max(w, maxWeight);
        }
        int minNeed = maxWeight, maxNeed = sum;
        while (minNeed < maxNeed) {
            int mid = (minNeed + maxNeed) / 2;
            int ship = 0, load = 0;
            for (auto& w : weights) {
    
                if (mid - load >= w) {
                    load += w;
                } else {
                    
                    ship++;
                   
                    if (ship == days) {
                        break;
                    }
                    load = w;
                }
            }
  
            if (ship < days) {
                maxNeed = mid;
            } else {
                
                minNeed = mid + 1;
            }
        }
        return minNeed;
    }


int main()
{
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    int days;
    cin >> days;

    int res = shipWithinDays(a,days);

    cout << res << endl;

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

 int numberOfBoomerangs(vector<vector<int>>& points) {
        int n = points.size();
if(n==1) return 0;

    int ans = 0;
    unordered_map<int,int> checkBoomerang; 
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j) continue; 
            int x = (points[i][0] - points[j][0])*(points[i][0] - points[j][0]);
            int y = (points[i][1] - points[j][1])*(points[i][1] - points[j][1]);
            int distance = x + y;
            checkBoomerang[distance]++;
        }
    
        for(auto &it : checkBoomerang){
            int totalBoomerangs = it.second;  
            ans += totalBoomerangs*(totalBoomerangs-1); 
        }
        checkBoomerang.clear(); 
    }
    return ans;
    }

int main()
{
    int n;
    cin>>n;
     vector<vector<int>>v(n , vector<int>(2 ,0));
    for (int i = 0; i < n; i++){
        for(int j =0 ; j<2 ; j++){
            cin>>v[i][j];
        }
    }
    
    int res = numberOfBoomerangs(v);

    cout << res << endl;

    return 0;
}    
#include <bits/stdc++.h>

using namespace std;

void solve(int i, int j, int m, int n, vector<vector<int>> &h, vector<vector<int>> &temp, int prev)
{
    if (i < 0 || j < 0 || i >= m || j >= n || temp[i][j] != -1 || h[i][j] < prev)
    {
        return;
    }
    temp[i][j] = 1;
    solve(i + 1, j, m, n, h, temp, h[i][j]);
    solve(i - 1, j, m, n, h, temp, h[i][j]);
    solve(i, j + 1, m, n, h, temp, h[i][j]);
    solve(i, j - 1, m, n, h, temp, h[i][j]);
}

vector<vector<int>> pacificAtlantic(vector<vector<int>> &h)
{

    int m = h.size();
    int n = h[0].size();
    vector<vector<int>> temp1(m, vector<int>(n, -1));
    for (int i = 0; i < n; i++)
    {
        solve(0, i, m, n, h, temp1, -1);
    }
    for (int i = 0; i < m; i++)
    {
        solve(i, 0, m, n, h, temp1, -1);
    }
    vector<vector<int>> temp2(m, vector<int>(n, -1));
    for (int i = 0; i < n; i++)
    {
        solve(m - 1, i, m, n, h, temp2, -1);
    }
    for (int i = 0; i < m; i++)
    {
        solve(i, n - 1, m, n, h, temp2, -1);
    }
    vector<vector<int>> re;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (temp1[i][j] == 1 && temp2[i][j] == 1)
            {
                re.push_back({i, j});
            }
        }
    }
    return re;
}

int main()
{
    int n;
    cin >> n;
    int m;
    cin>>m;
    vector<vector<int>> v(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }

    vector<vector<int>> res = pacificAtlantic(v);

      for (int i = 0; i < res.size(); i++)
    {
        for (int j = 0; j < res[i].size(); j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;

    }

    return 0;
}



#include <bits/stdc++.h>

using namespace std;

    void dfs(vector<vector<int>>& isConnected, int i,int j){
        isConnected[i][j] = 0;
        for(int x=0;x<isConnected.size();x++){
            if(isConnected[j][x]==1){dfs(isConnected,j,x);}
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int maxp=0;
        vector<int> vis(isConnected[0].size(),0);
        for(int i=0;i<isConnected.size();i++){
            for(auto j=0;j<isConnected[0].size();j++){
                if(isConnected[i][j]==1){
                    maxp++;
                    dfs(isConnected,i,j);
                }
            }
        }
        return maxp;
    }

 int main()
{
    int n;
    cin >> n;
    int m;
    cin>>m;
    vector<vector<int>> v(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }

    int res = findCircleNum(v);

     cout<<res<<endl;

    return 0;
}   


/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    vector<vector<int>> area,Grid;
    
    Node* buildTree(int rs,int re,int cs,int ce){
        if(rs==re || cs==ce){
            Node *n = new Node(Grid[rs-1][cs-1],true);
            return n;
        }
        int a = area[re][ce]-area[re][cs-1]-area[rs-1][ce]+area[rs-1][cs-1];
        if(a==0 || a==(re-rs+1)*(ce-cs+1)){
            Node *n = new Node(a>0,true);
            return n;
        }
        int midrow = rs+(re-rs)/2;
        int midcol = cs + (ce-cs)/2;
        Node *n = new Node(0,false);
        n->topLeft = buildTree(rs,midrow,cs,midcol);
        n->topRight = buildTree(rs,midrow,midcol+1,ce);
        n->bottomLeft = buildTree(midrow+1,re,cs,midcol);
        n->bottomRight = buildTree(midrow+1,re,midcol+1,ce);
        return n;
    }
    
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        Grid=grid;
        area.clear();
        for(int i=0;i<n+1;i++){
            vector<int> tmp(n+1,0);
            area.push_back(tmp);
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==1 && j==1)
                    area[i][j]=grid[i-1][j-1];
                else if(i==1)
                    area[i][j]=grid[i-1][j-1]+area[i][j-1];
                else if(j==1)
                    area[i][j]=grid[i-1][j-1]+area[i-1][j];
                else
                    area[i][j]=grid[i-1][j-1]+area[i][j-1]+area[i-1][j]-area[i-1][j-1];
            }
        }
        return buildTree(1,n,1,n);
        
    }
};
#include <bits/stdc++.h>

using namespace std;

vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);
        for(vector<int>& arr: pre){
            graph[arr[1]].push_back(arr[0]);
            indegree[arr[0]]++;
        }
        queue<int> kyu;
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0) kyu.push(i);
        }
        
        vector<int> ans;
        while(kyu.size() != 0){
            int vtx = kyu.front();
            kyu.pop();
            ans.push_back(vtx);
            for(int nbr : graph[vtx]){
                if(--indegree[nbr] == 0) kyu.push(nbr);
            }
        }
        if(ans.size() != n) return {};
        return ans;
    }

int main()
{
    int n;
    cin >> n;
    int m;
    cin>>m;
    vector<vector<int>> v(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }

    int pre ; 
    cin>>pre;
    vector<int> res = findOrder(pre ,v);

    for (int i = 0; i < res.size(); i++)
    {
            cout<<res[i]<<" ";

    }

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int minSwaps(vector<vector<int>>& grid){
        int n = grid.size();
        int ans = 0;
        vector<int> t;
        
        for(int i=0;i<n;i++){
            int zero = 0;
            for(int j=n-1;j>=0;j--){
                if(grid[i][j]) break;
                zero++;
            }
            t.push_back(zero);
        }
        
 
        for(int i=0;i<n;i++){
            
            int curr = i;
            int req = n - 1 - i; 
            
            while(curr < n and t[curr] < req) curr++;
            
            if(curr == n) return -1;
            
            ans += curr - i;
            
            while(curr > 0){
                t[curr] = t[curr - 1];
                curr--;
            }
            
        }
        
        return ans;
    }


int main()
{
    int n;
    cin >> n;
    int m;
    cin>>m;
    vector<vector<int>> v(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }

    int res = minSwaps(v);

    cout<<res<<endl;

    return 0;
}



#include <bits/stdc++.h>

using namespace std;

 int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int,pair<int,int>>> q;
        int n = grid.size();
        int zerocount = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1) q.push({0,{i,j}});
                else{
                    zerocount++;
                    grid[i][j] = INT_MAX;
                }
            }
        }
        
        if(q.empty() || zerocount == 0) return -1;
        int arr[5] = {0,1,0,-1,0};
        
        int ans=0;
        
        while(!q.empty()){
            auto top = q.front(); q.pop();
            int curr_dist = top.first;
            int x = top.second.first;
            int y = top.second.second;
            
            for(int i=0;i<4;i++){
                int xnew = x+arr[i];
                int ynew = y+arr[i+1];
                
                if(xnew>=0 && xnew<n && ynew>=0 && ynew<n && grid[xnew][ynew]>curr_dist+1){
                    grid[xnew][ynew]=curr_dist+1;
                    q.push({curr_dist+1,{xnew,ynew}});
                    ans = max(ans,grid[xnew][ynew]);
                }
            }
        }
        
        return ans; 
    }

int main()
{
    int n;
    cin >> n;
    int m;
    cin>>m;
    vector<vector<int>> v(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }

    int res = maxDistance(v);

    cout<<res<<endl;

    return 0;
}



#include <bits/stdc++.h>

using namespace std;

 int minEatingSpeed(vector<int>& piles, int H) {
        int low = 1, high = 1000000000, k = 0;
        while (low <= high) {
            k = (low + high) / 2;
            int h = 0;
            for (int i = 0; i < piles.size(); i ++) 
                h += ceil(1.0 * piles[i] / k);
            if (h > H)
                low = k + 1;
            else
                high = k - 1;
        }
        return low;
    }


int main()
{
    int n;
    cin >> n;
   
    vector<int>v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }

    int h;
    cin>>h;

    int res = minEatingSpeed(v,h);

    cout<<res<<endl;

    return 0;
}
