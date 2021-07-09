/*   __               (\_/)
  ._( .)<(MEOW) (WOOF)('V')
   \____)             (U U)
*/
#include <bits/stdc++.h>
#define name "gss" //pls dont forget your task's name
#define inf 0x3f3f
#define maxn int(5e4) + 54
#define pri_q priority_queue
#define pf push_front
#define pb push_back
#define popb pop_back
#define popf pop_front
#define fi first
#define se second
#define cut cout << endl
#define boost() ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)
#define Fin(name) freopen(name ".inp", "r", stdin)
#define Fout(name) freopen(name ".out", "w", stdout)
#define forup(type, i, start, stop) for (type i = (type)(start), i##_end = static_cast<decltype(i)>(stop); i <= i##_end; ++i)
#define fordown(type, i, start, stop) for (type i = (type)(start), i##_end = static_cast<decltype(i)>(stop); i >= i##_end; --i)
#define allVi(x) x.begin(), x.end()
#define allArr(x, start, end) x, x + begin, x + end + begin

typedef long long ll;
typedef unsigned long long ull;
int a[maxn] = {};

const void IO()
{
    Fin(name);
    Fout(name);
}
using namespace std;
struct Node
{
    int maxPrefixSum;
    int maxSuffixSum;
    int totalSum;
    int maxSubarraySum;
    Node()
    {
        maxPrefixSum = maxSuffixSum = maxSubarraySum = -inf;
        totalSum = -inf;
    }
};

Node merge(Node leftChild, Node rightChild)
{
    Node nodeCha;
    nodeCha.maxPrefixSum = max(leftChild.maxPrefixSum, leftChild.totalSum + rightChild.maxPrefixSum);
    nodeCha.maxSuffixSum = max(rightChild.maxSuffixSum, rightChild.totalSum + leftChild.maxSuffixSum);
    nodeCha.totalSum = leftChild.totalSum + rightChild.totalSum;
    nodeCha.maxSubarraySum = max({leftChild.maxSubarraySum, rightChild.maxSubarraySum, leftChild.maxSuffixSum + rightChild.maxPrefixSum});
    return nodeCha;
}

void taoSubTree(Node *tree, int start, int end, int tro)
{
    if (start == end)
    {
        tree[tro].totalSum = a[start];
        tree[tro].maxSuffixSum = a[start];
        tree[tro].maxPrefixSum = a[start];
        tree[tro].maxSubarraySum = a[start];
        return;
    }
    int mid = (start + (end - start) / 2);
    taoSubTree(tree, start, mid, 2 * tro);
    taoSubTree(tree, mid + 1, end, 2 * tro + 1);
    tree[tro] = merge(tree[2 * tro], tree[2 * tro + 1]);
}

Node calQuery(Node *tree, int begin, int end, int qL, int qR, int tro)
{
    if (begin > qR || end < qL)
    {
        Node nullNode;
        return nullNode;
    }
    if (begin >= qL && end <= qR)
    {
        return tree[tro];
    }
    int mid = (begin + (end - begin) / 2);
    Node left = calQuery(tree, begin, mid, qL, qR, 2 * tro);
    Node right = calQuery(tree, mid + 1, end, qL, qR, 2 * tro + 1);
    Node res = merge(left, right);
    return res;
}

int query(Node *tree, int start, int end, int n)
{
    Node res = calQuery(tree, 1, n, start, end, 1);
    return res.maxSubarraySum;
}

Node *tree = new Node[int(5e4) * 4];
int main()
{
    boost();
#ifndef ONLINE_JUDGE
    IO();
#endif
    int n(0);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    taoSubTree(tree, 0, n - 1, 1);
    int t(0);
    cin >> t;
    while (t--)
    {
        int l(0), r(0);
        cin >> l >> r;
        cout << query(tree, l, r, n) << endl;
    }
    return 0;
}