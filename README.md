# Segment-Tree
CSES Problem Max Range query and update in segment tree

```

Given an array of n integers, your task is to process q queries of the following types:
update the value at position k to u
what is the sum of values in range [a,b]?
Input

The first input line has two integers n and q: the number of values and queries.

The second line has n integers x1,x2,…,xn: the array values.

Finally, there are q lines describing the queries. Each line has three integers: either "1 k u" or "2 a b".

Output

Print the result of each query of type 2.

Constraints
1≤n,q≤2⋅105
1≤xi,u≤109
1≤k≤n
1≤a≤b≤n
Example

Input:
8 4
3 2 4 5 1 1 5 3
2 1 4
2 5 6
1 3 1
2 1 4

Output:
14
2
11

```

BUILD

```
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
 
 ```

UPDATE

```

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
 
 ```

QUERY

```

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
