#include <iostream>
using namespace std;

const int LEN = 111;
//数据结构
typedef struct {
    int num[LEN];
    int len;
    int exp;
}Node;
//切分

void cup(Node& src, Node& des, int st, int l) {
    int i, j;
    for (i = st, j = 0; i < st + l; i++, j++)
        des.num[j] = src.num[i];
    des.exp = src.exp + st;
    des.len = l;
}

//相加
void add(Node& a, Node& b, Node & ans) {
    if (a.exp < b.exp)
        swap(a,b);

    ans.exp = b.exp;
    int k = a.exp - b.exp;
    int ta, tb;
    int cc = 0;
    int i;
    int len;
    int alen = a.exp + a.len;
    int blen = b.exp + b.len;

    if (alen > blen)
        len = alen;
    else
        len = blen;
    len -= ans.exp;
    for (i = 0; i < len; i++){
        if (i < k || i >= k + a.len)
            ta = 0;
        else
            ta = a.num[i-k];
        if (i < b.len)
            tb = b.num[i];
        else
            tb = 0;
        ans.num[i] = (ta + tb + cc) % 10;
        cc = (ta + tb + cc) / 10;
    }
    if (cc)
        ans.num[i++] = cc;
    ans.len = i;
}

//相乘
void mul(Node& a, Node& b, Node& ans) {
    int ma = a.len / 2;
    int mb = b.len / 2;
    if (!ma || !mb) {
        if(!ma) {
//            swap(a,b);
Node& t = a;
a = b;
b = t;
        }
        int cc = 0;
        int w = b.num[0];
        ans.exp = a.exp + b.exp;

        int i;
        for (i = 0; i < a.len; i++) {
            ans.num[i] = (cc + a.num[i] * w) % 10;
            cc = (cc + a.num[i] * w) / 10;
        }
        if (cc)
            ans.num[i++] = cc;
        ans.len = i;
    }else {
        Node t1, t2, t3, t4, t5;
        Node ah, al, bh, bl;
        cup(a, ah, ma, a.len - ma);
        cup(a, al, 0, ma);
        cup(b, bh, mb, b.len - mb);
        cup(b, bl, 0, mb);

        mul(ah, bh, t1);
        mul(ah, bl, t2);
        mul(al, bh, t3);
        mul(al, bl, t4);

        add(t3, t4, ans);
        add(t2, ans, t5);
        add(t1, t5, ans);
    }
}
/*
//  大数乘法
const int M = 10000;
typedef struct Node {
    int s[M];
    int l;
    int c;
}Node, *pNode;

char sa[M], sb[M];

void cp(pNode src, pNode des, int st, int l) {
    int i, j;
    for (i = st, j = 0; i < st + l; i++, j++)
        des->s[j] = src->s[i];
    des->l = l;
    des->c = st + src->c;
}


void add(pNode pa, pNode pb, pNode ans) {

    if (pa->c < pb->c) {
        pNode temp = pa;
        pa = pb;
        pb = temp;
    }
    ans->c = pb->c;
    int cc = 0;
    int k = pa->c - pb->c;
    int alen = pa->c + pa->l;
    int blen = pb->c + pb->l;
    int len;
    if (alen > blen)
        len = alen;
    else
        len = blen;
    len -= pb->c;
    int i;
    for (i = 0; i < len; i++) {
        int ta, tb;
        if (i < k || i >= k + pa->l)
            ta = 0;
        else
            ta = pa->s[i - k];
        if (i < pb->l)
            tb = pb->s[i];
        else
            tb = 0;
        ans->s[i] = (ta + tb + cc) % 10;
        cc = (ta + tb + cc) / 10;
    }
    if (cc)
        ans->s[i++] = cc;
    ans->l = i;
}

void mul(pNode pa, pNode pb, pNode ans) {
    Node ah, al, bh, bl;
    Node t1, t2, t3, t4, z;
    int ma = pa->l / 2;
    int mb = pb->l / 2;
    if (!ma || !mb) {
        if (!ma){
            pNode temp = pa;
            pa = pb;
            pb=  temp;
        }
        ans->c = pa->c + pb->c;
        int w = pb->s[0];
        int cc = 0;
        int i;
        for (i = 0; i <pa->l; i++)
        {
            ans->s[i] = (cc + pa->s[i] * w) % 10;
            cc = (cc + pa->s[i] * w) / 10;
        }
        if (cc)
            ans->s[i++] = cc;
        ans->l = i;
    }else {
        cp(pa, &ah, ma, pa->l - ma);
        cp(pa, &al, 0, ma);
        cp(pb, &bh, mb, pb->l - mb);
        cp(pb, &bl, 0, mb);

        mul(&ah, &bh, &t1);
        mul(&ah, &bl, &t2);
        mul(&al, &bh, &t3);
        mul(&al, &bl, &t4);

        add(&t3, &t4, ans);
        add(&t1, ans, &z);
        add(&t2, &z, ans);
    }
}
*/
string multiply(string num1, string num2) {
    Node a, b, ans;
    string res;
    int z = 0;

    for (int i = num1.size() - 1; i >= 0; i--)
        a.num[z++] = num1[i] - '0';
    a.len = num1.size();
    a.exp = 0;
    z = 0;
    for (int i = num2.size() - 1; i >= 0; i--)
        b.num[z++] = num2[i] - '0';
    b.exp = 0;
    b.len = num2.size();
    mul(a, b, ans);
    for (int i = ans.len - 1; i >= 0; i--) {
        res += (char) (ans.num[i] + '0');
    }

    return res;
}

//string multiply(string num1, string num2) {
//    Node a, b, ans;
//    string res;
//    int z = 0;
//
//    for (int i = num1.size() - 1; i >= 0; i--)
//        a.s[z++] = num1[i] - '0';
//    a.l = num1.size();
//    a.c = 0;
//    z = 0;
//    for (int i = num2.size() - 1; i >= 0; i--)
//        b.s[z++] = num2[i] - '0';
//    b.c = 0;
//    b.l = num2.size();
//
//    mul(&a, &b, &ans);
//    for (int i = ans.l - 1; i >= 0; i--) {
//        cout << ans.s[i];
//        res += (char) (ans.s[i] + '0');
//    }
//    cout << endl;
//    return res;
//}

int main() {
//    cout << multiply("5", "9");
Node a, b;
a.len = 1;
b.len = 2;
//swap(a,b);
    Node t = a;
    a = b;
    b = t;
cout << a.len << ' ' << b.len;
    return 0;
}
