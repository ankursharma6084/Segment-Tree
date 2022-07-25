#include<bits/stdc++.h>
using namespace std;

 // Don't let the worst get the best of you 

 vector<int> tree; 

 void buildTree(vector<int> &arr, int idx , int st , int end)
 {
    if(st == end)
    {
        tree[idx] = arr[st];
        return;
    }

    int mid = (st+end)>>1 ;
    buildTree(arr , 2*idx+1 ,st , mid);
    buildTree(arr , 2*idx+2 ,mid+1 , end);
    tree[idx] = tree[2*idx+1] + tree[2*idx+2] ; 
 }

 void update(vector<int> &arr, int idx , int st , int end, int val , int place)
 {
    if(st == end)
    {
        arr[place] = val ;
        tree[idx] = arr[st];
        return;
    }

    int mid = (st+end)>>1 ;
    if(place >= st && place <= mid)
    update(arr , 2*idx+1 ,st , mid , val , place);

    else
    update(arr , 2*idx+2 ,mid+1 , end , val , place);
    tree[idx] = tree[2*idx+1] + tree[2*idx+2] ; 
 }

 int query(int idx , int lq , int rq, int cl , int ch)
 {
    if(cl >= lq && ch <= rq)
    {
        return tree[idx] ;
    }

    if(ch < lq || cl > rq) return 0;

    int mid = (cl+ch)>>1 ;
    int l = query(2*idx+1 , lq , rq , cl , mid);
    int r = query(2*idx+2 , lq , rq , mid+1 , ch);
    return l+r ;
 }


 
int32_t main()  {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin>>n;
  int q; cin>>q;
  vector<int> arr(n);

  for(int i=0; i<n; i++)
      cin>>arr[i];

  tree.resize(4*n);

  buildTree(arr , 0 , 0 , n-1) ;
  
  while(q--)
  {
      int type; cin>>type;
      int l , r ; cin>>l>>r ;
 
      if(type == 2)
      {
         l-- , r-- ;
         int ans = query(0 , l , r , 0 , n-1) ;
         cout<<ans<<endl;
      }

      else{
         l--;
         update(arr , 0 , 0 , n-1 , r , l);
      }
  }
 
return 0;
}
