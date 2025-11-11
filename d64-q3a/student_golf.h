#ifndef __STUDENT_H__
#define __STUDENT_H__
#define S size_t
#import<bits/stdc++.h>
#import"priority_queue.h"
template<typename T,typename C>T CP::priority_queue<T,C>::get_kth(S k)const{S s=mSize<7?mSize:7,i=0;T a[s];for(;i<s;i++)a[i]=mData[i];std::sort(a,a+s,mLess);return a[s-k];}
#endif